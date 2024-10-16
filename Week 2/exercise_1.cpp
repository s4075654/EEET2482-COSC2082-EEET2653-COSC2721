#include <stdio.h>

unsigned char return_the_minimum_value_of_its_elements(char *an_array_of_integers, unsigned long long int its_size) {
  unsigned char the_minimum_value_of_its_elements = *an_array_of_integers;

  for(unsigned long long int integer = 0; integer < its_size; ++integer) {
    if(*(an_array_of_integers + integer) < the_minimum_value_of_its_elements) {
      the_minimum_value_of_its_elements = *(an_array_of_integers + integer);
    }
  }

  return(the_minimum_value_of_its_elements);
}

int main(int argc, char **argv) {
  char an_array_of_integers[] = {'a', 'n', ' ', 'a', 'r', 'r', 'a', 'y', ' ', 'o', 'f', ' ', 'i', 'n', 't', 'e', 'g', 'e', 'r', 's'};
  setbuf(stdout, NULL);

  printf("The minimum value of its elements: %hhu\n", return_the_minimum_value_of_its_elements(an_array_of_integers, sizeof(an_array_of_integers)));

  return(0);
}
