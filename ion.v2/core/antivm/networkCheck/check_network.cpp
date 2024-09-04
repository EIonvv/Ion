#include "check_network.hpp"

bool NetworkCheck::check()
{
    
    if (ShellExecute(NULL, "open", AY_OBFUSCATE("ping"), AY_OBFUSCATE("google.com"), NULL, SW_HIDE) == (HINSTANCE)42)
    {
        return true;
    }
    else
    {
        return false;
    }

    return false;
};