#include "osUsername.hpp"

extern "C"
{
    char *UserName()
    {
        char name[100];

        // Find the user name in the environment
        if (getenv(AY_OBFUSCATE("USERNAME")) != NULL)
        {
            strncpy(name, getenv(AY_OBFUSCATE("USERNAME")), sizeof(name));
        }
        else
        {
            strncpy(name, getenv(AY_OBFUSCATE("USER")), sizeof(name));
        }

        // Allocate memory for the return string
        size_t len = strlen(name);
        char *result = new char[len + 1]; // Allocate enough space for the null terminator
        strcpy(result, name);

        return result;
    }
}