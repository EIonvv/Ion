#include "GetProcess.hpp"

void GetProcess::getProc(int argc, char *argv[])
{
    std::string command = "powershell -Command Get-Process " + std::string(argv[2]);
    int result = system(command.c_str());
    if (result != 0)
    {
        printf(AY_OBFUSCATE("Failed to execute command"));
    }

    std::cout << AY_OBFUSCATE("Process information displayed") << std::endl;
}
