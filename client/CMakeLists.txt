
#project(HelloClient)

set(HELLO_CLIENT_SRC Main.cpp)
list(APPEND HELLO_CLIENT_SRC HelloClient.cpp)

add_executable(helloclient ${HELLO_CLIENT_SRC})
target_link_libraries(helloclient pthread socketclient log)

