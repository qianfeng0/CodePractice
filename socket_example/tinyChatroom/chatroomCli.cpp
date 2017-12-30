#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <thread>
#include "error.h"

const char* signout = "sign out\n";

void recvHandle(int fd)
{
    /*
    char recvBuff[2028];
    int len = 0;
    while((len = read(fd, recvBuff, sizeof(recvBuff) - 1)) > 0){
        recvBuff[len] = '\0';
        printf("%s\n", recvBuff);
    }
    if(len < 0)
        err_sys("read error!\n");
    printf("disconnect\n");
    */
    char recvBuff[2028];
    int len = 0;
    while(1){
        len = recv(fd, recvBuff, sizeof(recvBuff) - 1, MSG_DONTWAIT);
        if(len > 0){
            recvBuff[len] = '\0';
            printf("%s", recvBuff);
        }
        else if(len < 0 && errno != EAGAIN){
            //perror("read");
            //err_sys("read error\n");
            break;
        }
        else if(len == 0){
            break;
        }
        sleep(1);
    }
}

int main(int argc, char **argv)
{
    if (argc != 2){
        printf("cmd: *.out <sign in name>\n");
        return 0;
    }

    int socketfd;
    struct sockaddr_in servaddr;

    //socket
    if ((socketfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        err_sys("socket error!\n");

    //server address
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(4000);
    if (inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) <= 0)
        err_sys("inet_ption error!\n");

    //connect server
    if (connect(socketfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
        err_sys("connect error\n");

    //send name
    if(write(socketfd, argv[1], strlen(argv[1])) <= 0)
        err_sys("write error!\n");
    //recv thread
    std::thread recvThread(recvHandle, socketfd);

    //input
    char txBuff[1024];
    while(1){
        fgets(txBuff, sizeof(txBuff) - 1, stdin);
        //is sign out?
        if(strcmp(txBuff, signout) == 0){
            if(close(socketfd) == -1)
                err_sys("close error!\n");
            printf("cmd:sign out sucess\n");
            break;
        }
        if(write(socketfd, txBuff, strlen(txBuff)) <= 0)
            err_sys("write error!\n");
    }
    recvThread.join();
    printf("process finish\n");
    pause();
    return 0;
}