#pragma once

#include <iostream>
#include <Windows.h>

#include "../../../core/resources/obfuscate.hpp"
#include "../../../core/debug/Logger/Logger.hpp"

class Powershell
{
public:
    static void startPowershell(const std::string *command);
};