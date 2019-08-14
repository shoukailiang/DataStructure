//
// Created by liang on 2019/8/14.
//

/**
 * 判断是否是回文
 */

#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main() {
  stack<char> stk;
  string s;
  cin >> s;
  int len = s.length();
  int mid = len / 2;
  for (int i = 0; i < mid; i++) {
    stk.push(s[i]);
  }
  for (int i = (len % 2 == 0 ? mid : mid + 1); i < len; i++) {
    if (s[i] != stk.top()) {
      cout << "不是回文" << endl;
      return 1;
    }
    stk.pop(); //出栈
  }
  cout << "是回文" << endl;
  return 0;
}