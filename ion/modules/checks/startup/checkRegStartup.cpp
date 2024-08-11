#include "checkRegStartup.hpp"

void checkRegStartup::checkRegStartUp()
{
    std::string command = "powershell -Command \"Get-CimInstance -ClassName Win32_StartupCommand | Where-Object { $_.Command -like '*\\*.exe*' } | Select-Object -Property Name, Command | Out-String -Width 4096\"";
    int result = system(command.c_str());

    if (result != 0)
    {
        printf(AY_OBFUSCATE("Failed to execute command"));
    }

    if (result == 0)
    {
        std::cout << AY_OBFUSCATE("Registry startup entries checked") << std::endl;
    }

    return;
}
