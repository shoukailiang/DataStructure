//
// Created by liang on 2019/8/9.
//



typedef int ElemType;

#include <iostream>
#include <cstdio>
#include "LinkQueue.h"

using namespace std;

int main() {
  LinkQueue myqueue;
  int i, x, a[] = {6, 8, 16, 2, 34, 56, 7, 10, 22, 45, 62, 88};
  InitQueue(myqueue);
  for (i = 0; i < 12; i++) {
    if (!EnQueue(myqueue, a[i])) {
      cout << "进队失败！" << endl;
      return 1;
    }
  }
  if (!GetHead(myqueue, x)) {
    cout << "取队首元素失败" << endl;
    return 1;
  }
  cout << "当前队首元素数据是：" << x << endl;
  cout << "当前链队的长度是：" << Length(myqueue) << endl;
  cout << "依次出队的数据元素序列为：" << endl;
  while (!QueueEmpty(myqueue)) {
    if (!DeQueue(myqueue, x)) {
      cout << "出队失败！" << endl;
      return 1;
    }
    cout << x << ' ';
  }
  cout << endl;
  cout << "当前链队的长度是：" << Length(myqueue) << endl;
  DestroyQueue(myqueue);
  return 0;
}