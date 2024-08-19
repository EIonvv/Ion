#pragma once

#include "iostream"

#include "resources/obfuscate.hpp"
#include "Debug/Logger.hpp"

#include "systeminfo/username/OS_Username.hpp"

class CoreManager
{
public:
    static bool Initialize(int argc, char *argv[]);
    static std::string GetUsername();
    static void Logger(const std::string *message);
};
