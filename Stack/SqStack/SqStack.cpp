//
// Created by liang on 2019/8/9.
//
typedef int ElemType;

#include <iostream>
#include "SqStack.h"

using namespace std;

int main() {
  SqStack mystack;
  int i, x, a[] = {6, 8, 16, 2, 34, 56, 7, 10, 22, 45, 62, 88, 90, 3, 9};
  InitStack(mystack, 10, 10);             // 初始化顺序栈
  for (i = 0; i < 12; i++)
    if (!Push(mystack, a[i])) {              // a[i]依次进顺序栈
      cout << "进栈失败！" << endl;
      return 0;
    }
  if (!GetTop(mystack, x)) {         // 取栈顶元素并赋值给x
    cout << "取栈顶元素失败！" << endl;
    return 0;
  }

  cout << "当前栈顶数据元素是：" << x << endl;
  cout << "当前顺序栈的长度是：" << Length(mystack) << endl;
  cout << "依次出栈的数据元素序列为：";
  while (!StackEmpty(mystack)) {    // 判栈是否非空
    if (!Pop(mystack, x)) {          // 栈顶元素出栈并赋值给x
      cout << "出栈失败！" << endl;
      return 0;
    }
    cout << x << ' ';
  }
  cout << endl;
  cout << "当前顺序栈的长度是：" << Length(mystack) << endl;
  cout << endl;
  DestroyStack(mystack);           // 销毁顺序栈
}