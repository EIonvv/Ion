#pragma once 

#include <iostream>
#include <Windows.h>

#include "../../../core/resources/obfuscate.hpp"
#include "../../../core/debug/Logger.hpp"

class cmd
{
public:
    static void execute(std::string command);
};