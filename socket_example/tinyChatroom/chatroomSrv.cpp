#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

#include <netinet/in.h>
#include <sys/socket.h>
#include <mutex>
#include <string.h>
#include <thread>
#include <string>
#include <list>
#include <map>

#include "error.h"

const char* signInMsg = "welcome to chatroom!\n";

std::list<int> connectingfd;
std::mutex connectingfd_mutex;
std::map<int, std::string> fdToname;
std::mutex fdToName_mutex;
/*
void sendToOtherClient(int sendSockfd, char* buff){
    connectingfd_mutex.lock();
    for(std::list<int>::iterator ite = connectingfd.begin(); ite != connectingfd.end(); ite++){
        if(*ite != sendSockfd){
            if (write(*ite, buff, strlen(buff)) < 0)
                err_sys("sendToOtherClient: write error %d\n", *ite);
        }
    }
    connectingfd_mutex.unlock();
}
*/

void sendToOtherClient(int sendSockfd, const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	char buff[1024];
	vsnprintf(buff, sizeof(buff) - 1, fmt, ap);
	va_end(ap);

    connectingfd_mutex.lock();
    for(std::list<int>::iterator ite = connectingfd.begin(); ite != connectingfd.end(); ite++){
        if(*ite != sendSockfd){
            if (write(*ite, buff, strlen(buff)) < 0)
                err_sys("sendToOtherClient: write error %d\n", *ite);
        }
    }
    connectingfd_mutex.unlock();
}
void clientHandle(const int fd)
{
    //add fd to list
    connectingfd_mutex.lock();
    connectingfd.push_back(fd);
    connectingfd_mutex.unlock();

    char rxBuff[1024];
    int len = 0;

    //recv sign in name
    len = read(fd, rxBuff, sizeof(rxBuff) - 1);
    rxBuff[len] = '\0';
    fdToName_mutex.lock();
    fdToname.insert(std::pair<int,std::string>(fd, rxBuff));
    fdToName_mutex.unlock();

    //send sign in msg
    if (write(fd, signInMsg, strlen(signInMsg)) < 0)
        err_sys("write error\n");
    
    //send sign in msg to connecting client
    sendToOtherClient(fd, "system: % sign in\n", fdToname[fd].data());
    
    //recv data
    while(((len = read(fd, rxBuff, sizeof(rxBuff) - 1)) > 0)){
        rxBuff[len] = '\0';
        printf("%s: %s", fdToname[fd].data(), rxBuff);
        sendToOtherClient(fd, "%s: %s", fdToname[fd].data(), rxBuff);
    }
    if(len < 0)
        err_sys("read error!\n");

    sendToOtherClient(fd, "system: %s sign out\n", fdToname[fd].data());
    //close
    if (close(fd) == -1)
        err_sys("close error!\n");

    //delete fd in list
    connectingfd_mutex.lock();
    std::list<int>::iterator ite = connectingfd.begin();
    while(ite != connectingfd.end()){
        if(*ite == fd){
            connectingfd.erase(ite);
            break;
        }
        ite++;
    }
    connectingfd_mutex.unlock();

    printf("name:%s(%d) sign out\n", fdToname[fd].data(), fd);

    //delete map of fd to name
    fdToName_mutex.lock();
    fdToname.erase(fd);
    fdToName_mutex.unlock();
}

int main(int argc, char **argv)
{
    int socketfd, connfd;
    struct sockaddr_in serverAddr;

    if ((socketfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        err_sys("socket error!\n");

    bzero(&serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(4000);

    if (bind(socketfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1)
        err_sys("bind error!\n");

    if (listen(socketfd, 1024) == -1)
        err_sys("listen error!\n");

    printf("chatroom startup!\n");
    while (1)
    {
        printf("wait connet......\n");
        if ((connfd = accept(socketfd, (sockaddr *)NULL, NULL)) < 0)
            err_sys("accept error!\n");
        
        std::thread th(clientHandle, connfd);
        th.detach();
    }
    return 0;
}