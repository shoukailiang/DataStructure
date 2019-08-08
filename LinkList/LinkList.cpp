//
// Created by liang on 2019/8/8.
//

typedef int ElemType;

#include <iomanip>
#include <iostream>
#include "LinkList.h"

using namespace std;
// ����

int main() {
  LinkList mylist;
  int i, j, temp, forLocate, forGet, forInsert, forDelete, a[] = {6, 8, 16, 2, 34, 56, 7, 10, 22, 45};
  // ��ʼ��
  InitList(mylist);
  cout << "�ҳ�ʼ����һ��ͷ��㡣" << endl;
  // ͷ�巨����
  CreateList_Front(mylist, a, 10);
  cout << "�Ҵ�����һ����ͷ���ĵ�������Ϊ��" << Length(mylist) << endl;
  cout << endl << "���е�Ԫ������Ϊ��" << endl;
  ListPrint(mylist);

  cout << endl << "<====����ִ�ж�λԪ�ز���(��������),��Ҫ�ҵ�Ԫ��ֵ��" << endl;
  cout << "�����룺";
  cin >> forLocate;
  j = LocateElem_index(mylist, forLocate);
  if (j != -1 && GetElem(mylist, 1, temp)) {
    cout << "�ҵ��ˣ����ǵ�" << j + 1 << "��Ԫ�أ����У�" << temp << "�ǵ�һ��Ԫ�أ�====>" << endl;
    cout << "����ʵ����" << j + 2 << "�����ͷ���Ļ�" << endl;
  } else {
    cout << "û�ҵ����Ԫ�أ�" << endl;
  }
  //�������ʹ������һ��������
  cout << endl << "<====����ִ�ж�λԪ�ز���(����ָ�룬��ӡ������),��Ҫ�ҵ�Ԫ��ֵ��" << endl;
  cout << "�����룺";
  cin >> forLocate;
  LinkList q = LocateElem(mylist, forLocate);
  if (q != NULL) {
    cout << "��ַ��:" << q << endl;
    cout << "������:" << q->data << endl;
  } else {
    cout << "û�ҵ����Ԫ�أ�" << endl;
  }


  cout << endl << "<====����ִ��ȡԪ�ز���,��Ҫ�ҵڼ���Ԫ�أ�" << endl;
  cout << "�����룺";
  cin >> forGet;
  if (GetElem(mylist, forGet, temp)) {
    cout << "��" << forGet << "��Ԫ�ص�ֵ��:" << temp << "====>" << endl;

  } else {
    cout << "Ԫ�ز����ڣ�" << endl;
  }


  cout << endl << "<====����ִ�в������,��Ҫ��ʲôԪ�ز���˳���" << endl;
  cout << "�����룺";
  cin >> forInsert;
  cout << "���뵽�ڼ���λ�ã�" << endl;
  cout << "�����룺";
  cin >> temp;
  if (!ListInsert(mylist, temp, forInsert)) {
    cout << "����ʧ��!" << endl;
    return 0;
  } else {
    cout << "==>����ɹ�������������Ϊ��====>" << endl;
  }
  ListPrint(mylist);


  cout << endl << "<====����ִ��ɾ������,��Ҫɾ���ڼ���Ԫ�أ�" << endl;
  cout << "�����룺";
  cin >> forDelete;
  if (!ListDelete(mylist, forDelete, temp)) {
    cout << "ɾ��ʧ��!" << endl;
    return 0;
  } else {
    cout << "ɾ���ɹ���ɾ���������Ϊ��====>" << endl;
  }
  ListPrint(mylist);


  cout << endl << "<====����ִ�����ٲ���***" << endl;
  DestroyList(mylist);
  cout << "���ٳɹ�====>" << endl;
}