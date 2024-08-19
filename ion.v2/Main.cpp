#include "core/CoreManager.hpp"
#include "modules/ModulesManager.hpp"

int main(int argc, char *argv[])
{

    CoreManager *core_manager = new CoreManager();
    ModuleManager *module_manager = new ModuleManager();

    core_manager->Initialize(argc, argv);
    module_manager->stopProcess(argv[1]);

    delete core_manager;
    delete module_manager;
    return 0;
};