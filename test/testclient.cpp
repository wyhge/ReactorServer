#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <iostream>

#define PORT 8888

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "Socket creation error\n";
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, "172.18.211.146", &serv_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address / Address not supported\n";
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Connection Failed\n";
        return -1;
    }

    std::string message;
    char buffer[1024] = {0};
    while(true) {
        std::cout << "Enter message: ";
        std::getline(std::cin, message);
        send(sock, message.c_str(), message.size(), 0);
        std::cout << "Message sent\n";
        int valread = read(sock, buffer, 1024);
        std::cout << "Reply is: " << buffer << "\n";
        memset(buffer, 0, sizeof(buffer));
    }

    return 0;
}