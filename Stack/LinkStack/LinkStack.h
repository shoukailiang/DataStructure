//
// Created by liang on 2019/9/21.
//

#ifndef DATASTRUCTURE_LINKSTACK_H
#define DATASTRUCTURE_LINKSTACK_H



typedef struct SNode *Stack;
struct SNode {
  ElementType Data;
  Stack Next;
};


Stack CreateStack() {
  // 创建一个堆栈的头结点，返回该节点的指针
  Stack S;
  S = (Stack) malloc(sizeof(struct SNode));
  S->Next = NULL;
  return S;
}

// 判断是否为空
bool IsEmpty(Stack S) {
  return (S->Next == NULL);
}

// 入栈
bool Push(Stack S, ElementType X) {
  Stack tmpCell;

  tmpCell = (Stack) malloc(sizeof(struct SNode));
  tmpCell->Data = X;
  // 链栈栈顶元素是链表头结点，新入栈的链表在栈顶元素后面
  tmpCell->Next = S->Next;
  S->Next = tmpCell;
  return true;
}

// 出栈
ElementType Pop(Stack S) {
  Stack FirstCell;
  ElementType TopElem;
  if (IsEmpty(S)) {
    printf("堆栈空");
    return ERROR;
  } else {
    FirstCell = S->Next;   // 出栈第一个元素在栈顶元素后面
    S->Next = FirstCell->Next;  //把第一个元素从链栈删除
    TopElem = FirstCell->Data;   // 取出被删除结点的值
    free(FirstCell);  // 释放空间
    return TopElem;
  }
}

#endif //DATASTRUCTURE_LINKSTACK_H
