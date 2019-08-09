//
// Created by liang on 2019/8/8.
//

#ifndef DATASTRUCTURE_LINKLIST_H
#define DATASTRUCTURE_LINKLIST_H




/**
 * ͷ��㲻������ݣ����ÿյ�ͷ��㣬��Ϊ�˲���ͳһ��һ������ʱ����ǰ�����к�̣������ձ�ͷǿձ��ͳһ��
 */
typedef struct Node {
  ElemType data;
  struct Node *next;
} LNode, *LinkList;

/**
 * ��ʼ��
 * @param L
 */
void InitList(LinkList &L) {
  L = (LNode *) malloc(sizeof(LNode));
  if (!L) {                          // �洢����ʧ��
    exit(1);
  }
  L->next = NULL;
}

/**
 * ����
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
 * ��L��ָ�ĵ������в��ҵ�һ��ֵ��e ��ȵĽ��
 * @param L
 * @param e
 * @return �����ڣ��򷵻���ָ�룻���򷵻ؿ�ָ��
 */
LNode *LocateElem(LinkList L, ElemType e) {
  LinkList p = L->next;                  // pָ�������еĵ�һ�����
  while (p && p->data != e) {
    p = p->next;
  }
  return p;
}

/**
 * ��L��ָ�ĵ������в��ҵ�һ��ֵ��e��ȵĽ��
 * @param L
 * @param e
 * @return �����ڣ��򷵻�Ԫ��˳�򣬷��򷵻�-1
 */
int LocateElem_index(LinkList L, ElemType e) {
  int i = 0;
  LinkList p = L->next;                               // pָ�������еĵ�һ�����
  while (p && p->data != e) {
    p = p->next;
    i++;
  }
  // ����������,���ʾû��ƥ���
  if (i == Length(L)) {
    return -1;
  }
  return i;
}

/**
 * �ڴ���ͷ���ĵ�����L�еĵ�i�����֮ǰ����Ԫ��e����ǰ�巨
 * @param L
 * @param i ����λ�ã�1��ʼ
 * @param e
 * @return
 */
bool ListInsert(LinkList &L, int i, ElemType e) {
  LinkList p = L, s;
  int j = 0;
  while (p->next && j < i - 1) {     // Ѱ�ҵ�i-1�����,����pָ��˽��
    p = p->next;
    j++;
  }
  if (j != i - 1) return false;                   // i��λ�ò�����
  if ((s = (LNode *) malloc(sizeof(LNode))) == NULL) exit(1);  // �洢����ʧ��
  s->data = e;
  s->next = p->next;
  p->next = s;                  // �����½��
  return true;
}

/**
 * ɾ������ͷ���ĵ�����L�еĵ�i����㣬����e������ֵ
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
  } //Ѱ�ҵ�i-1�����,����pָ��˽��
  if (j != i - 1) return false;                    // i��λ�ò�����
  q = p->next;                                     // qָ������
  p->next = q->next;                               // ɾ��q��ָ���
  e = q->data;
  free(q);
  return true;
}

/**
 * ȡ��������L�е�i��Ԫ�أ�����e������ֵ
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
  }  // Ѱ�ҵ�i�����,����pָ��˽��
  if (j != i) return false;                         // i��λ�ò�����
  e = p->data;                                     // ��ȡԪ�ص�ֵ����e
  return true;
}

/**
 * ��֪һά����A[n]�д������Ա������Ԫ�أ�����β�巨����������L
 * @param L
 * @param a
 * @param n
 */
void CreateList_Rear(LinkList &L, ElemType a[], int n) {
  LinkList p, q = L;
  int i;
  L = (LinkList) malloc(sizeof(LNode));    // ������ͷ���
  for (i = 0; i < n; i++) {
    p = (LinkList) malloc(sizeof(LNode));          // �����½��
    p->data = a[i];                               // ��Ԫ��ֵ
    q->next = p;                                  // ������β���֮��
    q = p;                                         // qָ���µı�β
  }
  q->next = NULL;                                    // ��β���next���ÿ�
}

/**
 * ��֪һά����A[n]�д������Ա������Ԫ�أ�����ͷ�巨����������L
 * @param L
 * @param a
 * @param n
 */
void CreateList_Front(LinkList &L, ElemType a[], int n) {
  LinkList p;
  int i;
  L = (LinkList) malloc(sizeof(LNode));              //������ͷ���
  L->next = NULL;
  for (i = n - 1; i >= 0; i--) {
    p = (LinkList) malloc(sizeof(LNode));           //�����½��
    p->data = a[i];                                // ��Ԫ��ֵ
    p->next = L->next;                          // ������ͷ���͵�һ�����֮��
    L->next = p;
  }
}

/**
 * ��ӡ���
 * @param L
 */
void ListPrint(LinkList L) {
  LinkList p = L->next;  // ָ��ͷ������һ���ڵ㣬ӦΪͷ���û����
  while (p) {
    cout << setw(6) << p->data;
    p = p->next;
  }
  cout << endl;
}

/**
 * ����
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
