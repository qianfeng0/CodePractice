/*
mknod in1
mknod in2

开2个终端，分别输入
cat > in1
cat > in2

select阻塞等待时，能被信号中断返回，可以用pselect屏蔽信号

epoll，使用EPOLLET模式时，fd要采用非阻塞，每次要判断EAGAIN，读完所有数据。
*/

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/poll.h>
#include <sys/epoll.h>

#include <unordered_set>
#include <set>
#include <algorithm>
#include <vector>

#define BUFF_SIZE   1024

#define EPOLL_MAX_EVENTS  10

void use_select(std::unordered_set<int> &fds);
void use_poll(std::unordered_set<int> &fds);
void use_epoll(std::unordered_set<int> &fds);

int main()
{
    int pipe_fd1, pipe_fd2;

    pipe_fd1 = open("./in1", O_RDONLY | O_NONBLOCK);
    if (pipe_fd1 == -1)
        perror("open");

    pipe_fd2 = open("./in2", O_RDONLY | O_NONBLOCK);
    if (pipe_fd1 == -1)
        perror("open");

    if (fcntl(0, F_SETFL, O_NONBLOCK) == -1){
        perror("fcntl");
    }
    printf("in1[%d] in2[%d]\n", pipe_fd1, pipe_fd2);

    std::unordered_set<int> fds;

    fds.insert(pipe_fd1);
    fds.insert(pipe_fd2);
    fds.insert(0);

    //use_select(fds);
    //use_poll(fds);
    use_epoll(fds);
/*
    char buff[1024];
    int count = 0;
    while(1){
        count = read(pipe_fd1, buff, BUFF_SIZE - 1);
        buff[count] = '\0';
        printf("1:[%d] %s", count, buff);

        count = read(pipe_fd2, buff, BUFF_SIZE - 1);
        buff[count] = '\0';
        printf("2:[%d] %s", count, buff);
    }
    */
    return 0;
}

void use_select(std::unordered_set<int> &fds)
{
    struct timeval timeout = {5, 0};

    fd_set read_fds;

    char buff[BUFF_SIZE];
    int count = 0;

    while(1){
        int nfd = 0;
        FD_ZERO(&read_fds);

        //注意timeout在select完后会被修改
        timeout.tv_sec = 5;
        timeout.tv_usec = 0;

        for (int i : fds){
            FD_SET(i, &read_fds);
            if (i > nfd){
                nfd = i;
            }
        }
        nfd++;

        switch(select(nfd, &read_fds, NULL, NULL, &timeout)){
            case -1:
                perror("select");
                exit(-1);
                break;
            case 0:
                printf("time out\n");
                break;
            default:
                printf("tag\n");
                for (int fd : fds){
                    if (FD_ISSET(fd, &read_fds)){
                        count = read(fd, buff, BUFF_SIZE - 1);
                        if (count == 0){
                            printf("close [%d]\n", fd);
                            if(close(fd) == -1)
                                perror("close");
                            fds.erase(fd);
                            continue;
                        }
                        buff[count] = '\0';
                        printf("%d:[%d] %s", fd, count, buff);
                    }
                }

        }
    }
}

void use_poll(std::unordered_set<int> &fds)
{
    char buff[BUFF_SIZE];
    int count = 0;

    int size = fds.size();
    std::vector<struct pollfd> pollfds(size, {0,0,0});
    std::vector<struct pollfd>::iterator ite = pollfds.begin();

    for(int i : fds){
        ite->fd = i;
        ite->events = POLLIN;
        ite++;
    }

    int timeout = -1;
    int numready = 0;
    while(pollfds.size() > 0){
        numready = poll(&pollfds[0], pollfds.size(), timeout);
        switch(numready){
            case -1:
                perror("poll");
                exit(1);
                break;
            case 0:
                printf("timeout\n");
                break;
            default:
                printf("tag\n");
                for (ite = pollfds.begin(); ite != pollfds.end(); ite++){
                    if (ite->revents & (POLLIN | POLLRDHUP | POLLHUP)){
                        count = read(ite->fd, buff, BUFF_SIZE - 1);
                        
                        if (count == 0){
                            printf("close [%d]\n", ite->fd);
                            if(close(ite->fd) == -1)
                                perror("close");
                            ite = pollfds.erase(ite);
                            ite--;
                            continue;
                        }
                        
                        buff[count] = '\0';
                        printf("%d:[%d] %s\n", ite->fd, count, buff);
                    }
                }
                break;
        }
    }
}

void use_epoll(std::unordered_set<int> &fds)
{
    
    struct epoll_event ev;
    
    int efd = epoll_create1(0);
    if (efd == -1){
        perror("epoll");
    }

    for (int fd : fds){
        ev.events = EPOLLIN | EPOLLET;
        ev.data.fd = fd;
        if (epoll_ctl(efd, EPOLL_CTL_ADD, fd, &ev) == -1){
            perror("epoll");
            exit(EXIT_FAILURE);
        }
    }
    
    struct epoll_event events[EPOLL_MAX_EVENTS];
    int nfds;

    char buff[BUFF_SIZE];
    int count = 0;
    while(1){
        nfds = epoll_wait(efd, events, EPOLL_MAX_EVENTS, -1);

        switch(nfds){
            case -1:
                perror("epoll_wait");
                exit(EXIT_FAILURE);
                break;
            case 0:
                printf("time out\n");
                break;
            default:
                for (int n = 0; n < nfds; n++){
                    int fd = events[n].data.fd;

                    while((count = read(fd, buff, 5 - 1)) > 0){
                        buff[count] = '\0';
                        printf("%d:[%d] %s\n", fd, count, buff);
                    }

                    if (count == -1 && errno != EAGAIN){
                        perror("read");
                        exit(1);
                    }
                    else if (count == 0){
                        if (epoll_ctl(efd, EPOLL_CTL_DEL, fd, &events[n]) == -1){
                            perror("epoll");
                            exit(EXIT_FAILURE);
                        }
        
                        printf("close [%d]\n", fd);
                        if(close(fd) == -1)
                            perror("close");
                        
                        break;
                    }
                    /*
                    else if (count == -1 && errno == EAGAIN)
                    while(1){
                        count = read(fd, buff, 5 - 1);
                        if (count == -1 && errno == EAGAIN){
                            break;
                        }
                        else if (count == 0){
                            if (epoll_ctl(efd, EPOLL_CTL_DEL, fd, &events[n]) == -1){
                                perror("epoll");
                                exit(EXIT_FAILURE);
                            }
            
                            printf("close [%d]\n", fd);
                            if(close(fd) == -1)
                                perror("close");
                            
                            break;
                        }
                        else{
                            buff[count] = '\0';
                            printf("%d:[%d] %s\n", fd, count, buff);
                        }
                    }
                    */
                }
        }
    }
}