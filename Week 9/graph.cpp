#include <stdio.h>

typedef struct Facebooker {
  Facebooker *connections_with_their_friends[5000];
  char name[];
} Facebooker;

void view(Facebooker a_given_facebooker) {
  setbuf(stdout, NULL);

  puts("All friends' names of a given Facebooker:");
  for(unsigned int name = 0; name < 5000; ++name) {
    printf("%s\n", (*(*(a_given_facebooker.connections_with_their_friends + name))).name);
  }
}

void view_all_friends(Facebooker a_given_facebooker) {

  puts("All friends' names of friends of a given Facebooker:");
  for(unsigned int friends_of_a_given_facebooker = 0; friends_of_a_given_facebooker < 5000; ++friends_of_a_given_facebooker) {
    for(unsigned int name = 0; name < 5000; ++name) {
      printf("%s\n", (*(*(*(*(a_given_facebooker.connections_with_their_friends + friends_of_a_given_facebooker))).connections_with_their_friends + name)).name);
    }
  }
}

void view_all_mutual_friends_of_two_given_facebookers(Facebooker given_facebooker_one, Facebooker given_facebooker_two) {

  puts("All mutual friends of two given Facebookers");
  for(unsigned int friends_of_given_facebooker_one = 0; friends_of_given_facebooker_one < 5000; ++friends_of_given_facebooker_one) {
    for(unsigned int friends_of_given_facebooker_two = 0; friends_of_given_facebooker_two < 5000; ++friends_of_given_facebooker_two) {
      if(*(given_facebooker_one.connections_with_their_friends + friends_of_given_facebooker_one) == *(given_facebooker_two.connections_with_their_friends + friends_of_given_facebooker_two)) {
	printf("%s\n", (*(*(given_facebooker_two.connections_with_their_friends + friends_of_given_facebooker_two))).name);
      }
    }
  }
}

void the_following_functionalities() {
  Facebooker given_facebooker_one;
  Facebooker given_facebooker_two;
  
  view(given_facebooker_two);
  view_all_friends(given_facebooker_two);
  view_all_mutual_friends_of_two_given_facebookers(given_facebooker_one, given_facebooker_two);
}

int main(int argc, char **argv) {

  the_following_functionalities();

  return(0);
}
