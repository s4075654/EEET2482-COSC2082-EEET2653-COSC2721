#include <stdio.h>
#include <stdlib.h>

unsigned long long int a_loop_that_continuously_request_1MB_from_the_heap() {
  unsigned long long int how_much_memory_has_been_allocated = 0;

  while(1) {
    try {
      char *an_array_of_char = (char *)malloc(1024 * 1024 * sizeof(char));
      if(an_array_of_char == NULL) {

	throw("the exception to stop the loop if allocation fails");
      }
    }
    catch(const char *the_exception_to_stop_the_loop_if_allocation_fails) {

      return(how_much_memory_has_been_allocated);
    }
    how_much_memory_has_been_allocated += 1024 * 1024;
  }
}

int main(int argc, char **argv) {
  setbuf(stdout, NULL);

  printf("Memory has been allocated: %llu\n", a_loop_that_continuously_request_1MB_from_the_heap());

  return(0);
}