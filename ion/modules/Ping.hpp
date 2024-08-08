#pragma once

#include <cstdlib> // For std::system
#include <iostream>
#include <ws2tcpip.h>


class Ping
{
public:
    static void pingHost(char *host);
};