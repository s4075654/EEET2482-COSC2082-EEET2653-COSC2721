#include <stdio.h>

template <int N> class factorial;

template <> class factorial<0> {
public:
  static const size_t value = 1;
};

template <int N> class factorial {
public:
  static const size_t value = N * factorial<N - 1>::value;
};

int main(int argc, char **argv) {
  setbuf(stdout, NULL);

  printf("The factorial of N: %zu\n", factorial<'N'>::value);

  return (0);
}
