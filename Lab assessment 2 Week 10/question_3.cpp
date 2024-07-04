#include <list>

class product {
  long double unit_price;
  char name[];
};

class shop {
  std::list<product> list_of_current_selling_products;
  char name[];
};

class order {
  size_t order_id;
  std::list<product> list_of_bought_products;
  long double the_total_expense;
};

class CustomerAccount {
  std::list<order> list_of_orders;
  char name[];
  enum { normal_account, gold_membership_account } discount;
};

int main(int argc, char **argv) {
  setbuf(stdout, NULL);

  
  
  return(0);
}
