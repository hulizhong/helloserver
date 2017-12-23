
#############################
#
#    the helloserver's distributed pressure test client.
#
#############################

#cmake_minimum_required(VERSION 2.8)
#project(HelloPressure)
#set(CMAKE_BUILD_TYPE "debug")
#set(CMAKE_CXX_FLAGS "-O0")

set(HELLO_PRESSURE_SERVER_SRC MainServer.cpp PressureServer.cpp)
set(HELLO_PRESSURE_CLIENT_SRC MainClient.cpp PressureClient.cpp)

add_executable(hellopressureserver ${HELLO_PRESSURE_SERVER_SRC})
target_link_libraries(hellopressureserver socketserver log)

add_executable(hellopressureclient ${HELLO_PRESSURE_CLIENT_SRC})
target_link_libraries(hellopressureclient socketclient log)

## generate the debian package.
install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/hellopressureserver DESTINATION run) 
install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/hellopressureclient DESTINATION run) 
