//
// Created by liang on 2019/8/8.
//

#ifndef TEST_C_SQLIST_H
#define TEST_C_SQLIST_H

#define LIST_INIT_SIZE  100               // 顺序表(默认的)的初始分配最大容量
#define LIST_INCREMENT  10                // (默认的)增补空间量


/**
 *数组静态分配,有缺点
 */
typedef struct {
  ElemType elem[LIST_INIT_SIZE];
  int length;
  int listsize;
  int incrementsize;
} SqList_static;

/**
 *数组动态分配
 */
typedef struct {
  ElemType *elem;                       // 存储数据元素的一维数组
  int length;                           // 线性表的当前长度
  int listsize;                         // 当前分配的数组容量（以ElemType为单位）
  int incrementsize;                    // 增补空间量（以ElemType为单位）
} SqList;

/**
 * 构造一个最大容量为maxsize的顺序表
 * @param L
 * @param maxsize
 * @param increase
 */
void InitList(SqList &L, int maxsize = LIST_INIT_SIZE, int increase = LIST_INCREMENT) {
  L.elem = (ElemType *) malloc(maxsize * sizeof(ElemType));  // 为顺序表分配一个最大容量为 maxsize 的数组空间
  if (!L.elem) exit(1);
  L.length = 0;
  L.listsize = maxsize;
  L.incrementsize = increase;  // 需要时可扩容incresize个元素空间
}

/**
 * 长度
 * @param L
 * @return 返回长度
 */
int Length(SqList L) {
  return L.listsize;
}

/**
 * 是否为空
 * @param L
 * @return 返回是否为空
 */
bool Empty(SqList L) {
  if (L.length == 0) {
    return true;
  } else {
    return false;
  }
}

/**
 * 查找
 * @param L
 * @param e
 * @return  索引,找到返回下标，找不到返回-1
 */
int LocateElem(SqList L, ElemType e) {
  for (int i = 0; i < L.length; i++)
    if (L.elem[i] == e) return i;   // 找到满足判定的数据元素为第 i 个元素
  return -1;                     // 该线性表中不存在满足判定的数据元素
}

/**
 * 在顺序表L的第i个元素之前插入新的元素e，
 * @param L
 * @param i
 * @param e
 * @return
 */
bool ListInsert(SqList &L, int i, ElemType e) {
  // 若表中当前容量不足，则按预定义的增量扩容
  int j;
  if (i < 0 || i > L.length) return false;            // i值不合法
  if (L.length >= L.listsize) {                   // 当前存储空间已满，增补空间
    L.elem = (ElemType *) realloc(L.elem, (L.listsize + L.incrementsize) * sizeof(ElemType));
    if (!L.elem) exit(1);                   // 存储分配失败
    L.listsize += L.incrementsize;           // 当前存储容量增加
  }
  for (j = L.length; j > i; j--) {
    L.elem[j] = L.elem[j - 1];
  }
  L.elem[i] = e;                           // 插入元素e
  L.length++;                            // 表长增1
  return true;
}

/**
 * 在顺序表L中删除第i个元素，并用e返回其值
 * @param L
 * @param i
 * @param e
 * @return
 */
bool ListDelete(SqList &L, int i, ElemType &e) {
  if (i < 0 || i > L.length) {
    return false;
  }
  if (L.length <= 0) {
    return false;
  }
  e = L.elem[i];
  for (int j = i + 1; j < L.length; ++j) {
    L.elem[j - 1] = L.elem[j];
  }
  L.length--;
  return true;
}

/**
 *
 * @param L
 * @param i
 * @param e
 * @return  取出失败返回false,成功返回true,并用e返回其值
 */
bool GetElem(SqList L, int i, ElemType &e) {     // 取出顺序表L中第i个元素，并用e返回其值。
  if (i < 0 || i > L.length) return false;            // i值不合法
  if (L.length <= 0) return false;               // 表空无数据元素可取
  e = L.elem[i];                                 // 被取元素的值赋给e
  return true;
}

/**
 * 打印输出
 * @param L
 */
void PrintList(SqList L) {
  for (int i = 0; i < L.length; i++) {
    cout << setw(6) << L.elem[i];
  }
  cout << endl;
}

/**
 * 销毁咯~~~
 * @param L
 */
void DestroyList(SqList &L) {       // 释放顺序表L所占存储空间
  free(L.elem);
  L.elem = NULL;
  L.listsize = 0;
  L.length = 0;
}

#endif //TEST_C_SQLIST_H
