#include "removeExclusion.hpp"

void removeExclusion::removePath(int argc, char *argv[])
{
    std::string command = "powershell -Command Remove-MpPreference -ExclusionPath " + std::string(argv[2]);
    int result = system(command.c_str());
    if (result != 0)
    {
        printf(AY_OBFUSCATE("Failed to execute command"));
    }

    std::cout << AY_OBFUSCATE("Exclusion removed") << std::endl;
};

void removeExclusion::removeExtension(int argc, char *argv[])
{
    std::string command = "powershell -Command Remove-MpPreference -ExclusionExtension " + std::string(argv[2]);

    int result = system(command.c_str());

    if (result != 0)
    {
        std::cerr << AY_OBFUSCATE("Failed to execute command") << std::endl;
    }

    std::cout << AY_OBFUSCATE("Exclusion removed") << std::endl;
};