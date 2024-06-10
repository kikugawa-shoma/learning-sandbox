#include <bits/stdc++.h>

using namespace std;

long long countInversion(vector<int> A);
vector<int> mergeSort(vector<int> A, long long int *counter);

int main()
{
  int n, buf;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &buf);
    v[i] = buf;
  }

  long long int res = countInversion(v);

  cout << res << endl;

  return 0;
}

long long int countInversion(vector<int> A)
{
  long long int counter = 0;
  mergeSort(A, &counter);
  return counter;
}

void printVec(vector<int> v)
{
  if (v.size() == 0)
  {
    return;
  }
  cout << v[0];
  for (auto it = v.begin() + 1; it != v.end(); it++)
  {
    cout << " " << *it;
  }
  cout << endl;
}

vector<int> mergeSort(vector<int> A, long long int *counter)
{
  if (A.size() <= 1)
  {
    return A;
  }
  int mid = A.size() / 2;
  vector<int> L(A.begin(), A.begin() + mid);
  vector<int> R(A.begin() + mid, A.end());
  auto sortedL = mergeSort(L, counter);
  auto sortedR = mergeSort(R, counter);
  vector<int> merged;
  int li = 0, ri = 0, lM = sortedL.size(), rM = sortedR.size();
  while (1)
  {
    if (li == lM && ri == rM)
    {
      break;
    }
    if (li == lM)
    {
      merged.push_back(sortedR[ri++]);
      continue;
    }
    if (ri == rM)
    {
      *counter += rM;
      merged.push_back(sortedL[li++]);
      continue;
    }
    if (sortedL[li] <= sortedR[ri])
    {
      *counter += ri;
      merged.push_back(sortedL[li++]);
      continue;
    }
    else
    {
      merged.push_back(sortedR[ri++]);
      continue;
    }
  }
  return merged;
}
