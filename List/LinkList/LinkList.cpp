//
// Created by liang on 2019/9/20.
//
#include <iostream>

typedef int ElementType;

#include "LinkList.h"

int main(){
  List L = MakeEmpty();
  Print(L);
  Insert(L,11,1);
  Insert(L,25,1);
  Insert(L,33,2);
  Insert(L,77,3);
  Print(L);
  printf("当前链表长度为：%d\n",Length(L));
  printf("此时链表中第二个结点的值是：%d\n",FindKth(L,2));
  printf("查找22是否在该链表中：");
  if(Find(L,22))
    printf("是！\n");
  else
    printf("否！\n");
  printf("查找33是否在该链表中：");
  if(Find(L,33))
    printf("是！\n");
  else
    printf("否！\n");
  Delete(L,1);
  Delete(L,3);
  printf("----------删除后-----\n");
  Print(L);
  return 0;
}
