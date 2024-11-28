#include <iostream>
#include <stdio.h>
#include <string>
#include <sys/mman.h>
#include <vector>

class Book {
private:
  ptrdiff_t price;
  std::string *name;

  Book() { name = new std::string; };
  ~Book() { delete name; }

public:
  friend void a();
  friend void b();
};

void a() {
  bool the_allocations_are_succeeded_or_not = true;
  std::vector<Book *> three_book_objects(3);

  for (unsigned char object = 0; object < 3; ++object) {
    *(three_book_objects.data() + object) = new Book();
    if (*(three_book_objects.data() + object) == NULL) {
      the_allocations_are_succeeded_or_not = false;
    }
  }
  puts("All information of the objects:");
  for (Book *object : three_book_objects) {
    printf("%td %s", (*object).price, (*(*object).name).data());
    putchar('\n');

    delete (object);
  }
}

void b() {
  unsigned long long int n, the_most_expensive_book = 0;

  printf("Enter a number n: ");
  scanf("%llu", &n);

  Book **an_array_of_n_book_objects =
      (Book **)mmap(NULL, n * sizeof(Book *), PROT_READ | PROT_WRITE,
                    MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

  puts("Input value for them:");
  for (unsigned long long int book_object = 0; book_object < n; ++book_object) {
    *(an_array_of_n_book_objects + book_object) = new Book();
    scanf("%td", &((*(*(an_array_of_n_book_objects + book_object))).price));
    if ((*(*(an_array_of_n_book_objects + book_object))).price >
        (*(*(an_array_of_n_book_objects + the_most_expensive_book))).price) {
      the_most_expensive_book = book_object;
    }
    while (getchar() != ' ')
      ;
    std::getline(std::cin,
                 (*(*(*(an_array_of_n_book_objects + book_object))).name));
  }
  printf("The most expensive book: %s\n",
         (*(*(*(an_array_of_n_book_objects + the_most_expensive_book))).name)
             .data());
  for (unsigned long long int book_object = 0; book_object < n; ++book_object) {

    delete *(an_array_of_n_book_objects + book_object);
  }

  munmap(an_array_of_n_book_objects, n * sizeof(Book *));
}

int main(int argc, char **argv) {
  setbuf(stdout, NULL);

  a();
  b();

  return (0);
}
