//
// Created by liang on 2019/8/14.
//

#include <iostream>
#include "IndexMaxHeap.h"

using namespace std;

int main() {

  int n = 10;
  IndexMaxHeap<int> indexMaxHeap(n);
  int arr[] = {15, 17, 19, 13, 22, 16, 28, 30, 41, 61};
  for (int i = 0; i < n; i++) {
    indexMaxHeap.insert(i, arr[i]);
  }

  // 输出最大值得index
  cout << indexMaxHeap.getMaxIndex() << endl;

  cout << "extractMax" << endl;
  while (!indexMaxHeap.isEmpty())
    cout << indexMaxHeap.extractMax() << " ";
  cout << endl;


  return 0;
}