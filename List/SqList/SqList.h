//
// Created by liang on 2019/9/19.
//

#ifndef DATASTRUCTURE_SQLIST_H
#define DATASTRUCTURE_SQLIST_H


#define MAXSIZE 100  // MAXSIZE ����Ϊ Data ����Ĵ�С
#define ERROR -1

typedef struct LNode *List;

struct LNode {
  ElementType Data[MAXSIZE];
  int Last;            // ���һ����Ԫ�ظ���-1���������±�
};

//�����±�Ϊ i ��Ԫ�أ�L->Data[i]
//���Ա�ĳ��ȣ�L->Last+1


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
    printf("����");
    return false;
  }
  if (i < 0 || L->Last + 1 < i) {  //λ��Խ�磬����������� L->Data[L->Last+1]�����涼������λ����
    printf("λ�ò��Ϸ�");
    return false;
  }

  for (j = L->Last; j >= i; j--)   // �Ӻ���ǰ�������Ųһ������ a[i]�ڳ�λ��
    L->Data[j + 1] = L->Data[j];
  L->Data[i] = X;    //��Ԫ�ز���
  L->Last++;    // Last��Ȼָ�����Ԫ��
  return true;
}

bool Delete(List L, int i) {
  int j;
  if (i < 0 || L->Last < i) {  //λ��Խ�磬��ɾ����ൽ L->Data[L->Last]
    printf("L->Data[%d]������Ԫ��", i);
    return false;
  }
  for (j = i; j <= L->Last; j++)   // ��ǰ����������ǰŲһ������ a[i] ������
    L->Data[j - 1] = L->Data[j];
  L->Last--;  // Last��Ȼָ�����Ԫ��
  return true;
}

int Length(List L) {
  return L->Last + 1;
}

// �������
ElementType FindKth(List L, int K) {
  if (K < 0 || K > L->Last) {
    printf("L->Data[%d]������Ԫ��", K);
    return ERROR;
  }
  return L->Data[K];
}

#endif //DATASTRUCTURE_SQLIST_H
