//
// Created by liang on 2019/8/10.
//

#include <iostream>

using namespace std;

/**
 * 二分查找法,在有序数组arr中,查找target
 * @tparam T
 * @param arr
 * @param n
 * @param target
 * @return 如果找到target,返回相应的索引index,如果没有找到target,返回-1
 */
template<typename T>
int binarySearch(T arr[], int n, T target) {
  // 在arr[l...r]之中查找target
  int l = 0, r = n - 1;

  while (l <= r) {
    // int mid = (l + r) / 2;
    int mid = l + (r - l) / 2;
    if (target == arr[mid]) {
      return mid;
    }
    if (target < arr[mid]) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }

  }
  return -1;
}


// 用递归的方式写二分查找法
template<typename T>
int __binarySearch2(T arr[], int l, int r, T target) {
  if (l > r) {
    return -1;
  }
  int mid = (l + r) / 2;
  if (arr[mid] == target) {
    return mid;
  } else if (arr[mid] > target) {
    return __binarySearch2(arr, 0, mid - 1, target);
  } else {
    return __binarySearch2(arr, mid + 1, r, target);
  }
}

template<typename T>
int binarySearch2(T arr[], int n, T target) {
  return __binarySearch2(arr, 0, n - 1, target);
}

int main() {
  int a[] = {1, 2, 3, 4, 5, 6};
  cout << binarySearch(a, 6, 1) << endl;
  cout << binarySearch2(a, 6, 1) << endl;
}