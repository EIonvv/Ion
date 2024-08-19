#include "core/CoreManager.hpp"

int main(int argc, char* argv[])
{
    CoreManager* core_manager = new CoreManager();
    core_manager->Initialize(argc, argv);

    delete core_manager;
    return 0;
};