#include "ModulesManager.hpp"

int ModuleManager::startBeamNG()
{
    beamNG::StartBeamNG();
    return 0;
}

void ModuleManager::startCalc()
{
    calc::execute();
}

void ModuleManager::startNotepad()
{
    notepad::start();
}

void ModuleManager::startCmd(std::string command)
{
    cmd::execute(command);
}

bool ModuleManager::startPowershell(const std::string *command, const bool hide)
{
    // Powershell::startPowershell(command, hide);
    try {
        Powershell::startPowershell(command, hide);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
    return true;
}

void ModuleManager::stopProcess(const std::string *processName)
{
    // if no process name is provided, return
    if (*processName == "")
    {
        CoreManager::Logger(new const std::string(AY_OBFUSCATE("No process name provided")), false);
        return;
    }

    StopByName::stop(new const std::string(*processName));
}

int ModuleManager::ProcessID(const char *procName)
{
    return process::findProcessByName(procName);
}

void ModuleManager::stopPID(DWORD processID)
{
    StopByProcID::stop(processID);
}