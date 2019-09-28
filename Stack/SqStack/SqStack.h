//
// Created by liang on 2019/9/21.
//

#ifndef DATASTRUCTURE_SQSTACK_H
#define DATASTRUCTURE_SQSTACK_H


#define ERROR -1;

typedef struct SNode *Stack;

struct SNode {
  ElementType *Data;
  int Top;
  int MaxSize;
};


Stack CreateStack(int MaxSize) {
  Stack S = (Stack) malloc(sizeof(struct SNode));
  S->Data = (ElementType *) malloc(MaxSize * sizeof(ElementType));
  S->Top = -1;
  S->MaxSize = MaxSize;
  return S;
}

int IsFull(Stack S) {
  return (S->Top == S->MaxSize - 1);
}

int IsEmpty(Stack S) {
  return (S->Top == -1);
}

bool Push(Stack S, ElementType X) {
  if (IsFull(S)) {   // Top �� 0 ��ʼ
    printf("��ջ��");
    return false;
  } else {
    S->Top++;   // ջ��Ԫ�ؼ�һ
    S->Data[S->Top] = X;   // �Ž�����
    return true;
  }
}

ElementType Pop(Stack S) {
  if (IsEmpty(S)) {
    printf("��ջ��");
    return ERROR;
  } else {
    ElementType val = S->Data[S->Top];  //ȡ������
    S->Top--;  // ջ��Ԫ�ؼ�һ
    return val;
  }
}


#endif //DATASTRUCTURE_SQSTACK_H
