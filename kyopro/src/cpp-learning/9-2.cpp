#include <iostream>

using namespace std;

template <class Type>
Type maxof(Type x[], int n)
{
  Type tmp_max = x[0];
  for (int i = 0; i < n; i++)
  {
    tmp_max = max(x[i], tmp_max);
  }
  return tmp_max;
}

int main()
{
  int a[10] = {2, 6, 3, 100, 29, 2, 3, 5, 5};
  double b[10] = {2, 6, 3, 100, 29, 2, 3, 5, 2000};
  cout << maxof(a, 10) << endl;
  cout << maxof(b, 10) << endl;
  return 0;
}