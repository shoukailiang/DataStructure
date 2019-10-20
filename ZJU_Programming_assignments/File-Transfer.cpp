//
// Created by liang on 2019/10/18.
//
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000                  /* 集合最大元素个数 */
typedef int ElementType;           /* 默认元素可以用非负整数表示 */
typedef int SetName;               /* 默认用根结点的下标作为集合名称 */
typedef ElementType SetType[MAXN]; /* 假设集合元素下标从0开始 */

void Union( SetType S, SetName Root1, SetName Root2 )
{
  // 如果根结点的下标不同，说明不是一个集合
  /* 保证小集合并入大集合 */
  if ( S[Root2] < S[Root1] ) { /* 如果集合2比较大 */
    S[Root2] += S[Root1];     /* 集合1并入集合2  */
    S[Root1] = Root2;
  }
  else {                         /* 如果集合1比较大 */
    S[Root1] += S[Root2];     /* 集合2并入集合1  */
    S[Root2] = Root1;
  }
}

SetName Find( SetType S, ElementType X )
{ /* 默认集合元素全部初始化为-1 */
  if ( S[X] < 0 ) /* 找到集合的根 */
    return X;
  else
    return S[X] = Find( S, S[X] ); /* 路径压缩 */
}


void Initialization(SetType S, int n)
{
  for (int i = 0; i < n; i++)
  {
    S[i] = -1;
  }
}

void Input_connection(SetType S)
{
  ElementType u, v;
  SetName Root1, Root2;
  scanf("%d %d\n", &u, &v);
  Root1 = Find(S, u - 1);
  Root2 = Find(S, v - 1);
  if (Root1 != Root2)
    Union(S, Root1, Root2);
}

void Check_connection(SetType S)
{
  ElementType u, v;
  SetName Root1, Root2;
  scanf("%d %d\n", &u, &v);
  Root1 = Find(S, u - 1);
  Root2 = Find(S, v - 1);
  if (Root1 == Root2)
    printf("yes\n");
  else
    printf("no\n");
}

void Check_network(SetType S, int n)
{
  int i, counter = 0;
  for (i = 0; i < n; i++)
  {
    if (S[i] < 0)
      counter++;
  }
  if (counter == 1)
    printf("The network is connected.\n");
  else
    printf("There are %d components.\n");
}

int main()
{
  SetType S;
  int n;
  char in;
  scanf("%d\n", &n);
  Initialization(S, n);
  do
  {
    scanf("%c", &in);
    switch (in)
    {
      case 'I':
        Input_connection(S);
        break;
      case 'C':
        Check_connection(S);
        break;
      case 'S':
        Check_network(S, n);
        break;
    }
  } while (in != 'S');
  return 0;
}


