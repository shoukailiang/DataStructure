//
// Created by liang on 2019/8/17.
//
#include <iostream>

#define LENGTH 100
using namespace std;

/**
 * ��д��ֵ�����㷨����ֵ�����㷨��ҲҪ�������������
 *
 * @param arr     ����
 * @param left    �������
 * @param right   �ұ�����
 * @param findVal ����ֵ
 * @return ����ҵ����ͷ��ض�Ӧ���±꣬���û���ҵ�������-1
 */
int insertValueSearch(int arr[], int left, int right, int findVal) {

  cout << "��ֵ���Ҵ���~~" << endl;

  //ע�⣺findVal < arr[0]  ��  findVal > arr[LENGTH - 1] ������Ҫ
  //�������ǵõ��� mid ����Խ��
  if (left > right || findVal < arr[0] || findVal > arr[LENGTH - 1]) {
    return -1;
  }
  // ���mid, ����Ӧ
  int mid = left + (right - left) * (findVal - arr[left]) / (arr[right] - arr[left]);
  int midVal = arr[mid];
  if (findVal > midVal) { // ˵��Ӧ�����ұߵݹ�
    return insertValueSearch(arr, mid + 1, right, findVal);
  } else if (findVal < midVal) { // ˵������ݹ����
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
  cout << "����λ�ã�" << index << endl;
}
