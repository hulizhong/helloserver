cmake_minimum_required(VERSION 2.8)
project(HelloServer)

set(CMAKE_BUILD_TYPE "debug")
set(CMAKE_CXX_FLAGS "-O0")

############################################################ ADD compile file.
## Method1. add compile files one by one.
SET(HELLO_SERVER_SRC Main.cpp)
LIST(APPEND HELLO_SERVER_SRC SocketServer.cpp)

## Method2. add compile files by regular express.


############################################################ Add client director.
add_subdirectory(client)


#message("helloserver", "------------ok")
add_executable(helloserver ${HELLO_SERVER_SRC})

