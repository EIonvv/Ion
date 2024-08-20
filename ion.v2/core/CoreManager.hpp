#pragma once

#include "iostream"
#include "chrono"

#include "resources/obfuscate.hpp"
#include "Debug/Logger/Logger.hpp"

#include "systeminfo/username/OS_Username.hpp"
#include "systeminfo/timezone/getTimezone.hpp"

class CoreManager : public std::string
{
public:
    static bool Initialize(int argc, char *argv[]);
    static bool Logger(const std::string *message, bool debug_mode = false);

public:
    static std::string GetUsername();
    static std::string Timezone();
};
