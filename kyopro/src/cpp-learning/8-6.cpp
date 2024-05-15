#include <iostream>

using namespace std;

// char*型で受け取っているので配列とは挙動が異なる
void put_char(const char *s)
{
  int i = sizeof(s);
  cout << "size:" << i << endl;
  for (int i = 0; i < sizeof(s); i++)
  {
    cout << s[i] << endl;
  }
}

int main()
{
  char s1[5] = "abcd";
  const char *s2 = "efgh\0";
  cout << "s1:" << s1 << endl;
  cout << "s2:" << s2 << endl;
  cout << "===============" << endl;
  put_char(s1);
  cout << "===============" << endl;
  put_char(s2);
  cout << "===============" << endl;
  cout << "sizeof \"ABC\":" << sizeof("ABC") << endl;
  char s3[5] = "ABC";
  cout << "sizeof s3:" << sizeof(s3) << endl;
  cout << "sizeof s3:" << sizeof((char *)(s3)) << endl;
}
