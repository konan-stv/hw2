cmake_minimum_required(VERSION 3.2)

find_package(GTest REQUIRED)
find_package(Boost REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

project(ip_filter VERSION 0.0.1)

add_executable(ip_filter main.cpp)
add_executable(runTests test.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

set_target_properties(ip_filter PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

set_target_properties(runTests PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

install(TARGETS ip_filter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_CONTACT konan@konanlabs.ru)

include(CPack)
