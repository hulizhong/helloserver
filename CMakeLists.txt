cmake_minimum_required(VERSION 2.8)
project(HelloServer)

set(CMAKE_BUILD_TYPE "debug")
set(CMAKE_CXX_FLAGS "-O0 -std=c++11")
#add_compile_options(-std=c++11)


############################################################ Add submodule director.
add_subdirectory(util)

## generate libsocketserver.so libsocketclient.so
add_subdirectory(Socket)

## generate helloclient
add_subdirectory(client)

## generate hellopressureclient hellopressureserver
add_subdirectory(dpt)


############################################################ ADD main compile file.
## Method1. add compile files one by one.
SET(HELLO_SERVER_SRC Main.cpp)
LIST(APPEND HELLO_SERVER_SRC HelloServer.cpp)

## Method2. add compile files by regular express.


#message("helloserver", "------------ok")
add_executable(helloserver ${HELLO_SERVER_SRC})
target_link_libraries(helloserver socketserver log)

