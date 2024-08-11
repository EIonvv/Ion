#include "checkRegStartup.hpp"

void checkRegStartup::checkRegStartUp()
{
    system(AY_OBFUSCATE("powershell -Command \"Get-CimInstance -ClassName Win32_StartupCommand | Where-Object { $_.Command -like '*\\*.exe*' } | Select-Object -Property Name, Command | Out-String -Width 4096\""));
}
