//
// Created by liang on 2019/8/25.
//
#include <iostream>
#include "../DenseGraph/DenseGraph.h"
#include "../SparseGraph/SparseGraph.h"
#include "ReadGraph.h"

using namespace std;

int main() {

  string filename = "C:\\Users\\liang\\OneDrive\\code\\Data Structure and Algorithms\\DataStructure\\Graph\\testG1.txt";

  SparseGraph g1(13, false);
  ReadGraph<SparseGraph> readGraph1(g1, filename);
  g1.show();

  cout << endl;

  DenseGraph g2(13, false);
  ReadGraph<DenseGraph> readGraph2(g2, filename);
  g2.show();
  return 0;
}