#include <iostream>
#include "account.h"

using namespace std;

Account::Account(string fullName, int currentBalance)
{
  _fullName = fullName;
  _currentBalance = currentBalance;
}

string Account::fullName()
{
  return _fullName;
}

int Account::deposit(int amount)
{
  return _currentBalance += amount;
}

int Account::withdraw(int amount)
{
  return _currentBalance -= amount;
}
