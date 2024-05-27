#include <bits/stdc++.h>

using namespace std;

int calcSum(int bit, vector<int> A)
{
  bool shouldUse;
  int amount = 0;
  for (int i = 0; i < A.size(); i++)
  {
    shouldUse = (bit >> i) % 2;
    if (shouldUse)
    {
      amount += A[i];
    }
  }
  return amount;
}

int main()
{
  int n, q, buf;
  cin >> n;
  vector<int> A, M;

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &buf);
    A.push_back(buf);
  }

  cin >> q;
  for (int i = 0; i < q; i++)
  {
    scanf("%d", &buf);
    M.push_back(buf);
  }

  map<int, bool> canBeCreated;

  for (int bit = 0; bit < pow(2, n); bit++)
  {
    canBeCreated.insert(make_pair(calcSum(bit, A), true));
  }

  for (auto m : M)
  {
    if (canBeCreated.find(m) != canBeCreated.end())
    {
      cout << "yes" << endl;
    }
    else
    {
      cout << "no" << endl;
    }
  }

  return 0;
}