cmake_minimum_required(VERSION 2.6)

#compiler options
set(CMAKE_CXX_FLAGS "-std=c++14")
set(CMAKE_BUILD_TYPE Debug)

# project name
project(UnitTestG)

# include header directories
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(testClasses)
include_directories(../SkatV2)

#source files
set(SOURCES src/main.cpp
            testClasses/ExplTest.cpp
            testClasses/deckest.cpp
            ../SkatV2/Engine/src/skatdeck.cpp)

# set executable name and sources
add_executable(runTests ${SOURCES})

# link executable with the GTest and pthread library
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
