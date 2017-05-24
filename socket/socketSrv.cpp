#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
//#include <sys/socket.h>
#include "error.h"

int main()
{
    int socketfd, connectfd;
    struct sockaddr_in servaddr;

    if ((socketfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        err_sys("socket error!\n");
    
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(4000);

    if (bind(socketfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1)
        err_sys("bind error!\n");
    
    if (listen(socketfd, 1024))
        err_sys("listen error!\n");

    while(1){
        printf("waiting connet......\n");
        if ((connectfd = accept(socketfd, (struct sockaddr*)NULL, NULL)) < 0)
            err_sys("accept error!\n");
        
        int len = 0;
        char buff[1024];
        while((len = read(connectfd, buff, sizeof(buff) - 1)) > 0){
            buff[len] = '\0';
            printf("%s\n", buff);
        }
        if(len < 0)
            err_sys("read error!\n");

        if(close(connectfd) == -1)
            err_sys("close error!\n");
    }
    return 0;
}