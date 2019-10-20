//
// Created by liang on 2019/10/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ElementType int
#define MaxN 35

typedef struct SNode *Stack;
struct SNode
{
  ElementType *data;
  int top;
  int MaxSize;
};

int pre[MaxN], in[MaxN], post[MaxN]; //存储先序、中序、后序遍历的数组

Stack CreateStack(int MaxSize);
void Push(Stack PtrS, ElementType X);
ElementType Pop(Stack PtrS);
void Post_solve(int preL, int inL, int postL, int n);

int main()
{
  int i, j = 0, k = 0, x, N;
  int first = 1;
  char str[10];

  scanf("%d", &N);
  Stack s = CreateStack(N);
  for (int i = 0; i < 2 * N; i++)
  {
    scanf("%s", str);
    if (strcmp(str, "Push") == 0)
    {
      scanf("%d", &x);
      pre[j++] = x;
      Push(s, x);
    }
    else
    {
      in[k++] = Pop(s);
    }
  }
  Post_solve(0, 0, 0, N);
  for (i = 0; i < N; i++)
  {
    if (first)
    {
      first = 0;
      printf("%d", post[i]);
    }
    else
    {
      printf(" %d", post[i]);
    }
  }

  return 0;
}

void Post_solve(int preL, int inL, int postL, int n)
{ /*preL,inL,postL分别表示当前遍历数组的最左端*/
  int i, root;
  int Left, Right;

  if (n == 0)
    return; //当递归至只有没有数时，直接返回
  if (n == 1)
  {
    post[postL] = pre[preL]; //当递归至只有一个数时，先序，中序，后序的数组里面的值是相等的
    return;
  }
  root = pre[preL];           //当前树的根结点肯定是先序遍历的第一个结点
  post[postL + n - 1] = root; //在后序遍历中，当前树的根结点肯定是最后访问的
  for (i = 0; i < n; i++)
  { /*在中序遍历中找到当前树的根结点*/
    if (in[inL + i] == root)
      break;
  }
  Left = i;                                                         //当前树的左子树所包含的结点数
  Right = n - Left - 1;                                             //当前树的右子树所包含的结点数
  Post_solve(preL + 1, inL, postL, Left);                           //递归解决左子树的后序遍历
  Post_solve(preL + Left + 1, inL + Left + 1, postL + Left, Right); //递归解决右子树的后序遍历
}

//建立空栈
Stack CreateStack(int MaxSize)
{
  Stack S = (Stack)malloc(sizeof(struct SNode));
  S->data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
  S->top = -1;
  S->MaxSize = MaxSize;

  return S;
}
//入栈
void Push(Stack S, ElementType X)
{
  if (S->top == S->MaxSize - 1)
    printf("堆栈满\n");
  else
    S->data[++(S->top)] = X;
}
//出栈
#define Error -1
ElementType Pop(Stack S)
{
  if (S->top == -1)
  {
    printf("空栈\n");
    return Error;
  }
  else
  {
    return (S->data[(S->top)--]);
  }
}

