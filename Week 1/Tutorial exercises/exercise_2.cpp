#include <stdio.h>

ssize_t* enter_values_for_them(ssize_t *an_array_of_5_integers) {

  puts("Enter values: ");
  scanf("%zd %zd %zd %zd %zd", an_array_of_5_integers, an_array_of_5_integers + 1, an_array_of_5_integers + 2, an_array_of_5_integers + 3, an_array_of_5_integers + 4);

  return(an_array_of_5_integers);
}

void print_out_the_maximum_value_and_their_average(ssize_t *an_array_of_5_integers) {
  ssize_t the_maximum_value = *an_array_of_5_integers;
  long double their_average = 0.0;

  for(unsigned char value = 1; value <= 5; ++value) {
    if(*(an_array_of_5_integers + value - 1) > the_maximum_value) {
      the_maximum_value = *(an_array_of_5_integers + value - 1);
    }
    their_average += *(an_array_of_5_integers + value - 1);
  }
  printf("The maximum value: %zd\n", the_maximum_value);
  printf("Their average: %Lf\n", their_average / 5);
}

int main(int argc, char **argv) {
  ssize_t an_array_of_5_integers[5];
  setbuf(stdout, NULL);
  
  print_out_the_maximum_value_and_their_average(enter_values_for_them(an_array_of_5_integers));

  return(0);
}
