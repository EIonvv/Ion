#pragma once

#include "iostream"
#include "chrono"

#include "resources/obfuscate.hpp"
#include "Debug/Logger/Logger.hpp"

#include "systeminfo/cpu/cpu.hpp"
#include "systeminfo/location/getLocation.hpp"
#include "systeminfo/os_ver/version.hpp"
#include "systeminfo/username/OS_Username.hpp"
#include "systeminfo/timezone/getTimezone.hpp"

class CoreManager : public std::string
{
private:
    static std::string version;
    static std::string location;
    static std::string os_version;
    static std::string username;
    static std::string timezone;

public:
    static bool Initialize(int argc, char *argv[]);
    static bool Logger(const std::string *message, bool debug_mode = false);

public:
    static std::string CPU();
    static std::string GetLocation();
    static std::string OSVersion();
    static std::string GetUsername();
    static std::string Timezone();
};
