#include <netinet/in.h>
#include <arpa/inet.h>

#include <unistd.h>
#include <stdio.h>
//#include <stdlib.h>
#include <string.h>

#include "error.h"

#define MAXLINE 1000

int main(int argc, char **argv)
{
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr;

    if(argc != 2)
        err_sys("usage: a.out <IPaddress>");
    
    if( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
        err_sys("SOCKET error");
    
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(13);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
        err_sys("inet_pton error for %s", argv[1]);
    
    if ( connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0 ) 
        err_sys("connect error");
        
    int count = 0;
    while( (n = read(sockfd, recvline, MAXLINE)) > 0)
    {
        count++;
        recvline[n] = 0;
        if(fputs(recvline, stdout) == EOF)
            err_sys("fputs error");
    }
    printf("count: %d\n", count);
    
    if(n < 0)
        err_sys("read error");

    return 0;
}