#include "cpu.hpp"

std::string cpu::GetCpuInfo()
{
    std::string cpu_info = "";
    std::array<char, 128> buffer;
    FILE *pipe = _popen("wmic cpu get name | findstr /v name", "r");
    if (!pipe)
    {
        throw std::runtime_error("popen() failed!");
    }
    while (!feof(pipe))
    {
        if (fgets(buffer.data(), 128, pipe) != NULL)
        {
            cpu_info += buffer.data();
        }

        // cut out any newline characters
        cpu_info.erase(std::remove(cpu_info.begin(), cpu_info.end(), '\n'), cpu_info.end());
    }
    _pclose(pipe);
    return cpu_info;
}