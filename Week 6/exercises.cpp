#include "exercises.hpp"
#include <stdio.h>

Student::Student() { puts("themselves"); }
Student::~Student() { puts("themselves"); }

const char *Student::toString() {

  return ((std::to_string(studentID) + name).data());
}
