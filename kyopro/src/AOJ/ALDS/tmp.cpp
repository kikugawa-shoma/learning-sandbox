#include <bits/stdc++.h>

using namespace std;

void printVec(vector<int> v)
{
  cout << v[0];
  for (int i = 1; i < v.size(); i++)
  {
    cout << " " << v[i];
  }
  cout << endl;
}

int main()
{
  vector<int> v = {1, 2, 3, 4, 5};
  int midIndex = v.size() / 2;
  auto l = vector<int>(v.begin(), v.begin() + midIndex);
  auto r = vector<int>(v.begin() + midIndex, v.end());
  l[0] = 100;
  printVec(v);
  printVec(l);
  printVec(r);

  return 0;
}