#include "student.h"
#include <stdio.h>
#include <string>

Student::Student() {

  puts("themselves");
}
Student::~Student() {

  puts("themselves");
}

const char *Student::toString() {

  return((std::to_string(studentID) + name).data());
}

class Staff {
  friend class Tutor;
  int staffID;
  std::string name;

  Staff() {
    puts("themselves");
  }
  ~Staff() {
    puts("themselves");
  }

  const char *toString() {

    return((std::to_string(staffID) + name).data());
  }
  friend void showInfoStaff(Staff &staff);
  friend int main(int argc, char **argv);
};

class Tutor : Student, Staff {
  Tutor() {
    puts("themselves");
  }
  ~Tutor() {
    puts("themselves");
  }

  void consultation() {

    puts("a message, e.g. ");
  }
  friend Tutor a();
  void setName(const char *a_string) {

    Staff::name.assign(a_string);
  }
  const char *toString() {

    return((std::to_string(studentID) + Student::name + std::to_string(staffID) + Staff::name).data());
  }
  friend void showInfoStudent(Student &stu);
  friend void showInfoStaff(Staff &staff);
  friend int main(int argc, char **argv);
};

Tutor a() {
  Tutor a_tutor_object;

  return(a_tutor_object);
}

void showInfoStudent(Student &stu) {

  puts("All information of a Student or Tutor:");
  printf("%s\n", stu.toString());
}

void showInfoStaff(Staff &staff) {

  puts("All information of a Staff or Tutor:");
  printf("%s\n", staff.toString());
}

int main(int argc, char **argv) {
  Tutor a_tutor_object = a();

  a_tutor_object.setName("a string");

  Student a_student;
  setbuf(stdout, NULL);

  showInfoStudent(a_student);
  showInfoStudent(a_tutor_object);

  Staff a_staff;

  showInfoStaff(a_staff);
  showInfoStaff(a_tutor_object);

  return(0);
}
