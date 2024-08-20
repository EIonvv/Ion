#include "Logger.hpp"
#include <memory>

// Assuming AY_OBFUSCATE can be replaced or handled differently
const char *kInfoLabel = "INFO";
const char *kSuccessColorCode = "\033[1;32m";
const char *kResetColorCode = "\033[0m";

bool DebugLogger::Info(const std::string *message, const char *functionName)
{
    try
    {
        std::cout << "[" << kSuccessColorCode << kInfoLabel << kResetColorCode << "] " << functionName << ": " << std::string(*message) << std::endl;
        return true;
    }
    catch (...)
    {
        std::cerr << kResetColorCode << "Exception caught during logging." << std::endl;
        return false;
    }
}