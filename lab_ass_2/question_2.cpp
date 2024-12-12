#include <stdio.h>
#include <list>
#include <string.h>

class Broker {
  char name[7];
  unsigned short int buyPrice;
  Broker *nextBuyer;

public:
  Broker(const char *broker, unsigned short int price) {
    strncpy(name, broker, 7);
    buyPrice = price;
    nextBuyer = NULL;
  }

  friend void a_function_to_print_out_all_transactions_exactly_as_above(Broker *transactions);
  friend void a_function_to_print_out_information_of_the_broker_with_the_lowest_profit_excluding_the_last_broker_who_has_not_sold_the_house(Broker *transactions);
  friend void use_linked_list_concepts_to_record_real_estate_transactions();
};

void a_function_to_print_out_all_transactions_exactly_as_above(Broker *transactions) {
  setbuf(stdout, NULL);

  puts("Print out all transactions exactly as above:");
  printf("•\t%s: bought the house for $%hu\n", (*transactions).name, (*transactions).buyPrice);
  while((*transactions).nextBuyer != NULL) {
    printf("•\t%s --> %s\t: price = $%hu\n", (*transactions).name, (*(*transactions).nextBuyer).name, (*(*transactions).nextBuyer).buyPrice);
    transactions = (*transactions).nextBuyer;
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

  real_estate_transactions.emplace_back("David", 800);  
  real_estate_transactions.emplace_back("John", 1000);
  real_estate_transactions.emplace_back("Peter", 1200);
  real_estate_transactions.emplace_back("Luna", 1800);
  real_estate_transactions.emplace_back("Sophia", 3500);
  
  std::list<Broker>::iterator transaction = real_estate_transactions.begin();

  for(unsigned char buyer = 1; buyer <= 4; ++buyer) {
    (*transaction).nextBuyer = &*std::next(transaction);
    ++transaction;
  }
  a_function_to_print_out_all_transactions_exactly_as_above(&real_estate_transactions.front());
  a_function_to_print_out_information_of_the_broker_with_the_lowest_profit_excluding_the_last_broker_who_has_not_sold_the_house(&real_estate_transactions.front());
}

int main(int argc, char **argv) {

  use_linked_list_concepts_to_record_real_estate_transactions();

  return(0);
}
