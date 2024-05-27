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

  int count = 0;
  sort(S.begin(), S.end());
  for (auto tt : T)
  {
    auto l = lower_bound(S.begin(), S.end(), tt);
    auto r = upper_bound(S.begin(), S.end(), tt);
    count += int((r - l) > 0);
  }

  cout << count << endl;

  return 0;
}