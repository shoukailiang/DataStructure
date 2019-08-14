//
// Created by liang on 2019/8/13.
//

#include <iostream>

using namespace std;

//源自啊哈算法
void quickSort(int *arr, int left, int right) {
  int i, j, t, temp;
  if (left > right)
    return;
  temp = arr[left]; //temp中存的就是基准数
  i = left;
  j = right;
  while (i != j) { //顺序很重要，要先从右边开始找
    while (arr[j] >= temp && i < j)
      j--;
    while (arr[i] <= temp && i < j)//再找右边的
      i++;
    if (i < j)//交换两个数在数组中的位置
    {
      t = arr[i];
      arr[i] = arr[j];
      arr[j] = t;
    }
  }
  //最终将基准数归位
  arr[left] = arr[i];
  arr[i] = temp;
  quickSort(arr, left, i - 1);//继续处理左边的，这里是一个递归的过程
  quickSort(arr, i + 1, right);//继续处理右边的 ，这里是一个递归的过程
}

int main() {
  // 测试模板函数，传入整型数组
  int a[10] = {10, 7, 6, 4, 3, 2, 5, 1, 9, 8,};
  quickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
  for (int i = 0; i < 10; i++)
    cout << a[i] << " ";
  cout << endl;
}
