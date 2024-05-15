#include <iostream>

using namespace std;

int main()
{
  int a = 1;
  cout << (a += 3) << endl;
  cout << a << endl;
  return 0;
}