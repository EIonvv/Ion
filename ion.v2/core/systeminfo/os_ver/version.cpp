#include "version.hpp"

std::string Version::GetOSVersion()
{
    // Get version of Windows
    OSVERSIONINFOEX osvi;

    ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

    GetVersionEx((OSVERSIONINFO *)&osvi);

    std::string version = std::to_string(osvi.dwMajorVersion) + "." + std::to_string(osvi.dwMinorVersion);

    return version;
}