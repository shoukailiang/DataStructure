//
// Created by liang on 2019/9/28.
//
#include <iostream>

#define MaxData 100000
#define ERROR -1
using namespace std;

#include "MaxHeap.h"


int main() {
  MaxHeap H;
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
     99
    /  \
     88  66
    / \  / \
   55 11 22 44
  /
   33
  */
  LevelOrderTraversal(H);
  DeleteMax(H);
  LevelOrderTraversal(H);
  DeleteMax(H);
  LevelOrderTraversal(H);
  DeleteMax(H);
  LevelOrderTraversal(H);
  DeleteMax(H);
  LevelOrderTraversal(H);

  // 构建最大堆
  cout << "----------------------请输入以构建一个新的最大堆---------------------" << endl;
  MaxHeap H2;
  H2 = Create(100);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> H2->Elements[++H2->Size];
  adjust(H2);
  bl(H2);

  return 0;
}
