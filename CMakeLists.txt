cmake_minimum_required(VERSION 2.8)
project(HelloServer)

set(CMAKE_BUILD_TYPE "debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb3")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
set(CMAKE_INSTALL_PREFIX "/opt/helloserver")
#set(CMAKE_CXX_FLAGS "-O0 -std=c++11")
#add_compile_options(-std=c++11)

############################################################ make deb package.
include(InstallRequiredSystemLibraries)
set(_VERSION_MAJOR 0)  
set(_VERSION_MINOR 1)  
set(_VERSION_PATCH 1)

## the package type
set(CPACK_GENERATOR "DEB")

## the package version
set(CPACK_PACKAGE_VERSION_MAJOR "${_VERSION_MAJOR}")  
set(CPACK_PACKAGE_VERSION_MINOR "${_VERSION_MINOR}")  
set(CPACK_PACKAGE_VERSION_PATCH "${_VERSION_PATCH}")
set(CPACK_PACKAGE_VERSION ${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH})

## the package name.
set(CPACK_PACKAGE_NAME "helloserver")
## after install, will show name in system.
set(CPACK_DEBIAN_PACKAGE_NAME "helloserver")

## set the default install prefix.
set(CPACK_PACKAGING_INSTALL_PREFIX "/opt/helloserver")
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "amd64")
#set(CPACK_PACKAGE_DESCRIPTION "the high performace tcp socket server.")
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "the high performace tcp socket server.")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "members of helloserver@yeah.net") 
#set(CPACK_PACKAGE_CONTACT "hulizhong@yeah.net") 

## for what.
set(CPACK_DEBIAN_PACKAGE_SECTION "net")
set(CPACK_DEBIAN_PACKAGE_PRIORITY "Optional")

option(CPACK_UBUNTU "to build the ubuntu's deb package." ON)
##option(CPACK_UBUNTU "to build the ubuntu's deb package." OFF)
#option(CPACK_DEBIAN "to build the debian's deb package." ON)

if (CPACK_UBUNTU)
    set(CPACK_DEBIAN_PACKAGE_DEPENDS "liblog4cxx10v5")
    set(CPACK_PACKAGE_FILE_NAME ${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-ubuntu-${CPACK_DEBIAN_PACKAGE_ARCHITECTURE})
endif (CPACK_UBUNTU)

if (CPACK_DEBIAN)
    set(CPACK_DEBIAN_PACKAGE_DEPENDS "liblog4cxx10")
    set(CPACK_PACKAGE_FILE_NAME ${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-debian-${CPACK_DEBIAN_PACKAGE_ARCHITECTURE})
endif (CPACK_DEBIAN)

## why at last.
include(CPack)

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


############################################################ ADD binary into deb.
#PROJECT_BINARY_DIR 运行cmake命令的目录,通常是${PROJECT_SOURCE_DIR}/build
#CMAKE_CURRENT_BINARY_DIR target编译目录
install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/helloserver DESTINATION run) 
#install(FILES ${CMAKE_CURRENT_BINARY_DIR}/helloserver DESTINATION run) 

