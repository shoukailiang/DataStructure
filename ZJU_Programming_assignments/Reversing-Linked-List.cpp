//
// Created by liang on 2019/10/7.
//

#include <stdio.h>

#define MAX 100000
typedef struct {
  int data;
  int next;
} Node;

//计算并返回单链表节点数
int CountNodes(Node *list, int pList) {
  int cnt = 1;
  while ((pList = list[pList].next) != -1)
    cnt++;
  return cnt;
}

int ReverseK(Node *list, int pList, int n, int k) {
  int prevNode, currNode, nextNode;
  //需要连接的前一个节点、当前节点、后一个节点
  prevNode = -1;
  currNode = pList;
  nextNode = list[currNode].next;
  int lastHead, head = -1;
  for (int i = 0; i < n / k; i++) {  //分为n/k段分别逆转，每段k个节点
    lastHead = head;            //记录前一段的（未逆转的）头结点，以便连接到当前段的(未逆转的）尾节点
    head = currNode;            //记录当前段的头结点
    for (int j = 0; j < k; j++) { //k个节点逆转：后一个节点指向前一个节点
      list[currNode].next = prevNode;
      prevNode = currNode;
      currNode = nextNode;
      nextNode = list[nextNode].next;
    }
    if (i == 0)          //第一段逆转后的头结点将作为表头返回
      pList = prevNode;
    else                //连接逆转后的前后两段
      list[lastHead].next = prevNode;
  }
  list[head].next = currNode;     //将不用逆转的剩余部分连接到逆转链表尾部
  return pList;
}

void printList(Node *list, int p) {
  while (list[p].next != -1) {
    printf("%05d %d %05d\n", p, list[p].data, list[p].next);
    p = list[p].next;
  }
  printf("%05d %d %d\n", p, list[p].data, list[p].next);
}

int main() {
  int pList, n, k;
  scanf("%d%d%d", &pList, &n, &k);
  Node list[MAX];
  int addr, data, next;
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &addr, &data, &next);
    list[addr].data = data;
    list[addr].next = next;
  }
  int num = CountNodes(list, pList);  //因输入中有无效的节点，需要先计算单链表中的总结点数
  int pNewList = ReverseK(list, pList, num, k);
  printList(list, pNewList);

  return 0;
}
