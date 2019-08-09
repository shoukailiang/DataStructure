//
// Created by liang on 2019/8/8.
//

typedef int ElemType;    // ˳�����Ԫ������Ϊint
#include <iostream>
#include <iomanip>  // ���ļ�����malloc()��realloc()��free()�Ⱥ���
using namespace std;
#include "SqList.h"



// ����
int main() {
  SqList mylist;
  int i, j, temp, forLocate, forGet, forInsert, forDelete;
  // ��ʼ��
  InitList(mylist, 50, 10);
  // ����Ԫ��
  for (i = 0, j = 1; i < 10; i++, j++) {
    if (!ListInsert(mylist, i, 2 * j)) {
      cout << "����!" << endl;
      return 0;
    }
  }
  cout << "�Ҵ�����һ��˳�����Ϊ��" << Length(mylist) << endl;
  cout << endl << "���е�Ԫ������Ϊ��" << endl;
  PrintList(mylist);


  cout << endl << "***����ִ��Ԫ�ض�λ����,��������Ҫ���ҵ�Ԫ�أ�***" << endl;
  cin >> forLocate;
  j = LocateElem(mylist, forLocate);
  if (j != -1) {
    cout << "�ҵ��ˣ����ǵ�" << j + 1 << "��Ԫ�ء�" << endl;
  } else {
    cout << "��λʧ�ܣ�" << endl;
  }


  cout << endl << "***����ִ��ȡԪ�ز���,��Ҫ�ҵڼ���Ԫ�أ������룺***" << endl;
  cin >> forGet;
  if (GetElem(mylist, forGet - 1, temp)) {
    cout << "��" << forGet << "��Ԫ�ص�ֵ��:" << temp << endl;
  } else {
    cout << "ȡԪ��ʧ�ܣ�" << endl;
  }


  cout << endl << "***����ִ�в������,��Ҫ��ʲôԪ�ز���˳��������룺***" << endl;
  cin >> forInsert;
  cout << "***���뵽�ڼ���λ�ã�***" << endl;
  cin >> temp;
  if (!ListInsert(mylist, temp - 1, forInsert)) {
    cout << "����!" << endl;
    return 0;
  } else {
    cout << "����ɹ���������˳���Ϊ��" << endl;
  }
  PrintList(mylist);


  cout << endl << "***����ִ��ɾ������,��Ҫɾ���ڼ���Ԫ�أ������룺***" << endl;
  cin >> forDelete;
  if (!ListDelete(mylist, forDelete - 1, temp)) {
    cout << "ɾ��ʧ��!" << endl;
    return 0;
  } else {
    cout << "ɾ���ɹ���ɾ�����˳���Ϊ��" << endl;
  }
  PrintList(mylist);

  cout << endl << "***����ִ�г�������***" << endl;
  DestroyList(mylist);

  cout << "***˳����Ѿ����٣�***" << endl;
  return 0;
}