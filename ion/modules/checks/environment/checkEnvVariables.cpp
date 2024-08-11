#include "checkEnvVariables.hpp"

void checkEnvVariables::CheckVariables()
{
    std::string command = "set";

    std::cout << AY_OBFUSCATE("Checking Environment Variables") << std::endl;

    system(AY_OBFUSCATE("set"));

    std::cout << AY_OBFUSCATE("Environment Variables check complete") << std::endl;

    return;
}
