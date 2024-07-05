#include <stdio.h>

template <typename InputNumber>

void swap(InputNumber *value_of_input_number_one, InputNumber *value_of_input_number_two) {
  
  *value_of_input_number_one ^= *value_of_input_number_two;
  *value_of_input_number_two ^= *value_of_input_number_one;
  *value_of_input_number_one ^= *value_of_input_number_two;
}

void swap_the_values_of_two_input_numbers() {
  unsigned char input_number_one, input_number_two;
  setbuf(stdout, NULL);

  printf("The values of two input numbers: ");
  scanf("%hhu %hhu", &input_number_one, &input_number_two);
  swap(&input_number_one, &input_number_two);
  puts("Swap the values of two input numbers:");
  printf("%hhu %hhu\n", input_number_one, input_number_two);
  
  size_t input_size_t_one = (size_t)input_number_one, input_size_t_two = (size_t)input_number_two;
  
  swap(&input_size_t_one, &input_size_t_two);
  printf("%zu %zu\n", input_size_t_one, input_size_t_two);
}

int main(int argc, char **argv) {

  swap_the_values_of_two_input_numbers();

  return(0);
}
