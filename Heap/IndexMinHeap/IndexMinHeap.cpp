//
// Created by liang on 2019/8/15.
//


#include <iostream>
#include "IndexMinHeap.h"

using namespace std;

int main() {

  int n = 10;
  IndexMinHeap<int> indexMinHeap(n);
  int arr[] = {15, 17, 19, 13, 22, 16, 28, 30, 41, 61};
  for (int i = 0; i < n; i++) {
    indexMinHeap.insert(i, arr[i]);
  }

  // 输出最小值得index
  cout << indexMinHeap.getMinIndex() << endl;

  cout << "extractMax" << endl;
  while (!indexMinHeap.isEmpty())
    cout << indexMinHeap.extractMin() << " ";
  cout << endl;


  return 0;
}