//
// Created by liang on 2019/8/9.
//

#ifndef DATASTRUCTURE_LINKSTACK_H
#define DATASTRUCTURE_LINKSTACK_H

// ��ջ�Ľ��ṹ�͵�������ͬ
typedef struct Node {
  ElemType data;
  struct Node *next;
} LNode, *LinkStack;

/**
 * ��ʼ��
 * @param S
 */
void InitStack(LinkStack &S) {
  S = NULL;
}

/**
 * ����
 * @param S
 * @return
 */
int Length(LinkStack S) {
  int k = 0;
  LinkStack p = S;
  while (p) {
    k++;
    p = p->next;                            // ������һ����㡣
  }
  return k;
}

/**
 * ����ջ��ջ������Ԫ��e
 * @param S
 * @param e
 * @return
 */
bool Push(LinkStack &S, ElemType e) {
  LinkStack p;
  if ((p = (LNode *) malloc(sizeof(LNode))) == NULL) return false;  // �洢����ʧ��
  p->data = e;
  p->next = S;                      // �����µ�ջ��Ԫ��
  S = p;                            // �޸�ջ��ָ��
  return true;
}

/**
 * ɾ����ջջ��Ԫ�أ�����e������ֵ
 * @param S
 * @param e
 * @return
 */
bool Pop(LinkStack &S, ElemType &e) {
  LinkStack p;
  if (S)                          // ջ�ǿ�
  {
    p = S;
    S = S->next;            // �޸�ջ��ָ��
    e = p->data;                // Ԫ��e������ֵ
    free(p);                  // �ͷŽ��ռ�
    return true;
  } else return false;            // ջ�գ���ջʧ��
}

/**
 * ��ȡջ��
 * @param S
 * @param e
 * @return
 */
bool GetTop(LinkStack S, ElemType &e) {
  if (S)                    // ջ�ǿ�
  {
    e = S->data;           // Ԫ��e������ֵ
    return true;
  } else return false;      // ջ�գ�ȡջ��Ԫ��ʧ��
}

/**
 * վ��
 * @param S
 * @return
 */
bool StackEmpty(LinkStack S) {
  if (!S) return true;
  else return false;
}

/**
 * ����
 * @param S
 */
void DestroyStack(LinkStack &S) {
  LinkStack p, p1;
  p = S;
  while (p) {
    p1 = p;
    p = p->next;
    free(p1);                                // �ͷ�p1��ָ�Ŀռ�
  }
  S = NULL;                                    // S�ÿ�
}


#endif //DATASTRUCTURE_LINKSTACK_H
