#include <stdio.h>
#include <emscripten/bind.h>
#include <vector>

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

struct ArrayField
{
  int field[2];
};

ArrayField getArrayField()
{
  auto ais = new ArrayField();
  ais->field[0] = 1;
  ais->field[1] = 88;

  return *ais;
}

struct Person
{
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

void printPerson(Person person)
{
  printf("Person: %s, %d\n", person.name.c_str(), person.age);
}

struct Buffer {
  unsigned int pointer;
  unsigned int size;
};

Buffer getBufferUIint()
{  
  uint8_t vertices[] = {
    1, 2, 3, 100
  };
  int cnt = 4;
  printf("Pointer: %p\n", vertices);
  printf("Vertices: %i, %i, %i, %i\n", vertices[0], vertices[1], vertices[2], vertices[3]);

  Buffer buffer = { .pointer = (unsigned int) vertices, .size = (unsigned int) cnt };

  return buffer;
}

std::vector<int> getIntVector () {
  std::vector<int> v;

  for (int i = 0; i < 5; ++i) {
    v.push_back(i);
  }

  return v;
}

std::vector<float> getFloatVector () {
  std::vector<float> v;

  for (int i = 0; i < 5; ++i) {
    v.push_back(i * 1.11111f);
  }

  return v;
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

  value_array<Buffer>("Buffer")
    .element(&Buffer::pointer)
    .element(&Buffer::size)
    ;

  register_vector<int>("vector<int>");

  register_vector<float>("vector<float>");

  function("printString", &printString);
  function("add", &add);
  function("getString", &getString);
  function("getPointer", &getPointer, allow_raw_pointers());
  function("printPointer", &printPointer, allow_raw_pointers());
  function("printFromClass", &printFromClass, allow_raw_pointers());
  function("getArrayField", &getArrayField);
  function("getPerson", &getPerson);
  function("printPerson", &printPerson);
  function("getBufferUIint", &getBufferUIint);
  function("getIntVector", &getIntVector);
  function("getFloatVector", &getFloatVector);
}

