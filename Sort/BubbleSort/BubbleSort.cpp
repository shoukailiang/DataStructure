//
// Created by liang on 2019/8/11.
//

#include <iostream>

using namespace std;

template<typename T>
void bubbleSort(T arr[], int n) {
  bool flag = false;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < n - 1 - i; ++j) {
      if (arr[j] > arr[j + 1]) {
        flag = true;
        swap(arr[j], arr[j + 1]);
      }
    }
    if (!flag) { // 在一趟排序中，一次交换都没有发生过
      break;
    } else {
      flag = false; // 重置flag, 进行下次判断
    }
  }

}

int main() {
  int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  bubbleSort(a, 10);
  for (int i = 0; i < 10; i++)
    cout << a[i] << " ";
  cout << endl;
}