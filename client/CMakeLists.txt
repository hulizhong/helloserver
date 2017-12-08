#cmake_minimum_required(VERSION 2.8)

project(HelloClient)

set(HELLO_CLIENT_SRC Main.cpp)
list(APPEND HELLO_CLIENT_SRC SocketClient.cpp)

add_executable(helloclient ${HELLO_CLIENT_SRC})
target_link_libraries(helloclient "-lpthread")

