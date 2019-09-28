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
  cout << "��������Ľ���ǣ�";
  IterInOrderTraversal(BST);
  cout << endl;
  cout << "������Сֵ�ǣ�" << FindMin(BST)->Data << endl;
  cout << "�������ֵ�ǣ�" << FindMax(BST)->Data << endl;
  cout << "����ֵΪ3�Ľ�����������ֵΪ��" << Find(3, BST)->Left->Data << endl;
  cout << "����ֵΪ7�Ľ�����������ֵΪ��" << IterFind(7, BST)->Right->Data << endl;
  cout << "ɾ��ֵΪ2�Ľ��" << endl;
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
  cout << "��������Ľ���ǣ�";
  InOrderTraversal(BST);
  cout << endl;
  return 0;
}