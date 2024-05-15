#include <iostream>

class Account
{
  std::string _fullName;
  int _currentBalance;

public:
  Account(std::string fullName, int currentBalance);
  std::string fullName();
  int depositInline(int amount)
  {
    return _currentBalance += amount;
  };
  int deposit(int amount);
  int withdraw(int amount);
};
