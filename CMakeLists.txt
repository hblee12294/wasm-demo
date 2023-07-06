cmake_minimum_required(VERSION 3.8)

project(test)

## ccall cwrap

set(CMAKE_EXECUTABLE_SUFFIX ".html")

add_executable(index main.c)

set_target_properties(index PROPERTIES LINK_FLAGS "-s WASM=1 -s EXPORTED_RUNTIME_METHODS=['ccall'] --shell-file ${CMAKE_CURRENT_SOURCE_DIR}/templates/ccall.html --no-entry")

# Embind

add_executable(index2 main_bind.cpp)

set_target_properties(index2 PROPERTIES LINK_FLAGS "--bind -s WASM=1 -s PRECISE_F32=1 --shell-file ${CMAKE_CURRENT_SOURCE_DIR}/templates/embind.html --no-entry")
