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
        Logger(new const std::string(AY_OBFUSCATE("Username is empty")), false);
        return false;
    }

    if (check)
    {
        Logger(new const std::string(AY_OBFUSCATE("CoreManager initialized")), false);
    }

    return true;
#endif

#ifdef __linux__
    Logger(new const std::string("Linux"));
    return true;
#endif

#ifdef __APPLE__
    Logger(new const std::string("MacOS"));
    return true;
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
    const std::string *ver = new std::string(OSVersion().c_str());

    if (ver->empty())
    {
        std::cerr << "OS Version is empty" << std::endl;
        return false;
    }

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
        delete ver;
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
