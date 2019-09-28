//
// Created by liang on 2019/9/21.
//

#ifndef DATASTRUCTURE_LINKQUEUE_H
#define DATASTRUCTURE_LINKQUEUE_H

typedef struct QNode *Queue;

struct Node { // �����еĽڵ�
  ElementType Data;
  struct Node *Next;
};

struct QNode {
  struct Node *Front;// ���е�ͷָ��
  struct Node *Rear;// ���е�βָ��
};

Queue CreateQueue() {
  Queue Q = (Queue) malloc(sizeof(struct QNode));
  Q->Front = NULL;
  Q->Rear = NULL;
  return Q;
}

int IsEmpty(Queue Q) {
  return (Q->Front == NULL);
}

void AddQ(Queue Q, ElementType X) {
  struct Node *node;
  node = (struct Node *) malloc(sizeof(struct Node));
  node->Data = X;
  node->Next = NULL;
  if (Q->Rear == NULL) {  //��ʱ���п�
    Q->Rear = node;
    Q->Front = node;
  } else { //��Ϊ��
    Q->Rear->Next = node;  // ��������
    Q->Rear = node;   // rear ��Ȼ�������
  }
}

ElementType DeleteQ(Queue Q) {
  struct Node *FrontCell;
  ElementType FrontElem;
  if (IsEmpty(Q)) {
    printf("���п�");
    return ERROR;
  } else {
    FrontCell = Q->Front;
    if (Q->Front == Q->Rear) { // ������ֻ��һ��Ԫ��
      Q->Front = Q->Rear = NULL;// ɾ��������ÿ�
    } else {
      Q->Front = Q->Front->Next;
    }
    FrontElem = FrontCell->Data;
    free(FrontCell);
    return FrontElem;
  }
}


#endif //DATASTRUCTURE_LINKQUEUE_H
