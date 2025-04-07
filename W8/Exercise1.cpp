#include <algorithm>
#include <stdio.h>
#include <vector>

class Book {
private:
  size_t availableCopies;
  std::vector<char *> namesOfBorrowers;
  char title[];

public:
  Book(){};

  friend class User;
};

class User {
  std::vector<Book *> borrowedBooks;
  char name[];

public:
  User(){};

  bool doBorrow(Book &abook) {

    borrowedBooks.push_back(&abook);
    abook.namesOfBorrowers.push_back(abook.title);
    --abook.availableCopies;

    return (0);
  }
  void doReturn(Book &abook) {

    borrowedBooks.erase(
        std::remove(borrowedBooks.begin(), borrowedBooks.end(), &abook),
        borrowedBooks.end());
    abook.namesOfBorrowers.erase(std::remove(abook.namesOfBorrowers.begin(),
                                             abook.namesOfBorrowers.end(),
                                             abook.title),
                                 abook.namesOfBorrowers.end());
    ++abook.availableCopies;
  }
};

class SuperUser {
  friend void d();
  bool doBorrow(Book &book1, Book &book2) { return (0); }
};

void b() {
  std::vector<Book *> three_book_objects(3);
  setbuf(stdout, NULL);

  for (unsigned char book_object = 0; book_object < 3; ++book_object) {
    three_book_objects.at(book_object) = new Book;
  }

  User user_object_one, user_object_two;

  user_object_one.doBorrow(*three_book_objects.at(2));
  user_object_two.doReturn(*three_book_objects.at(2));
  for (unsigned char book_object = 0; book_object < 3; ++book_object) {

    delete three_book_objects.at(book_object);
  }
  puts("Test");
}

void d() {
  SuperUser the_superuser;
  Book book_1, book_2;

  the_superuser.doBorrow(book_1, book_2);
}

int main(int argc, char **argv) {

  b();
  d();

  return (0);
}
