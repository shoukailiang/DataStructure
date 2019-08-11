//
// Created by liang on 2019/8/11.
//

#include <iostream>

using namespace std;

template<typename T>
void insertionSort(T arr[], int n) {
  for (int i = 0; i < n; ++i) {
    // 方法一
//    for (int j = i; j > 0; --j) {
//      if (arr[j] < arr[j - 1]) {
//        swap(arr[j], arr[j - 1]);
//      } else {
//        break;
//      }
//    }
    T e = arr[i];            // 先copy一份
    int j; // j保存元素e应该插入的位置
    for (j = i; j > 0; --j) {
      if (arr[j - 1] > e) {
        arr[j] = arr[j - 1];
      }
    }
    arr[j] = e;
  }
}

int main() {
  int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  insertionSort(a, 10);
  for (int i = 0; i < 10; i++)
    cout << a[i] << " ";
  cout << endl;
}