#pragma once

#include <string>

class Student {
  friend class Tutor;
  friend class SchoolSystem;
  int studentID;
  std::string name;

  Student();

public:
  ~Student();

  const char *toString();
  friend void showInfoStudent(Student &stu);
  friend int main(int argc, char **argv);
};
