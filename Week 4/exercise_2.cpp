#include <stdio.h>
#include <stdlib.h>

class BankAcc {
public:
  float amount;
  char name[];
  BankAcc(BankAcc *all_data, unsigned long long int *account) {

    all_data = (BankAcc *)realloc(all_data, (*account + 1) * sizeof(BankAcc));
    *(all_data + (*account)++) = *this;
  }
  
  const char* withdraw(float num) {
    if(amount >= num) {
      amount -= num;
    }
    else {
      puts("an error message.");
      
      return("an error code");
    }

    return(NULL);
  }
  friend void c(int argc, char *command_line_argument, BankAcc *all_data, unsigned long long int account);
};

void c(int not_give_the_command_line_argument, char *command_line_argument, BankAcc *all_data, unsigned long long int account) {
    if (not_give_the_command_line_argument != 1) {
      unsigned long long int line = 0;
      FILE *a_file = fopen(command_line_argument, "a");

      for(unsigned long long int line = 0; line < account; ++line) {
	fprintf(a_file, "%f %s\n", (*(all_data + line)).amount, (*(all_data + line)).name);
      }

      fclose(a_file);
    }
}

int main(int argc, char **argv) {
  BankAcc *all_data = (BankAcc *)malloc(3 * sizeof(BankAcc));
  unsigned long long int account = 0;
  BankAcc bank_account_object_1(all_data, &account);
  BankAcc bank_account_object_2(all_data, &account);
  BankAcc bank_account_object_3(all_data, &account);

  puts("All information:");
  printf("%f %s %f %s %f %s\n", bank_account_object_1.amount, bank_account_object_1.name, bank_account_object_2.amount, bank_account_object_2.name, bank_account_object_3.amount, bank_account_object_3.name);

  BankAcc his(all_data, &account);
  his.withdraw(atof("float num"));

  c(argc, *(argv + 1), all_data, account);

  free(all_data);
  return(0);
}
