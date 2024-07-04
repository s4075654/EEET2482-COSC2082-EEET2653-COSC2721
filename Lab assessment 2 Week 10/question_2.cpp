#include <stdio.h>
#include <list>
#include <string.h>

class Broker {
  char *name;
  long double buyPrice;
  Broker *nextBuyer;

  friend void a_function_to_print_out_all_transactions_exactly_as_above(Broker *transactions);
  friend void a_function_to_print_out_information_of_the_broker_with_the_lowest_profit_excluding_the_last_broker_who_has_not_sold_the_house(Broker *transactions);
  friend void use_linked_list_concepts_to_record_real_estate_transactions();
};

void a_function_to_print_out_all_transactions_exactly_as_above(Broker *transactions) {
  setbuf(stdout, NULL);

  puts("Print out all transactions exactly as above:");
  printf("•%s: bought the house for $%hu\n", (*transactions).name, (*transactions).buyPrice);
  transactions = (*transactions).nextBuyer;
  while(transactions != NULL) {
    transactions = (*transactions).nextBuyer;
    printf("•%s --> %s: price = $%hu\n", (*transactions).name, (*(*transactions).nextBuyer).name, (*transactions).buyPrice);
  }
}

void a_function_to_print_out_information_of_the_broker_with_the_lowest_profit_excluding_the_last_broker_who_has_not_sold_the_house(Broker *transactions) {
  short int profit = (*(*transactions).nextBuyer).buyPrice - (*transactions).buyPrice;
  Broker *transaction = transactions;
  
  transactions = (*transactions).nextBuyer;
  while((*transactions).nextBuyer != NULL) {
    if((*(*transactions).nextBuyer).buyPrice - (*transactions).buyPrice < profit) {
      profit = (*(*transactions).nextBuyer).buyPrice - (*transactions).buyPrice;
      transaction = transactions;
    }
    transactions = (*transactions).nextBuyer;
  }
  puts("Print out information on the broker with the lowest profit excluding the last broker who has not sold the house:");
  printf("%s\n%hu\n", (*transaction).name, (*transaction).buyPrice);
}

void use_linked_list_concepts_to_record_real_estate_transactions() {
  std::list<Broker> real_estate_transactions;
  std::list<Broker>::iterator real_estate_transaction = real_estate_transactions.begin();
  
  strcpy((*real_estate_transaction).name, "David");
  (*real_estate_transaction).buyPrice = 800;
  (*real_estate_transaction).nextBuyer = &(*std::next(real_estate_transaction));
  std::advance(real_estate_transaction, 1);
  strcpy((*real_estate_transaction).name, "John");
  (*real_estate_transaction).buyPrice = 1000;
  (*real_estate_transaction).nextBuyer = &(*std::next(real_estate_transaction));
  std::advance(real_estate_transaction, 1);
  strcpy((*real_estate_transaction).name, "Peter");
  (*real_estate_transaction).buyPrice = 1200;
  (*real_estate_transaction).nextBuyer = &(*std::next(real_estate_transaction));
  std::advance(real_estate_transaction, 1);
  strcpy((*real_estate_transaction).name, "Luna");
  (*real_estate_transaction).buyPrice = 1800;
  (*real_estate_transaction).nextBuyer = &(*std::next(real_estate_transaction));
  std::advance(real_estate_transaction, 1);
  strcpy((*real_estate_transaction).name, "Sophia");
  (*real_estate_transaction).buyPrice = 3500;
  a_function_to_print_out_all_transactions_exactly_as_above(&(*real_estate_transactions.begin()));
  a_function_to_print_out_information_of_the_broker_with_the_lowest_profit_excluding_the_last_broker_who_has_not_sold_the_house(&(*real_estate_transactions.begin()));
}

int main(int argc, char **argv) {

  use_linked_list_concepts_to_record_real_estate_transactions();

  return(0);
}
