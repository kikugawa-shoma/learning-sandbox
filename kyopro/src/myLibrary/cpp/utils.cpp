#include <iostream>
#include <vector>

using namespace std;

// long longの省略
#define ll long long;

/**
 * vectorを空白区切りで一行で出力(最後に改行)
 */
template <typename T>
void printVec(vector<T> &A)
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

/**
 * 1文字を出力(最後に改行)
 */
template <typename T>
void printSca(T A)
{
  cout << A << endl;
}
