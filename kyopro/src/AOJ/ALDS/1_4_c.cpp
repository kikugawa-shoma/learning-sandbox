#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  map<string, bool> M;
  bool hit;

  for (int i = 0; i < n; i++)
  {
    char buffer[255];
    string op, s;

    scanf("%s", buffer);
    op = buffer;
    scanf("%s", buffer);
    s = buffer;

    if (op.compare("insert") == 0)
    {
      M.insert(make_pair(s, true));
    }
    else
    {
      hit = M.find(s) != M.end();
      if (hit)
      {
        cout << "yes" << endl;
      }
      else
      {
        cout << "no" << endl;
      }
    }
  }
  return 0;
}