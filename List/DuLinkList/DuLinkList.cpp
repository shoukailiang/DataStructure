//
// Created by liang on 2019/8/9.
//


#include <iostream>
#include "DuLinkList.h"

using namespace std;

int main() {
  int a, e;
  DuLinkList head, p, q;
  p = q = head = (DuLNode *) malloc(sizeof(DuLNode));
  cout << "���������ֹ���˫������" << "����0����" << endl;
  scanf("%d", &a);
  while (a != 0) {
    p = (DuLNode *) malloc(sizeof(DuLNode));
    p->data = a;
    p->prior = q;
    q->next = p;
    q = p;
    scanf("%d", &a);
  }
  q->next = NULL;
  printf("����֮ǰ��˫��������:");
  p = head->next;
  while (p != NULL) {
    printf("%3d,", p->data);
    p = p->next;
  }
  printf("\n");
  cout << "������һ�����ֲ��뵽˫������" << endl;
  int num, loc;
  cin >> num;
  cout << "��Ҫ�����λ��" << endl;
  cin >> loc;
  if (ListInsert(head, loc, num)) {
    printf("����ɹ�\n");
    printf("����֮���˫��������:");
    p = head->next;
    while (p != NULL) {
      printf("%3d,", p->data);
      p = p->next;
    }
    printf("\n");
  } else {
    printf("����ʧ��\n");
  }
  cout << "������һ��λ����ɾ��" << endl;
  cin >> loc;
  if (ListDelete(head, loc, e)) {
    printf("ɾ���ɹ�\n");
    printf("��ɾ����Ԫ���ǣ�%d\n", e);
    printf("ɾ��֮���˫��������:");
    p = head->next;
    while (p != NULL) {
      printf("%3d,", p->data);
      p = p->next;
    }
    printf("\n");
  } else {
    printf("ɾ��ʧ��\n");
  }
}
