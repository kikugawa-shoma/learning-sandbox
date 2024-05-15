#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Queue
{
  static const int MAX_SIZE = 100005;
  long long int head = 0;
  long long int tail = 0;
  T buffer[MAX_SIZE];

public:
  void push(T element)
  {
    if (this->isFull())
    {
      throw("Buffer ring is Full");
    }
    buffer[tail] = element;
    tail = this->nextIndex(tail);
  }

  T pop()
  {
    if (this->isEmpty())
    {
      throw("Queue is empty");
    }
    T headElement = buffer[head];
    head = this->nextIndex(head);
    return headElement;
  }

  bool isEmpty()
  {
    return head == tail;
  }

  bool isFull()
  {
    return this->currentSize() == MAX_SIZE - 1;
  }

  int currentSize()
  {
    if (head <= tail)
    {
      return tail - head;
    }
    else
    {
      return tail + (MAX_SIZE - head + 1);
    }
  }

private:
  int nextIndex(int i)
  {
    if (i < 0 || i >= MAX_SIZE)
    {
      return -1; // 範囲外エラー
    }
    if (i < MAX_SIZE - 1)
    {
      return i + 1;
    }
    return 0;
  }
};
