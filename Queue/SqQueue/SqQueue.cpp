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
  printf("3���\n");
  AddQ(Q, 5);
  printf("5���\n");
  AddQ(Q, 11);
  printf("11���\n");
  printf("%d����\n", DeleteQ(Q));
  printf("%d����\n", DeleteQ(Q));
  return 0;
}
