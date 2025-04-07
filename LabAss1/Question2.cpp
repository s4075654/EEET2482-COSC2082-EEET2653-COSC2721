#include <string>
#include <stdio.h>
#include <iostream>
#include <string.h>

class Student {
private:
  std::string name;
  long double scores[3];
  
  Student() {};

  void inputData() {
    puts("Input data (name and scores) for the student:");
    std::getline(std::cin, name);
    scanf("%Lf %Lf %Lf", scores, scores + 1, scores + 2);
  }
  void showInfo() {
    puts("Print out information of the student:");
    printf("%s\n%Lf %Lf %Lf\n", name.data(), *(scores), *(scores + 1), *(scores + 2));
  }
  
  friend void operator>>(void *cin, Student &object);
  friend void operator<<(void *cout, Student &object);
  bool operator>(Student object) {

    return((*scores + *(scores + 1) + *(scores + 2)) / 3 > (*object.scores + *(object.scores + 1) + *(object.scores + 2)) / 3);
  }
  friend Student operator+(int n, Student &object);
  friend void c();
  friend int main(int argc, char **argv);
};

void operator>>(void *cin, Student &object) {

  return(object.inputData());
}

void operator<<(void *cout, Student &object) {
    
  return(object.showInfo());
}

Student operator+(int n, Student &object) {
  for(unsigned char score = 0; score < 3; ++score) {
    *(object.scores + score) = *(object.scores + score) + n;
  }
  
  return(object);
}

void c() {
  Student student_objects[10];
  FILE *a_file = fopen("data.txt", "r");
  char all_information_from_a_file[29];
  unsigned char student_object = 0, the_student_with_highest_average_score = 0;
  long double highest_average_score = 0;

  while(fgets(all_information_from_a_file, 29, a_file) != NULL && student_object < 10) {
    
    char *information_from_a_file = strtok(all_information_from_a_file, ",");
    
    (*(student_objects + student_object)).name.assign(information_from_a_file);
    for(unsigned char value = 0; value < 3; ++value) {
      information_from_a_file = strtok(NULL, " ");
      sscanf(information_from_a_file, "%Lf", (*(student_objects + student_object)).scores + value);
    }
    if((*(*(student_objects + student_object)).scores + *(*(student_objects + student_object)).scores + 1 + *(*(student_objects + student_object)).scores + 2) / 3.0 > highest_average_score) {
      highest_average_score = (*(*(student_objects + student_object)).scores + *(*(student_objects + student_object)).scores + 1 + *(*(student_objects + student_object)).scores + 2) / 3.0;
      the_student_with_highest_average_score = student_object;
    }
    ++student_object;
  }
  puts("Print out info of the student with highest average score:");
  printf("%s\n%Lf %Lf %Lf\n", (*(student_objects + the_student_with_highest_average_score)).name.data(), *((*(student_objects + the_student_with_highest_average_score)).scores), *(((*(student_objects + the_student_with_highest_average_score)).scores) + 1), *(((*(student_objects + the_student_with_highest_average_score)).scores) + 2));
  
  fclose(a_file);
}

int main(int argc, char **argv) {
  Student an_object, object;
  void *cin = NULL, *cout = NULL;
  setbuf(stdout, NULL);

  an_object.inputData();
  while(getchar() != '\n');
  an_object.showInfo();
  cin >> object;
  while(getchar() != '\n');
  cout << object;
  printf("Return true if average score of object1 is larger than that of object2; return false otherwise: %hhu\n", an_object > object);
  puts("Return a result object that has the same name, but all scores are increased:");
  printf("%s\n%Lf %Lf %Lf\n", ((int)'n' + an_object).name.data(), *(((int)'n' + an_object).scores), *(((int)'n' + an_object).scores + 1), *(((int)'n' + an_object).scores + 2));
  c();

  return(0);
}
