#include "KillProcess.hpp"

void KillProcess::killProc(int argc, char *argv[])
{
    std::string command = "powershell -Command Stop-Process -Name " + std::string(argv[2]);
    int result = system(command.c_str());
    if (result != 0)
    {
        printf(AY_OBFUSCATE("Failed to execute command"));
    }

    std::cout << AY_OBFUSCATE("Process killed") << std::endl;
}