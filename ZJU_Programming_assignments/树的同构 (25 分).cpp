//
// Created by liang on 2019/10/8.
//
#include <stdio.h>

#define OK 1
#define ERROR 0

#define MaxTree 10
#define Null -1        //区别于系统的NULL 0

typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef char ElementType;/* ElemType类型根据实际情况而定，这里假设为char */

typedef struct TreeNode {
  ElementType data;
  int left;
  int right;
} Tree;

Tree T1[MaxTree], T2[MaxTree];

int BulidTree(Tree T[]) {
  int N, check[MaxTree], root = Null;    //root = Null 空树则返回Null
  char cl, cr;        //左右孩子序号
  scanf("%d\n", &N);
  if (N) {
    for (int i = 0; i < N; i++)
      check[i] = 0;
    for (int i = 0; i < N; i++) {
      scanf("%c %c %c\n", &T[i].data, &cl, &cr);
      //找root
      if (cl != '-') {
        T[i].left = cl - '0';
        check[T[i].left] = 1;    //不是根节点
      } else {
        T[i].left = Null;
      }
      if (cr != '-') {
        T[i].right = cr - '0';
        check[T[i].right] = 1;    //不是根节点
      } else {
        T[i].right = Null;
      }
    }

    for (int i = 0; i < N; i++)        //check[]=0的为根节点
      if (!check[i]) {
        root = i;
        break;
      }
  }
  return root;
}

Status Isomprphic(int root1, int root2) {
  if ((root1 == Null) && (root2 == Null))//都是空 ，同构
    return OK;
  if ((root1 == Null) && (root2 != Null) || (root1 != Null) && (root2 == Null))//其中一个为空，不同构
    return ERROR;
  if (T1[root1].data != T2[root2].data)     //根数据不同,不同构
    return ERROR;
  if ((T1[root1].left == Null) && (T2[root2].left == Null)) //左子树为空，则判断右子树
    return Isomprphic(T1[root1].right, T2[root2].right);

  if ((T1[root1].left != Null) && (T2[root2].left != Null) &&
      (T1[T1[root1].left].data == T2[T2[root2].left].data))//两树左子树皆不空，且值相等
    return (Isomprphic(T1[root1].left, T2[root2].left) &&  //判断其子树
            Isomprphic(T1[root1].right, T2[root2].right));
  else //两树左子树有一个空  或者  皆不空但值不等
    // 1.两个左子树的element值不一样（有可能是左边和右边同构，右边和左边同构）
    // 2.左边指向空树，右边指向不空树（有可能是左边和右边同构，右边和左边同构）
    return (Isomprphic(T1[root1].left, T2[root2].right) &&  //交换左右子树判断
            Isomprphic(T1[root1].right, T2[root2].left));

}

int main() {
  int root1, root2;
  root1 = BulidTree(T1);
  root2 = BulidTree(T2);
  if (Isomprphic(root1, root2))
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
