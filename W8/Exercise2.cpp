#include <string>
#include <list>
#include <stdio.h>

class staff {
  std::string name;
  enum { one, none } department;

  void joinDept() {};
  void leaveDept() {};

  friend int main(int argc, char **argv);
};

class department {
  struct {
    staff at_least_one_staff;
  } name;
  struct {
    staff at_least_one_staff;
  } location;
  std::list<staff> staff_list;

  friend int main(int argc, char **argv);
};

class AcademicDepartment : department {
  size_t number_of_courses;

  friend int main(int argc, char **argv);
};

class NoncademicDepartment : department {
  size_t number_of_services;

  friend int main(int argc, char **argv);
};

int main(int argc, char **argv) {
  AcademicDepartment all_attributes;
  NoncademicDepartment methods;
  setbuf(stdout, NULL);
  
  printf("all_attributes.name.at_least_one_staff.department = %hhu\n", all_attributes.name.at_least_one_staff.department);
  printf("all_attributes.name.at_least_one_staff.name = %s\n", all_attributes.name.at_least_one_staff.name.data());
  all_attributes.name.at_least_one_staff.joinDept();
  all_attributes.name.at_least_one_staff.leaveDept();
  printf("all_attributes.location = %p\n", all_attributes.location);
  printf("all_attributes.staff_list = %p\n", all_attributes.staff_list);
  printf("all_attributes.number_of_courses = %zu\n", all_attributes.number_of_courses);
  printf("methods.number_of_services = %zu\n", methods.number_of_services);

  return(0);
}
