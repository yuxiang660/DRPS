#pragma once

#include "Connection.h"
#include <memory>

class Server
{
public:
    Server();
    ~Server();

    void listen(uint32_t port, int32_t backlog);
    std::shared_ptr<Connection> accept();

private:
    void bind(uint32_t port);

private:
    int server;
};
