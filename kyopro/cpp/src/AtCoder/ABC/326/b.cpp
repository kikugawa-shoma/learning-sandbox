#include <iostream>

using namespace std;

int main()
{
  string N_str;
  cin >> N_str;
  int roopN;
  string roopN_str;
  roopN_str = N_str;
  while (1)
  {
    if (int(roopN_str[0] - '0') * int(roopN_str[1] - '0') == int(roopN_str[2] - '0'))
    {
      cout << roopN_str << endl;
      return 0;
    }
    roopN = stoi(roopN_str);
    roopN_str = to_string(roopN + 1);
  }
  return 0;
}