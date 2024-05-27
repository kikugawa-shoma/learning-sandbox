# vector

## 受け取ったvectorの要素を書き換える関数でのvectorの受け取り方と渡し方
```cpp
void updateVector(vector<int> &V)
{
  V[0] = 100;
}

vector<int> A = {1,2}
updateVector(A)
```