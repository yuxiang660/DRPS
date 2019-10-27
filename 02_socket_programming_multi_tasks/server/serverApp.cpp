#include "Server.h"
#include "Connection.h"
#include <iostream>
#include <memory>
#include <thread>

static const uint32_t port = 8080;
static const int32_t serverBacklog = 3;
const char* serverMessage = "你好 from server";

void workerMain(std::shared_ptr<Connection> connection)
{
    std::cout << "server receives message from the client: " << connection->receive() << std::endl;

    std::cout << "server sends message to client: " << serverMessage << std::endl;
    connection->send(serverMessage);
}

void startWorker(std::shared_ptr<Connection> connection)
{
    std::thread* workerThread = new std::thread(workerMain, connection);
}

int main(int argc, char const *argv[])
{
    // 1. create a server by opening a socket.
    Server server;

    // 2. listen for connections on the port with the server socke.
    server.listen(port, serverBacklog);

    // 3. block for the connection from clients.
    while (1)
    {
        auto connection = server.accept();
        startWorker(connection);
    }
    
    return 0;
}