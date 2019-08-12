//
// Created by liang on 2019/8/11.
//
#include <iostream>
#include <ctime>
#include "SparseGraph.h"

using namespace std;

int main() {

  int N = 20; // 20个节点
  int M = 100; // 边

  srand(time(NULL));


  // Sparse Graph
  SparseGraph g1(N, false);
  for (int i = 0; i < M; i++) {
    int a = rand() % N;
    int b = rand() % N;
    g1.addEdge(a, b);
  }
  // O(E)
  for (int v = 0; v < N; v++) {
    cout << v << " : ";
    SparseGraph::adjIterator adj(g1, v);
    for (int w = adj.begin(); !adj.end(); w = adj.next())
      cout << w << " ";
    cout << endl;
  }
}