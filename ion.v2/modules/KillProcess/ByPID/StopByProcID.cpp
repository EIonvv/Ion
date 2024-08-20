#include "StopByProcID.hpp"

DWORD StopByProcID::stop(DWORD processID)
{
    HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, processID);
    if (hProcess == NULL)
    {
        return 1;
    }

    if (TerminateProcess(hProcess, 0) == 0)
    {
        return 1;
    }

    return 0;
}
