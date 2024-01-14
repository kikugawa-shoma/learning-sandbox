#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long
#define rep(i, N) for (ll i = 0; i < N; i++)

using namespace std;

template <typename T>
void printVecML(vector<T> &A)
{
  size_t N = A.size();
  rep(i, N)
  {
    cout << A[i] << endl;
  }
}

template <typename T>
void printSca(T A)
{
  cout << A << endl;
}

template <typename T>
void inputVec(vector<T> &A)
{
  size_t N = A.size();
  rep(i, N)
  {
    cin >> A[i];
  }
}

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

void insertionSort(vector<ll> &A, ll g, ll &count)
{
  for (ll i = g; i < A.size(); i++)
  {
    ll v = A[i];
    ll j = i - g;
    while (j >= 0 && A[j] > v)
    {
      A[j + g] = A[j];
      j = j - g;
      count++;
    }
    A[j + g] = v;
  }
}

ll shellSort(vector<ll> &A, vector<ll> G)
{
  ll N = A.size();
  ll cnt = 0;
  ll M = G.size();
  rep(i, M)
  {
    insertionSort(A, G[i], cnt);
  }
  return cnt;
}

vector<ll> gs_create(ll n)
{
  vector<ll> G = {1};
  while (1)
  {
    ll g = G.back() * 3 + 1;
    if (g >= n)
      break;
    G.push_back(g);
  }
  reverse(G.begin(), G.end());
  return G;
}

int main()
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  inputVec(A);

  vector<ll> G;
  G = gs_create(N);
  printSca(G.size());
  printVec(G);

  ll cnt = shellSort(A, G);
  printSca(cnt);
  printVecML(A);

  return 0;
}