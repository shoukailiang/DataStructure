//
// Created by liang on 2019/9/21.
//
#include <iostream>

typedef int ElementType;

#include "SqQueue.h"

int main() {
  Queue Q;
  Q = CreateQueue(10);
  AddQ(Q, 3);
  printf("3入队\n");
  AddQ(Q, 5);
  printf("5入队\n");
  AddQ(Q, 11);
  printf("11入队\n");
  printf("%d出队\n", DeleteQ(Q));
  printf("%d出队\n", DeleteQ(Q));
  return 0;
}
