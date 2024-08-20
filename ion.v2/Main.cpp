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
        logger->LogDynamic(new const std::string(AY_OBFUSCATE("Timezone is not UTC")));
    } else {
        logger->LogDynamic(new const std::string(AY_OBFUSCATE("Timezone is UTC")));
    }

    module_manager->startCmd("/c echo Hello World");


    module_manager->stopProcess(input == NULL ? "" : input);

    delete core_manager;
    delete module_manager;
    delete logger;

    return 0;
};