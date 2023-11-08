#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// 2次元ベクターのprint関数
template <typename T>
void print_1_vec(vector<T> v)
{
  for (auto i = 0; i < v.size(); i++)
  {
    cout << v[i] << ' ';
  }
  cout << endl;
}

// 2次元ベクターの関数
template <typename T>
void print_2_vec(vector<vector<T>> v)
{
  for (auto i = 0; i < v.size(); i++)
  {
    for (auto j = 0; j < v[i].size(); j++)
    {
      cout << v[i][j] << ' ';
    }
    if (i != v.size())
    {
      cout << endl;
    }
  }
}

vector<vector<char>> create_patterns(int n, char head)
{
  vector<vector<char>> ret;
  vector<char> CHARS = {'A', 'B', 'C', '.', '.'};
  vector<char> chars_to_use(n);
  copy(CHARS.begin(), CHARS.begin() + n, chars_to_use.begin());
  do
  {
    // TODO:chars_to_useが候補の並びか判定してpush_backするか決める
    ret.push_back(chars_to_use);
  } while (next_permutation(chars_to_use.begin(), chars_to_use.end()));
  return ret;
};

int main()
{
  int N;
  cin >> N;
  string R, C;
  cin >> R >> C;
  vector<vector<char>> patterns = create_patterns(N, 'a');
  print_2_vec(patterns);
  return 0;
}
