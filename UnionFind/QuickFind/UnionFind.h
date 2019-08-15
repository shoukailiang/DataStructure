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
  int *id;
  int count;

public:
  UnionFind(int n) {
    count = n;
    id = new int[n];
    for (int i = 0; i < n; i++)
      id[i] = i;
  }

  ~UnionFind() {
    delete[] id;
  }

  int find(int p) {
    assert(p >= 0 && p < count);
    return id[p];
  }

  bool isConnected(int p, int q) {
    return find(p) == find(q);
  }

  void unionElements(int p, int q) {

    int pID = find(p);
    int qID = find(q);

    if (pID == qID)
      return;

    for (int i = 0; i < count; i++)
      if (id[i] == pID)
        id[i] = qID;
  }
};


#endif //DATASTRUCTURE_UNIONFIND_H
