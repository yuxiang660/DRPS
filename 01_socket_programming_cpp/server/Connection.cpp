#include "Connection.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <cstring>
#include <iostream>

Connection::Connection(int connection) :
    connection(connection)
{
}

Connection::~Connection()
{
    if (connection >= 0)
    {
        ::close(connection);
    }
}

void Connection::send(const std::string& content)
{
    if (::send(connection, content.c_str(), content.size(), 0) < 0)
    {
        printf("Error - server send message: %s\n", strerror(errno));
    }
}

std::string Connection::receive()
{
    char buffer[1024] = {0};
    if (::recv(connection, buffer, sizeof(buffer), 0) < 0)
    {
        printf("Error - server receive message: %s\n", strerror(errno));
    }

    return buffer;
}
