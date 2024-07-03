class Broker {
  long double buyPrice;
  Broker *nextBuyer;
  char name[];
};

void a_function_to_print_out_all_transactions_exactly_as_above(Broker *transactions) {

  printf("%s: bought the house for $%Lf\n", (*transactions).name, (*transactions).buyPrice);
  transactions = (*transactions).nextBuyer;
  while(transactions != NULL) {
    transactions = nextBuyer;
    printf("
