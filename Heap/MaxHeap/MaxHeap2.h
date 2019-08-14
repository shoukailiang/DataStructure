//
// Created by liang on 2019/8/14.
//

#ifndef DATASTRUCTURE_MAXHEAP2_H
#define DATASTRUCTURE_MAXHEAP2_H

#include <algorithm>
#include <cassert>
#include <cmath>

using namespace std;

/**
 * 用数组来实现最大堆，从数组下标0开始
 * @tparam Item
 */
template<typename Item>
class MaxHeap {
private:
  Item *data;
  int count;
  int capacity;

  // 将插入的元素上浮，和父节点相比
  void shiftUp(int k) {
    while (k > 0 && data[(k - 1) / 2] < data[k]) {
      swap(data[(k - 1) / 2], data[k]);
      k /= 2;
    }
  }

  void shiftDown(int k) {
    while (2 * k + 1 <= count) {  // 2*k+1为左边的节点
      int j = 2 * k + 1; // 在此轮循环中,data[k]和data[j]交换位置
      if (j + 1 <= count && data[j + 1] > data[j]) {//j+1为右边的
        j++;
      }
      // data[j] 是 data[2*k]和data[2*k+1]中的最大值

      if (data[k] >= data[j]) break;
      swap(data[k], data[j]);
      k = j;
    }
  }


public:
  MaxHeap(int capacity) {
    data = new Item[capacity];
    count = 0;
    this->capacity = capacity;
  }

  MaxHeap(Item arr[], int n) {
    data = new Item[n];
    capacity = n;
    // heapify
    for (int i = 0; i < n; i++)
      data[i] = arr[i];
    count = n - 1;   // 数组从0开始

    for (int i = count / 2; i >= 0; i--)
      shiftDown(i);
  }

  ~MaxHeap() {
    delete[] data;
  }

  int size() {
    return count;
  }

  bool isEmpty() {
    return count == 0;
  }

  void insert(Item item) {
    assert(count <= capacity);
    data[count] = item;
    count++;
    shiftUp(count);
  }

  Item extractMax() {
    assert(count > 0);
    Item ret = data[0];

    swap(data[0], data[count]);
    count--;
    shiftDown(0);

    return ret;
  }

  Item getMax() {
    assert(count >= 0);
    return data[0];
  }
};


#endif //DATASTRUCTURE_MAXHEAP2_H
