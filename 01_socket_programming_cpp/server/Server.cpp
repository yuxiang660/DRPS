#include "Server.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <cstring>
#include <stdexcept>

Server::Server()
{
    server = socket(AF_INET, SOCK_STREAM, 0);

    if (server < 0)
    {
        printf("Error - open server: %s\n", strerror(errno));
        throw std::runtime_error("open server error");
    }
}

Server::~Server()
{
    if (server >= 0)
    {
        close(server);
    }
}

void Server::bind(uint32_t port)
{
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (::bind(server, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        printf("Error - server bind: %s\n", strerror(errno));
        throw std::runtime_error("bind error");
    }
}

void Server::listen(uint32_t port, int32_t backlog)
{
    bind(port);
    
    if (::listen(server, backlog) < 0)
    {
        printf("Error - server listen: %s\n", strerror(errno));
        throw std::runtime_error("listen error");
    }
}

std::shared_ptr<Connection> Server::accept()
{
    sockaddr_in clientAddress;
    int length = sizeof (clientAddress);
    int connection = ::accept
    (
        server,
        (struct sockaddr*)&clientAddress,
        (socklen_t*)&length
    );

    if (connection < 0)
    {
        printf("Error - server accept: %s\n", strerror(errno));
        throw std::runtime_error("connection error");
    }

    return std::make_shared<Connection>(connection);
}
