#include "exercises.hpp"
#include <stdio.h>

Student::Student() {
  name = "public";
  score = (ptrdiff_t) "public";
}

ptrdiff_t Student::get_score() { return (score); }

void b() {
  Student student_object_one, student_object_two;

  puts("All information of the two students: ");
  printf("%s, %td, %s, %td", student_object_one.name.data(),
         student_object_one.get_score(), student_object_two.name.data(),
         student_object_two.get_score());
}

void c() {
  Student an_array_of_three_students[3];
  unsigned char the_student_with_the_highest_score = 0;

  for (unsigned char student = 0; student < 3; ++student) {
    *(an_array_of_three_students + student) = Student();
    if ((*(an_array_of_three_students + student)).get_score() >
        (*(an_array_of_three_students + the_student_with_the_highest_score))
            .get_score()) {
      the_student_with_the_highest_score = student;
    }
  }
  puts("Information of the student with highest score:");
  printf("%s %td",
         (*(an_array_of_three_students + the_student_with_the_highest_score))
             .name.data(),
         (*(an_array_of_three_students + the_student_with_the_highest_score))
             .get_score());
}
