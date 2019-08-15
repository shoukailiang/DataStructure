//
// Created by liang on 2019/8/15.
//

#include <iostream>
#include "UnionFind.h"

using namespace std;

int main() {
  UnionFind unionFind(10);

  cout << unionFind.find(1) << endl;
  unionFind.isConnected(2, 4);
}
