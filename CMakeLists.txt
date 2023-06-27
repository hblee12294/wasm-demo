cmake_minimum_required(VERSION 3.8)

project(test)

set(CMAKE_EXECUTABLE_SUFFIX ".html")

add_executable(index main.c)

set_target_properties(index PROPERTIES LINK_FLAGS "-s WASM=1 -s EXPORTED_RUNTIME_METHODS=['ccall'] --shell-file ${CMAKE_CURRENT_SOURCE_DIR}/template/shell_minimal.html --no-entry")

# set_target_properties(main PROPERTIES COMPILE_FLAGS "-Os -s SIDE_MODULE=1 ")
# set_target_properties(main PROPERTIES LINK_FLAGS    "-Os -s WASM=1 -s SIDE_MODULE=1 -s STANDALONE_WASM --no-entry")
# set_target_properties(main PROPERTIES LINK_FLAGS "-Os -s WASM=1 -s SIDE_MODULE=1 -s --no-entry")
