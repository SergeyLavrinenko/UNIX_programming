project (hello)

add_executable(hello main.cpp)
target_link_libraries(hello ${DBUS_LIBRARIES})

