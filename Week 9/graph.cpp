#include <stdio.h>

typedef struct Facebooker {
  struct Facebooker *connections_with_their_friends[5000];
  char name[];
} Facebooker;

void view(Facebooker a_given_facebooker) {
  setbuf(stdout, NULL);

  puts("View (print out to screen) all friends' names of a given Facebooker:");
  for(unsigned short int name = 0; name < 5000; ++name) {
    printf("%s\n", (*(*(a_given_facebooker.connections_with_their_friends + name))).name);
  }
}

void view_all_friends(Facebooker a_given_facebooker) {

  puts("View all friends' names of friends of a given Facebooker:");
  for(unsigned short int friends = 0; friends < 5000; ++friends) {
    for(unsigned short int name = 0; name < 5000; ++name) {
      printf("%s\n", (*(*(*(*(a_given_facebooker.connections_with_their_friends + friends))).connections_with_their_friends + friends)).name);
    }
  }
}

void view_all_mutual_friends_of_two_given_facebookers(Facebooker given_facebooker_one, Facebooker given_facebooker_two) {

  puts("View all mutual friends of two given Facebookers:");
  for(unsigned short int friends = 0; friends < 5000; ++friends) {
    for(unsigned short int all_mutual_friends = 0; all_mutual_friends < 5000; ++all_mutual_friends) {
      if(*(given_facebooker_one.connections_with_their_friends + friends) == *(given_facebooker_two.connections_with_their_friends + all_mutual_friends)) {
	printf("%s\n", (*(*(given_facebooker_two.connections_with_their_friends + friends))).name);
      }
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
