//
// Created by liang on 2019/8/14.
//

/**
 * ����ת��
 */
#include <iostream>
#include <stack>

using namespace std;

int main() {
  int b, n, e;
  cout << "����������ת���Ľ��Ƽ���ֵ��" << endl;
  cin >> b >> n;
  cout << "��ֵ" << n << "��" << b << "����Ϊ��" << endl;
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

