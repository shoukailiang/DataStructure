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
  printf("��ǰ������Ϊ��%d\n",Length(L));
  printf("��ʱ�����еڶ�������ֵ�ǣ�%d\n",FindKth(L,2));
  printf("����22�Ƿ��ڸ������У�");
  if(Find(L,22))
    printf("�ǣ�\n");
  else
    printf("��\n");
  printf("����33�Ƿ��ڸ������У�");
  if(Find(L,33))
    printf("�ǣ�\n");
  else
    printf("��\n");
  Delete(L,1);
  Delete(L,3);
  printf("----------ɾ����-----\n");
  Print(L);
  return 0;
}
