#include "Client.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <cstring>
#include <string>
#include <iostream>
#include <stdexcept>

Client::Client()
{
    client = socket(AF_INET, SOCK_STREAM, 0);

    if (client < 0)
    {
        printf("Error - open client: %s\n", strerror(errno));
        throw std::runtime_error("open client error");
    }
}

Client::~Client()
{
    if (client >= 0)
    {
        close(client);
    }
}

void Client::connect(const char* ip, uint32_t port)
{
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr(ip);
    serverAddress.sin_port = htons(port);


    if (::connect(client, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0)
    {
        printf("Error - connect to server: %s\n", strerror(errno));
        throw std::runtime_error("connnect to server error");
    }
}

void Client::send(const std::string& content)
{
    if (::send(client, content.c_str(), content.size(), 0) < 0)
    {
        printf("Error - client send message: %s\n", strerror(errno));
    }
}

std::string Client::receive()
{
    char buffer[1024] = {0};
    if (recv(client, buffer, sizeof(buffer), 0) < 0)
    {
        printf("Error - client receive message: %s\n", strerror(errno));
    }

    return buffer;
}