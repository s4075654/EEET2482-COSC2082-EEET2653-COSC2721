#include <stdio.h>
#include <assert.h>

unsigned char check_if_it_is_valid_hexadecimal_number_or_not(char *it) {
  char *hexadecimal_digit = it + 3;

  if(*it != '0') {

    return(0);
  }
  if(*(it + 1) != 'x' && *(it + 1) != 'X') {

    return(0);
  }
  if(*(it + 2) < '0' || *(it + 2) > '9' && *(it + 2) < 'A' || *(it + 2) > 'F' && *(it + 2) < 'a' || *(it + 2) > 'f') {

    return(0);
  }
  while(*hexadecimal_digit != '\0') {
    if(*hexadecimal_digit < '0' || *hexadecimal_digit > '9' && *hexadecimal_digit < 'A' || *hexadecimal_digit > 'F' && *hexadecimal_digit < 'a' || *hexadecimal_digit > 'f') {

      return(0);
    }
    ++hexadecimal_digit;
  }

  return(1);
}

void displays_the_hexadecimal_number_to_the_console(char *user_input_argument, unsigned char valid) {
  size_t the_hexadecimal_number;

  puts("It is valid hexadecimal number.");
  if(!valid) {
    puts("Not.");
  }
  sscanf(user_input_argument, "%zx", &the_hexadecimal_number);
  printf("The hexadecimal number: %#zx\n", the_hexadecimal_number);
}

int main(int argc, char **argv) {
  setbuf(stdout, NULL);
  
  assert(argc == 2);
  displays_the_hexadecimal_number_to_the_console(*(argv + 1), check_if_it_is_valid_hexadecimal_number_or_not(*(argv + 1)));

  return(0);
}
