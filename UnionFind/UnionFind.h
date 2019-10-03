//
// Created by liang on 2019/10/3.
//

#ifndef DATASTRUCTURE_UNIONFIND_H
#define DATASTRUCTURE_UNIONFIND_H


typedef int ElementType;
typedef struct {
  ElementType Data; // ��ֵ
  int parent;  // ָ�򸸽��
} SetType;

// ����
int Find(SetType s[], ElementType x) {
  int i;
  // �ҵ������и�ֵ��Ӧ���±�
  for (i = 0; i < MaxSize && s[i].Data != x; i++);
  if (MaxSize <= i) // ���û���ҵ������� -1
    return -1;
  // �ҵ��ý��ĸ����
  for (; s[i].parent >= 0; i = s[i].parent);
  return i; // ���ظ���������� s �е��±�
}

// ��
void Union(SetType s[], ElementType x1, ElementType x2) {
  int root1 = Find(s, x1);  // �ҵ� x1 �ĸ�����±�
  int root2 = Find(s, x2);  // �ҵ� x2 �ĸ�����±�
  // ����������±겻ͬ��˵������һ������
  if (root1 != root2) {
    s[root1].parent = root2;   // �� x1 �ҵ� x2 �ļ���
  }
}


#endif //DATASTRUCTURE_UNIONFIND_H
