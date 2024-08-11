#include "checkArpTable.hpp"

void CheckArpTable::checkTable()
{
    system(AY_OBFUSCATE("arp -a"));
}