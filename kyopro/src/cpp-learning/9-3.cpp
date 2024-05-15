#include <iostream>

using namespace std;

// 関数テンプレート(テンプレート仮引数が1つの場合)
template <class Type>
Type maxof(Type a, Type b)
{
  return a > b ? a : b;
}

// 関数テンプレート(テンプレート仮引数が複数の場合)
template <typename S, typename T>
S returnRight(S a, T b)
{
  return b;
}

int main()
{
  int intA = 1;
  int intB = 3;
  cout << maxof(intA, intB) << endl;
  cout << maxof(intB, intA) << endl;

  double doubleA = 100;
  double doubleB = 99;
  cout << maxof(doubleA, doubleB) << endl;
  cout << maxof(doubleB, doubleA) << endl;

  // 明示的な具現化が必要な場合
  cout << maxof<int>(doubleA, intA) << endl;

  char charA = 'a';
  char charB = 'b';
  cout << maxof(charA, charB) << endl;

  cout << returnRight(intA, intB) << endl;
  cout << returnRight(intA, doubleB) << endl; // これは明示的な具現化が不要
  cout << returnRight(intA, 99.8) << endl;    // 暗黙的に型変換される

  return 0;
}