#pragma once
#pragma comment(lib, "Ws2_32.lib")
#include "my_c_functions.h"

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>

#include "modules/checks/startup/checkStartup.hpp"
#include "modules/checks/startup/checkRegStartup.hpp"
#include "modules/checks/network/checkArpTable.hpp"
#include "modules/checks/windows_defender/checkExclusions.hpp"

#include "modules/removals/removeExclusion.hpp"

#include "modules/Ping.hpp"
