#include "GetPid.hpp"

int process::findProcessByName(const char *procName)
{
    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(PROCESSENTRY32);
    int pid = -1;
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (Process32First(snapshot, &entry) == TRUE)
    {
        while (Process32Next(snapshot, &entry) == TRUE)
        {
            if (strcmp(const_cast<char *>(entry.szExeFile), procName) == 0)
            {
                pid = entry.th32ProcessID;
                break;
            }
        }
    }

    // if pid is -1, the process was not found
    if (pid == -1)
    {
        DebugLogger::Info(new const std::string(AY_OBFUSCATE("Process not found.")));
    }

    CloseHandle(snapshot);
    return pid;
}