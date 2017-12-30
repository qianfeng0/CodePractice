#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <string>
#include <unistd.h>

#include <time.h>

#include <sys/socket.h>
#include <netinet/in.h>

#define SYS_OK      0
#define SYS_ERR     -1

#define SYS_EXIT(format, arg...)    \
{ \
    printf(format, ##arg); \
    exit(1); \
}

inline void sys_err(char* format, ...)
{
    char buff[1024];

    va_list args;
    va_start(args, format);
    vsnprintf(buff, 1024, format, args);
    va_end(args);
    exit(1);
}

int main(int argc, char **argv)
{
    int res = 0;

    int listenfd;
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0){
        SYS_EXIT("socket error listenfd[%d]\n", listenfd);
    }
    printf("listenfd[%d]\n", listenfd);

    struct sockaddr_in servAddr;
    bzero(&servAddr, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port = htons(2000);

    res = bind(listenfd, (struct sockaddr*)&servAddr, sizeof(servAddr));
    if (res == SYS_ERR){
        SYS_EXIT("bind error [%d]\n", res);
    }

    res = listen(listenfd, 1024);
    if (res == SYS_ERR){
        SYS_EXIT("listen error [%d]\n", res);
    }

    while(1){
        int connectfd = 0;
        struct sockaddr_in connect_addr;
        bzero(&connect_addr, sizeof(connect_addr));

        //connectfd = accept(listenfd, (sockaddr*)&connect_addr, NULL);
        connectfd = accept(listenfd, (sockaddr*)NULL, NULL);
        if (connectfd < 0){
            SYS_EXIT("accept error, connectfd[%d]", connectfd);
        }
        printf("accept! connectfd[%d], addr[%ux]\n", connectfd, connect_addr.sin_addr.s_addr);

        time_t tick = time(NULL);
        std::string str_time(ctime(&tick));

        res = write(connectfd, str_time.c_str(), str_time.length());
        if (res == SYS_ERR){
            SYS_EXIT("write error [%d]", res);
        }

        res = close(connectfd);
        if (SYS_ERR == res){
            SYS_EXIT("close error [%d]\n", res);
        }
    }
    return 0;
}