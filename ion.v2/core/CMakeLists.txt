add_subdirectory(debug)
add_subdirectory(resources)
add_subdirectory(systeminfo)

target_sources(ion PRIVATE
  "CoreManager.cpp"
  "CoreManager.hpp"
)
