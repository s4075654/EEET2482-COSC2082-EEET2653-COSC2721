#include <stdlib.h>
#include <stdio.h>

size_t doubleVal(char *an_integer, unsigned char version) {

  return(strtoull(an_integer, NULL, version) * 2);
}

long double doubleVal(char *a_floating) {

  return(strtold(a_floating, NULL) * 2.0);
}

int main(int argc, char **argv) {

  if(setbuf(stdout, NULL), *(*(argv + 1)) == '0' && *(*(argv + 1) + 1) == 'x') {
    printf("0x%X\n", doubleVal(*(argv + 1), 16));

    return(0);
  }
  char *floating_point_value = *(argv + 1);
  unsigned char decimal_point = 0;
  while(*floating_point_value != '\0') {
    if(*floating_point_value == '.') {
      decimal_point = 1;
      break;
    }
    ++floating_point_value;
  }
  if(decimal_point == 1) {
    printf("%.2Lf\n", doubleVal(*(argv + 1)));

    return(0);
  }
  printf("%zu\n", doubleVal(*(argv + 1), 10));
  
  return(0);
}
