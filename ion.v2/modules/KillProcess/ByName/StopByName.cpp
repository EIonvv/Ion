#include "StopByName.hpp"

void StopByName::stop(const std::string *processName)
{
    // if no process name is provided, return
    if (*processName == "")
    {
        CoreManager::Logger(new const std::string(AY_OBFUSCATE("No process name provided")), true);
        return;
    }

    // Create a snapshot of all processes
    HANDLE hProcessSnap;
    PROCESSENTRY32 pe32;
    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hProcessSnap == INVALID_HANDLE_VALUE)
    {
        CoreManager::Logger(new const std::string(AY_OBFUSCATE("CreateToolhelp32Snapshot (of processes)")), false);
        return;
    }

    // Set the size of the structure before using it
    pe32.dwSize = sizeof(PROCESSENTRY32);

    // Retrieve information about the first process,
    // and exit if unsuccessful
    if (!Process32First(hProcessSnap, &pe32))
    {
        CoreManager::Logger(new const std::string(AY_OBFUSCATE("Process32First")), false); // show cause of failure
        CloseHandle(hProcessSnap); // clean the snapshot object
        return;
    }

    // Now walk the snapshot of processes, and
    // display information about each process in turn
    do
    {
        if (pe32.szExeFile == *processName)
        {
            HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, pe32.th32ProcessID);
            if (hProcess == NULL)
            {
                CoreManager::Logger(new const std::string(AY_OBFUSCATE("OpenProcess")), false);
            }
            else
            {
                if (!TerminateProcess(hProcess, 0))
                {
                    CoreManager::Logger(new const std::string(AY_OBFUSCATE("TerminateProcess")), false);
                }
                else
                {
                    CoreManager::Logger(new const std::string(AY_OBFUSCATE("Process terminated")), false);
                }
                CloseHandle(hProcess);
            }
        }
    } while (Process32Next(hProcessSnap, &pe32));

    CloseHandle(hProcessSnap);
}