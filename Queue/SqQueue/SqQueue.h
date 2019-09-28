//
// Created by liang on 2019/9/21.
//

#ifndef DATASTRUCTURE_SQQUEUE_H
#define DATASTRUCTURE_SQQUEUE_H

#define ERROR -1


struct QNode {
  ElementType *Data;
  int Front, Rear;// ���е�ͷβָ��
  int MaxSize;
};

typedef struct QNode *Queue;

Queue CreateQueue(int MaxSize) {
  Queue Q = (Queue) malloc(sizeof(struct QNode));
  Q->Data = (ElementType *) malloc(MaxSize * sizeof(ElementType));
  Q->Front = Q->Rear = 0;
  Q->MaxSize = MaxSize;
  return Q;
}

int IsFull(Queue Q) {
  return ((Q->Rear + 1) % Q->MaxSize == Q->Front);
}

bool AddQ(Queue Q, ElementType X) {
  if (IsFull(Q)) {
    printf("������");
    return false;
  } else {
    Q->Rear = (Q->Rear + 1) % Q->MaxSize;
    Q->Data[Q->Rear] = X;
    return true;
  }
}

int IsEmpty(Queue Q) {
  return (Q->Front == Q->Rear);
}

// ����
ElementType DeleteQ(Queue Q) {
  if (IsEmpty(Q)) {
    printf("���п�");
    return ERROR;
  } else {
    Q->Front = (Q->Front + 1) % Q->MaxSize;
    return Q->Data[Q->Front];
  }
}


#endif //DATASTRUCTURE_SQQUEUE_H
