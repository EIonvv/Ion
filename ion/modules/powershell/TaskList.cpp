#include "TaskList.hpp"

void TaskList::taskList(int argc, char *argv[])
{
    std::cout << AY_OBFUSCATE("Listing out the running processes...") << std::endl;
    int ret = system("tasklist");
    if (ret != 0)
    {
        std::cout << AY_OBFUSCATE("Error in listing out the running processes.") << std::endl;
    }

    return;
}