#include <string>
#include <stdio.h>

class Employee {
  friend class Manager;
  double salary;
  std::string name;
  
  Employee() {};

  virtual void showInfo() {
    puts("Print out all information:");
    printf("%s\n", name.data());
    printf("%f\n", salary);
  }

  friend int main(int argc, char **argv);
  friend long double b();
};

class Manager : Employee {
  double allowance;

  Manager() {};

  void showInfo() override {
    puts("Print out all information:");
    printf("%s\n", name.data());
    printf("%f %f\n", salary, allowance);
  }

  friend int main(int argc, char **argv);
  friend long double b();
};

long double b() {
  Manager *an_array_of_05_manager_objects[5];
  long double their_total_income = 0.0;
  
  for(unsigned char manager_object = 0; manager_object < 5; ++manager_object) {
    *(an_array_of_05_manager_objects + manager_object) = new Manager();
    their_total_income += (*(*(an_array_of_05_manager_objects + manager_object))).salary + (*(*(an_array_of_05_manager_objects + manager_object))).allowance;
  }

  return(their_total_income);
}

int main(int argc, char **argv) {
  Employee an_object_for_class_employee;
  Manager an_object_for_class_manager;
  setbuf(stdout, NULL);
  
  an_object_for_class_employee.showInfo();
  an_object_for_class_manager.showInfo();
  printf("The average of their total income: %Lf\n", b() / 5);

  return(0);
}
