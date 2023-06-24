# Demo

## Hello World

`emcc main.c -o index.html`

## Hello World2

`emcc -o index2.html main2.c -O3 -s WASM=1 -s "EXPORTED_RUNTIME_METHODS=['ccall']" --shell-file template/shell_minimal.html`

## Run
`emrun --no_browser index.html --port 80`