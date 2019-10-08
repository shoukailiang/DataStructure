//
// Created by liang on 2019/10/4.
//
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
  ElementType Data[MAXSIZE];
  Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
  List L;
  ElementType X;
  Position P;

  L = ReadInput();
  scanf("%d", &X);
  P = BinarySearch( L, X );
  printf("%d\n", P);

  return 0;
}

/* 你的代码将被嵌在这里 */
Position BinarySearch( List L, ElementType X ){
  Position left= 1, right=L->Last;
  while(left<=right){
    Position mid =(left+right)/2;
    if(L->Data[mid]>X){
      right=mid-1;
    }else if(L->Data[mid]<X){
      left=mid+1;
    }else{
      return mid;
    }
  }
  return NotFound;
}