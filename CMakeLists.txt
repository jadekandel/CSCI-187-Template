cmake_minimum_required(VERSION 3.16)

project(MyProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

# The GUI application.
# Include ALL files you need to run your application,
# including view and controller files.
# main.cpp must stay here and must NOT appear in test_build below, or you
# will get a "duplicate main" link error.
add_executable(app
    # EDIT THIS LIST:
    src/main.cpp
    src/prime.cpp
)
target_link_libraries(app PRIVATE Qt6::Widgets)

# The test binary. Include model classes and test .cpp files (no h files)
# In this class, we only test the model classes, not view and controller files.
# test_main.cpp provides main() for the test binary and must stay in this
# list. Every other test file (e.g. test_prime.cpp) is an ordinary doctest
# file with no special line at the top — copy test_prime.cpp as the
# starting point for a new test file and just add it below.
add_executable(test_build
    # EDIT THIS LIST:
    tests/test_main.cpp
    tests/test_prime.cpp
    src/prime.cpp
)
target_link_libraries(test_build PRIVATE Qt6::Widgets)
target_include_directories(test_build PRIVATE src tests)

enable_testing()
add_test(NAME test_build COMMAND test_build)
