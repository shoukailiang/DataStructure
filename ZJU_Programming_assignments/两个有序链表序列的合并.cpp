//
// Created by liang on 2019/10/4.
//
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
  ElementType Data;
  PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
  List L1, L2, L;
  L1 = Read();
  L2 = Read();
  L = Merge(L1, L2);
  Print(L);
  Print(L1);
  Print(L2);
  return 0;
}

/* 你的代码将被嵌在这里 */
List Merge( List L1, List L2 ){
  List a,b,c,x;
  x = (List)malloc(sizeof(struct Node));
  a=L1->Next;
  b= L2->Next;
  c=x;
  while(a&&b){
    if(a->Data<=b->Data){
      c->Next=a;
      c=a;
      a=a->Next;
    }else{
      c->Next=b;
      c=b;
      b=b->Next;
    }
  }
  // 循环结束后，有一个链表有存在多余的
  c->Next=a?a:b;
  L1->Next=NULL;
  L2->Next=NULL;
  return x;
}
