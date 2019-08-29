//
// Created by liang on 2019/8/29.
//
#include <iostream>

using namespace std;

int violenceMatch(string str1, string str2) {

  int s1Len = str1.size();
  int s2Len = str2.size();

  int i = 0; // i索引指向s1
  int j = 0; // j索引指向s2
  while (i < s1Len && j < s2Len) {// 保证匹配时，不越界

    if (str1[i] == str2[j]) {//匹配ok
      i++;
      j++;
    } else { //没有匹配成功
      //如果失配（即str1[i]! = str2[j]），令i = i - (j - 1)，j = 0。
      i = i - (j - 1);
      j = 0;
    }
  }

  //判断是否匹配成功
  if (j == s2Len) {
    return i - j;
  } else {
    return -1;
  }
}

int main() {
  string str1 = "abcdabc123";
  string str2 = "abc123";
  int index = violenceMatch(str1, str2);
  cout << "index=" << index;
}

