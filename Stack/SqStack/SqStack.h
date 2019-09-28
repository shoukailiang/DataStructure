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
  if (IsFull(S)) {   // Top 从 0 开始
    printf("堆栈满");
    return false;
  } else {
    S->Top++;   // 栈顶元素加一
    S->Data[S->Top] = X;   // 放进最上
    return true;
  }
}

ElementType Pop(Stack S) {
  if (IsEmpty(S)) {
    printf("堆栈空");
    return ERROR;
  } else {
    ElementType val = S->Data[S->Top];  //取出最上
    S->Top--;  // 栈顶元素减一
    return val;
  }
}


#endif //DATASTRUCTURE_SQSTACK_H
