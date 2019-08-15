//
// Created by liang on 2019/8/15.
//

#ifndef DATASTRUCTURE_UNIONFIND_H
#define DATASTRUCTURE_UNIONFIND_H


#include <iostream>
#include <cassert>

using namespace std;


class UnionFind {

private:
  int *parent;
  int *sz; // sz[i]表示以i为根的集合中元素个数，目的是合并的时候减少层数，提高效率
  int count;

public:
  UnionFind(int count) {
    parent = new int[count];
    sz = new int[count];
    this->count = count;
    for (int i = 0; i < count; i++) {
      parent[i] = i;
      sz[i] = 1; // 刚开始只有自身
    }
  }

  ~UnionFind() {
    delete[] parent;
    delete[] sz;
  }

  int find(int p) {
    assert(p >= 0 && p < count);
    while (p != parent[p])
      p = parent[p];
    return p;
  }

  bool isConnected(int p, int q) {
    return find(p) == find(q);
  }

  void unionElements(int p, int q) {

    int pRoot = find(p);
    int qRoot = find(q);

    if (pRoot == qRoot)
      return;

    if (sz[pRoot] < sz[qRoot]) {   // size少的合并到多的
      parent[pRoot] = qRoot;
      sz[qRoot] += sz[pRoot];
    } else {
      parent[qRoot] = pRoot;
      sz[pRoot] += sz[qRoot];
    }
  }
};

#endif //DATASTRUCTURE_UNIONFIND_H
