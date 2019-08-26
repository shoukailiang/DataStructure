//
// Created by liang on 2019/8/26.
//

#include <iostream>
#include "../SparseGraph/SparseGraph.h"
#include "../DenseGraph/DenseGraph.h"
#include "../ReadGraph/ReadGraph.h"
#include "Path.h"
#include "ShortestPath.h"

using namespace std;


int main() {

  string filename = "C:\\Users\\liang\\OneDrive\\code\\Data Structure and Algorithms\\DataStructure\\Graph\\testG2.txt";
  SparseGraph g = SparseGraph(7, false);
  ReadGraph<SparseGraph> readGraph(g, filename);
  g.show();
  cout << endl;

  Path<SparseGraph> dfs(g, 0);
  cout << "DFS : ";
  dfs.showPath(6);

  ShortestPath<SparseGraph> bfs(g, 0);
  cout << "BFS : ";
  bfs.showPath(6);

  return 0;
}