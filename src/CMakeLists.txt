include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

add_library(pid_lib pid.cpp ${CMAKE_SOURCE_DIR}/include/pid.hpp)
target_include_directories(pid_lib PUBLIC ../include)