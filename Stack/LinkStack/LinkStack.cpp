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
  InitStack(mystack);                 // 初始化链栈
  for (i = 0; i < 12; i++)
    if (!Push(mystack, a[i]))            // a[i]依次进链栈
    {
      cout << "进栈失败！" << endl;
      return 0;
    }
  if (!GetTop(mystack, x))             // 取栈顶元素并赋值给x
  {
    cout << "取栈顶元素失败！" << endl;
    return 0;
  }
  cout << "当前栈顶数据元素是：" << x << endl;
  cout << "当前链栈的长度是：" << Length(mystack) << endl;
// 求链栈的长度并输出
  cout << "依次出栈的数据元素序列为：";
  while (!StackEmpty(mystack))       // 判栈是否非空
  {
    if (!Pop(mystack, x))              // 栈顶元素出栈并赋值给x
    {
      cout << "出栈失败！" << endl;
      return 0;
    }
    cout << x << ' ';
  }
  cout << endl;
  cout << "当前链栈的长度是：" << Length(mystack) << endl;
  cout << endl;
  DestroyStack(mystack);             // 撤销链栈

  return 0;
}
