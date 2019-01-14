cmake_minimum_required(VERSION 3.2)

set(Boost_DEBUG 1)

find_package(Boost COMPONENTS range REQUIRED)

project(ip_filter VERSION 0.0.1)

add_executable(ip_filter main.cpp)

set_target_properties(ip_filter PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

install(TARGETS ip_filter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_CONTACT konan@konanlabs.ru)

include(CPack)
