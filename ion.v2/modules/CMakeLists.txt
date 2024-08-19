add_subdirectory(StartProcess)
add_subdirectory(KillProcess)

target_sources(
    ion 
    PRIVATE 
    "ModulesManager.cpp"
)