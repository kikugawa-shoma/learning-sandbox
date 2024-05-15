#include <iostream>

using namespace std;

class Date
{
  int _y;
  int _m;
  int _d;
  mutable int _mm;

public:
  Date(int year, int month, int day, int minute = 0)
  {
    _y = year;
    _m = month;
    _d = day;
    _mm = minute;
  }
  void print() const
  {
    cout << _y << "年" << _m << "月" << _d << "日";
    cout << _mm << "分" << endl;
  }
  void updateMinute(int newMinute) const
  {
    _mm = newMinute;
  }
};

int main()
{
  // 定数オブジェクトd1の生成
  const Date d1 = Date(1, 1, 1);
  d1.print();
  // 定数オブジェクトの場合でも、mutableなメンバ変数に限り、メンバ関数で更新可能
  d1.updateMinute(100);
  d1.print();
  return 0;
}