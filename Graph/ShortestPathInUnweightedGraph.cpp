//
// Created by liang on 2019/10/26.
//

#include<iostream>
#include<cstdlib>
#include<queue>
#include<stack>
#define Init -1
#define MaxVertex  100
int path[MaxVertex];  // �洢·�� ��s(ԭ��)��w·�Ͼ�����ĳ������
int dist[MaxVertex];  // �洢·������,s(ԭ��)��w�����·��
int G[MaxVertex][MaxVertex]; // ͼ
int Ne;  // ������
int Nv;  // ��
typedef int Vertex;
using namespace std;


void build(){
  int v1,v2;
  // ��ʼ����
  cin>>Nv;
  for(int i=1;i<=Nv;i++)
    for(int j=1;j<=Nv;j++)
      G[i][j] = 0;
  // ��ʼ��·��
  for(int i=1;i<=Nv;i++)
    path[i] = Init;
  // ��ʼ��·������
  for(int i=1;i<=Nv;i++)
    dist[i] = Init;
  // ��ʼ����
  cin>>Ne;
  for(int i=0;i<Ne;i++){
    cin>>v1>>v2;
    G[v1][v2] = 1; // ����ͼ
  }
}

void Unweighted(Vertex v){
  queue<Vertex> q;
  dist[v] = 0;  // ���Լ��ľ����� 0
  Vertex w;
  q.push(v);
  while(!q.empty()){
    w = q.front();
    q.pop();
    for(int i=1;i<=Nv;i++)
      // ���û�����ʹ�������ͨ
      if(dist[i]==Init && G[w][i]){
        dist[i] = dist[w]+1;  // ����һ���ľ��� + 1
        path[i] = w;  // w ����һ��Ҫ��·������һ��·��
        q.push(i);
      }
  }
}

// ��ȡ·��
void getTail(Vertex v){
  for(int i=1;i<=Nv;i++){
    if(i==v)
      continue;
    stack<Vertex> s;
    cout<<v<<"��"<<i<<"����̾����ǣ�"<<dist[i];
    Vertex w = i;
    // ��û������ʼ���ǰһֱ��ѭ��
    while(path[w]!=Init){
      s.push(w);  // ��ջ
      w = path[w];
    }
    // ���������ջԪ�أ��õ�·��
    cout<<"    ��·��Ϊ��";
    if(v != i)
      cout<<v;
    while(!s.empty()){
      // ���ջ��Ԫ��
      cout<<"��"<<s.top();
      s.pop(); // ��ջ
    }
    cout<<endl;
  }
}


int main(){
  build();
  Unweighted(3);
  getTail(3);
  return 0;
}

