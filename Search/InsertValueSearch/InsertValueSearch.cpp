//
// Created by liang on 2019/8/17.
//
#include <iostream>

#define LENGTH 100
using namespace std;

/**
 * 编写插值查找算法，插值查找算法，也要求数组是有序的
 *
 * @param arr     数组
 * @param left    左边索引
 * @param right   右边索引
 * @param findVal 查找值
 * @return 如果找到，就返回对应的下标，如果没有找到，返回-1
 */
int insertValueSearch(int arr[], int left, int right, int findVal) {

  cout << "插值查找次数~~" << endl;

  //注意：findVal < arr[0]  和  findVal > arr[LENGTH - 1] 必须需要
  //否则我们得到的 mid 可能越界
  if (left > right || findVal < arr[0] || findVal > arr[LENGTH - 1]) {
    return -1;
  }
  // 求出mid, 自适应
  int mid = left + (right - left) * (findVal - arr[left]) / (arr[right] - arr[left]);
  int midVal = arr[mid];
  if (findVal > midVal) { // 说明应该向右边递归
    return insertValueSearch(arr, mid + 1, right, findVal);
  } else if (findVal < midVal) { // 说明向左递归查找
    return insertValueSearch(arr, left, mid - 1, findVal);
  } else {
    return mid;
  }
}

int main() {
  int arr[LENGTH];
  for (int i = 0; i < LENGTH; i++) {
    arr[i] = i + 1;
  }
  int index = insertValueSearch(arr, 0, LENGTH - 1, 1);
  cout << "索引位置：" << index << endl;
}
