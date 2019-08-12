//
// Created by liang on 2019/8/12.
//

#include <iostream>

using namespace std;

//交换法
void shellSort(int *arr, int n) {
  for (int gap = n / 2; gap > 0; gap / 2) {
    for (int i = gap; i < n; i++) {
      for (int j = i - gap; j >= 0; j -= gap) {
        if (arr[j] > arr[j + gap]) {
          swap(arr[j], arr[j + gap]);
        }
      }
    }
  }
}

//移动法- 性能高点
void shellSort2(int *arr, int n) {
  for (int gap = n / 2; gap > 0; gap / 2) {
    for (int i = gap; i < n; i++) {
      int j = i;
      int temp = arr[j];
      if (arr[j] < arr[j - gap]) {
        while (j - gap >= 0 && temp < arr[j - gap]) {
          //移动
          arr[j] = arr[j - gap];
          j -= gap;
        }
        //当退出while后，就给temp找到插入的位置
        arr[j] = temp;
      }
    }
  }
}


int main() {
  // 测试模板函数，传入整型数组
  int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  shellSort(a, 10);
  for (int i = 0; i < 10; i++)
    cout << a[i] << " ";
  cout << endl;
}