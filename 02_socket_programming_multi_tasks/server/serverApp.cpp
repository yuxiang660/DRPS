#include "Server.h"
#include <string.h>
#include <iostream>

static const uint32_t port = 8080;
static const int32_t serverBacklog = 3;
const char* serverMessage = "你好 from server";

int main(int argc, char const *argv[])
{
    // 1. create a server by opening a socket.
    Server server;

    // 2. listen for connections on the port with the server socke.
    server.listen(port, serverBacklog);

    // 3. block for the connection from clients.
    auto connection = server.accept();

    // 4. receive a message from the client.
    std::cout << "server receives message from the client: " << connection->receive() << std::endl;

    // 5. send a message to the client.
    std::cout << "server sends message to client: " << serverMessage << std::endl;
    connection->send(serverMessage);
    
    return 0;
}