#include "Logger.hpp"

bool DebugLogger::LogDynamic(const std::string *message)
{
    if (message != nullptr)
    {
        std::cout << *message << std::endl;
        delete message; // Ensure to delete the dynamically allocated string

        return true;
    }

    std::cout << AY_OBFUSCATE("Failed to log message.") << std::endl;
    return false;
}
