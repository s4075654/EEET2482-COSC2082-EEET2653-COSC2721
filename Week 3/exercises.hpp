#include <string>

#ifndef EXERCISES_HPP
#define EXERCISES_HPP

class Student {
 private:
  ssize_t score;
  std::string password;
 public:
  std::string name;
  Student();
  ssize_t get_score();
  void changePwd();
  FILE *existing_password;
};

void b();
void c();

#endif
