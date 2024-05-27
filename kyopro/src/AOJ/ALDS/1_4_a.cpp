#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, q;
  vector<int> S, T;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    S.push_back(tmp);
  }
  cin >> q;
  for (int i = 0; i < q; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    T.push_back(tmp);
  }

  map<int, bool> M;
  for (auto ss : S)
  {
    M.insert(make_pair(ss, true));
  }

  int count = 0;
  for (auto tt : T)
  {
    if (M.find(tt) != M.end())
    {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}