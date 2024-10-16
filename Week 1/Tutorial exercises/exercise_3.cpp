#include <stdio.h>
#include <string>
#include <iostream>

size_t replace_the_lowercase_characters_by_uppercase_and_vice_versa(std::string& a_string) {
  size_t the_sum_of_digits_in_the_string = 0;

  for(unsigned long long int character = 0; character < a_string.length(); ++character) {
    if(*(a_string.data() + character) >= 'a' && *(a_string.data() + character) <= 'z') {
      *(a_string.data() + character) -= 32;
    }
    else {
      if(*(a_string.data() + character) >= 'A' && *(a_string.data() + character) <= 'Z') {
	*(a_string.data() + character) += 32;
      }
    }
    if(*(a_string.data() + character) >= '0' && *(a_string.data() + character) <= '9') {
      the_sum_of_digits_in_the_string += *(a_string.data() + character) - 48;
    }
    putchar(*(a_string.data() + character));
  }

  return(the_sum_of_digits_in_the_string);
}

int main(int argc, char **argv) {
  std::string a_string;
  setbuf(stdout, NULL);

  puts("Input a string: ");
  std::getline(std::cin, a_string);
  size_t the_sum_of_digits_in_the_string = replace_the_lowercase_characters_by_uppercase_and_vice_versa(a_string);
  putchar('\n');
  printf("The sum of digits in the string: %zu\n", the_sum_of_digits_in_the_string);

  return(0);
}
