//
// Created by liang on 2019/9/19.
//
#include <iostream>

typedef int ElementType;  // ElementType �ɶ���Ϊ��������
#include "SqList.h"

using namespace std;

int main() {
  int i = 0;
  List L = MakeEmpty();
  Insert(L, 11, 0);
  printf("�����Ա�L-Data[0]����11\n");
  Insert(L, 25, 0);
  printf("�����Ա�L-Data[0]����25\n");
  Insert(L, 33, 0);
  printf("�����Ա�L-Data[0]����33\n");
  Insert(L, 77, 0);
  printf("�����Ա�L-Data[0]����77\n");
  printf("��ʱ�����Ա�Ϊ��");
  for (i = 0; i < Length(L); i++)
    printf("%d ", L->Data[i]);

  printf("\n");
  printf("����ֵΪ12���±��ǣ�%d\n", Find(L, 12));

  printf("�±�Ϊ3�����Ա��ֵ�ǣ�%d\n", FindKth(L, 3));
  Delete(L, 2);
  printf("ɾ�����Ա��е�2��Ԫ��\n");
  Delete(L, 2);
  printf("ɾ�����Ա��е�2��Ԫ��\n");
  printf("��ʱ�����Ա�Ϊ��");
  for (i = 0; i < Length(L); i++)
    printf("%d ", L->Data[i]);
  printf("\n");
  return 0;
}
