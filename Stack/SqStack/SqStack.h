//
// Created by liang on 2019/8/9.
//

#ifndef DATASTRUCTURE_SQSTACK_H
#define DATASTRUCTURE_SQSTACK_H


# define STACK_INIT_SIZE  100      // ˳��ջ (Ĭ�ϵ�)�ĳ�ʼ�����������
# define STACK_INCREMENT  10        // (Ĭ�ϵ�)�����ռ���

typedef struct {
  ElemType *stack;                  // �洢����Ԫ�ص�һά����
  int top;                         // ջ��ָ��
  int stacksize;                   // ��ǰ�����������������ElemTypeΪ��λ��
  int incrementsize;             // �����ռ�������ElemTypeΪ��λ��
} SqStack;

/**
 * ��ʼ��
 * @param S
 * @param maxsize
 * @param incresize
 */
void InitStack(SqStack &S, int maxsize = STACK_INIT_SIZE,
               int incresize = STACK_INCREMENT) {
  S.stack = (ElemType *) malloc(maxsize * sizeof(ElemType)); // Ϊ˳��ջ�����ʼ�洢�ռ�
  if (!S.stack) exit(1);                                // �洢�ռ����ʧ��
  S.top = -1;                                            // ��ջ��
  S.stacksize = maxsize;                                 // ˳��ջ�ĵ�ǰ����
  S.incrementsize = incresize;                           // �����ռ�
}

/**
 * ����
 * @param S
 * @return
 */
int Length(SqStack S) {
  return S.top + 1;
}

/**
 * ��˳��ջ��ջ������Ԫ��e
 * @param S
 * @param e
 * @return
 */
bool Push(SqStack &S, ElemType e) {
  if (S.top == S.stacksize - 1) {
    S.stack = (ElemType *) realloc(S.stack, (S.stacksize + S.
       incrementsize) * sizeof(ElemType));      // ջ������˳��ջ�����ռ�
    if (!S.stack) return false;                // ����洢�ռ�ʧ��
    S.stacksize += S.incrementsize;
  }
  S.stack[++S.top] = e;                             // ջ��ָ�����ƣ�Ԫ��e��ջ
  return true;
}

/**
 * ɾ��˳��ջջ��Ԫ�أ�����e������ֵ
 * @param S
 * @param e
 * @return
 */
bool Pop(SqStack &S, ElemType &e) {
  if (S.top == -1) return false;
  e = S.stack[S.top--];
  return true;
}

/**
 * ȡ˳��ջջ��Ԫ�أ�����e������ֵ
 * @param S
 * @param e
 * @return
 */
bool GetTop(SqStack S, ElemType &e) {
  if (S.top == -1) return false;
  e = S.stack[S.top];
  return true;
}

/**
 * ջ�Ƿ�Ϊ��
 * @param S
 * @return
 */
bool StackEmpty(SqStack S) {
  if (S.top == -1) return true;
  else return false;
}

/**
 * ����
 * @param S
 */
void DestroyStack(SqStack &S) {
  free(S.stack);
  S.stack = NULL;
  S.stacksize = 0;
  S.top = -1;
}


#endif //DATASTRUCTURE_SQSTACK_H
