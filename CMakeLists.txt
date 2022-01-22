cmake_minimum_required(VERSION 3.22)
project(WOT_strategy)

set(CMAKE_CXX_STANDARD 11)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(WOT_strategy main.cpp ServerAPI/WotStrategyServer.cpp ServerAPI/WotStrategyServer.h ServerAPI/TcpConnection.cpp ServerAPI/TcpConnection.h)
target_link_libraries(WOT_strategy ${CONAN_LIBS})
