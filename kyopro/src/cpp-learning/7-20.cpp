#include <bits/stdc++.h>

using namespace std;

int main()
{
  while (1)
  {
    int *a = new (nothrow) int[10000];
    cout << a << endl;
    if (a == NULL)
    {
      cout << "Stopped due to array construction faillure" << endl;
    }
  }
}