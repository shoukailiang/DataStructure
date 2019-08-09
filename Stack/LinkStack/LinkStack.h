//
// Created by liang on 2019/8/9.
//

#ifndef DATASTRUCTURE_LINKSTACK_H
#define DATASTRUCTURE_LINKSTACK_H

// 链栈的结点结构和单链表相同
typedef struct Node {
  ElemType data;
  struct Node *next;
} LNode, *LinkStack;

/**
 * 初始化
 * @param S
 */
void InitStack(LinkStack &S) {
  S = NULL;
}

/**
 * 长度
 * @param S
 * @return
 */
int Length(LinkStack S) {
  int k = 0;
  LinkStack p = S;
  while (p) {
    k++;
    p = p->next;                            // 访问下一个结点。
  }
  return k;
}

/**
 * 在链栈的栈顶插入元素e
 * @param S
 * @param e
 * @return
 */
bool Push(LinkStack &S, ElemType e) {
  LinkStack p;
  if ((p = (LNode *) malloc(sizeof(LNode))) == NULL) return false;  // 存储分配失败
  p->data = e;
  p->next = S;                      // 插入新的栈顶元素
  S = p;                            // 修改栈顶指针
  return true;
}

/**
 * 删除链栈栈顶元素，并让e返回其值
 * @param S
 * @param e
 * @return
 */
bool Pop(LinkStack &S, ElemType &e) {
  LinkStack p;
  if (S)                          // 栈非空
  {
    p = S;
    S = S->next;            // 修改栈顶指针
    e = p->data;                // 元素e返回其值
    free(p);                  // 释放结点空间
    return true;
  } else return false;            // 栈空，出栈失败
}

/**
 * 获取栈顶
 * @param S
 * @param e
 * @return
 */
bool GetTop(LinkStack S, ElemType &e) {
  if (S)                    // 栈非空
  {
    e = S->data;           // 元素e返回其值
    return true;
  } else return false;      // 栈空，取栈顶元素失败
}

/**
 * 站空
 * @param S
 * @return
 */
bool StackEmpty(LinkStack S) {
  if (!S) return true;
  else return false;
}

/**
 * 销毁
 * @param S
 */
void DestroyStack(LinkStack &S) {
  LinkStack p, p1;
  p = S;
  while (p) {
    p1 = p;
    p = p->next;
    free(p1);                                // 释放p1所指的空间
  }
  S = NULL;                                    // S置空
}


#endif //DATASTRUCTURE_LINKSTACK_H
