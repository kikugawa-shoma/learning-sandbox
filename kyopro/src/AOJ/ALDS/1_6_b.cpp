#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &A, int p, int r);
void printRes(vector<int> A, int r);

int main()
{
  int n, buf;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &buf);
    v.push_back(buf);
  }
  int r = partition(v, 0, n - 1);
  printRes(v, r);
  return 0;
}

int partition(vector<int> &A, int p, int r)
{
  auto endOfSmaller = A.begin();
  auto borderIter = A.begin() + r;
  int border = *(borderIter);
  for (auto iter = A.begin(); iter != A.end() - 1; iter++)
  {
    if (*iter <= border)
    {
      iter_swap(endOfSmaller, iter);
      endOfSmaller++;
    }
  }
  iter_swap(borderIter, endOfSmaller);
  return endOfSmaller - A.begin();
}

void printRes(vector<int> v, int r)
{
  auto rIter = v.begin() + r;
  cout << *v.begin();
  for (auto iter = v.begin() + 1; iter != v.end(); iter++)
  {
    if (iter == rIter)
    {
      cout << " [" << *iter << "]";
    }
    else
    {
      cout << " " << *iter;
    }
  }
  cout << endl;
}
