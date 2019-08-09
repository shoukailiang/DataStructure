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
  InitQueue(myQueue, 10, 10);   //��ʼ��ѭ������
  for (i = 0; i < 12; i++) {
    if (!EnQueue(myQueue, a[i])) {
      cout << "����ʧ�ܣ�" << endl;
      return 1;
    }
  }
  if (!GetHead(myQueue, x)) {
    cout << "ȡ����Ԫ��ʧ�ܣ�" << endl;
    return 1;
  }
  cout << "��ǰ����Ԫ�������ǣ�" << x << endl;
  cout << "��ǰ˳����еĳ����ǣ�" << Length(myQueue) << endl;
  cout << "���γ��Ե�����Ԫ������Ϊ��";
  while (!QueueEmpty(myQueue)) {
    if (!DeQueue(myQueue, x)) {
      cout << "����ʧ��" << endl;
      return 1;
    }
    cout << x << ' ';
  }
  cout << endl;
  cout << "��ǰ˳����еĳ����ǣ�" << Length(myQueue) << endl;
  cout << endl;
  DestroyQueue(myQueue);
  return 0;
}
