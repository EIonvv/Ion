#include "ModulesManager.hpp"

void ModuleManager::startCalc()
{
    calc::start();
}

void ModuleManager::stopProcess(const std::string &processName)
{   
    // if no process name is provided, return

    if (processName.empty())
    {
        DebugLogger::LogDynamic(new const std::string(AY_OBFUSCATE("No process name provided")));
        return;
    }

    StopByName::stop(processName);
}
