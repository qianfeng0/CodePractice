#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <string>
#include <unistd.h>

#include <time.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SYS_OK      0
#define SYS_ERR     -1

#define SYS_EXIT(format, arg...)    \
{ \
    printf(format, ##arg); \
    exit(1); \
}

#define MAXLINE     1024

int main(int argc, char **argv)
{
    int res = 0;
    if(argc != 2){
        SYS_EXIT("usage: a.out <IPaddress>\n");
    }

    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if ( sockfd < 0 ){
        SYS_EXIT("SOCKET error");
    }

    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(2000);

    res = inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
    if (res <= 0)
        SYS_EXIT("inet_pton error for %s", argv[1]);
    
    res = connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    if ( res == SYS_ERR ) 
        SYS_EXIT("connect error");
        
    int count = 0;
    char rbuff[MAXLINE];
    int len = 0;
    while((len = read(sockfd, rbuff, MAXLINE)) > 0)
    {
        count++;
        rbuff[len] = 0;
        if(fputs(rbuff, stdout) == EOF)
            SYS_EXIT("fputs error\n");
    }
    printf("count: %d\n", count);
    
    if(len < 0)
        SYS_EXIT("read error\n");

    return 0;
}