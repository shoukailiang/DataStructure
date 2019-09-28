//
// Created by liang on 2019/9/21.
//

#ifndef DATASTRUCTURE_LINKQUEUE_H
#define DATASTRUCTURE_LINKQUEUE_H

typedef struct QNode *Queue;

struct Node { // 队列中的节点
  ElementType Data;
  struct Node *Next;
};

struct QNode {
  struct Node *Front;// 队列的头指针
  struct Node *Rear;// 队列的尾指针
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
  if (Q->Rear == NULL) {  //此时队列空
    Q->Rear = node;
    Q->Front = node;
  } else { //不为空
    Q->Rear->Next = node;  // 将结点入队
    Q->Rear = node;   // rear 仍然保持最后
  }
}

ElementType DeleteQ(Queue Q) {
  struct Node *FrontCell;
  ElementType FrontElem;
  if (IsEmpty(Q)) {
    printf("队列空");
    return ERROR;
  } else {
    FrontCell = Q->Front;
    if (Q->Front == Q->Rear) { // 队列中只有一个元素
      Q->Front = Q->Rear = NULL;// 删除后队列置空
    } else {
      Q->Front = Q->Front->Next;
    }
    FrontElem = FrontCell->Data;
    free(FrontCell);
    return FrontElem;
  }
}


#endif //DATASTRUCTURE_LINKQUEUE_H
