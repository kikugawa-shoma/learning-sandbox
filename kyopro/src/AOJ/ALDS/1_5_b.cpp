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

vector<int> merge(vector<int> l, vector<int> r, int *count)
{
  int li = 0, ri = 0;
  vector<int> ret;
  while (li < l.size() || ri < r.size())
  {
    (*count)++;
    if (li == l.size())
    {
      ret.push_back(r[ri++]);
      continue;
    }
    if (ri == r.size())
    {
      ret.push_back(l[li++]);
      continue;
    }
    if (l[li] <= r[ri])
    {
      ret.push_back(l[li++]);
      continue;
    }
    else
    {
      ret.push_back(r[ri++]);
      continue;
    }
  }
  return ret;
}

vector<int> mergeSort(vector<int> v, int *count)
{
  if (v.size() == 1)
  {
    return v;
  }
  int midIndex;
  midIndex = v.size() / 2;

  // TODO:vectorのslice方法をTipsにまとめる
  auto l = vector<int>(v.begin(), v.begin() + midIndex);
  auto r = vector<int>(v.begin() + midIndex, v.end());

  auto sortedL = mergeSort(l, count);
  auto sortedR = mergeSort(r, count);
  return merge(sortedL, sortedR, count);
}

int main()
{
  int n, buf, count = 0;
  vector<int> v;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &buf);
    v.push_back(buf);
  }

  auto res = mergeSort(v, &count);

  printVec(res);
  cout << count << endl;

  return 0;
}