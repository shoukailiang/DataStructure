//
// Created by liang on 2019/8/31.
//

#include <vector>
#include <string>
#include <iostream>

using namespace std;

//计算模式P的部分匹配值，保存在next数组中
void kmpNext(const string &P, vector<int> &next) {
  int i, j;
  int m = P.size();//模式字符串的长度
  next[0] = 0;//首字符的对称值肯定为0
  for (i = 1, j = 0; i < m; ++i) {//计算每一个位置的对称值

    //j总是用来记录上一个前缀的最大对称值
    while (j > 0 && P[i] != P[j]) {
      j = next[j - 1];//j将循环递减，值得注意的是next[j]<j总是成立
    }

    if (P[i] == P[j]) {
      j++;//增加j的唯一方法
    }

    next[i] = j;//获取最终值
  }
}


void KmpMatch(const string &T, const string &P, vector<int> &next) {
  int n, m;
  n = T.size();
  m = P.size();
  kmpNext(P, next);
  for (int i = 0, q = 0; i < n; ++i) {
    while (q > 0 && P[q] != T[i]) {
      q = next[q - 1];
    }
    if (P[q] == T[i]) {
      q++;
    }
    if (q == m) {
      cout << "模式文本的偏移为：" << (i - m + 1) << endl;
      q = next[q - 1];//寻找下一个匹配
    }
  }
}

int main() {
  vector<int> next(20, 0); //保存待搜索字符串的部分匹配表（所有前缀函数的对称值）
  string T = "BBC ABCDAB ABCDABCDABDE";//文本
  string P = "ABCDABD";//待搜索字符串
  cout << "文本字符串：" << T << endl;
  cout << "模式字符串：" << P << endl;
  KmpMatch(T, P, next);
  cout << "模式字符串的前缀函数表：" << endl;
  for (int i = 0; i < P.size(); i++) {
    cout << next[i] << " ";
  }
  cout << endl;
  return 0;
}


