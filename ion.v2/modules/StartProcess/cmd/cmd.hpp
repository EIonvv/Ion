#pragma once 

#include <iostream>
#include <Windows.h>

#include "../../../core/CoreManager.hpp"
#include "../../../core/resources/obfuscate.hpp"
#include "../../../core/debug/Logger/Logger.hpp"

class cmd
{
public:
    static void execute(std::string command);
};