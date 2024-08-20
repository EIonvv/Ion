#include "CoreManager.hpp"

bool CoreManager::Initialize(int argc, char *argv[])
{
    bool is_initialized;
#ifdef WIN32
    Logger(new const std::string(AY_OBFUSCATE("Windows")));
    bool check = Logger(new const std::string(AY_OBFUSCATE("Initializing CoreManager")), false);

    if (!check)
    {
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
    if (debug_mode)
    {
        DebugLogger *logger = new DebugLogger();

        try
        {
            logger->LogDynamic(message);
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

std::string CoreManager::GetUsername()
{
    std::string *username = new std::string(OS_Username::GetUsername());

    if (username->empty())
    {
        Logger(new const std::string(AY_OBFUSCATE("Failed to get username")));
        return std::string(AY_OBFUSCATE("Failed to get username"));
    }

    if (username->length() > 0)
    {
        delete username;

        return *username;
    }

    delete username;

    return 0;
}

std::string CoreManager::Timezone()
{
    getTimezone *tz = new getTimezone();

    std::string *timezone = new std::string(tz->Timezone());

    delete tz;

    return *timezone;
}
