#pragma once

#include <string>

class Client
{
public:
    Client();
    ~Client();

    void connect(const char* ip, uint32_t port);
    void send(const std::string& content);
    std::string receive();

private:
    int client;
};