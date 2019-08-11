//
// Created by liang on 2019/8/8.
//

#ifndef TEST_C_SQLIST_H
#define TEST_C_SQLIST_H

#define LIST_INIT_SIZE  100               // ˳���(Ĭ�ϵ�)�ĳ�ʼ�����������
#define LIST_INCREMENT  10                // (Ĭ�ϵ�)�����ռ���


/**
 *���龲̬����,��ȱ��
 */
typedef struct {
  ElemType elem[LIST_INIT_SIZE];
  int length;
  int listsize;
  int incrementsize;
} SqList_static;

/**
 *���鶯̬����
 */
typedef struct {
  ElemType *elem;                       // �洢����Ԫ�ص�һά����
  int length;                           // ���Ա�ĵ�ǰ����
  int listsize;                         // ��ǰ�����������������ElemTypeΪ��λ��
  int incrementsize;                    // �����ռ�������ElemTypeΪ��λ��
} SqList;

/**
 * ����һ���������Ϊmaxsize��˳���
 * @param L
 * @param maxsize
 * @param increase
 */
void InitList(SqList &L, int maxsize = LIST_INIT_SIZE, int increase = LIST_INCREMENT) {
  L.elem = (ElemType *) malloc(maxsize * sizeof(ElemType));  // Ϊ˳������һ���������Ϊ maxsize ������ռ�
  if (!L.elem) exit(1);
  L.length = 0;
  L.listsize = maxsize;
  L.incrementsize = increase;  // ��Ҫʱ������incresize��Ԫ�ؿռ�
}

/**
 * ����
 * @param L
 * @return ���س���
 */
int Length(SqList L) {
  return L.listsize;
}

/**
 * �Ƿ�Ϊ��
 * @param L
 * @return �����Ƿ�Ϊ��
 */
bool Empty(SqList L) {
  if (L.length == 0) {
    return true;
  } else {
    return false;
  }
}

/**
 * ����
 * @param L
 * @param e
 * @return  ����,�ҵ������±꣬�Ҳ�������-1
 */
int LocateElem(SqList L, ElemType e) {
  for (int i = 0; i < L.length; i++)
    if (L.elem[i] == e) return i;   // �ҵ������ж�������Ԫ��Ϊ�� i ��Ԫ��
  return -1;                     // �����Ա��в����������ж�������Ԫ��
}

/**
 * ��˳���L�ĵ�i��Ԫ��֮ǰ�����µ�Ԫ��e��
 * @param L
 * @param i
 * @param e
 * @return
 */
bool ListInsert(SqList &L, int i, ElemType e) {
  // �����е�ǰ�������㣬��Ԥ�������������
  int j;
  if (i < 0 || i > L.length) return false;            // iֵ���Ϸ�
  if (L.length >= L.listsize) {                   // ��ǰ�洢�ռ������������ռ�
    L.elem = (ElemType *) realloc(L.elem, (L.listsize + L.incrementsize) * sizeof(ElemType));
    if (!L.elem) exit(1);                   // �洢����ʧ��
    L.listsize += L.incrementsize;           // ��ǰ�洢��������
  }
  for (j = L.length; j > i; j--) {
    L.elem[j] = L.elem[j - 1];
  }
  L.elem[i] = e;                           // ����Ԫ��e
  L.length++;                            // ����1
  return true;
}

/**
 * ��˳���L��ɾ����i��Ԫ�أ�����e������ֵ
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
 * @return  ȡ��ʧ�ܷ���false,�ɹ�����true,����e������ֵ
 */
bool GetElem(SqList L, int i, ElemType &e) {     // ȡ��˳���L�е�i��Ԫ�أ�����e������ֵ��
  if (i < 0 || i > L.length) return false;            // iֵ���Ϸ�
  if (L.length <= 0) return false;               // ���������Ԫ�ؿ�ȡ
  e = L.elem[i];                                 // ��ȡԪ�ص�ֵ����e
  return true;
}

/**
 * ��ӡ���
 * @param L
 */
void PrintList(SqList L) {
  for (int i = 0; i < L.length; i++) {
    cout << setw(6) << L.elem[i];
  }
  cout << endl;
}

/**
 * ���ٿ�~~~
 * @param L
 */
void DestroyList(SqList &L) {       // �ͷ�˳���L��ռ�洢�ռ�
  free(L.elem);
  L.elem = NULL;
  L.listsize = 0;
  L.length = 0;
}

#endif //TEST_C_SQLIST_H
