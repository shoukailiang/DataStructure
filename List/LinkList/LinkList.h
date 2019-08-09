//
// Created by liang on 2019/8/8.
//

#ifndef DATASTRUCTURE_LINKLIST_H
#define DATASTRUCTURE_LINKLIST_H




/**
 * 头结点不存放数据，设置空的头结点，是为了操作统一（一：插入时既有前驱又有后继，二：空表和非空表的统一）
 */
typedef struct Node {
  ElemType data;
  struct Node *next;
} LNode, *LinkList;

/**
 * 初始化
 * @param L
 */
void InitList(LinkList &L) {
  L = (LNode *) malloc(sizeof(LNode));
  if (!L) {                          // 存储分配失败
    exit(1);
  }
  L->next = NULL;
}

/**
 * 长度
 * @param L
 * @return
 */
int Length(LinkList &L) {
  LinkList p = L->next;
  int k = 0;
  while (p) {
    k++;
    p = p->next;
  }
  return k;
}

/**
 * 在L所指的单链表中查找第一个值和e 相等的结点
 * @param L
 * @param e
 * @return 若存在，则返回其指针；否则返回空指针
 */
LNode *LocateElem(LinkList L, ElemType e) {
  LinkList p = L->next;                  // p指向链表中的第一个结点
  while (p && p->data != e) {
    p = p->next;
  }
  return p;
}

/**
 * 在L所指的单链表中查找第一个值和e相等的结点
 * @param L
 * @param e
 * @return 若存在，则返回元素顺序，否则返回-1
 */
int LocateElem_index(LinkList L, ElemType e) {
  int i = 0;
  LinkList p = L->next;                               // p指向链表中的第一个结点
  while (p && p->data != e) {
    p = p->next;
    i++;
  }
  // 如果到了最后,则表示没有匹配的
  if (i == Length(L)) {
    return -1;
  }
  return i;
}

/**
 * 在带有头结点的单链表L中的第i个结点之前插入元素e，即前插法
 * @param L
 * @param i 插入位置，1开始
 * @param e
 * @return
 */
bool ListInsert(LinkList &L, int i, ElemType e) {
  LinkList p = L, s;
  int j = 0;
  while (p->next && j < i - 1) {     // 寻找第i-1个结点,并让p指向此结点
    p = p->next;
    j++;
  }
  if (j != i - 1) return false;                   // i的位置不合理
  if ((s = (LNode *) malloc(sizeof(LNode))) == NULL) exit(1);  // 存储分配失败
  s->data = e;
  s->next = p->next;
  p->next = s;                  // 插入新结点
  return true;
}

/**
 * 删除带有头结点的单链表L中的第i个结点，并让e返回其值
 * @param L
 * @param i
 * @param e
 * @return
 */
bool ListDelete(LinkList &L, int i, ElemType &e) {
  LinkList p = L, q;
  int j = 0;
  while (p->next->next && j < i - 1) {
    p = p->next;
    j++;
  } //寻找第i-1个结点,并让p指向此结点
  if (j != i - 1) return false;                    // i的位置不合理
  q = p->next;                                     // q指向其后继
  p->next = q->next;                               // 删除q所指结点
  e = q->data;
  free(q);
  return true;
}

/**
 * 取出单链表L中第i个元素，并用e返回其值
 * @param L
 * @param i
 * @param e
 * @return
 */
bool GetElem(LinkList L, int i, ElemType &e) {
  LinkList p = L;
  int j = 0;
  while (p->next && j < i) {
    p = p->next;
    j++;
  }  // 寻找第i个结点,并让p指向此结点
  if (j != i) return false;                         // i的位置不合理
  e = p->data;                                     // 被取元素的值赋给e
  return true;
}

/**
 * 已知一维数组A[n]中存有线性表的数据元素，利用尾插法创建单链表L
 * @param L
 * @param a
 * @param n
 */
void CreateList_Rear(LinkList &L, ElemType a[], int n) {
  LinkList p, q = L;
  int i;
  L = (LinkList) malloc(sizeof(LNode));    // 创建立头结点
  for (i = 0; i < n; i++) {
    p = (LinkList) malloc(sizeof(LNode));          // 创建新结点
    p->data = a[i];                               // 赋元素值
    q->next = p;                                  // 插入在尾结点之后
    q = p;                                         // q指向新的表尾
  }
  q->next = NULL;                                    // 表尾结点next域置空
}

/**
 * 已知一维数组A[n]中存有线性表的数据元素，利用头插法创建单链表L
 * @param L
 * @param a
 * @param n
 */
void CreateList_Front(LinkList &L, ElemType a[], int n) {
  LinkList p;
  int i;
  L = (LinkList) malloc(sizeof(LNode));              //创建立头结点
  L->next = NULL;
  for (i = n - 1; i >= 0; i--) {
    p = (LinkList) malloc(sizeof(LNode));           //创建新结点
    p->data = a[i];                                // 赋元素值
    p->next = L->next;                          // 插入在头结点和第一个结点之间
    L->next = p;
  }
}

/**
 * 打印输出
 * @param L
 */
void ListPrint(LinkList L) {
  LinkList p = L->next;  // 指向头结点的下一个节点，应为头结点没东西
  while (p) {
    cout << setw(6) << p->data;
    p = p->next;
  }
  cout << endl;
}

/**
 * 销毁
 * @param L
 */
void DestroyList(LinkList &L) {
  LinkList p = L, p1;
  while (p) {
    p1 = p;
    p = p->next;
    free(p1);
  }
  L = NULL;
}

#endif //DATASTRUCTURE_LINKLIST_H
