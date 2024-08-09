target_sources(ion PRIVATE
  "Ping.cpp"
  "Ping.hpp"    
  "checks/network/checkArpTable.cpp"
  "checks/network/checkArpTable.hpp"
  "checks/startup/checkRegStartup.cpp"
  "checks/startup/checkRegStartup.hpp"
  "checks/startup/checkStartup.cpp"
  "checks/startup/checkStartup.hpp"
  "checks/startup/checkTaskScheduler.cpp"
  "checks/startup/checkTaskScheduler.hpp"
  "checks/windows_defender/checkExclusions.cpp"
  "checks/windows_defender/checkExclusions.hpp"
  "removals/removeExclusion.cpp"
  "removals/removeExclusion.hpp"
)

add_subdirectory(checks)