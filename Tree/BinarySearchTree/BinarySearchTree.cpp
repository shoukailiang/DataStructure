//
// Created by liang on 2019/9/22.
//
#include<iostream>

using namespace std;
typedef int ElementType1;
#include "BinarySearchTree.h"

int main() {
  BinTree BST = NULL;
  BST = Insert(5, BST);
  BST = Insert(7, BST);
  BST = Insert(3, BST);
  BST = Insert(1, BST);
  BST = Insert(2, BST);
  BST = Insert(4, BST);
  BST = Insert(6, BST);
  BST = Insert(8, BST);
  BST = Insert(9, BST);
  /*
          5
         /\
        3  7
       /\	 /\
      1 4 6  8
      \       \
       2       9
  */
  cout << "中序遍历的结果是：";
  IterInOrderTraversal(BST);
  cout << endl;
  cout << "查找最小值是：" << FindMin(BST)->Data << endl;
  cout << "查找最大值是：" << FindMax(BST)->Data << endl;
  cout << "查找值为3的结点左子树结点值为：" << Find(3, BST)->Left->Data << endl;
  cout << "查找值为7的结点右子树结点值为：" << IterFind(7, BST)->Right->Data << endl;
  cout << "删除值为2的结点" << endl;
  Delete(5, BST);
  /*
          5
         /\
        3  7
       /\	 /\
      1 4 6  8
      \       \
       2       9
  */
  cout << "中序遍历的结果是：";
  InOrderTraversal(BST);
  cout << endl;
  return 0;
}