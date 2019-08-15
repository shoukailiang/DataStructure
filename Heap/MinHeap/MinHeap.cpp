//
// Created by liang on 2019/8/15.
//

#include <iostream>
#include <ctime>
#include "MinHeap.h"

using namespace std;


int main() {
  MinHeap<int> minHeap = MinHeap<int>(100);

  srand(time(NULL));
  for (int i = 0; i < 63; i++) {
    minHeap.insert(rand() % 100);
  }


  cout << "extractMin" << endl;
  while (!minHeap.isEmpty())
    cout << minHeap.extractMin() << " ";
  cout << endl;

  return 0;
}
