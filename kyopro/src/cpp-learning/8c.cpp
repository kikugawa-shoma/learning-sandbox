#include <iostream>

using namespace std;

// コマンドライン引数を表示するプログラム
int main(int argc, char **argv)
{
  for (int i = 0; i < argc; i++)
  {
    cout << argv[i] << endl;
  }
  return 0;
}