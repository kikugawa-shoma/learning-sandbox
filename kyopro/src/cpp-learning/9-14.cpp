// 名前空間namespaceと有効範囲解決演算子::の挙動
#include <iostream>

using namespace std;

namespace namespace1
{
  void helloWorld()
  {
    cout << "hello world 1" << endl;
  }
}

// 宣言だけnamespace内に書き、定義は大域的な空間に書く
namespace namespace2
{
  void helloWorld();
}

// 実装は別で書く
void namespace2::helloWorld()
{
  cout << "hello world 2" << endl;
}

char message[] = "Global";

int main()
{
  namespace1::helloWorld();
  namespace2::helloWorld();

  char message[] = "Block";
  if (true)
  {
    char message[] = "Block in Block";
    cout << message << endl;
    cout << ::message << endl;
  }
  cout << message << endl;
  cout << ::message << endl;
  return 0;
}