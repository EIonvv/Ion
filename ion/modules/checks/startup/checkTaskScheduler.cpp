#include "checkTaskScheduler.hpp"

void checkTaskScheduler::check()
{
    std::string command = "schtasks /query /fo LIST /v | findstr /i /c:\"\\\"";

    std::cout << "Checking Task Scheduler" << std::endl;

    std::system(command.c_str());

    std::cout << "Task Scheduler check complete" << std::endl;

    return;
}