#include "CoreManager.hpp"

bool CoreManager::Initialize(int argc, char *argv[])
{
#ifdef WIN32
    bool check = Logger(new const std::string(AY_OBFUSCATE("Initializing CoreManager")), false);

    if (!check)
    {
        return false;
    }

    if (CoreManager::GetUsername().empty())
    {
        Logger(new const std::string(AY_OBFUSCATE("Failed to get username")), false);
        return false;
    }

    if (check == true)
    {
        Logger(new const std::string(AY_OBFUSCATE("CoreManager initialized")), false);
    }

    return true;
#endif

#ifdef __linux__
    Logger(new const std::string("Linux"));
    return false;
#endif

#ifdef __APPLE__
    Logger(new const std::string("MacOS"));
    return false;
#endif
}

/**
 * @brief Log a message to the console
 *
 * @c std::string* `message` - The message to log
 * @return void
 *
 */
bool CoreManager::Logger(const std::string *message, bool debug_mode)
{

    if (debug_mode)
    {
        DebugLogger *logger = new DebugLogger();

        try
        {
            logger->Info(message);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
            return false;
        }

        delete logger;

        return true;
    }
    else
    {
        return true;
    }
}

std::string CoreManager::CPU()
{
    return cpu::GetCpuInfo();
}

std::string CoreManager::GetLocation()
{
    Location *location = new Location;

    const std::string *loc = new std::string(location->GetLocation());

    delete location;

    return *loc;
};

std::string CoreManager::OSVersion()
{
    return Version::GetOSVersion();
}

std::string CoreManager::GetUsername()
{
    OS_Username *os_username = new OS_Username();

    const std::string *username = new std::string(os_username->GetUsername());

    delete os_username;

    return *username;
}

std::string CoreManager::Timezone()
{
    getTimezone *tz = new getTimezone();

    std::string *timezone = new std::string(tz->Timezone());

    delete tz;

    return *timezone;
}
