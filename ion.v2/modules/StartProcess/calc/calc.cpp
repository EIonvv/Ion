#include "calc.hpp"

void calc::execute()
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    if (!CreateProcess(AY_OBFUSCATE("C:\\Windows\\System32\\calc.exe"), NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
    {
        CoreManager::Logger(new const std::string(AY_OBFUSCATE("Failed to start calc.exe")), false);
        return;
    } else {
        CoreManager::Logger(new const std::string(AY_OBFUSCATE("Successfully started calc.exe")), true);
    }

    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return;
}