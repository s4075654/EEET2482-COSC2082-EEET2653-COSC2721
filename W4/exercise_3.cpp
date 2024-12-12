#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

char* a(std::string *str1) {
  
  (*str1).reserve(strlen((*str1).data()));
  
  unsigned long long int left_side = 0, right_side = strlen((*str1).data()) - 1;

  while(left_side < right_side) {
    *((*str1).data() + left_side) ^= *((*str1).data() + right_side);
    *((*str1).data() + right_side) ^= *((*str1).data() + left_side);
    *((*str1).data() + left_side) ^= *((*str1).data() + right_side);
    ++left_side;
    --right_side;
  }
  puts("it out.");
  printf("%s", (*str1).data());

  return((*str1).data());
}

std::string b(char *all_characters_of_str2) {
  char *character = all_characters_of_str2;

  while(*character != '\0') {
    if(*character >= 'a' && *character <= 'z') {
      *character -= 32;
    }
    else {
      if(*character >= 'A' && *character <= 'Z') {
	*character += 32;
      }
    }
    ++character;
  }
  puts("it out.");
  printf("%s", all_characters_of_str2);

  return(all_characters_of_str2);
}

void ask_the_user_to_input_two_strings_str1() {
  std::string str1, str2;
  setbuf(stdout, NULL);

  puts("Input two strings str1, str2 which may contain whitespace characters from the console. //");
  std::getline(std::cin, str1);
  std::getline(std::cin, str2);
  char *character_array = a(&str1);
  putchar('\n');
  std::string C = b(str2.data());
  putchar('\n');
  printf("Convert to the other: \"%s\" \"%s\"\n", character_array, C.data());
}

int main(int argc, char **argv) {

  ask_the_user_to_input_two_strings_str1();

  return(0);
}
