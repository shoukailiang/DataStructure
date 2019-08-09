//
// Created by liang on 2019/8/9.
//
typedef int ElemType;

#include <iostream>
#include <cstdio>
#include "SqQueue.h"

using namespace std;

int main() {
  SqQueue myQueue;
  int i, x, a[] = {6, 8, 16, 2, 34, 56, 7, 10, 22, 45, 62, 88};
  InitQueue(myQueue, 10, 10);   //初始画循环队列
  for (i = 0; i < 12; i++) {
    if (!EnQueue(myQueue, a[i])) {
      cout << "进队失败！" << endl;
      return 1;
    }
  }
  if (!GetHead(myQueue, x)) {
    cout << "取队首元素失败！" << endl;
    return 1;
  }
  cout << "当前队首元素数据是：" << x << endl;
  cout << "当前顺序队列的长度是：" << Length(myQueue) << endl;
  cout << "依次出对的数据元素序列为：";
  while (!QueueEmpty(myQueue)) {
    if (!DeQueue(myQueue, x)) {
      cout << "出对失败" << endl;
      return 1;
    }
    cout << x << ' ';
  }
  cout << endl;
  cout << "当前顺序队列的长度是：" << Length(myQueue) << endl;
  cout << endl;
  DestroyQueue(myQueue);
  return 0;
}
