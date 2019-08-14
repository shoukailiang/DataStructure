//
// Created by liang on 2019/8/14.
//

/**
 * 进制转换
 */
#include <iostream>
#include <stack>

using namespace std;

int main() {
  int b, n, e;
  cout << "请输入数制转换的进制及数值：" << endl;
  cin >> b >> n;
  cout << "数值" << n << "的" << b << "进制为：" << endl;
  stack<int> stk;
  while (n) {
    stk.push(n % b);
    n /= b;
  }
  while (!stk.empty()) {
    cout << stk.top();
    stk.pop();
  }
  return 0;
}

