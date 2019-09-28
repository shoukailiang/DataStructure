//
// Created by liang on 2019/9/21.
//
typedef int ElementType;

#include <iostream>
#include "LinkStack.h"

int main(){
  Stack S;
  S = CreateStack();
  printf("5入栈\n");
  Push(S,5);
  printf("7入栈\n");
  Push(S,7);
  printf("66入栈\n");
  Push(S,66);
  printf("%d出栈\n",Pop(S));
  printf("%d出栈\n",Pop(S));
  return 0;
}