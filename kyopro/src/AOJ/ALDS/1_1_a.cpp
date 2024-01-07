#include <iostream>
#include <vector>

#define ll long long

using namespace std;

void printV(vector<ll> &A)
{
  size_t L = A.size();
  for (size_t l = 0; l < L; l++)
  {
    cout << A[l];
    if (l != L - 1)
    {
      cout << ' ';
    }
  }
  cout << endl;
}

void insertionSort(vector<long long> &A, int N)
{
  printV(A);
  for (int i = 1; i < N; i++)
  {
    long long elementToInsert = A[i];
    bool hasInserted = false;
    for (int j = i - 1; j >= 0; j--)
    {
      long long alreadyInsertedElement = A[j];
      if (alreadyInsertedElement > elementToInsert)
      {
        A[j + 1] = alreadyInsertedElement;
      }
      else
      {
        A[j + 1] = elementToInsert;
        hasInserted = true;
        break;
      }
    }
    if (!hasInserted)
    {
      A[0] = elementToInsert;
    }
    printV(A);
  }
}

int main()
{
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  insertionSort(A, N);
  return 0;
}
