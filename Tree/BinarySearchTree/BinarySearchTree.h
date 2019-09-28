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

// 查找递归实现
BinTree Find(ElementType1 X, BinTree BST) {
  if (!BST)  // 如果根结点为空，返回 NULL
    return NULL;
  if (X < BST->Data) // 比根结点小，去左子树查找
    return Find(X, BST->Left);
  else if (BST->Data < X)  // 比根结点大，去右子树查找
    return Find(X, BST->Right);
  else if (BST->Data == X) // 找到了
    return BST;
}

// 查找非递归实现
BinTree IterFind(ElementType1 X, BinTree BST) {
  while (BST) {
    if (X < BST->Data)
      BST = BST->Left;
    else if (BST->Data < X)  // 比根结点大，去右子树查找
      BST = BST->Right;
    else if (BST->Data == X) // 找到了
      return BST;
  }
  return NULL;
}

// 查找最小值的递归实现
BinTree FindMin(BinTree BST) {
  if (!BST)    // 如果为空了，返回 NULL
    return NULL;
  else if (BST->Left)   // 还存在左子树，沿左分支继续查找
    return FindMin(BST->Left);
  else  // 找到了
    return BST;
}

// 查找最大值的非递归实现
BinTree FindMax(BinTree BST) {
  if (BST)  // 如果不空
    while (BST->Right)   // 只要右子树还存在
      BST = BST->Right;
  return BST;
}

// 插入
BinTree Insert(ElementType1 X, BinTree BST) {
  if (!BST) {  // 如果为空，初始化该结点
    BST = (BinTree) malloc(sizeof(struct TreeNode));
    BST->Data = X;
    BST->Left = NULL;
    BST->Right = NULL;
  } else { // 不为空
    if (X < BST->Data)  // 如果小，挂在左边
      BST->Left = Insert(X, BST->Left);
    else if (BST->Data < X)  // 如果大，挂在右边
      BST->Right = Insert(X, BST->Right);
    // 如果相等，什么都不用做
  }
  return BST;
}

// 删除
BinTree Delete(ElementType1 X, BinTree BST) {
  BinTree tmp;
  if (!BST)
    cout << "要删除的元素未找到";
  else if (X < BST->Data)   // X 比当前结点值小，在左子树继续查找删除
    BST->Left = Delete(X, BST->Left);
  else if (BST->Data < X)   // x 比当前结点值大，在右子树继续查找删除
    BST->Right = Delete(X, BST->Right);
  else {  //  找到被删除结点
    if (BST->Left && BST->Right) {  // 被删除结点有俩孩子结点
      tmp = FindMin(BST->Right);   // 找到右子树中值最小的
      BST->Data = tmp->Data;     // 用找到的值覆盖当前结点
      BST->Right = Delete(tmp->Data, BST->Right);    // 把前面找到的右子树最小值结点删除
    } else {  // 被删除结点只有一个孩子结点或没有孩子结点
      tmp = BST;
      if (!BST->Left) {
        // 只有右孩子或无子结点
        BST = BST->Right;
      } else {
        // 只有左孩子
        BST = BST->Left;
      }
      free(tmp);
    }
  }
  return BST;
}

// 先序遍历
void PreOrderTraversal(BinTree BT) {
  if (BT) {
    cout << BT->Data << " ";  // 打印根
    PreOrderTraversal(BT->Left);  // 进入左子树
    PreOrderTraversal(BT->Right);  // 进入右子树
  }
}

// 先序遍历迭代版
void IterPreOrderTraversal(BinTree BT) {
  BinTree T;
  Stack S = CreateStack();
  T = BT;// 从根节点出发
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

// 中序遍历
void InOrderTraversal(BinTree BT) {
  if (BT) {
    InOrderTraversal(BT->Left);  // 进入左子树
    cout << BT->Data << " ";  // 打印根
    InOrderTraversal(BT->Right);  // 进入右子树
  }
}

// 中序遍历迭代版
void IterInOrderTraversal(BinTree BT) {
  BinTree T;
  Stack S = CreateStack();
  T = BT;// 从根节点出发
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

// 输出二叉树中所有的叶节点
void PreOrderPrintLeaves(BinTree BT) {
  if (BT) {
    if (!BT->Left && !BT->Right) { // 如果BT是叶子
      cout << BT->Data;
    }
    PreOrderPrintLeaves(BT->Left);
    PreOrderPrintLeaves(BT->Right);
  }
}

// 求二叉树的高度
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
