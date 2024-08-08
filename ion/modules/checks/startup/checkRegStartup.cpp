#include "checkRegStartup.hpp"

void checkRegStartup::checkRegStartUp()
{
    std::string command = "powershell -Command \"Get-CimInstance -ClassName Win32_StartupCommand | Select-Object -Property Name, Command | Out-String -Width 4096\"";
    int result = system(command.c_str());

    if (result != 0)
    {
        std::cerr << "Failed to execute command" << std::endl;
    }
}
