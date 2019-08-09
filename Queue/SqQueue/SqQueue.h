//
// Created by liang on 2019/8/9.
//

#ifndef DATASTRUCTURE_SQQUEUE_H
#define DATASTRUCTURE_SQQUEUE_H


#define QUENU_INIT_SIZE 100
#define QUENUINCREMENT 10

typedef struct {
  ElemType *queue;
  int front;
  int rear;
  int queuesize;
  int incrementsize;
} SqQueue;

/**
 * 初始化操作
 * @param Q
 * @param maxsize
 * @param incresize
 */
void InitQueue(SqQueue &Q, int maxsize = QUENU_INIT_SIZE, int incresize = QUENUINCREMENT) {
  Q.queue = (ElemType *) malloc(maxsize * sizeof(ElemType));
  if (!Q.queue) {
    exit(01);
  }
  Q.front = Q.rear = 0;
  Q.queuesize = maxsize;
  Q.incrementsize = incresize;
}

/**
 * 求队列的长度
 * @param Q
 * @return
 */
int Length(SqQueue Q) {
  return (Q.rear - Q.front + Q.queuesize) % Q.queuesize;
}

/**
 * 进队操作,从队尾插入元素，
 * @param Q
 * @param e
 * @return 成功则返回true
 */
bool EnQueue(SqQueue &Q, ElemType e) {
  if ((Q.rear + 1) % Q.queuesize == Q.front) { //队满给顺序队列增补空间
    Q.queue = (ElemType *) realloc(Q.queue, (Q.queuesize + Q.incrementsize) * sizeof(ElemType));
    if (!Q.queue) {
      return false;
    }
    if (Q.front > Q.rear) {  //队首指针在队尾指针后面，重新确定位置
      for (int i = Q.queuesize; i >= Q.front; i--) {
        Q.queue[i + Q.incrementsize] = Q.queue[i];
      }
      Q.front += Q.incrementsize;
    }
    Q.queuesize += Q.incrementsize;
  }
  Q.queue[Q.rear] = e;
  Q.rear = (Q.rear + 1) % Q.queuesize;
  return true;
}

/**
 * 出队操作
 * @param Q
 * @param e
 * @return
 */
bool DeQueue(SqQueue &Q, ElemType &e) {
  if (Q.front == Q.rear) return false;
  e = Q.queue[Q.front];
  Q.front = (Q.front + 1) % Q.queuesize;
  return true;
}

/**
 * 取队首元素操作
 * @param Q
 * @param e
 * @return
 */
bool GetHead(SqQueue Q, ElemType &e) {
  if (Q.front == Q.rear) return false;
  e = Q.queue[Q.front];
  return true;
}

/**
 * 是否为空
 * @param Q
 * @return
 */
bool QueueEmpty(SqQueue Q) {
  return Q.front == Q.rear;
}

/**
 * 销毁
 * @param Q
 */
void DestroyQueue(SqQueue &Q) {
  free(Q.queue);
  Q.queuesize = 0;
  Q.front = Q.rear = 0;
}


#endif //DATASTRUCTURE_SQQUEUE_H
