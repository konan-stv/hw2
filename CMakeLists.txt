cmake_minimum_required(VERSION 3.6)

## Use the variable PROJECT_NAME for changing the target name
set( PROJECT_NAME "ip_filter" )

## Set our project name
project(${PROJECT_NAME} CXX)

set (GTEST_ROOT /usr/src/gtest)
set (GTEST_LIBRARY /usr/src/gtest/libgtest.a)
set (GTEST_MAIN_LIBRARY /usr/src/gtest/libgtest_main.a)

find_package(Boost REQUIRED)
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

if(DEFINED ENV{TRAVIS_BUILD_NUMBER})
  project(${PROJECT_NAME} VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
  project(${PROJECT_NAME} VERSION 0.0.255)
#  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -L/usr/lib/x86_64-linux-gnu")
endif()

##configure_file(version.h.in version.h)

## Use all the *.cpp files we found under this folder for the project
FILE(GLOB SRCS "*.cpp")

## Define the executable
##add_library(lib${PROJECT_NAME} ip_filter.cpp)

add_executable(runTest test.cpp)
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(
  runTest ${GTEST_LIBRARIES} Threads::Threads)

set_target_properties(${PROJECT_NAME} runTest PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra;--std=c++1z"
)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_CONTACT konan@konanlabs.ru)

include(CPack)

enable_testing()

add_test(runTest runTest)
