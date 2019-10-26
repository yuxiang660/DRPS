#pragma once

#include "Connection.h"
#include <memory>

class Server
{
public:
    Server();
    ~Server();

    void bind(uint32_t port);
    void listen(int32_t backlog);
    std::shared_ptr<Connection> accept();

private:
    int server;
};
