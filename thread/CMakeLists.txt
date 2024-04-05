add_executable(thread thread.cpp)

add_executable(jthread jthread.cpp)
target_compile_options(jthread PUBLIC --std=c++20)
