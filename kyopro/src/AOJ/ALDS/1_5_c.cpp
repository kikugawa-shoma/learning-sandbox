#include <bits/stdc++.h>

using namespace std;

void koch(pair<float, float> p1, pair<float, float> p2, int n, vector<pair<float, float>> &res)
{
  if (n == 0)
  {
    return;
  }
  pair<float, float> s, t, u;

  s.first = (p1.first * 2.0 + p2.first * 1.0) / 3.0;
  s.second = (p1.second * 2.0 + p2.second * 1.0) / 3.0;

  u.first = (p1.first * 1.0 + p2.first * 2.0) / 3.0;
  u.second = (p1.second * 1.0 + p2.second * 2.0) / 3.0;

  t.first = s.first + ((pow(3, 0.5) * (-u.second + s.second)) + u.first - s.first) / 2;
  t.second = s.second + (pow(3, 0.5) * (u.first - s.first) + u.second - s.second) / 2;

  koch(p1, s, n - 1, res);
  res.push_back(s);
  koch(s, t, n - 1, res);
  res.push_back(t);
  koch(t, u, n - 1, res);
  res.push_back(u);
  koch(u, p2, n - 1, res);
}

int main()
{
  int n;
  cin >> n;
  pair<float, float> p1, p2;
  p1 = make_pair(0, 0);
  p2 = make_pair(100, 0);

  vector<pair<float, float>> results;
  results.push_back(p1);
  koch(p1, p2, n, results);
  results.push_back(p2);

  for (auto result : results)
  {
    cout << setprecision(10) << result.first << " " << result.second << endl;
  }

  return 0;
}
