#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/socket.h>
#include <netinet/in.h>

#include <time.h>
#include <string.h>

#include "error.h"

#define MAXLINE 1000

int main(int argc, char **argv)
{
    int listenfd, connfd;
    struct sockaddr_in servaddr;
    char buff[MAXLINE];
    time_t ticks;

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
    {
        printf("socket error!\n");
        exit(1);
    }
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(13);
        
    if(bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1)
        err_sys("bind error!\n");

    if(listen(listenfd, 1024) == -1)
        err_sys("listen error!\n");

    while(1)
    {
        if((connfd = accept(listenfd, (sockaddr*)NULL, NULL)) < 0)
            err_sys("accept error!\n");
        printf("accept\n");
        ticks = time(NULL);
        //printf("%.24s\n", ctime(&ticks));
        snprintf(buff, sizeof(buff), "%.24s\n", ctime(&ticks));
        if(write(connfd, buff, strlen(buff)) < 0)
            err_sys("write error");
        if(write(connfd, buff, strlen(buff)) < 0)
            err_sys("write error");

        if(close(connfd) == -1)
            err_sys("close error!\n");
    }
    

    return 0;
}