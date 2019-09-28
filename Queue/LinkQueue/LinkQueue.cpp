//
// Created by liang on 2019/9/21.
//

typedef int ElementType;

#include <iostream>
#include "LinkQueue.h"

int main() {
  Queue Q;
  Q = CreateQueue();
  printf("入队5\n");
  AddQ(Q, 5);
  printf("入队4\n");
  AddQ(Q, 4);
  printf("入队3\n");
  AddQ(Q, 3);
  printf("出队%d\n", DeleteQ(Q));
  printf("出队%d\n", DeleteQ(Q));
  printf("出队%d\n", DeleteQ(Q));
  printf("%d\n", DeleteQ(Q));
  return 0;
}