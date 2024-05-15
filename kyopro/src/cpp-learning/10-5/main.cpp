#include <iostream>
#include "account.h"

using namespace std;

int main()
{
  Account account("tanaka", 1000);

  cout << account.fullName() << endl;
  cout << account.deposit(100) << endl;
  cout << account.depositInline(100) << endl;
  cout << account.withdraw(50) << endl;

  Account *p = &account;
  cout << (*p).fullName() << endl;
  cout << p->fullName() << endl;

  return 0;
}