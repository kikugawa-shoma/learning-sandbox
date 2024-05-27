#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct Node
{
  Node *prev;
  Node *next;
  T value;
};

/**
 * 双方向連結リストクラス
 */
template <typename T>
class LinkedList
{
public:
  Node<T> *FIRST = new Node<T>; // 実装上用意したNULLノード

  LinkedList()
  {
    FIRST->next = FIRST;
    FIRST->prev = FIRST;
  }

  int sizeOfList()
  {
    return _SIZE;
  }

  /**
   * 与えられたvalueを持つノードを先頭に追加する
   * @param value - 追加するノードのvalue
   */
  void insert(T value)
  {
    Node<T> *nodeToAdd = createNode(value);
    Node<T> *crntHead = FIRST->next; // NOTE:要素数が0のときcrntHead == FIRSTとなるのでうまくいく

    FIRST->next = nodeToAdd;
    nodeToAdd->prev = FIRST;
    nodeToAdd->next = crntHead;
    crntHead->prev = nodeToAdd;
  }

  /**
   * 与えられたvalueと一致するvalueを持つ最初のノードを削除する
   * @param value - 削除したいノードのvalue
   */
  void deleteByValue(T value)
  {
    Node<T> *nodeToDelete = searchByValue(value);
    deleteNode(nodeToDelete);
  }

  /**
   * 引数で与えられたvalueを値として持つ最初のノードを返却する
   * NOTE:valueを値として持つノードが存在しなければNullノードのポインタが返却される
   * @param value - 検索したいノードのvalue
   * @return - ヒットしたノードのポインタ
   */
  Node<T> *searchByValue(T value)
  {
    Node<T> *crntNode = FIRST->next;
    while (crntNode != FIRST)
    {
      if (crntNode->value == value)
        break;
      crntNode = crntNode->next;
    }
    return crntNode;
  }

  /**
   * 最初のノードを削除
   */
  void deleteFirst()
  {
    deleteNode(FIRST->next);
  }

  /**
   * 最後のノードを削除
   */
  void deleteLast()
  {
    deleteNode(FIRST->prev);
  }

  void printList()
  {
    Node<T> *crntNode = FIRST->next;
    while (1)
    {
      cout << crntNode->value;
      Node<T> *nextNode = crntNode->next;
      if (nextNode == FIRST)
      {
        break;
      }
      cout << " ";
      crntNode = nextNode;
    }
    cout << endl;
  }

private:
  int _SIZE = 0; // FIRSTを含まない要素数

  /**
   * 与えられた値をvalueとして持つノードを作成し、そのノードのポインタを返却する。
   * @param valueOfNode - 作成するノードに持たせる値
   * @return - 作成したノードへのポインタ
   */
  Node<T> *createNode(T valueOfNode)
  {
    Node<T> *node = new Node<T>;
    node->value = valueOfNode;
    _SIZE++;
    return node;
  }

  /**
   * 与えられたノードを削除して、trueを返す。
   * 与えられたノードが存在しないノードの場合は何もせずにfalseを返す。
   *
   * @param node - 削除するノードのポインタ
   * @return - 削除結果(true:削除した、false:削除しなかった)
   */
  bool deleteNode(Node<T> *node)
  {
    if (node == FIRST)
    {
      // 受け取ったノードがFIRSTの場合は削除しない
      return false;
    }

    // 削除するノードの1つ前のノード
    Node<T> *prevNode = node->prev;
    // 削除するノードの1つ後のノード
    Node<T> *nextNode = node->next;

    // ポインタを付け替える
    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    // メモリの開放と要素数の更新
    free(node);
    --_SIZE;

    return true;
  }
};

int main()
{
  int n;
  scanf("%d", &n);
  char command[20];
  int q;
  LinkedList linkedList = LinkedList<int>();
  for (int i = 0; i < n; i++)
  {
    scanf("%s", command);
    string s(command);
    if (s.compare("insert") == 0 || s.compare("delete") == 0)
    {
      scanf("%d", &q);
      if (s.compare("insert") == 0)
      {
        linkedList.insert(q);
      }
      if (s.compare("delete") == 0)
      {
        linkedList.deleteByValue(q);
      }
    }
    if (s.compare("deleteFirst") == 0)
    {
      linkedList.deleteFirst();
    }
    if (s.compare("deleteLast") == 0)
    {
      linkedList.deleteLast();
    }
    scanf("%*c");
  }
  linkedList.printList();

  return 0;
}