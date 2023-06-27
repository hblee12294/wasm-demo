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

  void EMSCRIPTEN_KEEPALIVE myFunction()
  {
    printSomething();
  }

  char *EMSCRIPTEN_KEEPALIVE getString()
  {
    return "Hooooooooo Ya!!!!";
  }

  int EMSCRIPTEN_KEEPALIVE add(int a, int b)
  {
    return a + b;
  }

#ifdef __cplusplus
}
#endif
