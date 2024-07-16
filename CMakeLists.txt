cmake_minimum_required(VERSION 3.10)

# Set project name
project(NMEAParser)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
add_executable(NMEAParser src/main.cpp src/nmea_parser.cpp)

# Add test executable
add_executable(NMEAParserTest test/test_nmea_parser.cpp src/nmea_parser.cpp)

# Include Catch2 testing framework
include(CTest)
include(FetchContent)
FetchContent_Declare(
    catch
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v2.13.7
)
FetchContent_MakeAvailable(catch)
target_link_libraries(NMEAParserTest Catch2::Catch2)

# Enable testing
enable_testing()
add_test(NAME NMEAParserTest COMMAND NMEAParserTest)
