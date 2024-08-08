#include "checkArpTable.hpp"

void CheckArpTable::checkTable()
{
    system("arp -a");
}