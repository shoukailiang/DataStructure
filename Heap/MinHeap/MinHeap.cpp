//
// Created by liang on 2019/9/28.
//
#include <iostream>

#define MinData -100000
#define ERROR -1
using namespace std;

#include "MinHeap.h"


int main() {
  MinHeap H;
  int MaxSize = 100;
  H = Create(MaxSize);
  Insert(H, 55);
  Insert(H, 66);
  Insert(H, 44);
  Insert(H, 33);
  Insert(H, 11);
  Insert(H, 22);
  Insert(H, 88);
  Insert(H, 99);
  /*
      11
     /   \
     33  22
    / \  / \
   66 44 55 88
  /
 99
  */
  LevelOrderTraversal(H);
  DeleteMin(H);
  LevelOrderTraversal(H);
  DeleteMin(H);
  LevelOrderTraversal(H);
  DeleteMin(H);
  LevelOrderTraversal(H);
  DeleteMin(H);
  LevelOrderTraversal(H);

  // 构建最小堆
  cout << "----------------------请输入以构建一个新的最小堆---------------------" << endl;
  MinHeap H2;
  H2 = Create(100);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> H2->Elements[++H2->Size];
  adjust(H2);
  bl(H2);

  return 0;
}
