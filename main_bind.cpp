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

struct ArrayField {
  int field[2];
};

ArrayField getArrayField()
{
  auto ais = new ArrayField();
  ais->field[0] = 1;
  ais->field[1] = 88;

  return *ais;
}

struct Person {
  std::string name;
  int age;
  ArrayField secrets;
};

Person getPerson()
{
  auto person = new Person();
  person->name = "Biden";
  person->age = 78;

  auto secrets = new ArrayField();
  secrets->field[0] = 6;
  secrets->field[1] = 9;
  person->secrets = *secrets;

  return *person;
}


EMSCRIPTEN_BINDINGS(my_module) {
  class_<C>("C");

  value_object<ArrayField>("ArrayField")
    .field("field", &ArrayField::field) // Need to register the array type below
    ;

  value_object<Person>("Person")
    .field("name", &Person::name)
    .field("age", &Person::age)
    .field("secrets", &Person::secrets)
    ;

  // Register std::array<int, 2> because ArrayField::field is interpreted as such
  value_array<std::array<int, 2>>("array_int_2")
    .element(emscripten::index<0>())
    .element(emscripten::index<1>())
    ;

  function("printString", &printString);
  function("add", &add);
  function("getString", &getString);
  function("getPointer", &getPointer, allow_raw_pointers());
  function("printPointer", &printPointer, allow_raw_pointers());
  function("printFromClass", &printFromClass, allow_raw_pointers());
  function("getArrayField", &getArrayField);
  function("getPerson", &getPerson);
}

