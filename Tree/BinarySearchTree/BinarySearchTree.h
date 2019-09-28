//
// Created by liang on 2019/9/22.
//

#ifndef DATASTRUCTURE_BINARYSEARCHTREE_H
#define DATASTRUCTURE_BINARYSEARCHTREE_H

typedef struct TreeNode *BinTree;
struct TreeNode {
  ElementType1 Data;
  BinTree Left;
  BinTree Right;
};
// LinkStack------------------
typedef BinTree ElementType;
#define ERROR NULL

#include "../../Stack/LinkStack/LinkStack.h"
//------------------------

// ���ҵݹ�ʵ��
BinTree Find(ElementType1 X, BinTree BST) {
  if (!BST)  // ��������Ϊ�գ����� NULL
    return NULL;
  if (X < BST->Data) // �ȸ����С��ȥ����������
    return Find(X, BST->Left);
  else if (BST->Data < X)  // �ȸ�����ȥ����������
    return Find(X, BST->Right);
  else if (BST->Data == X) // �ҵ���
    return BST;
}

// ���ҷǵݹ�ʵ��
BinTree IterFind(ElementType1 X, BinTree BST) {
  while (BST) {
    if (X < BST->Data)
      BST = BST->Left;
    else if (BST->Data < X)  // �ȸ�����ȥ����������
      BST = BST->Right;
    else if (BST->Data == X) // �ҵ���
      return BST;
  }
  return NULL;
}

// ������Сֵ�ĵݹ�ʵ��
BinTree FindMin(BinTree BST) {
  if (!BST)    // ���Ϊ���ˣ����� NULL
    return NULL;
  else if (BST->Left)   // �������������������֧��������
    return FindMin(BST->Left);
  else  // �ҵ���
    return BST;
}

// �������ֵ�ķǵݹ�ʵ��
BinTree FindMax(BinTree BST) {
  if (BST)  // �������
    while (BST->Right)   // ֻҪ������������
      BST = BST->Right;
  return BST;
}

// ����
BinTree Insert(ElementType1 X, BinTree BST) {
  if (!BST) {  // ���Ϊ�գ���ʼ���ý��
    BST = (BinTree) malloc(sizeof(struct TreeNode));
    BST->Data = X;
    BST->Left = NULL;
    BST->Right = NULL;
  } else { // ��Ϊ��
    if (X < BST->Data)  // ���С���������
      BST->Left = Insert(X, BST->Left);
    else if (BST->Data < X)  // ����󣬹����ұ�
      BST->Right = Insert(X, BST->Right);
    // �����ȣ�ʲô��������
  }
  return BST;
}

// ɾ��
BinTree Delete(ElementType1 X, BinTree BST) {
  BinTree tmp;
  if (!BST)
    cout << "Ҫɾ����Ԫ��δ�ҵ�";
  else if (X < BST->Data)   // X �ȵ�ǰ���ֵС������������������ɾ��
    BST->Left = Delete(X, BST->Left);
  else if (BST->Data < X)   // x �ȵ�ǰ���ֵ������������������ɾ��
    BST->Right = Delete(X, BST->Right);
  else {  //  �ҵ���ɾ�����
    if (BST->Left && BST->Right) {  // ��ɾ������������ӽ��
      tmp = FindMin(BST->Right);   // �ҵ���������ֵ��С��
      BST->Data = tmp->Data;     // ���ҵ���ֵ���ǵ�ǰ���
      BST->Right = Delete(tmp->Data, BST->Right);    // ��ǰ���ҵ�����������Сֵ���ɾ��
    } else {  // ��ɾ�����ֻ��һ�����ӽ���û�к��ӽ��
      tmp = BST;
      if (!BST->Left) {
        // ֻ���Һ��ӻ����ӽ��
        BST = BST->Right;
      } else {
        // ֻ������
        BST = BST->Left;
      }
      free(tmp);
    }
  }
  return BST;
}

// �������
void PreOrderTraversal(BinTree BT) {
  if (BT) {
    cout << BT->Data << " ";  // ��ӡ��
    PreOrderTraversal(BT->Left);  // ����������
    PreOrderTraversal(BT->Right);  // ����������
  }
}

// �������������
void IterPreOrderTraversal(BinTree BT) {
  BinTree T;
  Stack S = CreateStack();
  T = BT;// �Ӹ��ڵ����
  while (T || !IsEmpty(S)) {
    while (T) {
      Push(S, T);
      cout << T->Data << " ";
      T = T->Left;
    }

    T = Pop(S);
    T = T->Right;
  }
}

// �������
void InOrderTraversal(BinTree BT) {
  if (BT) {
    InOrderTraversal(BT->Left);  // ����������
    cout << BT->Data << " ";  // ��ӡ��
    InOrderTraversal(BT->Right);  // ����������
  }
}

// �������������
void IterInOrderTraversal(BinTree BT) {
  BinTree T;
  Stack S = CreateStack();
  T = BT;// �Ӹ��ڵ����
  while (T || !IsEmpty(S)) {
    while (T) {
      Push(S, T);
      T = T->Left;
    }
    T = Pop(S);
    cout << T->Data << " ";
    T = T->Right;
  }
}

// ��������������е�Ҷ�ڵ�
void PreOrderPrintLeaves(BinTree BT) {
  if (BT) {
    if (!BT->Left && !BT->Right) { // ���BT��Ҷ��
      cout << BT->Data;
    }
    PreOrderPrintLeaves(BT->Left);
    PreOrderPrintLeaves(BT->Right);
  }
}

// ��������ĸ߶�
int GetHeight(BinTree BT) {
  int HL, HR, MaxH;
  if (BT) {
    HL = GetHeight(BT->Left);
    HR = GetHeight(BT->Right);
    MaxH = HL > HR ? HL : HR;
    return (MaxH + 1);
  } else {
    return 0;
  }
}


#endif //DATASTRUCTURE_BINARYSEARCHTREE_H
