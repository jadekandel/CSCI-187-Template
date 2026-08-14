cmake_minimum_required(VERSION 3.16)

project(MyProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

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
target_link_libraries(app PRIVATE Qt5::Widgets)

# The test binary. Include model classes and test .cpp files (no h files)
# In this class, we only test the model classes, not view and controller files. 
add_executable(test_build
    # EDIT THIS LIST:
    tests/test_prime.cpp
    src/prime.cpp
)
target_link_libraries(test_build PRIVATE Qt5::Widgets)
target_include_directories(test_build PRIVATE src tests)

enable_testing()
add_test(NAME test_build COMMAND test_build)
