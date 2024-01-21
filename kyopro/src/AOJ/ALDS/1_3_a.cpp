#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, N) for (ll i = 0; i < N; i++)

const ll MAX_STACK_SIZE = 1000;

class Stack
{
public:
  Stack() : data(), tail()
  {
  }

  bool push(ll s)
  {
    data[tail] = s;
    tail++;
    return true;
  }

  ll pop()
  {
    return data[--tail];
  }

  void printStack()
  {
    rep(i, tail)
    {
      cout << data[i] << ' ';
    }
    cout << endl;
  }

private:
  ll data[MAX_STACK_SIZE];
  ll tail;
};

template <typename T>
void printVecML(vector<T> &A)
{
  size_t N = A.size();
  rep(i, N)
  {
    cout << A[i] << endl;
  }
}

vector<string> inputStrVec()
{
  string inputStr;
  getline(cin, inputStr);
  inputStr.push_back(' ');

  stringstream ss{inputStr};
  vector<string> v(0);
  string tmp;
  while (getline(ss, tmp, ' '))
  {
    if (tmp.size() != 0)
      v.push_back(tmp);
  }
  return v;
}

template <typename T>
void printSca(T A)
{
  cout << A << endl;
}

int main()
{
  Stack stack;

  vector<string> strs;
  strs = inputStrVec();

  rep(i, strs.size())
  {
    string str = strs[i];
    ll a1, a2;
    switch (str[0])
    {
    case '+':
      a1 = stack.pop();
      a2 = stack.pop();
      stack.push(a1 + a2);
      break;
    case '-':
      a1 = stack.pop();
      a2 = stack.pop();
      stack.push(a2 - a1);
      break;
    case '*':
      a1 = stack.pop();
      a2 = stack.pop();
      stack.push(a1 * a2);
      break;
    default:
      ll num = atoi(strs[i].c_str());
      stack.push(num);
      break;
    }
  }

  printSca(stack.pop());

  return 0;
}