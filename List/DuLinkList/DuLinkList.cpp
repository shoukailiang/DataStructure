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
  cout << "请输入数字构成双向链表" << "，以0结束" << endl;
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
  printf("插入之前的双向链表是:");
  p = head->next;
  while (p != NULL) {
    printf("%3d,", p->data);
    p = p->next;
  }
  printf("\n");
  cout << "请输入一个数字插入到双向链表" << endl;
  int num, loc;
  cin >> num;
  cout << "你要插入的位置" << endl;
  cin >> loc;
  if (ListInsert(head, loc, num)) {
    printf("插入成功\n");
    printf("插入之后的双向链表是:");
    p = head->next;
    while (p != NULL) {
      printf("%3d,", p->data);
      p = p->next;
    }
    printf("\n");
  } else {
    printf("插入失败\n");
  }
  cout << "请输入一个位置来删除" << endl;
  cin >> loc;
  if (ListDelete(head, loc, e)) {
    printf("删除成功\n");
    printf("被删除的元素是：%d\n", e);
    printf("删除之后的双向链表是:");
    p = head->next;
    while (p != NULL) {
      printf("%3d,", p->data);
      p = p->next;
    }
    printf("\n");
  } else {
    printf("删除失败\n");
  }
}
