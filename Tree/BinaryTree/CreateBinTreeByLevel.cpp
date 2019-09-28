//
// Created by liang on 2019/9/24.
//
#include <iostream>

#define NoInfo 0

// Data
typedef int ElementType1;

typedef struct TreeNode *BinTree;
struct TreeNode {
  ElementType1 Data;
  BinTree Left;
  BinTree Right;
};
// LinkQueue
typedef BinTree ElementType;
#define ERROR NULL;

#include "../../Queue/LinkQueue/LinkQueue.h"

using namespace std;


BinTree CreateBinTree() {
  ElementType1 Data;
  BinTree BT, T;
  Queue Q = CreateQueue();
  // 建立第一个节点，即根节点
  cin >> Data;
  if (Data != NoInfo) {
    // 分配根节点单元，并将节点地址入队
    BT = (BinTree) malloc(sizeof(struct TreeNode));
    BT->Data = Data;
    BT->Left = BT->Right = NULL;
    AddQ(Q, BT);
  } else {
    return NULL;
  }
  while (!IsEmpty(Q)) {
    T = DeleteQ(Q);// 取出一节点地址
    cin >> Data;// 读入T的左孩子
    if (Data == NoInfo) {
      T->Left = NULL;
    } else {// 分配新节点，作为出队节点左孩子
      T->Left = (BinTree) malloc(sizeof(struct TreeNode));
      T->Left->Data = Data;
      T->Left->Left = T->Right->Right = NULL;
      AddQ(Q, T->Left);
    }
    cin >> Data;// 读入T的右孩子
    if (Data == NoInfo) {
      T->Right = NULL;
    } else {// 分配新节点，作为出队节点右孩子
      T->Right = (BinTree) malloc(sizeof(struct TreeNode));
      T->Right->Data = Data;
      T->Right->Left = T->Right->Right = NULL;
      AddQ(Q, T->Right);
    }
  }
  return BT;
}

int main() {

}
