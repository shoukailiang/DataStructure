//
// Created by liang on 2019/8/9.
//

#ifndef DATASTRUCTURE_LINKQUEUE_H
#define DATASTRUCTURE_LINKQUEUE_H


typedef struct LNode {
  ElemType data;
  struct LNode *next;
} *QueuePtr;

typedef struct {
  QueuePtr front;
  QueuePtr rear;
} LinkQueue;           //����

/**
 * ��ʼ������
 * @param Q
 */
void InitQueue(LinkQueue &Q) {
  Q.front = NULL;
  Q.rear = NULL;
}

/**
 * �����ӵĳ���
 * @param Q
 * @return
 */
int Length(LinkQueue Q) {
  QueuePtr p = Q.front;
  int k = 0;
  while (p) {
    k++;
    p = p->next;
  }
  return k;
}

/**
 * ���Ӳ���
 * @param Q
 * @param e
 * @return
 */
bool EnQueue(LinkQueue &Q, ElemType e) {
  QueuePtr s;
  if ((s = (LNode *) malloc(sizeof(LNode))) == NULL) {
    return false;
  }
  s->data = e;
  s->next = NULL;
  if (Q.rear == NULL) {
    Q.front = Q.rear = s;
  } else {
    Q.rear = Q.rear->next = s;
  }
  return true;
}

/**
 * ���Ӳ���
 * @param Q
 * @param e
 * @return
 */
bool DeQueue(LinkQueue &Q, ElemType &e) {
  QueuePtr p;
  if (Q.front == NULL) {
    return false;
  }
  p = Q.front;
  e = p->data;
  Q.front = p->next;
  if (Q.front == NULL) {
    Q.rear = NULL;
  }
  free(p);
  return true;
}

/**
 * ȡ����Ԫ�ز���
 * @param Q
 * @param e
 * @return
 */
bool GetHead(LinkQueue &Q, ElemType &e) {
  if (Q.front == NULL) {
    return false;
  }
  e = Q.front->data;
  return true;
}

/**
 * �ж϶ӿղ���
 * @param Q
 * @return
 */
bool QueueEmpty(LinkQueue &Q) {
  if (!Q.front) {
    return true;
  } else {
    return false;
  }
}

/**
 * �������Ӳ���
 * @param Q
 */
void DestroyQueue(LinkQueue &Q) {
  QueuePtr p = Q.front, p1;
  while (p) {
    p1 = p;
    p = p->next;
    free(p1);
  }
  Q.front = Q.rear = NULL;
}


#endif //DATASTRUCTURE_LINKQUEUE_H
