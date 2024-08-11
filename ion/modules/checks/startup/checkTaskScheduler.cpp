#include "checkTaskScheduler.hpp"

void checkTaskScheduler::check()
{
    std::cout << "Checking Task Scheduler" << std::endl;

    std::system(AY_OBFUSCATE("schtasks /query /fo LIST /v"));

    std::cout << "Task Scheduler check complete" << std::endl;

    return;
}