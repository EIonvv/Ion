#include "powershell.hpp"

void Powershell::startPowershell(const std::string *command)
{
    ShellExecuteA(NULL, AY_OBFUSCATE("open"), AY_OBFUSCATE("powershell"), command->c_str(), NULL, SW_SHOWNORMAL);
}