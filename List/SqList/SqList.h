//
// Created by liang on 2019/9/19.
//

#ifndef DATASTRUCTURE_SQLIST_H
#define DATASTRUCTURE_SQLIST_H


#define MAXSIZE 100  // MAXSIZE 定义为 Data 数组的大小
#define ERROR -1

typedef struct LNode *List;

struct LNode {
  ElementType Data[MAXSIZE];
  int Last;            // 最后一个（元素个数-1）类似于下标
};

//访问下标为 i 的元素：L->Data[i]
//线性表的长度：L->Last+1


List MakeEmpty() {
  List L;
  L = (List) malloc(sizeof(struct LNode));
  L->Last = -1;
  return L;
}


int Find(List L, ElementType X) {
  int i = 0;
  while (i <= L->Last && L->Data[i] != X) {
    i++;
  }

  if (i > L->Last) {
    return ERROR;
  } else {
    return i;
  }
}


bool Insert(List L, ElementType X, int i) {
  int j;
  if (L->Last == MAXSIZE - 1) {
    printf("表满");
    return false;
  }
  if (i < 0 || L->Last + 1 < i) {  //位置越界，如果将数插入 L->Data[L->Last+1]，下面都不用腾位置了
    printf("位置不合法");
    return false;
  }

  for (j = L->Last; j >= i; j--)   // 从后往前依次向后挪一个，给 a[i]腾出位置
    L->Data[j + 1] = L->Data[j];
  L->Data[i] = X;    //新元素插入
  L->Last++;    // Last仍然指向最后元素
  return true;
}

bool Delete(List L, int i) {
  int j;
  if (i < 0 || L->Last < i) {  //位置越界，而删除最多到 L->Data[L->Last]
    printf("L->Data[%d]不存在元素", i);
    return false;
  }
  for (j = i; j <= L->Last; j++)   // 从前往后依次向前挪一个，将 a[i] 覆盖了
    L->Data[j - 1] = L->Data[j];
  L->Last--;  // Last仍然指向最后元素
  return true;
}

int Length(List L) {
  return L->Last + 1;
}

// 按序查找
ElementType FindKth(List L, int K) {
  if (K < 0 || K > L->Last) {
    printf("L->Data[%d]不存在元素", K);
    return ERROR;
  }
  return L->Data[K];
}

#endif //DATASTRUCTURE_SQLIST_H
