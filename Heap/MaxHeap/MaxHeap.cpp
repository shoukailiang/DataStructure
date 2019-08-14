//
// Created by liang on 2019/8/14.
//

#include <iostream>
#include <ctime>
#include "MaxHeap.h"

using namespace std;



int main() {
  MaxHeap<int> maxheap = MaxHeap<int>(100);

  srand(time(NULL));
  for (int i = 0; i < 63; i++) {
    maxheap.insert(rand() % 100);
  }

  maxheap.testPrint();

  cout << "extractMax"<<endl;
  while (!maxheap.isEmpty())
    cout << maxheap.extractMax() << " ";
  cout << endl;

  return 0;
}
