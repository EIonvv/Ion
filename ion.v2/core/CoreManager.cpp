#include "CoreManager.hpp"

bool CoreManager::Initialize(int argc, char *argv[])
{

#ifdef WIN32
    Logger(new const std::string("Windows"));
#endif

#ifdef __linux__
    Logger(new const std::string("Linux"));
#endif

#ifdef __APPLE__
    Logger(new const std::string("MacOS"));
#endif

    Logger(new const std::string(GetUsername()));

    return 0;
}

std::string CoreManager::GetUsername()
{
    std::string *username = new std::string(OS_Username::GetUsername());

    if (username->empty())
    {
        Logger(new const std::string(AY_OBFUSCATE("Failed to get username")));
        return "Failed to get username";
    }

    if (username->length() > 0)
    {
        return *username;
    }

    delete username;
    return 0;
}

/**
 * @brief Log a message to the console
 *
 * @c std::string* `message` - The message to log
 * @return void
 *
 */
void CoreManager::Logger(const std::string *message)
{
    DebugLogger *logger = new DebugLogger();

    logger->LogDynamic(message);

    delete logger;
}
