#include "core/CoreManager.hpp"
#include "modules/ModulesManager.hpp"

int main(int argc, char *argv[])
{

    CoreManager *core_manager = new CoreManager();
    ModuleManager *module_manager = new ModuleManager();
    DebugLogger *logger = new DebugLogger();

    // if the core manager fails to initialize, return 1
    if (!core_manager->Initialize(argc, argv))
    {
        return 1;
    }

    module_manager->startCmd("/c echo Hello World");

    // Handle the command line arguments
    module_manager->stopProcess(argv[1] == nullptr ? "" : argv[1]);

    // Clean up
    delete core_manager;
    delete module_manager;
    delete logger;

    return 0;
};