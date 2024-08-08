cmake_minimum_required(VERSION 3.20)
project(ion LANGUAGES CXX C VERSION 1.0.0)

set_property(GLOBAL PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreadedDLL")

# Set the build directory explicitly
set(CMAKE_BINARY_DIR "E:/C++/ion/build")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Release) # This enables optimizations
set(CMAKE_CXX_COMPILE_FEATURES cxx_std_20 cxx_strong_enums cxx_lambdas cxx_auto_type cxx_constexpr cxx_nullptr cxx_range_for cxx_rvalue_references cxx_variadic_templates cxx_template_template_parameters cxx_decltype cxx_decltype_auto cxx_return_type_deduction cxx_aggregate_default_initializers cxx_alias_templates cxx_attributes cxx_binary_literals cxx_contextual_conversions cxx_defaulted_functions cxx_default_function_template_args cxx_defaulted_move_initializers cxx_delegating_constructors cxx_deleted_functions cxx_explicit_conversions cxx_final cxx_inheriting_constructors cxx_noexcept cxx_override cxx_user_literals cxx_generalized_initializers cxx_lambda_init_captures cxx_raw_string_literals cxx_reference_qualified_functions cxx_right_angle_brackets cxx_sizeof_member cxx_static_assert cxx_thread_local cxx_trailing_return_types cxx_unicode_literals cxx_uniform_initialization cxx_unrestricted_unions cxx_user_defined_literals cxx_variadic_macros cxx_std_20)

if(POLICY CMP0074)
  cmake_policy(SET CMP0074 NEW)
endif()

if(POLICY CMP0091)
  cmake_policy(SET CMP0091 NEW)
endif()

if(POLICY CMP0092)
  cmake_policy(SET CMP0092 NEW)
endif()

add_executable(
  ion 

  "Main.cpp"
  "Main.hpp"        

  "modules/Ping.cpp"
  "modules/Ping.hpp"

  "modules/checks/checkArpTable.cpp"
  "modules/checks/checkArpTable.hpp"

  "modules/checks/checkExclusions.cpp"
  "modules/checks/checkExclusions.hpp"
  
  "modules/checks/checkStartup.cpp"
  "modules/checks/checkStartup.hpp"

  "modules/checks/checkRegStartup.cpp"
  "modules/checks/checkRegStartup.hpp"

  "modules/removals/removeExclusion.cpp"
  "modules/removals/removeExclusion.hpp"
  )


if(CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ion PROPERTY CXX_STANDARD 20)
endif()

if(MSVC)
  target_compile_options(ion PRIVATE /GL /Ot /Oi /Oy /Ob2 /GF /GS- /Gy /Zc:inline /Zc:__cplusplus /Zc:preprocessor /Zc:threadSafeInit- /Zc:throwingNew /Zc:referenceBinding /Zc:externC /Zc:wchar_t /Zc:forScope /Zc:rvalueCast /Zc:strictStrings)
else()
  target_compile_options(ion PRIVATE -flto)
endif()


# Include directories
target_include_directories(ion PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


target_link_libraries(ion PRIVATE ws2_32)

# Set output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Enable position independent executables
set_target_properties(ion PROPERTIES POSITION_INDEPENDENT_CODE ON)
set_target_properties(ion PROPERTIES STRIP_ON_DEPLOY ON)
set_target_properties(ion PROPERTIES STRIP ON)

# Install targets
install(TARGETS ion
        RUNTIME DESTINATION bin
        COMPONENT Runtime)

# Embed a manifest that requires administrator privileges
set_target_properties(ion PROPERTIES
    LINK_FLAGS "/MANIFESTUAC:\"level='requireAdministrator' uiAccess='false'\""
)
