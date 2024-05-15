#include <iostream>

using namespace std;

class Account
{
  string _fullName;
  string _id;
  int _currentBalance;

public:
  Account(string fullName, string id, int currentBalance);
  string fullName() { return _fullName; }
  string id() { return _id; }
  int currentBalance();
  int deposit(int amount);
  int withdraw(int amount);
};

Account::Account(string fullName1, string id, int currentBalance)
{
  _fullName = fullName1;
  _id = id;
  _currentBalance = currentBalance;
}

int Account::currentBalance()
{
  return _currentBalance;
}

int Account::deposit(int amount)
{
  _currentBalance += amount;
  return _currentBalance;
}

int Account::withdraw(int amount)
{
  _currentBalance -= amount;
  return _currentBalance;
}

int main()
{
  Account account1("tanaka", "010", 1000);

  cout << account1.fullName() << endl;
  cout << account1.currentBalance() << endl;
  cout << account1.deposit(100) << endl;
  cout << account1.withdraw(50) << endl;
  return 0;
}