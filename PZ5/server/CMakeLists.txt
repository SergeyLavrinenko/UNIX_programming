project (socket_server)

add_executable(socket_server main.cpp)
target_link_libraries(socket_server ${DBUS_LIBRARIES})

