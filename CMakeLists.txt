cmake_minimum_required(VERSION 2.6)
project(OBD-CPP)

set(CMAKE_CXX_STANDARD 11)

#set(SOURCE_FILES src/codes.cpp src/codes.h src/commands.cpp src/commands.h src/decoders.cpp src/decoders.h src/utils.cpp src/utils.h src/OBDCommand.cpp src/OBDCommand.h src/OBDResponse.cpp src/OBDResponse.h src/UnitsAndScaling.cpp src/UnitsAndScaling.h src/async.cpp src/async.h)
set(SOURCE_FILES main.cpp src/obd.cpp src/obd.h src/elm327.cpp src/elm327.h src/OBDStatus.h)
add_executable(OBD-CPP ${SOURCE_FILES})

# Include Boost System
find_package(Boost COMPONENTS system filesystem REQUIRED)
target_link_libraries(OBD-CPP ${Boost_SYSTEM_LIBRARY})
target_link_libraries(OBD-CPP ${Boost_FILESYSTEM_LIBRARY})