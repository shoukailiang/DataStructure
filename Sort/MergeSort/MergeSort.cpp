//
// Created by liang on 2019/8/13.
//
#include <iostream>

using namespace std;

// 将arr[l...mid]和arr[mid+1...r]两部分进行归并
template<typename T>
void __merge(T arr[], int l, int mid, int r) {

  T temp[r - l + 1];
  int i = l; // 初始化i, 左边有序序列的初始索引
  int j = mid + 1; //初始化j, 右边有序序列的初始索引
  int t = 0; // 指向temp数组的当前索引

  //(一)
  //先把左右两边(有序)的数据按照规则填充到temp数组
  //直到左右两边的有序序列，有一边处理完毕为止
  while (i <= mid && j <= r) {//继续
    //如果左边的有序序列的当前元素，小于等于右边有序序列的当前元素
    //即将左边的当前元素，填充到 temp数组
    //然后 t++, i++
    if (arr[i] <= arr[j]) {
      temp[t] = arr[i];
      t += 1;
      i += 1;
    } else { //反之,将右边有序序列的当前元素，填充到temp数组
      temp[t] = arr[j];
      t += 1;
      j += 1;
    }
  }

  //(二)
  //把有剩余数据的一边的数据依次全部填充到temp
  while (i <= mid) { //左边的有序序列还有剩余的元素，就全部填充到temp
    temp[t] = arr[i];
    t += 1;
    i += 1;
  }

  while (j <= r) { //右边的有序序列还有剩余的元素，就全部填充到temp
    temp[t] = arr[j];
    t += 1;
    j += 1;
  }
  //(三)
  //将temp数组的元素拷贝到arr
  //注意，并不是每次都拷贝所有
  t = 0;
  int tempLeft = l; //
  //第一次合并 tempLeft = 0 , right = 1 //  tempLeft = 2  right = 3 // tL=0 ri=3
  //最后一次 tempLeft = 0  right = 7
  while (tempLeft <= r) {
    arr[tempLeft] = temp[t];
    t += 1;
    tempLeft += 1;
  }
}

// 递归使用归并排序,对arr[l...r]的范围进行排序
template<typename T>
void __mergeSort(T arr[], int l, int r) {
  if (l >= r) {
    return;
  }
  int mid = (l + r) / 2;
  __mergeSort(arr, l, mid);
  __mergeSort(arr, mid + 1, r);
  __merge(arr, l, mid, r);
}

template<typename T>
void __merge(T arr[], int n) {
  __mergeSort(arr, 0, n - 1);
}

int main() {
  // 测试模板函数，传入整型数组
  int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  __merge(a, 10);
  for (int i = 0; i < 10; i++)
    cout << a[i] << " ";
  cout << endl;
}