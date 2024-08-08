#pragma once

#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib> // For std::system
#include <iostream>
#include <filesystem>

class checkStartupFolder{
public:
    static void checkFolder();
};