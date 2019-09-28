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

// ��ʼ������,ͷ��㲻������ݣ����ÿյ�ͷ���
List MakeEmpty() {
  List L = (List) malloc(sizeof(struct LNode));
  L->Next = NULL;
  return L;
}

//���
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
  if (p) {         // ����ֻд��return p
    return p;
  } else {
    return NULL;
  }
}

bool Insert(List L, ElementType X, int i) {
  // ����Ĭ��L��ͷ���
  List tmp, pre;
  int cnt = 0;
  // ����λ��i-1�Ľڵ�
  pre = L;// preָ���ͷ
  while (pre && cnt < i - 1) {
    pre = pre->Next;
    cnt++;
  }
  // ���ҵĽڵ㲻��L
  if (pre == NULL || cnt != i - 1) {
    printf("����λ�ò�������\n");
    return false;
  } else {
    // �ҵ��˴�����ڵ��ǰһ���ڵ�pre,��i=1,pre��ָ���ͷ
    tmp = (List) malloc(sizeof(struct LNode));
    tmp->Data = X;
    tmp->Next = pre->Next;
    pre->Next = tmp;
    return true;
  }
}

bool Delete(List L, int i) {
  // ����Ĭ��L��ͷ���
  List tmp, pre;
  int cnt = 0;
  // ����λ��i-1�Ľڵ�
  pre = L;// preָ���ͷ
  while (pre && cnt < i - 1) {
    pre = pre->Next;
    cnt++;
  }
  // ���ҵĽڵ㲻��L
  if (pre == NULL || cnt != i - 1 || pre->Next == NULL) {
    printf("����λ�ò�������\n");
    return false;
  } else {
    // �ҵ��˴�ɾ���ڵ��ǰһ���ڵ�pre
    tmp = pre->Next;
    pre->Next = tmp->Next;
    free(tmp);
    return true;
  }
}

// �������Ԫ��
void Print(List L) {
  List t;
  int flag = 1;
  printf("��ǰ����Ϊ��");
  for (t = L->Next; t; t = t->Next) {
    printf("%d   ", t->Data);
    flag = 0;
  }
  if (flag)
    printf("NULL");
  printf("\n");
}


#endif //DATASTRUCTURE_LINKLIST_H
