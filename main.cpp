#include <sys/epoll.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <arpa/inet.h>  // 添加这一行

#include "EpollServer/EpollServer.h"

int main() {
    printf("main start \n");
    EpollServer server("xxx.xxx.xxx.xxx", 8888);
    return server.run();

    //return 0;
}