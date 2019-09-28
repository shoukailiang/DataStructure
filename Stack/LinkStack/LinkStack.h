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
  // ����һ����ջ��ͷ��㣬���ظýڵ��ָ��
  Stack S;
  S = (Stack) malloc(sizeof(struct SNode));
  S->Next = NULL;
  return S;
}

// �ж��Ƿ�Ϊ��
bool IsEmpty(Stack S) {
  return (S->Next == NULL);
}

// ��ջ
bool Push(Stack S, ElementType X) {
  Stack tmpCell;

  tmpCell = (Stack) malloc(sizeof(struct SNode));
  tmpCell->Data = X;
  // ��ջջ��Ԫ��������ͷ��㣬����ջ��������ջ��Ԫ�غ���
  tmpCell->Next = S->Next;
  S->Next = tmpCell;
  return true;
}

// ��ջ
ElementType Pop(Stack S) {
  Stack FirstCell;
  ElementType TopElem;
  if (IsEmpty(S)) {
    printf("��ջ��");
    return ERROR;
  } else {
    FirstCell = S->Next;   // ��ջ��һ��Ԫ����ջ��Ԫ�غ���
    S->Next = FirstCell->Next;  //�ѵ�һ��Ԫ�ش���ջɾ��
    TopElem = FirstCell->Data;   // ȡ����ɾ������ֵ
    free(FirstCell);  // �ͷſռ�
    return TopElem;
  }
}

#endif //DATASTRUCTURE_LINKSTACK_H
