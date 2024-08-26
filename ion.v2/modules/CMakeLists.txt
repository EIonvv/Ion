add_subdirectory(KillProcess)
add_subdirectory(GetPID)
add_subdirectory(StartProcess)

target_sources(
    ion 
    PRIVATE 
    "ModulesManager.cpp"
)