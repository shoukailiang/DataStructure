//
// Created by liang on 2019/8/11.
//

#ifndef DATASTRUCTURE_DENSEGRAPH_H
#define DATASTRUCTURE_DENSEGRAPH_H


#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 稠密图 - 邻接矩阵

class DenseGraph {
private:
  int n, m;        // n点数，m边数
  bool directed;   // 是否有方向
  vector<vector<bool>> g;  // 二维矩阵，true代表有这个边，false代表没
public:
  DenseGraph(int n, bool directed) {
    this->n = n;
    this->m = 0;
    this->directed = directed;
    for (int i = 0; i < n; i++)
      g.push_back(vector<bool>(n, false));// n*n 的矩阵  都是false
  }

  ~DenseGraph() {

  }

  int V() { return n; }

  int E() { return m; }

  void addEdge(int v, int w) {
    // 判断是否越界
    assert(v >= 0 && v < n);
    assert(w >= 0 && w < n);

    if (hasEdge(v, w))
      return;
    // 表示这有一条边
    g[v][w] = true;
    if (!directed)   // 如果是无向图的话
      g[w][v] = true;

    m++;
  }

  // 判断v和w之间是否有一条边
  bool hasEdge(int v, int w) {
    assert(v >= 0 && v < n);
    assert(w >= 0 && w < n);
    return g[v][w];
  }

  void show() {

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        cout << g[i][j] << "\t";
      cout << endl;
    }
  }

  class adjIterator {
  private:
    DenseGraph &G;
    int v;
    int index;
  public:
    adjIterator(DenseGraph &graph, int v) : G(graph) {
      this->v = v;
      this->index = -1;
    }

    int begin() {

      index = -1;
      return next();
    }

    int next() {
      for (index += 1; index < G.V(); index++)
        if (G.g[v][index])
          return index;
      return -1;
    }

    bool end() {
      return index >= G.V();
    }
  };
};


#endif //DATASTRUCTURE_DENSEGRAPH_H
