#include <iostream>

using namespace std;

void put_char(char *charp)
{
  cout << charp << endl;
}

int main()
{
  int i1[] = {1, 2, 3};
  int i2[] = {1, 2, 3, 4};
  char s1[] = "ABC";
  cout << sizeof(i1) << endl;
  cout << sizeof(i2) << endl;
  cout << sizeof(s1) << endl;

  char str1[][5] = {"abc", "def"};
  char *strp1[] = {"ABC", "DEF"};
  char *charp = "ABC";
  cout << charp << endl;
  cout << charp[0] << endl;
  cout << sizeof(charp) << endl;
  cout << "compilev1" << endl;
  put_char(charp);

  int intv = 3;
  int *intp = &intv;
  cout << intp << endl;

  return 0;
}