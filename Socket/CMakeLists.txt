
set(SOCKET_SERVER_SRC SocketServer.cpp)
set(SOCKET_CLIENT_SRC SocketClient.cpp)


add_library(socketserver SHARED ${SOCKET_SERVER_SRC})
add_library(socketclient SHARED ${SOCKET_CLIENT_SRC})
target_link_libraries(socketserver log)
target_link_libraries(socketclient log)

