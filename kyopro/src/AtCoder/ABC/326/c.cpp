#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printVectorInOneLiner(vector<int> v)
{
  for (int i = 0; i < (int)v.size(); i++)
  {
    cout << v[i] << ' ';
  }
  cout << endl;
};

void readVetorInOnerLiner(vector<int> *v)
{
  for (int i = 0; i < (int)(*v).size(); i++)
  {
    cin >> (*v)[i];
  }
}

int main()
{
  int N, M;
  cin >> N >> M;

  vector<int> A(N);
  readVetorInOnerLiner(&A);
  sort(A.begin(), A.end());
  int l, r;
  int maxv = 0;
  for (int i = 0; i < (int)A.size(); i++)
  {
    l = lower_bound(A.begin(), A.end(), A[i]) - A.begin();
    r = upper_bound(A.begin(), A.end(), A[i] + M - 1) - A.begin();
    maxv = max(r - l, maxv);
  }
  cout << maxv << endl;
  return 0;
}
