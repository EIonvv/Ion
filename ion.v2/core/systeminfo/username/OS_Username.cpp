#include "OS_Username.hpp"

std::string OS_Username::GetUsername()
{
    char username[UNLEN + 1];
    DWORD username_len = UNLEN + 1;
    GetUserNameA(username, &username_len);
    return std::string(username);
};
