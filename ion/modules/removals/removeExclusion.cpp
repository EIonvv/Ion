#include "removeExclusion.hpp"

void removeExclusion::removePath(int argc, char *argv[])
{
    std::string command = "powershell -Command \"Remove-MpPreference -ExclusionPath " + std::string(argv[2]) + "\"";
    int result = system(command.c_str());

    if (result != 0)
    {
        std::cerr << "Failed to execute command" << std::endl;
    }

    std::cout << "Exclusion removed" << std::endl;
};