//
// Created by liang on 2019/10/18.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ElementType int
#define MaxN 35
#define LEFT 0
#define RIGHT 1

typedef struct SNode *Stack;
struct SNode{
  ElementType *data;
  int top;
  int MaxSize;
};

struct TreeNode{
  int left;
  int right;
}node[MaxN];

Stack CreateStack(int MaxSize);
void Push(Stack PtrS,ElementType X);
ElementType Pop(Stack PtrS);
void PostOrderTraversal(int r);

int main()
{
  int N,x;
  int root = -1,fa;
  int child = LEFT;
  char str[10];

  Stack s = CreateStack(100);
  memset(node,-1,sizeof(node));
  scanf("%d",&N);
  for(int i=0; i<2*N; i++){
    scanf("%s",str);
    if(strcmp(str,"Push") == 0){
      scanf("%d",&x);
      if(root == -1){
        root = x;  //第一个输入的必是根结点
      }else{
        if(child == LEFT){
          node[fa].left = x;
        }else{
          node[fa].right = x;
        }
      }
      fa = x;
      child = LEFT;
      Push(s,x);
    }else{
      fa = Pop(s);
      child = RIGHT;
    }
  }
  PostOrderTraversal(root);

  return 0;
}

/*****后序遍历*****/
void PostOrderTraversal(int r)
{
  static int first = 1;

  if(r != -1){
    PostOrderTraversal(node[r].left);
    PostOrderTraversal(node[r].right);
    if( first ){
      first = 0;
      printf("%d",r);
    }else{
      printf(" %d",r);
    }
  }
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
void Push(Stack S,ElementType X)
{
  if(S->top == S->MaxSize-1)
    printf("堆栈满\n");
  else
    S->data[++(S->top)] = X;
}
//出栈
#define Error -1
ElementType Pop(Stack S)
{
  if(S->top == -1){
    printf("空栈\n");
    return Error;
  }else{
    return (S->data[(S->top)--]);
  }
}