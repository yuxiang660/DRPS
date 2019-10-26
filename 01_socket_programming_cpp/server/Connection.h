#pragma once

#include <string>

class Connection
{
public:
    Connection(int connection);
    ~Connection();

    void send(const std::string& content);
    std::string receive();

public:
    int connection;
};