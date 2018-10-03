cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_FLAGS "-std=c++14 -DUNIT_TEST")

# project name
project(GTestForSkatV2)

# debug build
set(CMAKE_BUILD_TYPE Debug)

# include header directories
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(testClasses)
include_directories(include)
include_directories(../SkatV2)

#source files
set(SOURCES src/main.cpp
            testMethods/cardTests.cpp
            testClasses/ExplTest.cpp
            testClasses/skatdecktest.cpp
            testClasses/tricktest.cpp
            testClasses/skatgameresulttest.cpp
            testClasses/skatgamesetuptest.cpp
            testClasses/stubgametest.cpp
            ../SkatV2/Engine/src/resultcollector.cpp
            ../SkatV2/Engine/src/gameinitiator.cpp
            ../SkatV2/Engine/src/skatdeck.cpp
            ../SkatV2/Engine/src/trick.cpp
            ../SkatV2/Engine/src/skatgameresult.cpp
            ../SkatV2/Engine/src/skatgamesetup.cpp
            ../SkatV2/Engine/src/random_numbers.cpp
            src/stubplayer.cpp)

# set executable name and sources
add_executable(runTests ${SOURCES})

# link executable with the GTest and pthread library
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
