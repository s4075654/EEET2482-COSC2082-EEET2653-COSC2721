#include <stdio.h>

class Facebooker {
  Facebooker *connections_with_their_friends[5000];
  char his[];
  
  friend void view(Facebooker a_given_facebooker);
  friend void view_all_friends(Facebooker a_given_facebooker);
  friend void view_all_mutual_friends_of_two_given_facebookers(Facebooker given_facebooker_one, Facebooker given_facebooker_two);
  friend int main(int argc, char **argv);
};

void view(Facebooker a_given_facebooker) {
  setbuf(stdout, NULL);

  puts("View (print out to screen) all friends' names of a given Facebooker:");
  for(unsigned short int name = 0; name < 5000; ++name) {
    printf("%s\n", (*(*(a_given_facebooker.connections_with_their_friends + name))).his);
  }
}

void view_all_friends(Facebooker a_given_facebooker) {

  puts("View all friends' names of friends of a given Facebooker:");
  for(unsigned short int connection = 0; connection < 5000; ++connection) {
    for(unsigned short int name = 0; name < 5000; ++name) {
      printf("%s\n", (*(*((*(*(a_given_facebooker.connections_with_their_friends + connection))).connections_with_their_friends + name))).his);
    }
  }
}

void view_all_mutual_friends_of_two_given_facebookers(Facebooker given_facebooker_one, Facebooker given_facebooker_two) {

  puts("View all mutual friends of two given Facebookers:");
  for(unsigned short int connection = 0; connection < 5000; ++connection) {
    for(unsigned short int name = 0; name < 5000; ++name) {
      (given_facebooker_one.connections_with_their_friends + connection == given_facebooker_two.connections_with_their_friends + name) ? printf("%s\n", (*(*(given_facebooker_two.connections_with_their_friends + name))).his) : 0;
    }
  }
}

int main(int argc, char **argv) {
  Facebooker given_facebooker_one, given_facebooker_two;

  view(given_facebooker_two);
  view_all_friends(given_facebooker_two);
  view_all_mutual_friends_of_two_given_facebookers(given_facebooker_one, given_facebooker_two);

  return(0);
}
