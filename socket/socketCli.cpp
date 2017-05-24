#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <string.h>

#include "error.h"

int main()
{
    int socketfd;
    struct sockaddr_in servaddr;

    if ((socketfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        err_sys("socket error!\n");

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(4000);
    if (inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) <= 0)
        err_sys("inet_pton error!\n");

    if (connect(socketfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
        err_sys("connect error!\n");

    char buff[1024];
    snprintf(buff, sizeof(buff) - 1, "hello");
    if (write(socketfd, buff, strlen(buff)) < 0)
        err_sys("write error!\n");

    if (close(socketfd) == -1)
        err_sys("close error!\n");

    pause();
}