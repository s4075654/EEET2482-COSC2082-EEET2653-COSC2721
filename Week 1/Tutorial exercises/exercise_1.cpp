#include <stdio.h>

typedef struct {
  long double a, b;
} AAndB;

AAndB input_coefficient_values_a_and_b_of_a_linear_equation() {
  AAndB coefficient_values;
  
  printf("Input coefficient value a: ");
  scanf("%Lf", &coefficient_values.a);
  printf("Input coefficient value b: ");
  scanf("%Lf", &coefficient_values.b);

  return(coefficient_values);
}

long double solve_it(AAndB coefficient_values) {

  return((0 - coefficient_values.b) / coefficient_values.a);
}

void print_out_result(long double result) {

  printf("Result: %Lf\n", result);
}

int main(int argc, char **argv) {
  setbuf(stdout, NULL);
  
  print_out_result(solve_it(input_coefficient_values_a_and_b_of_a_linear_equation()));
  
  return(0);
}
