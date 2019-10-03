//
// Created by liang on 2019/10/3.
//
#include<iostream>
#include<cstring>

#define MaxSize 1000
using namespace std;

#include "UnionFind.h"

int main() {
  SetType s[MaxSize];
  // 初始化数组，父结点全部指向 -1
  for (int i = 0; i < MaxSize; i++) {
    s[i].Data = i + 1;
    s[i].parent = -1;
  }
  cout << Find(s, 5) << endl;
  Union(s, 3, 5);
  cout << Find(s, 4) << endl;
  cout << Find(s, 3) << endl;
  Union(s, 1, 3);
  Union(s, 2, 4);
  Union(s, 8, 6);
  cout << Find(s, 6) << endl;
  cout << Find(s, 8) << endl;
  return 0;
}