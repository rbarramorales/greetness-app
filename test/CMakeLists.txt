# Parent project does not export its library target, so this CML implicitly
# depends on being added from it, i.e. the testing is done only from the build
# tree and is not feasible from an install location

project(greetness-appTests LANGUAGES CXX)

# ---- Dependencies ----

find_package(Catch2 REQUIRED)
include(Catch)

# ---- Tests ----

add_executable(greetness-app_test source/greetness-app_test.cpp)
target_link_libraries(
    greetness-app_test PRIVATE
    greetness-app_lib
    Catch2::Catch2WithMain
)
target_compile_features(greetness-app_test PRIVATE cxx_std_17)

catch_discover_tests(greetness-app_test)

# ---- End-of-file commands ----

add_folders(Test)
