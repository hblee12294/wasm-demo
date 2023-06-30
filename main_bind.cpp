#include <stdio.h>
#include <emscripten/bind.h>

#include "util.c"

using namespace emscripten;

// int main(int argc, char **argv)
// {
//   printf("Hello World\n");
// }

void printString()
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

class C {
public:
  void print()
  {
    printf("From class C!!!\n");
  };
};

auto c = new C();

C *getPointer()
{
  return c;
}

void printPointer(C *ptr)
{
  printf("Pointer: %p\n", ptr);
}

void printFromClass(C *ptr)
{
  ptr->print();
}

EMSCRIPTEN_BINDINGS(my_module) {
  class_<C>("C");

  function("printString", &printString);
  function("add", &add);
  function("getString", &getString);
  function("getPointer", &getPointer, allow_raw_pointers());
  function("printPointer", &printPointer, allow_raw_pointers());
  function("printFromClass", &printFromClass, allow_raw_pointers());
}

