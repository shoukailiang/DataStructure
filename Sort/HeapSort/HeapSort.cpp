//
// Created by liang on 2019/8/14.
//

#include <iostream>
#include "../../Heap/MaxHeap/MaxHeap.h"

using namespace std;

/**
 * heapSort2比heapSort1性能更好
 * @tparam T
 * @param arr
 * @param n
 */
template<typename T>
void heapSort2(T arr[], int n) {

  MaxHeap<T> maxheap = MaxHeap<T>(arr, n);
  for (int i = n - 1; i >= 0; i--)
    arr[i] = maxheap.extractMax();

}


template<typename T>
void heapSort1(T arr[], int n) {

  MaxHeap<T> maxheap = MaxHeap<T>(n);
  for (int i = 0; i < n; i++)
    maxheap.insert(arr[i]);

  for (int i = n - 1; i >= 0; i--)
    arr[i] = maxheap.extractMax();

}

int main() {
  int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  heapSort1(a, 10);
  for (int i = 0; i < 10; i++)
    cout << a[i] << " ";
  cout << endl;
}

