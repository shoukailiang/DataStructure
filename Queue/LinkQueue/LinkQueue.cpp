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
      cout << "����ʧ�ܣ�" << endl;
      return 1;
    }
  }
  if (!GetHead(myqueue, x)) {
    cout << "ȡ����Ԫ��ʧ��" << endl;
    return 1;
  }
  cout << "��ǰ����Ԫ�������ǣ�" << x << endl;
  cout << "��ǰ���ӵĳ����ǣ�" << Length(myqueue) << endl;
  cout << "���γ��ӵ�����Ԫ������Ϊ��" << endl;
  while (!QueueEmpty(myqueue)) {
    if (!DeQueue(myqueue, x)) {
      cout << "����ʧ�ܣ�" << endl;
      return 1;
    }
    cout << x << ' ';
  }
  cout << endl;
  cout << "��ǰ���ӵĳ����ǣ�" << Length(myqueue) << endl;
  DestroyQueue(myqueue);
  return 0;
}