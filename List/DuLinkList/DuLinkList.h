//
// Created by liang on 2019/8/9.
//

#ifndef DATASTRUCTURE_DULINKLIST_H
#define DATASTRUCTURE_DULINKLIST_H

typedef int ElemType;
typedef struct DuNode {
  ElemType data;
  struct DuNode *prior;
  struct DuNode *next;
} DuLNode, *DuLinkList;

/**
 * ��ʼ��
 * @param L
 */
void InitList(DuLinkList &L) {
  L = (DuLNode *) malloc(sizeof(DuLNode));       // ������һ�������������Ҫ�����ڿռ�
  if (!L) {
    exit(1);                        // �洢����ʧ��
  }
  L->next = NULL;                               // ��ͷ���ĺ��ָ�����ÿ�
  L->prior = NULL;                              // ��ͷ����ǰ��ָ�����ÿ�
}

/**
 * ����
 * @param L
 * @return
 */
int Length(DuLinkList L) {
  DuLinkList p = L->next;
  int k = 0;
  while (p) {     //��p��ָ��Ľ�㻹��ֵ
    k++;
    p = p->next;
  }
  return k;
}

/**
 * �ڴ�ͷ����˫������L�е�i�����֮ǰ����Ԫ��e
 * @param L
 * @param i
 * @param e
 * @return ����ֵ
 */
bool ListInsert(DuLinkList &L, int i, ElemType e) {
  DuLinkList p, s, q = L;
  int j = 0;
  while (q->next && j < i - 1) {
    q = q->next;
    j++;
  }   // Ѱ�ҵ�i-1�����,����qָ��˽��
  if (j != i - 1) {
    return false;                   // i��λ�ò�����
  }
  s = (DuLNode *) malloc(sizeof(DuLNode));
  if (!s) {
    exit(1);                            // �洢����ʧ��
  }
  s->data = e;
  if (q->next) {                                // �����λ�ò��Ǳ�β
    p = q->next;                                  // pָ��������λ��
    s->prior = p->prior;                          // �޸�ָ��
    p->prior->next = s;
    s->next = p;
    p->prior = s;
  } else {                               // �����λ���Ǳ�β
    q->next = s;
    s->prior = q;
    s->next = NULL;
  }
  return true;
}

/**
 * ɾ������ͷ����˫������L�еĵ�i����㣬����e������ֵ
 * @param L
 * @param i
 * @param e
 * @return  ����ֵ
 */
bool ListDelete(DuLinkList &L, int i, ElemType &e) {
  DuLinkList p = L;
  int j = 0;
  while (p->next && j < i) {
    p = p->next;
    j++;
  }      // Ѱ�ҵ�i�����,����pָ��˽��
  if (j != i) return false;                 // i��λ�ò�����
  if (p->next) {                             // ��ɾ���Ĳ��Ǳ�β���
    p->next->prior = p->prior;               // ���p��ǰ����Ϊ���p�ĺ�̵�ǰ��
  }
  p->prior->next = p->next;                // ���p�ĺ����Ϊ���p��ǰ���ĺ��
  e = p->data;
  free(p);
  return true;
}

#endif //DATASTRUCTURE_DULINKLIST_H
