#include <bits/stdc++.h>
#include <stack>

using namespace std;

template <typename T>
void printVec(vector<T> v)
{
  for (auto vv : v)
  {
    cout << ' ' << vv;
  }
}

int main()
{
  char c[20005] = "";
  cin >> c;
  stack<int> downPositions;
  stack<pair<int, int>> crntPonds;
  int pos = -1;

  while (1)
  {
    pos++;
    if (c[pos] == '\0')
    {
      break;
    }
    if (c[pos] == '\\')
    {
      downPositions.push(pos);
    }
    if (c[pos] == '/')
    {
      if (downPositions.empty())
      {
        continue;
      }
      int leftDownPos = downPositions.top();
      downPositions.pop();
      int waterAmount = (pos - leftDownPos);
      int updatedLeftDownPos = leftDownPos;
      while (!crntPonds.empty())
      {
        auto prePond = crntPonds.top();
        if (prePond.first > leftDownPos)
        {
          waterAmount += prePond.second;
          updatedLeftDownPos = prePond.first;
          crntPonds.pop();
          continue;
        }
        break;
      }
      crntPonds.push(make_pair(updatedLeftDownPos, waterAmount));
    }
  }
  vector<int> result;
  int S = 0;
  while (!crntPonds.empty())
  {
    auto pond = crntPonds.top();
    crntPonds.pop();
    result.push_back(pond.second);
    S += pond.second;
  }

  cout << S << endl;
  cout << result.size();
  reverse(result.begin(), result.end());
  printVec(result);
  cout << endl;

  return 0;
}