cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    greetness-app
    VERSION 0.1.0
    DESCRIPTION "App depending on greetness2"
    HOMEPAGE_URL "https://github.com/greetness-app"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(
    greetness-app_lib OBJECT
    source/lib.cpp
)

target_include_directories(
    greetness-app_lib ${warning_guard}
    PUBLIC
    "\$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
)

target_compile_features(greetness-app_lib PUBLIC cxx_std_17)

find_package(fmt REQUIRED)
target_link_libraries(greetness-app_lib PRIVATE fmt::fmt)


# ---- Declare executable ----

add_executable(greetness-app_exe source/main.cpp)
add_executable(greetness-app::exe ALIAS greetness-app_exe)

set_property(TARGET greetness-app_exe PROPERTY OUTPUT_NAME greetness-app)

target_compile_features(greetness-app_exe PRIVATE cxx_std_17)

find_package(greetness2 REQUIRED)
target_link_libraries(greetness-app_exe PRIVATE greetness2::greetness2)

target_link_libraries(greetness-app_exe PRIVATE greetness-app_lib)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT greetness-app_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of greetness-app"
  )
endif()

include(cmake/dev-mode.cmake)
