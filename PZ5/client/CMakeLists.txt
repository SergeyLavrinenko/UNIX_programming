project (socket_client)

add_executable(socket_client main.cpp)
target_link_libraries(socket_client ${DBUS_LIBRARIES})

