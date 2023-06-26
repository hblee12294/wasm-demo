#include <stdio.h>
#include <emscripten/emscripten.h>
#include "util.c"

// int main(int argc, char **argv)
// {
//   printf("Hello World\n");
// }

#ifdef __cplusplus
extern "C"
{
#endif

  void EMSCRIPTEN_KEEPALIVE myFunction(int argc, char **argv)
  {
    printSomething();
  }

  char *EMSCRIPTEN_KEEPALIVE getString()
  {
    return "Hooooooooo Ya!!!!";
  }

#ifdef __cplusplus
}
#endif
