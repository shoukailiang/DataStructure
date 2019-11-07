//
// Created by liang on 2019/11/7.
//
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
  int arr1[100] = { 0 }, arr2[100] = {0};
  int n, j,count=1,k,length=0;
  bool flag = true;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr1[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> arr2[i];
  }

  for (j = 1;  arr2[j - 1] <= arr2[j]; j++);

  count = j;

  for ( k = j; k < n; k++) {
    if (arr1[k] != arr2[k]) {
      break;
    }
  }

  if (n == k) {
    cout << "Insertion Sort\n";
    sort(arr2, arr2+count+1);
    cout << arr2[0];
    for (int i = 1; i < n; i++) {
      cout << " " << arr2[i] ;
    }
  }
  else {
    cout << "Merge Sort\n";
    for (length = 2; ; length *= 2) {
      for (int i = length; i < n; i+=length*2){
        if (arr2[i - 1] > arr2[i]) {
          flag = false;
          break;
        }
      }
      if (!flag) {
        length *= 2;
        break;
      }
    }
    for ( k = 0; k + length <= n; k += length) {
      sort(arr2 + k, arr2 + k + length);
    }
    sort(arr2 + k, arr2 + n);
    cout << arr2[0];
    for (int i = 1; i < n; i++) {
      cout <<" "<< arr2[i] ;
    }
  }
}
