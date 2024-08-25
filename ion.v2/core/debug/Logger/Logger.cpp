#include "Logger.hpp"
#include <memory>

// Assuming AY_OBFUSCATE can be replaced or handled differently
const char *kInfoLabel = AY_OBFUSCATE("INFO");
const char *kSuccessColorCode = AY_OBFUSCATE("\033[1;32m");
const char *kResetColorCode = AY_OBFUSCATE("\033[0m");

bool DebugLogger::Info(const std::string *message)
{

    try
    {
        std::cout << AY_OBFUSCATE("[") << kSuccessColorCode << kInfoLabel << kResetColorCode << AY_OBFUSCATE("] ") << *message << std::endl;
        return true;
    }
    catch (...)
    {
        std::cerr << kResetColorCode << AY_OBFUSCATE("An error occurred while logging the message") << std::endl;
        return false;
    }
}