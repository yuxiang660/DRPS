#include "Client.h"
#include <string.h>
#include <iostream>

static const char* ip = "127.0.0.1";
static const uint32_t port = 8080;
static const char* clientMessage = "hello from client";

int main(int argc, char const *argv[])
{
    // 1. create a client by opening a socket.
    Client client;

    // 2. connect to the server with the address and port of the server.
    client.connect(ip, port);

    // 3. send a message to the server.
    std::cout << "client sends message to server: " << clientMessage << std::endl;
    client.send(clientMessage);

    // 4. receive a message from the server.
    std::cout << "client receives message from server: " << client.receive() << std::endl;

    return 0;
}