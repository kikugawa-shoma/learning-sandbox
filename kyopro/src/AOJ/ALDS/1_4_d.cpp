#include <bits/stdc++.h>

using namespace std;

bool check(int p, int k, vector<int> W)
{
  int crntWeight = 0;
  int count = 0;
  for (auto w : W)
  {
    if (w > p)
    {
      return false;
    }
    if (crntWeight + w > p)
    {
      count++;
      crntWeight = w;
    }
    else
    {
      crntWeight += w;
    }
  }
  if (crntWeight != 0)
  {
    count++;
  }
  return k >= count;
}

int main()
{
  int N, K;
  vector<int> W;
  scanf("%d %d", &N, &K);
  for (int i = 0; i < N; i++)
  {
    int w;
    scanf("%d", &w);
    W.push_back(w);
  }

  long long int l = 0, r = 1000000000, m;
  while (r - l > 1)
  {
    m = (l + r) / 2;
    bool canLoad = check(m, K, W);
    if (canLoad)
    {
      r = m;
    }
    else
    {
      l = m;
    }
  }

  cout << r << endl;

  return 0;
}
