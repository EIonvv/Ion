#include "iostream"
#include "string"
#include "Windows.h"

#include "../../resources/obfuscate.hpp"
#include "../../debug/Logger/Logger.hpp"

class NetworkCheck : public std::string
{
public:
    static bool check();
};