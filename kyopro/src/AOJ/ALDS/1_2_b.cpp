#include <iostream>
#include <vector>

using namespace std;

#define ll long long

template <typename T>
void printV(vector<T> &A)
{
  size_t N = A.size();
  for (int i = 0; i < N; i++)
  {
    cout << A[i];
    if (i != N - 1)
    {
      cout << ' ';
    }
  }
  cout << endl;
}

template <typename T>
void printSca(T A)
{
  cout << A << endl;
}

ll selectionSort(vector<ll> &A, ll N)
{
  ll count = 0;
  for (int i = 0; i < N; i++)
  {
    ll tmpMinIndex = i;
    for (int j = i + 1; j < N; j++)
    {
      if (A[tmpMinIndex] > A[j])
      {
        tmpMinIndex = j;
      }
    }
    if (tmpMinIndex != i)
    {
      ll tmp = A[i];
      A[i] = A[tmpMinIndex];
      A[tmpMinIndex] = tmp;
      count++;
    }
  }
  return count;
}

int main()
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }

  ll count = selectionSort(A, N);

  printV(A);
  printSca(count);
  return 0;
}
