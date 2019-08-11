//
// Created by liang on 2019/8/10.
//
#include <iostream>
#include <ctime>

using namespace std;

#include "BinarySearchTree.h"


int main() {
  srand(time(NULL));
  BinarySearchTree<int, int> bst = BinarySearchTree<int, int>();

  int n = 10;
  for (int i = 0; i < n; i++) {
    int key = rand() % 10;
    // 为了后续测试方便,这里value值取和key值一样
    int value = key;
    cout << key << " ";
    bst.insert(key, value);
  }
  cout << endl;

  // test size
  cout << "size: " << bst.size() << endl << endl;

  // test preOrder
  cout << "preOrder: " << endl;
  bst.preOrder();
  cout << endl << endl;

  // test inOrder
  cout << "inOrder: " << endl;
  bst.inOrder();
  cout << endl << endl;

  // test postOrder
  cout << "postOrder: " << endl;
  bst.postOrder();
  cout << endl << endl;

  // test levelOrder
  cout << "levelOrder: " << endl;
  bst.levelOrder();
  cout << endl << endl;

  // test removeMin
  cout << "test removeMin" << endl;
  bst.removeMin();
  cout << "removeMin 成功" << endl;

  // test removeMax
  cout << "test removeMax" << endl;
  bst.removeMax();
  cout << "removeMax 成功" << endl;


  // test remove
  for (int i = 0; i < n; i++)
    if (bst.contain(i)) {
      bst.remove(i);
      cout << "After remove   size = " << bst.size() << endl;
    }
  return 0;
}
