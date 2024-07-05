#include <list>
#include <stdio.h>

class product {
  long double unit_price;
  char name[];
};

class shop {
  std::list<product> list_of_current_selling_products;
  char name[];
};

class order {
  friend class CustomerAccount;
  size_t order_id;
  std::list<product> list_of_bought_products;
  long double the_total_expense;
};

class CustomerAccount {
  std::list<order> list_of_orders;
  enum { normal_account, gold_membership_account } discount;
  char name[];

  long double buy() {
    long double the_total_expense = 0;

    for(std::list<order>::iterator orders = list_of_orders.begin(); orders != list_of_orders.end(); ++orders) {
      ++(*orders).order_id;
      the_total_expense += (*orders).the_total_expense;
    }
    if(discount == gold_membership_account) {
      
      return(the_total_expense * 95 / 100);
    }

    return(the_total_expense);
  }
  friend int main(int argc, char **argv);
};

int main(int argc, char **argv) {
  setbuf(stdout, NULL);

  CustomerAccount customer;
  printf("%Lf\n", customer.buy());
  
  return(0);
}
