cmake_minimum_required(VERSION 3.7)
project(OBD-CPP)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(OBD-CPP ${SOURCE_FILES})

# Include Boost System
find_package(Boost COMPONENTS system filesystem REQUIRED)
target_link_libraries(OBD-CPP ${Boost_SYSTEM_LIBRARY})
target_link_libraries(OBD-CPP ${Boost_FILESYSTEM_LIBRARY})