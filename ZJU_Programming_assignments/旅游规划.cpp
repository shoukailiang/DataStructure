//
// Created by liang on 2019/11/1.
//
#include <cstring>
#include <cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
//Dijkstra算法
#define MaxvertexNum 500
#define INFINITY 65535
#define Vertex int
#define WeightType int
#define ERROR -1

typedef struct ENode* Edge;
struct ENode {
  Vertex V1, V2;
  WeightType Dist, Cost;
};

typedef struct GNode* MGraph;//邻接矩阵
struct GNode {
  int Nv;
  int Ne;
  WeightType Dist[MaxvertexNum][MaxvertexNum];//distance
  WeightType Cost[MaxvertexNum][MaxvertexNum];
  Vertex S, D;//起点和终点
};

MGraph CreatGraph(int Nv) {
  Vertex V, W;
  MGraph Graph = (MGraph)malloc(sizeof(struct GNode));
  Graph->Nv = Nv;
  Graph->Ne = 0;
  for (V = 0; V < Graph->Nv; V++)
    for (W = 0; W < Graph->Nv; W++)
      Graph->Dist[V][W] = Graph->Dist[W][V] = INFINITY;
  return Graph;
}
void InsertEdge(MGraph Graph, Edge E) {
  //无向图，需要插入<V1,V2>和<V2,V1>
  Graph->Dist[E->V1][E->V2] = E->Dist;
  Graph->Cost[E->V1][E->V2] = E->Cost;
  Graph->Dist[E->V2][E->V1] = E->Dist;
  Graph->Cost[E->V2][E->V1] = E->Cost;
}
MGraph BuildGraph() {
  MGraph Graph;
  int Nv;
  Edge E;

  cin >> Nv;
  Graph = CreatGraph(Nv);

  cin >> Graph->Ne;
  cin >> Graph->S >> Graph->D;
  if (Graph->Ne != 0) {
    E = (Edge)malloc(sizeof(struct ENode));
    for (int i = 0; i < Graph->Ne; i++) {
      cin >> E->V1 >> E->V2 >> E->Dist >> E->Cost;
      InsertEdge(Graph, E);
    }
  }
  return Graph;
}
//寻找未被收录顶点中的dist最小者
Vertex FindMinDist(MGraph Graph, int dist[], int collected[]) {
  Vertex MinV, V;
  int MinDist = INFINITY;
  for (V = 0; V < Graph->Nv; V++) {
    if (collected[V] == false && dist[V] < MinDist) {
      MinDist = dist[V];
      MinV = V;
    }
  }
  if (MinDist < INFINITY)
    return MinV;
  else return ERROR;
}


//迪杰斯特拉算法
void Dijkstra(MGraph Graph, int dist[], int cost[], Vertex S) {
  int collected[MaxvertexNum];
  Vertex V, W;
  //初始化，不相邻的边设置为INFINITY,collected表示遍历
  for (V = 0; V < Graph->Nv; V++) {
    dist[V] = Graph->Dist[S][V];
    cost[V] = Graph->Cost[S][V];
    collected[V] = false;
  }
  dist[S] = cost[S] = 0;
  collected[S] = true;
  while (1) {
    V = FindMinDist(Graph, dist, collected);
    if (V == ERROR)
      break;
    //贪心原则
    collected[V] = true;
    for (W = 0; W < Graph->Nv; W++)
      if (collected[W] == false && Graph->Dist[V][W] < INFINITY) {
        if (dist[V] + Graph->Dist[V][W] < dist[W]) {//dist是W点到起点的最小距离，始终保持最小，实时更新
          dist[W] = dist[V] + Graph->Dist[V][W];
          cost[W] = cost[V] + Graph->Cost[V][W];
        }
        else if (dist[V] + Graph->Dist[V][W] == dist[W] && cost[V] + Graph->Cost[V][W] < cost[W])
          cost[W] = cost[V] + Graph->Cost[V][W];
      }
  }

}
int main() {
  int* dist, * cost;
  MGraph Graph = BuildGraph();
  dist = (int*)malloc(sizeof(int) * Graph->Nv);
  cost = (int*)malloc(sizeof(int) * Graph->Nv);
  Dijkstra(Graph, dist, cost, Graph->S);
  cout << dist[Graph->D] << " " << cost[Graph->D];
}
