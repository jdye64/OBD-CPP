cmake_minimum_required(VERSION 2.6)
project(OBD-CPP)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11 " COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x " COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Search for threads
find_package(Threads REQUIRED)

#set(SOURCE_FILES src/codes.cpp src/codes.h src/commands.cpp src/commands.h src/decoders.cpp src/decoders.h src/utils.cpp src/utils.h src/OBDCommand.cpp src/OBDCommand.h src/OBDResponse.cpp src/OBDResponse.h src/UnitsAndScaling.cpp src/UnitsAndScaling.h src/async.cpp src/async.h)
set(SOURCE_FILES main.cpp src/obd.cpp src/obd.h src/elm327.cpp src/elm327.h src/OBDStatus.h src/protocols/protocol.cpp src/protocols/protocol.h src/protocols/protocol_can.cpp src/protocols/protocol_can.h src/protocols/protocol_legacy.cpp src/protocols/protocol_legacy.h src/protocols/protocol_unknown.cpp src/protocols/protocol_unknown.h src/commands.h src/commands.cpp src/OBDCommand.h src/OBDCommand.cpp)
add_executable(OBD-CPP ${SOURCE_FILES})

# Include Boost System
find_package(Boost COMPONENTS system filesystem REQUIRED)
target_link_libraries(OBD-CPP ${Boost_SYSTEM_LIBRARY})
target_link_libraries(OBD-CPP ${Boost_FILESYSTEM_LIBRARY})
target_link_libraries(OBD-CPP ${Threads_LIBRARY})
target_link_libraries (OBD-CPP ${CMAKE_THREAD_LIBS_INIT})