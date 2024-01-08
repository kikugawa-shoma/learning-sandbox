#include <iostream>
#include <vector>

#define ll long long

using namespace std;



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

ll bubbleSort(vector<ll> &A)
{
  ll swapCount = 0;
  size_t N = A.size();
  for (int i = N - 1; i >= 0; i--)
  {
    for (int j = N - 1; j >= N - i; j--)
    {
      ll right = A[j];
      ll left = A[j - 1];
      if (right < left)
      {
        A[j - 1] = right;
        A[j] = left;
        swapCount++;
      }
    }
  }
  return swapCount;
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

  ll count = bubbleSort(A);

  printV(A);
  cout << count << endl;
  return 0;
}