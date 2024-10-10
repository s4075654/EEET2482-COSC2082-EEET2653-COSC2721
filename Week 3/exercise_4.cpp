#include <stdio.h>
#include <string>

class Cat {
public:
  std::string name;
  int age;

  Cat(){};
};

class Person {
public:
  Cat cat;
  char name[];

  Person(){};
};

unsigned char b(Person *three_persons) {
  unsigned char the_person_who_has_the_cat_with_the_highest_age = 0;

  for (unsigned char person = 0; person < 3; ++person) {
    if ((*(three_persons + person)).cat.age >
        (*(three_persons + the_person_who_has_the_cat_with_the_highest_age))
            .cat.age) {
      the_person_who_has_the_cat_with_the_highest_age = person;
    }
  }

  return (the_person_who_has_the_cat_with_the_highest_age);
}

void a() {
  Person an_array_of_three_persons[3];
  setbuf(stdout, NULL);

  puts("The information of the person who has the cat with the highest age:");

  unsigned char the_person_who_has_the_cat_with_the_highest_age =
      b(an_array_of_three_persons);

  printf("%s %d %s\n",
         (*(an_array_of_three_persons +
            the_person_who_has_the_cat_with_the_highest_age))
             .cat.name.data(),
         (*(an_array_of_three_persons +
            the_person_who_has_the_cat_with_the_highest_age))
             .cat.age,
         (*(an_array_of_three_persons +
            the_person_who_has_the_cat_with_the_highest_age))
             .name);
}

int main(int argc, char **argv) {

  a();

  return (0);
}
