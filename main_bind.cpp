#include <stdio.h>
#include <emscripten/bind.h>

#include "util.c"

using namespace emscripten;

// int main(int argc, char **argv)
// {
//   printf("Hello World\n");
// }

void myFunction()
{
  printSomething();
}

int add(int a, int b)
{
  return a + b;
}

std::string getString()
{
  return "Hooooooooo Ya!!!!";
}

EMSCRIPTEN_BINDINGS(my_module) {
  function("myFunction", &myFunction);
  function("add", &add);
  function("getString", &getString, allow_raw_pointers());
}

