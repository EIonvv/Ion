#include "notepad.hpp"

void notepad::start()
{
    // Create the process
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Start the process
    if (!CreateProcess(AY_OBFUSCATE("C:\\Windows\\System32\\notepad.exe"), NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
    {
        CoreManager::Logger(new const std::string(AY_OBFUSCATE("Failed to start notepad")), false);
    }
    else
    {
        CoreManager::Logger(new const std::string(AY_OBFUSCATE("Notepad started")), true);
    }

    // Close process and thread handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}