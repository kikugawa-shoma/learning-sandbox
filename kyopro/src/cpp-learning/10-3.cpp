#include <iostream>

using namespace std;

class RectangularPublic
{
public:
  int a, b, c;
  int volume()
  {
    return a * b * c;
  }
};

class RectangularPrivate
{
  int _a, _b, _c;

public:
  RectangularPrivate(int a, int b, int c)
  {
    _a = a;
    _b = b;
    _c = c;
  }
  int volume()
  {
    return _a * _b * _c;
  }
};

int main()
{
  // RectangularPublic
  RectangularPublic recPub1;
  recPub1.a = 2;
  recPub1.b = 3;
  recPub1.c = 4;
  cout << "Volume of recPub1 : " << recPub1.volume() << endl;

  // RectangularPrivate
  RectangularPrivate recPri1(3, 4, 5);
  cout << "Volume of recPri1 : " << recPri1.volume() << endl;

  return 0;
}