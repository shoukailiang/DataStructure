//
// Created by liang on 2019/9/21.
//
typedef int ElementType;

#include <iostream>
#include "LinkStack.h"

int main(){
  Stack S;
  S = CreateStack();
  printf("5��ջ\n");
  Push(S,5);
  printf("7��ջ\n");
  Push(S,7);
  printf("66��ջ\n");
  Push(S,66);
  printf("%d��ջ\n",Pop(S));
  printf("%d��ջ\n",Pop(S));
  return 0;
}