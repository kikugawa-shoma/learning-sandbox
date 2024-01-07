#include <iostream>
#include <vector>

using namespace std;

// long longの省略
#define ll long long
// repマクロ
#define rep(i, n) for (ll i = 0; i < N; i++)
// main関数省略
#define im int main()

/**
 * 入力受け取り
 * 形式例："3"
 */
template <typename T>
void inputSca(T &a)
{
  cin >> a;
}

/**
 * 入力受け取り
 * 形式例："1 2 3 ..."
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
 * vectorを空白区切りで一行で出力(最後に改行)
 */
template <typename T>
void printVec(vector<T> &A)
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
 * 1文字を出力(最後に改行)
 */
template <typename T>
void printSca(T A)
{
  cout << A << endl;
}

/**
 * main関数の雛形
 */
im
{
  return 0;
}