# Demo

## Hello World

<!-- `emcc -o index.html main.c -O3 -s WASM=1 -s "EXPORTED_RUNTIME_METHODS=['ccall']" --shell-file template/shell_minimal.html` -->

`emcmake cmake -B build`
`cmake --build ./build`

## Run

`deno run --allow-net --allow-read https://deno.land/std/http/file_server.ts`

<!-- `emrun --no_browser index.html --port 80` -->
