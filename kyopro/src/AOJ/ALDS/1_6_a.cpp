#include <bits/stdc++.h>

using namespace std;

vector<int> CountingSort(vector<int> A, int k);
void printVec(vector<int> V);

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
  vector<int> res = CountingSort(v, 10005);
  printVec(res);
  return 0;
}

vector<int> CountingSort(vector<int> A, int k)
{
  vector<int> C(k + 1);
  int N_c = C.size();
  for (int i = 0; i < N_c; i++)
  {
    C[i] = 0;
  }
  for (auto a : A)
  {
    C[a]++;
  }
  for (int i = 1; i < N_c; i++)
  {
    C[i] += C[i - 1];
  }
  vector<int> B(A.size());
  for (auto a : A)
  {
    B[--C[a]] = a;
  }
  return B;
}

void printVec(vector<int> V)
{
  int N = V.size();
  cout << *(V.begin());
  for (auto it = V.begin() + 1; it != V.end(); it++)
  {
    cout << " " << *it;
  }
  cout << endl;
}