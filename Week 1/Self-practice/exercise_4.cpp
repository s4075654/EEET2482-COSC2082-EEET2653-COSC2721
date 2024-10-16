#include <stdio.h>

ptrdiff_t reverse_the_digits_of_a_given_integer(ptrdiff_t a_given_integer) {
  size_t the_digits_of_a_given_integer = (a_given_integer >= 0) ? a_given_integer : -a_given_integer;
  size_t regetni_nevig_a_fo_stigid_eht = 0;

  while(the_digits_of_a_given_integer != 0) {
    regetni_nevig_a_fo_stigid_eht *= 10;
    regetni_nevig_a_fo_stigid_eht += the_digits_of_a_given_integer % 10;
    the_digits_of_a_given_integer /= 10;
  }
  (a_given_integer < 0) ?
    a_given_integer = -regetni_nevig_a_fo_stigid_eht : a_given_integer = regetni_nevig_a_fo_stigid_eht;

  return(a_given_integer);
}

int main(int argc, char **argv) {
  setbuf(stdout, NULL);

  printf("Reverse the digits: %td\n", reverse_the_digits_of_a_given_integer(123));

  return(0);
}
