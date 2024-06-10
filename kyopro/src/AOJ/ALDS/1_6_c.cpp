#include <bits/stdc++.h>

using namespace std;

struct Card
{
  char mark;
  int num;
};

int partition(vector<Card> &A, int p, int r);
void quickSort(vector<Card> &A, int p, int r);
bool judgeStable(vector<Card> A, vector<Card> B);

int main()
{
  int n, buf2;
  char buf1;
  cin >> n;
  vector<Card> v(n), savedV(n);
  for (int i = 0; i < n; i++)
  {
    cin >> buf1 >> buf2;
    Card c = {buf1, buf2};
    v[i] = c;
    savedV[i] = c;
  }

  quickSort(v, 0, v.size() - 1);

  bool isStable = judgeStable(savedV, v);
  if (isStable)
  {
    cout << "Stable" << endl;
  }
  else
  {
    cout << "Not stable" << endl;
  }

  for (auto card : v)
  {
    cout << card.mark << " " << card.num << endl;
  }

  return 0;
}

void quickSort(vector<Card> &A, int p, int r)
{
  if (p < r)
  {
    int q = partition(A, p, r);
    quickSort(A, p, q - 1);
    quickSort(A, q + 1, r);
  }
}

int partition(vector<Card> &A, int p, int r)
{
  int endOfSmaller = p;
  int border = A[r].num;
  for (int i = p; i < r; i++)
  {
    if (A[i].num <= border)
    {
      swap(A[endOfSmaller], A[i]);
      endOfSmaller++;
    }
  }
  swap(A[r], A[endOfSmaller]);
  return endOfSmaller;
}

bool judgeStable(vector<Card> A, vector<Card> sortedA)
{
  stable_sort(A.begin(), A.end(), [](Card p1, Card p2)
              { return p1.num < p2.num; });
  for (int i = 0; i < A.size(); i++)
  {
    if (A[i].mark != sortedA[i].mark || A[i].num != sortedA[i].num)
    {
      return false;
    }
  }
  return true;
}