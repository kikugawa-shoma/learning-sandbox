#include <iostream>

using namespace std;

void ex_func(int n)
{
  cout << "standard func is called!" << endl;
}

template <class T>
void ex_func(T n)
{
  cout << "template func is called!" << endl;
}

int main()
{
  int n = 0;
  ex_func(n);      // standard one will be called
  ex_func<int>(n); // template one will be called
  ex_func<>(n);    // template one will be called
  return 0;
}