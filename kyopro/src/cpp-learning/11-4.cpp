#include <iostream>

using namespace std;

class Date
{
  int _y;
  int _m;
  int _d;

public:
  Date(int year, int month, int day)
  {
    _y = year;
    _m = month;
    _d = day;
  }
};

class DateWithDefaultConstructor
{
  int _y;
  int _m;
  int _d;
  int DEFAULT_YEAR = 1;
  int DEFAULT_MONTH = 1;
  int DEFAULT_DAY = 1;

public:
  DateWithDefaultConstructor(int year, int month, int day)
  {
    _y = year;
    _m = month;
    _d = day;
  }
  DateWithDefaultConstructor()
  {
    cout << "Default constructor has been called!" << endl;
    _y = DEFAULT_YEAR;
    _m = DEFAULT_MONTH;
    _d = DEFAULT_DAY;
  }
  void print()
  {
    cout << _y << "年" << _m << "月" << _d << "日" << endl;
  }
};

int main()
{
  // インスタンス生成の方法3パターン
  // 最もシンプルな方法
  Date d1(2, 2, 2);
  // コンパイラによって暗黙の中に提供されるコピーコンストラクタによるインスタンス生成
  Date d2 = d1;
  // 一時インスタンスの生成(左辺) + コピーコンストラクタによるインスタンス生成
  Date d3 = Date(1, 1, 1);
  cout << &d1 << endl;
  cout << &d2 << endl;
  cout << &d3 << endl;

  DateWithDefaultConstructor d4;
  int N = 4;
  DateWithDefaultConstructor dd[N];
  for (int i = 0; i < N; i++)
  {
    dd[i].print(); // デフォルトコンストラクタで初期化されていることが分かる
  }
  DateWithDefaultConstructor d5(2, 2, 2); // デフォルトコンストラクタは呼ばれない
  d5.print();

  return 0;
}