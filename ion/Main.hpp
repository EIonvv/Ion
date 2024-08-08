#pragma once
#pragma comment(lib, "Ws2_32.lib")

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>

#include "modules/checks/checkStartup.hpp"
#include "modules/checks/checkRegStartup.hpp"
#include "modules/checks/checkArpTable.hpp"
#include "modules/checks/checkExclusions.hpp"

#include "modules/Ping.hpp"

#include "modules/removals/removeExclusion.hpp"


