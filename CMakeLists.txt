project(serialtest2)

add_executable(serialtest2 main.cpp)

target_link_libraries(serialtest2  -lserial)

install(TARGETS serialtest2 RUNTIME DESTINATION bin)
