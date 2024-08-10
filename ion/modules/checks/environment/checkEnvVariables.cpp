#include "checkEnvVariables.hpp"

void checkEnvVariables::CheckVariables()
{
    std::string command = "set";

    std::cout << AY_OBFUSCATE("Checking Environment Variables") << std::endl;

    std::system(command.c_str());

    std::cout << AY_OBFUSCATE("Environment Variables check complete") << std::endl;

    return;
}
