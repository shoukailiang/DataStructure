//
// Created by liang on 2019/9/20.
//

#ifndef DATASTRUCTURE_LINKLIST_H
#define DATASTRUCTURE_LINKLIST_H

#define ERROR -1

typedef struct LNode *List;

struct LNode {
  ElementType Data;
  List Next;
};

// 初始化链表,头结点不存放数据，设置空的头结点
List MakeEmpty() {
  List L = (List) malloc(sizeof(struct LNode));
  L->Next = NULL;
  return L;
}

//求表长
int Length(List L) {
  List p;
  int cnt = 0;
  p = L;
  while (p) {
    p = p->Next;
    cnt++;
  }
  return cnt;
}

ElementType FindKth(List L, int K) {
  List p;
  int cnt = 1;
  p = L;
  while (p && cnt < K) {
    p = p->Next;
    cnt++;
  }
  if ((cnt == K) && p) {
    return p->Data;
  } else {
    return ERROR;
  }
}

List Find(List L, ElementType X) {
  List p = L;
  while (p && p->Data != X) {
    p = p->Next;
  }
  if (p) {         // 可以只写成return p
    return p;
  } else {
    return NULL;
  }
}

bool Insert(List L, ElementType X, int i) {
  // 这里默认L有头结点
  List tmp, pre;
  int cnt = 0;
  // 查找位序i-1的节点
  pre = L;// pre指向表头
  while (pre && cnt < i - 1) {
    pre = pre->Next;
    cnt++;
  }
  // 所找的节点不在L
  if (pre == NULL || cnt != i - 1) {
    printf("插入位置参数错误\n");
    return false;
  } else {
    // 找到了待插入节点的前一个节点pre,若i=1,pre就指向表头
    tmp = (List) malloc(sizeof(struct LNode));
    tmp->Data = X;
    tmp->Next = pre->Next;
    pre->Next = tmp;
    return true;
  }
}

bool Delete(List L, int i) {
  // 这里默认L有头结点
  List tmp, pre;
  int cnt = 0;
  // 查找位序i-1的节点
  pre = L;// pre指向表头
  while (pre && cnt < i - 1) {
    pre = pre->Next;
    cnt++;
  }
  // 所找的节点不在L
  if (pre == NULL || cnt != i - 1 || pre->Next == NULL) {
    printf("插入位置参数错误\n");
    return false;
  } else {
    // 找到了待删除节点的前一个节点pre
    tmp = pre->Next;
    pre->Next = tmp->Next;
    free(tmp);
    return true;
  }
}

// 输出链表元素
void Print(List L) {
  List t;
  int flag = 1;
  printf("当前链表为：");
  for (t = L->Next; t; t = t->Next) {
    printf("%d   ", t->Data);
    flag = 0;
  }
  if (flag)
    printf("NULL");
  printf("\n");
}


#endif //DATASTRUCTURE_LINKLIST_H
