#include <stdio.h>
#include <iostream>
#include <string>

void a() {
  std::string a_string;
  FILE* a_file = fopen("pwd.dat", "w");

  puts("Input a password:");
  std::getline(std::cin, a_string);
  fputs(a_string.data(), a_file);

  fclose(a_file);
}

void b() {
  FILE* the_file = fopen("pwd.dat", "r");
  char stored_password;

  puts("Print:");
  while((stored_password = fgetc(the_file)) != EOF) {
    putchar(stored_password);
  }

  fclose(the_file);
}

int main(int argc, char **argv) {
  setbuf(stdout, NULL);

  puts("a menu");
  a();
  b();
  putchar('\n');

  return(0);
}
