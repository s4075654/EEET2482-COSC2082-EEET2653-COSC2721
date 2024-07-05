#include "exercises.hpp"
#include <vector>
#include <stdio.h>
#include <iostream>

class SchoolSystem {
  friend int main(int argc, char **argv);
  std::vector<Student> students;

  void addStudent() {
    Student student_object;

    puts("Input name and student ID for a student:");
    std::getline(std::cin, student_object.name);
    scanf("%d", &student_object.studentID);
    students.emplace(students.begin() + student_object.studentID, student_object);
  }
  void removeStudent() {
    int student_ID;

    printf("Input student ID: ");
    scanf("%d", &student_ID);
    students.erase(students.begin() + student_ID);
  }
};

int main(int argc, char **argv) {
  SchoolSystem all_information_of_students;
  FILE *a_file_namely_students = fopen("students.dat", "w+");
  
  fread(all_information_of_students.students.data(), sizeof(Student), sizeof(all_information_of_students.students) / sizeof(Student), a_file_namely_students);
  
  setbuf(stdout, NULL);

  all_information_of_students.addStudent();
  all_information_of_students.removeStudent();
  puts("School Management System");
  puts("1. View all students");
  puts("2. Add Student");
  puts("3. Remove Student");
  puts("4. Exit");
  printf("Enter Your Choice:………\n");
  fwrite(all_information_of_students.students.data(), sizeof(Student), sizeof(all_information_of_students.students) / sizeof(Student), a_file_namely_students);

  fclose(a_file_namely_students);
  return(main(argc, argv));
}
