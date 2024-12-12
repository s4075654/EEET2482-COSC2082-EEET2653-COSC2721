#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>

void a(char *str) {

  while(*str != '\0') {
    putchar(*str);
    putchar(' ');
    ++str;
  }
}

void b() {

  std::cout << std::setw(9) << std::setfill('0') << 1.234;
}

void c() {

  std::cout << std::fixed << std::setprecision(2) << 1.234;
}

void d() {
  size_t a_hexadecimal_value;

  printf("A hexadecimal value: ");
  scanf("%zx", &a_hexadecimal_value);
  printf("Its decimal value: %zu\n", a_hexadecimal_value);
  printf("Hexa form: %#zx", a_hexadecimal_value);
}

int main(int argc, char **argv) {
  std::string a_string;
  setbuf(stdout, NULL);

  puts("The console input:");
  std::getline(std::cin, a_string);
  a(a_string.data());
  putchar('\n');
  b();
  putchar('\n');
  c();
  putchar('\n');
  d();
  putchar('\n');

  return(0);
}
