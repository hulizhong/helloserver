
set(LOG_SRC Log.cpp)

## no need to test the async logger.
# USE_SYNC_LOG
# USE_ASYNC_LOG
# TEST_ASYNC_LOG
add_definitions(-DUSE_SYNC_LOG)

add_library(log SHARED ${LOG_SRC})
target_link_libraries(log log4cxx)

## generate the debian package.
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/liblog.so DESTINATION run) 

