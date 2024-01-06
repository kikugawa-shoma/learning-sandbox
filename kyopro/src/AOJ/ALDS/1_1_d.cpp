#include <iostream>

using namespace std;

int main()
{
  int N;
  cin >> N;
  long long R[N];
  for (int i = 0; i < N; i++)
  {
    cin >> R[i];
  }

  long long mins[N];
  mins[0] = INT64_MAX;

  for (int i = 1; i < N; i++)
  {
    mins[i] = min(mins[i - 1], R[i - 1]);
  }

  long long tmpMaxProfit = INT64_MIN;
  for (int i = 1; i < N; i++)
  {
    tmpMaxProfit = max(tmpMaxProfit, R[i] - mins[i]);
  }
  cout << tmpMaxProfit << endl;
}