#include "exercises.hpp"
#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

void Student::changePwd() {
  FILE *existing_password = fopen((name.append(".dat")).data(), "r");

  if (existing_password != NULL) {
    fseek(existing_password, 0, SEEK_END);
    if (ftell(existing_password) != 0) {
      char content[ftell(existing_password) + 1];
      std::string previous_password;

      fseek(existing_password, 0, SEEK_SET);
      fread(content, 1, sizeof(content), existing_password);
      *(content + sizeof(content) - 1) = '\0';
      puts("Previous password to check:");
      std::getline(std::cin, previous_password);
      assert(strcmp(previous_password.data(), content) == 0);
    }
  }
  std::string value_for_the_password;
  fclose(existing_password);
  existing_password = fopen((name + ".dat").data(), "w");

  puts("Provide value for the password:");
  std::getline(std::cin, value_for_the_password);
  fputs(value_for_the_password.data(), existing_password);

  fclose(existing_password);
}

int main(int argc, char **argv) {
  setbuf(stdout, NULL);

  b();
  putchar('\n');
  c();
  putchar('\n');
  Student people;
  people.changePwd();

  return (0);
}
