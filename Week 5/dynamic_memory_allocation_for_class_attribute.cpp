#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <iostream>

class Book {
private:
  ptrdiff_t price;
  std::string *name;
  
  Book() {
    name = new std::string;
  };
  ~Book() {
    delete name;
  }
  
public:
  friend void a();
  friend void b();
};

void a() {
  bool the_allocations_are_succeeded_or_not = true;
  std::vector<Book*> three_book_objects(3);

  for(unsigned char object = 0; object < 3; ++object) {
    *(three_book_objects.data() + object) = new Book();
    if(*(three_book_objects.data() + object) == NULL) {
      the_allocations_are_succeeded_or_not = false;
    }
  }
  puts("All information of the objects:");
  for(Book *object : three_book_objects) {
    printf("%td %s", (*object).price, (*(*object).name).data());
    putchar('\n');
    
    delete(object);
  }
}

void b() {
  unsigned long long int n, the_most_expensive_book = 0;
  
  printf("Enter a number n: ");
  scanf("%llu", &n);

  Book **an_array_of_n_book_objects = (Book **)malloc(n * sizeof(Book*));

  puts("Input value for them:");
  for(unsigned long long int book_object = 0; book_object < n; ++book_object) {
    *(an_array_of_n_book_objects + book_object) = new Book();
    scanf("%td", &((*(*(an_array_of_n_book_objects + book_object))).price));
    if((*(*(an_array_of_n_book_objects + book_object))).price > (*(*(an_array_of_n_book_objects + the_most_expensive_book))).price) {
      the_most_expensive_book = book_object;
    }
    while(getchar() != ' ');
    std::getline(std::cin, (*(*(*(an_array_of_n_book_objects + book_object))).name));
  }
  printf("The most expensive book: %s\n", (*(*(*(an_array_of_n_book_objects + the_most_expensive_book))).name).data());
  for(unsigned long long int book_object = 0; book_object < n; ++book_object) {
    
    delete *(an_array_of_n_book_objects + book_object);
  }

  free(an_array_of_n_book_objects);
}

int main(int argc, char **argv) {
  setbuf(stdout, NULL);

  a();
  b();

  return(0);
}
