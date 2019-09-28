//
// Created by liang on 2019/9/19.
//
#include <iostream>

typedef int ElementType;  // ElementType 可定义为任意类型
#include "SqList.h"

using namespace std;

int main() {
  int i = 0;
  List L = MakeEmpty();
  Insert(L, 11, 0);
  printf("在线性表L-Data[0]插入11\n");
  Insert(L, 25, 0);
  printf("在线性表L-Data[0]插入25\n");
  Insert(L, 33, 0);
  printf("在线性表L-Data[0]插入33\n");
  Insert(L, 77, 0);
  printf("在线性表L-Data[0]插入77\n");
  printf("此时的线性表为：");
  for (i = 0; i < Length(L); i++)
    printf("%d ", L->Data[i]);

  printf("\n");
  printf("查找值为12的下标是：%d\n", Find(L, 12));

  printf("下标为3的线性表的值是：%d\n", FindKth(L, 3));
  Delete(L, 2);
  printf("删除线性表中第2个元素\n");
  Delete(L, 2);
  printf("删除线性表中第2个元素\n");
  printf("此时的线性表为：");
  for (i = 0; i < Length(L); i++)
    printf("%d ", L->Data[i]);
  printf("\n");
  return 0;
}
