#include "core/CoreManager.hpp"
#include "modules/ModulesManager.hpp"

int main(int argc, char *argv[])
{

    CoreManager *core_manager = new CoreManager();
    ModuleManager *module_manager = new ModuleManager();
    DebugLogger *logger = new DebugLogger();

    char *input = argv[1];

    if (!core_manager->Initialize(argc, argv))
    {
        return 1;
    }

    if (core_manager->Timezone() != "UTC")
    {
        logger->Info(new const std::string(AY_OBFUSCATE("Timezone is not UTC")), __FUNCTION__);
    }
    else
    {
        logger->Info(new const std::string(AY_OBFUSCATE("Timezone is UTC")), __FUNCTION__);
    }

    // module_manager->startCmd("/c echo Hello World from CMD");

    // module_manager->startPowershell("Start-Process -FilePath 'Ion.exe' -ArgumentList 'Hello World from Powershell' -WindowStyle Hidden");
    module_manager->startPowershell(new const std::string(AY_OBFUSCATE("-Command \"echo Hello World from Powershell\" > log.txt")));

    module_manager->startPowershell(new const std::string(AY_OBFUSCATE("Start-Process -FilePath 'notepad.exe' -ArgumentList 'log.txt'")));
    // module_manager->startNotepad();

    Sleep(500);
    module_manager->stopProcess(new const std::string(AY_OBFUSCATE("notepad.exe")));
    Sleep(500);

    delete core_manager;
    delete module_manager;
    delete logger;

    return 0;
};