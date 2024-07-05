#include <stdio.h>
#include <iostream>

template <typename TheSameType>

void min3(TheSameType argument_one, TheSameType argument_two, TheSameType argument_three) {
  TheSameType the_least_of_these_arguments = argument_one;
  
  if(argument_two < the_least_of_these_arguments) {
    the_least_of_these_arguments = argument_two;
  }
  if(argument_three < the_least_of_these_arguments) {
    the_least_of_these_arguments = argument_three;
  }

  setbuf(stdout, NULL);
  
  puts("Print out the least of these arguments:");
  std::cout << the_least_of_these_arguments << '\n';
}

int main(int argc, char **argv) {

  min3("argument of the same type", "argument of the same type", "argument of the same type");

  return(0);
}
