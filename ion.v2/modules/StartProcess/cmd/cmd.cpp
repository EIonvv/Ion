#include "cmd.hpp"

void cmd::execute(std::string command)
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Ensure the command string is not const
    LPSTR cmdLine = const_cast<LPSTR>(static_cast<const char *>(command.c_str()));

    if (!CreateProcess("C:\\Windows\\System32\\cmd.exe", cmdLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
    {
        std::cout << "CreateProcess failed: " << GetLastError() << std::endl;
        return;
    }
    else
    {
        DebugLogger::LogDynamic(new const std::string(AY_OBFUSCATE("Successfully started cmd.exe")));
    }

    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return;
}