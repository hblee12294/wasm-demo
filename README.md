# WASM Demo

## Prerequisites

1. Install emscripten: https://emscripten.org/docs/getting_started/downloads.html
2. Install cmake: `brew install cmake`

## Build

<!-- `emcc -o index.html main.c -O3 -s WASM=1 -s "EXPORTED_RUNTIME_METHODS=['ccall']" --shell-file template/shell_minimal.html` -->

`emcmake cmake -B build`
`cmake --build ./build`

## Run Local Server

`deno run --allow-net --allow-read https://deno.land/std/http/file_server.ts`

<!-- `emrun --no_browser index.html --port 80` -->

## Try Demo

1. http://localhost:4507/build/index.html
2. http://localhost:4507/build/index2.html
