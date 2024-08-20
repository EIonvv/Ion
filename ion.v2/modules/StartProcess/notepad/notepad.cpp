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
        DebugLogger::Info(new const std::string(AY_OBFUSCATE("CreateProcess failed")), __FUNCTION__);
    }
    else
    {
        DebugLogger::Info(new const std::string(AY_OBFUSCATE("Notepad started")), __FUNCTION__);
    }

    // Close process and thread handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}