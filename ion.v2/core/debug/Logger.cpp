#include "Logger.hpp"

void DebugLogger::LogDynamic(const std::string *message)
{
    if (message != nullptr)
    {
        std::cout << *message << std::endl;
        delete message; // Ensure to delete the dynamically allocated string
    }
}
