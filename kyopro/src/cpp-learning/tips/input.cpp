#include "gtest/gtest.h"
#include <bits/stdc++.h>

using namespace std;

template <typename T>
vector<T> inputVector(long long n)
{
  vector<T> v;
  T buf;
  for (long long i = 0; i < n; i++)
  {
    scanf("%d", &buf);
    v.push_back(buf);
  }
  return v;
}

/**
 * 標準入力：1 2 3 4 5
 */
TEST(InputVectorTest, ReadsCorrectNumberOfIntegers)
{
  long long int n = 5;                         // 入力する整数の数
  std::vector<int> expected = {1, 2, 3, 4, 5}; // 期待される出力

  // inputVector関数をテスト対象に設定
  auto result = inputVector<int>(n);

  // 結果と期待値を比較
  EXPECT_EQ(result, expected);
}
