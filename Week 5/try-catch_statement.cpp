#include <stdio.h>
#include <stdexcept>

long double a() {
  double a, b;

  puts("Enter two double values a and b for division (a/b): ");
  try {
    scanf("%lf %lf", &a, &b);
    if(b == 0) {
      throw "an exception";
    }
  }
  catch(const char *an_exception) {
    printf("Re-enter value for b: ");
    scanf("%lf", &b);
  }

  return(a / b);
}

void b() {
  FILE *a_loop_that_continuously_request_1MB_from_the_heap = fopen("a_loop_that_continuously_request_1MB_from_the_heap.cpp", "w");

  fputs("#include <stdio.h>\n", a_loop_that_continuously_request_1MB_from_the_heap);
  fputs("#include <sys/mman.h>\n", a_loop_that_continuously_request_1MB_from_the_heap);
  fputc('\n', a_loop_that_continuously_request_1MB_from_the_heap);
  fputs("unsigned long long int a_loop_that_continuously_request_1MB_from_the_heap() {\n", a_loop_that_continuously_request_1MB_from_the_heap);
  fputs("  unsigned long long int how_much_memory_has_been_allocated = 0;\n", a_loop_that_continuously_request_1MB_from_the_heap);
  fputc('\n',  a_loop_that_continuously_request_1MB_from_the_heap);
  fputs("  while(1) {\n", a_loop_that_continuously_request_1MB_from_the_heap);
  fputs("    try {\n", a_loop_that_continuously_request_1MB_from_the_heap);
  fputs("      char *an_array_of_char = (char *)mmap(NULL, 1024 * 1024 * sizeof(char), PROT_READ, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);\n", a_loop_that_continuously_request_1MB_from_the_heap);
  fputs("      if(an_array_of_char == MAP_FAILED) {\n", a_loop_that_continuously_request_1MB_from_the_heap);
  fputc('\n', a_loop_that_continuously_request_1MB_from_the_heap);
  fputs("	throw(an_array_of_char);\n", a_loop_that_continuously_request_1MB_from_the_heap);
  fputs("      }\n", a_loop_that_continuously_request_1MB_from_the_heap);
  fputs("    }\n", a_loop_that_continuously_request_1MB_from_the_heap);
  fputs("    catch(char *the_exception_to_stop_the_loop_if_allocation_fails) {\n", a_loop_that_continuously_request_1MB_from_the_heap);
  fputc('\n', a_loop_that_continuously_request_1MB_from_the_heap);
  fputs("      munmap(the_exception_to_stop_the_loop_if_allocation_fails, 1024 * 1024 * sizeof(char));\n", a_loop_that_continuously_request_1MB_from_the_heap);
  fputs("      return(how_much_memory_has_been_allocated);\n", a_loop_that_continuously_request_1MB_from_the_heap);
  fputs("    }\n", a_loop_that_continuously_request_1MB_from_the_heap);
  fputs("    how_much_memory_has_been_allocated += 1024 * 1024;\n", a_loop_that_continuously_request_1MB_from_the_heap);
  fputs("  }\n", a_loop_that_continuously_request_1MB_from_the_heap);
  fputs("}\n", a_loop_that_continuously_request_1MB_from_the_heap);
  fputc('\n', a_loop_that_continuously_request_1MB_from_the_heap);
  fputs("int main(int argc, char **argv) {\n", a_loop_that_continuously_request_1MB_from_the_heap);
  fputs("  setbuf(stdout, NULL);\n", a_loop_that_continuously_request_1MB_from_the_heap);
  fputc('\n', a_loop_that_continuously_request_1MB_from_the_heap);
  fputs("  printf(\"Memory has been allocated: %llu\\n\", a_loop_that_continuously_request_1MB_from_the_heap());\n", a_loop_that_continuously_request_1MB_from_the_heap);
  fputc('\n', a_loop_that_continuously_request_1MB_from_the_heap);
  fputs("  return(0);\n", a_loop_that_continuously_request_1MB_from_the_heap);
  fputc('}', a_loop_that_continuously_request_1MB_from_the_heap);
  
  fclose(a_loop_that_continuously_request_1MB_from_the_heap);
}

int main(int argc, char **argv) {
  setbuf(stdout, NULL);

  printf("Division: %Lf\n", a());
  b();

  return(0);
}
