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
 * ��ʼ������
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
 * ����еĳ���
 * @param Q
 * @return
 */
int Length(SqQueue Q) {
  return (Q.rear - Q.front + Q.queuesize) % Q.queuesize;
}

/**
 * ���Ӳ���,�Ӷ�β����Ԫ�أ�
 * @param Q
 * @param e
 * @return �ɹ��򷵻�true
 */
bool EnQueue(SqQueue &Q, ElemType e) {
  if ((Q.rear + 1) % Q.queuesize == Q.front) { //������˳����������ռ�
    Q.queue = (ElemType *) realloc(Q.queue, (Q.queuesize + Q.incrementsize) * sizeof(ElemType));
    if (!Q.queue) {
      return false;
    }
    if (Q.front > Q.rear) {  //����ָ���ڶ�βָ����棬����ȷ��λ��
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
 * ���Ӳ���
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
 * ȡ����Ԫ�ز���
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
 * �Ƿ�Ϊ��
 * @param Q
 * @return
 */
bool QueueEmpty(SqQueue Q) {
  return Q.front == Q.rear;
}

/**
 * ����
 * @param Q
 */
void DestroyQueue(SqQueue &Q) {
  free(Q.queue);
  Q.queuesize = 0;
  Q.front = Q.rear = 0;
}


#endif //DATASTRUCTURE_SQQUEUE_H
