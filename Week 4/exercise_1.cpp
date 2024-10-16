#include <stdio.h>
#include <math.h>

class ComplNum {
private:
  long double real;
  double imag;

public:
  ComplNum() {};
  ComplNum(long double parameter_one, double parameter_two) {
    (*this).real = parameter_one;
    (*this).imag = parameter_two;
  }

  ComplNum operator-(ComplNum object) {

    return(ComplNum(real - object.real, imag - object.imag));
  }
  ComplNum operator-(double below) {

    return(ComplNum(real - below, imag));
  }
  friend ComplNum operator-(double below, ComplNum object) {

    return(ComplNum(below - object.real, -object.imag));
  }
  ComplNum operator--(int) {
    ComplNum object = *this;
    
    --real;
    --imag;

    return(object);
  }
  ComplNum operator--() {

    --real;
    --imag;

    return(*this);
  }

  friend long double c(ComplNum object);
  friend int main(int argc, char **argv);
};

long double c(ComplNum object) {

  return(sqrt(object.real * object.real + object.imag * object.imag));
}

int main(int argc, char **argv) {
  ComplNum object;
  double below;
  setbuf(stdout, NULL);

  printf("object - object = %Lf + (%fi)\n", (object - object).real, (object - object).imag);
  printf("object - double = %Lf + (%fi)\n", (object - below).real, object.imag);
  printf("double - object = %Lf + (%fi)\n", (below - object).real, -object.imag);
  printf("object-- = %Lf + (%fi)\n", object.real, object--.imag);
  printf("--object = %Lf + (%fi)\n", object.real, (--object).imag);
  printf("Absolute value: %Lf\n", c(object));

  return(0);
}
