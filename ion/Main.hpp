#pragma once
#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "advapi32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "ole32.lib")

// General utility functions
#include "core/core.hpp"

// Core functionalities
#include "core/info/osUsername.h"

// PowerShell module functionalities
#include "modules/powershell/GetProcess.hpp"
#include "modules/powershell/KillProcess.hpp"
#include "modules/powershell/TaskList.hpp"


// Removals and exclusions
#include "modules/removals/removeExclusion.hpp"

// Startup checks
#include "modules/checks/startup/checkStartup.hpp"
#include "modules/checks/startup/checkRegStartup.hpp"
#include "modules/checks/startup/checkTaskScheduler.hpp"

// Network checks
#include "modules/checks/network/checkArpTable.hpp"

// Environment checks
#include "modules/checks/environment/checkEnvVariables.hpp"

// Windows Defender checks
#include "modules/checks/windows_defender/checkExclusions.hpp"
