//
// Created by liang on 2019/9/22.
//
#include<stdio.h>
#include<stdlib.h>

typedef struct PolyNode *Polynomial;
struct PolyNode {
  int coef;
  int expon;
  Polynomial next;
};

void Attach(int c, int e, Polynomial *pRear) {
  Polynomial tmp;
  tmp = (Polynomial) malloc(sizeof(struct PolyNode));
  tmp->coef = c;
  tmp->expon = e;
  tmp->next = NULL;
  (*pRear)->next = tmp;
  (*pRear) = tmp;
}

Polynomial PolyRead() {
  Polynomial P, Rear, tmp;
  P = (Polynomial) malloc(sizeof(struct PolyNode));
  P->next = NULL;  //创建头节点完成
  Rear = P;
  int N, c, e, i;
  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%d %d", &c, &e);
    Attach(c, e, &Rear);
  }
  tmp = P;
  P = P->next;
  free(tmp);
  return P;
}

void PolyPrint(Polynomial P) {
  int flag = 0;
  if (!P) {
    printf("0 0");
  }
  while (P) {
    if (!flag)
      flag = 1;
    else
      printf(" ");
    printf("%d %d", P->coef, P->expon);
    P = P->next;
  }
  printf("\n");
}

Polynomial PolyMult(Polynomial P1, Polynomial P2) {
  Polynomial p1, p2, Rear, tmp, P;
  int c, e;
  P = (Polynomial) malloc(sizeof(struct PolyNode));
  P->next = NULL;
  Rear = P;
  p1 = P1;
  p2 = P2;
  if (!p1 || !p2)
    return NULL;
  while (p2) {
    c = p1->coef * p2->coef;
    e = p1->expon + p2->expon;
    if (c != 0) {
      Attach(c, e, &Rear);
      p2 = p2->next;
    }
  }
  p1 = p1->next;
  while (p1) {
    p2 = P2;
    Rear = P;
    while (p2) {
      c = p1->coef * p2->coef;
      e = p1->expon + p2->expon;
      if (c != 0) {

      }
      while (Rear->next && Rear->next->expon > e) {
        Rear = Rear->next;
      }
      if (Rear->next && Rear->next->expon == e) {
        if (Rear->next->coef + c)
          Rear->next->coef += c;
        else {
          tmp = Rear->next;
          Rear->next = tmp->next;
          free(tmp);
        }
      } else {
        tmp = (Polynomial) malloc(sizeof(struct PolyNode));
        tmp->expon = e;
        tmp->coef = c;
        tmp->next = Rear->next;
        Rear->next = tmp;
        Rear = tmp;
      }
      p2 = p2->next;
    }
    p1 = p1->next;
  }
  tmp = P;
  P = P->next;
  free(tmp);
  return P;
}

Polynomial PolyAdd(Polynomial P1, Polynomial P2) {
  Polynomial p1, p2, Rear, tmp, P;
  int coefSum;
  P = (Polynomial) malloc(sizeof(struct PolyNode));
  P->next = NULL;
  tmp = P;
  Rear = tmp;
  p1 = P1;
  p2 = P2;
  while (p1 && p2) {
    if (p1->expon == p2->expon) {
      coefSum = p1->coef + p2->coef;
      if (coefSum) {
        Attach(p1->coef + p2->coef, p1->expon, &Rear);
      }
      p1 = p1->next;
      p2 = p2->next;
    } else if (p1->expon > p2->expon) {
      Attach(p1->coef, p1->expon, &Rear);
      p1 = p1->next;
    } else if (p1->expon < p2->expon) {
      Attach(p2->coef, p2->expon, &Rear);
      p2 = p2->next;
    }
  }
  if (p1) {
    Rear->next = p1;
  } else if (p2) {
    Rear->next = p2;
  }
  tmp = P;
  P = P->next;
  free(tmp);
  return P;
}

int main(int argc, char const *argv[]) {
  Polynomial P1, P2, PMul, PAdd;
  P1 = PolyRead();
  P2 = PolyRead();
  PMul = PolyMult(P1, P2);
  PAdd = PolyAdd(P1, P2);
  PolyPrint(PMul);
  PolyPrint(PAdd);
  return 0;
}