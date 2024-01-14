#include <iostream>
#include <vector>

using namespace std;

// long longの省略
#define ll long long
// repマクロ
#define rep(i, N) for (ll i = 0; i < N; i++)

/**
 * 単一入力受け取り
 * 形式例："3"
 */
template <typename T>
void inputSca(T &a)
{
  cin >> a;
}

/**
 * 複数入力受け取り
 */
template <typename T>
void inputVec(vector<T> &A)
{
  size_t N = A.size();
  rep(i, N)
  {
    cin >> A[i];
  }
}

/**
 * print vector one liner
 * vectorを空白区切りで一行で出力(最後に改行)
 * 出力例："1 2 3 ..."
 */
template <typename T>
void printVecOL(vector<T> &A)
{
  size_t N = A.size();
  rep(i, N)
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
 * print vector multi liner
 */
template <typename T>
void printVecML(vector<T> &A)
{
  size_t N = A.size();
  rep(i, N)
  {
    cout << A[i] << endl;
  }
}

/**
 * 1文字を出力(最後に改行)
 */
template <typename T>
void printSca(T A)
{
  cout << A << endl;
}
