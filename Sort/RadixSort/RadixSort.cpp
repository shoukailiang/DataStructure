//
// Created by liang on 2019/8/17.
//

#include <iostream>

using namespace std;


void RadixSort(int arr[], int size) {
  //1. 得到数组中最大的数的位数
  int max = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  //得到最大数是几位数
  int length = 0;
  while (max > 1) {
    length++;
    max /= 10;
  }
  //定义一个二维数组，表示10个桶, 每个桶就是一个一维数组
  //说明
  //1. 二维数组包含10个一维数组
  //2. 为了防止在放入数的时候，数据溢出，则每个一维数组(桶)，大小定为size
  //3. 明确，基数排序是使用空间换时间的经典算法
  int bucket[10][size];
  //为了记录每个桶中，实际存放了多少个数据,我们定义一个一维数组来记录各个桶的每次放入的数据个数
  //可以这里理解
  //比如：bucketElementCounts[0] , 记录的就是  bucket[0] 桶的放入数据个数
  int bucketElementCounts[10] = { 0 };
  for (int i = 0, n = 1; i < length; ++i, n *= 10) {
    for (int j = 0; j < size; ++j) {
      //取出每个元素的对应位的值
      int digitOfElement = arr[j] / n % 10;
      //放入到对应的桶中
      bucket[digitOfElement][bucketElementCounts[digitOfElement]] = arr[j];
      bucketElementCounts[digitOfElement]++;
    }

    //按照这个桶的顺序(一维数组的下标依次取出数据，放入原来数组)
    int index = 0;
    //遍历每一桶，并将桶中是数据，放入到原数组
    for (int k = 0; k < 10; k++) {
      //如果桶中，有数据，我们才放入到原数组
      if (bucketElementCounts[k] != 0) {
        //循环该桶即第k个桶(即第k个一维数组), 放入
        for (int l = 0; l < bucketElementCounts[k]; l++) {
          //取出元素放入到arr
          arr[index++] = bucket[k][l];
        }
      }
      //第i+1轮处理后，需要将每个 bucketElementCounts[k] = 0
      bucketElementCounts[k] = 0;
    }
  }
}


int main() {
  int a[] = {53, 3, 542, 748, 14, 214};
  int size = sizeof(a)/ sizeof(a[0]);
  RadixSort(a, size);
  for (int i = 0; i < size; i++)
    cout << a[i] << " ";
  cout << endl;
}
