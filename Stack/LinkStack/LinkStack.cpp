//
// Created by liang on 2019/8/9.
//


typedef int ElemType;

#include <iostream>
#include <iomanip>
#include "LinkStack.h"

using namespace std;

int main() {
  LinkStack mystack;
  int i, x, a[] = {6, 8, 16, 2, 34, 56, 7, 10, 22, 45, 62, 88};
  InitStack(mystack);                 // ��ʼ����ջ
  for (i = 0; i < 12; i++)
    if (!Push(mystack, a[i]))            // a[i]���ν���ջ
    {
      cout << "��ջʧ�ܣ�" << endl;
      return 0;
    }
  if (!GetTop(mystack, x))             // ȡջ��Ԫ�ز���ֵ��x
  {
    cout << "ȡջ��Ԫ��ʧ�ܣ�" << endl;
    return 0;
  }
  cout << "��ǰջ������Ԫ���ǣ�" << x << endl;
  cout << "��ǰ��ջ�ĳ����ǣ�" << Length(mystack) << endl;
// ����ջ�ĳ��Ȳ����
  cout << "���γ�ջ������Ԫ������Ϊ��";
  while (!StackEmpty(mystack))       // ��ջ�Ƿ�ǿ�
  {
    if (!Pop(mystack, x))              // ջ��Ԫ�س�ջ����ֵ��x
    {
      cout << "��ջʧ�ܣ�" << endl;
      return 0;
    }
    cout << x << ' ';
  }
  cout << endl;
  cout << "��ǰ��ջ�ĳ����ǣ�" << Length(mystack) << endl;
  cout << endl;
  DestroyStack(mystack);             // ������ջ

  return 0;
}
