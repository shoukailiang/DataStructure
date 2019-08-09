//
// Created by liang on 2019/8/8.
//

typedef int ElemType;

#include <iomanip>
#include <iostream>
#include "LinkList.h"

using namespace std;
// 测试

int main() {
  LinkList mylist;
  int i, j, temp, forLocate, forGet, forInsert, forDelete, a[] = {6, 8, 16, 2, 34, 56, 7, 10, 22, 45};
  // 初始化
  InitList(mylist);
  cout << "我初始化了一个头结点。" << endl;
  // 头插法创建
  CreateList_Front(mylist, a, 10);
  cout << "我创建了一个带头结点的单链表，表长为：" << Length(mylist) << endl;
  cout << endl << "表中的元素依次为：" << endl;
  ListPrint(mylist);

  cout << endl << "<====现在执行定位元素操作(返回索引),您要找的元素值？" << endl;
  cout << "请输入：";
  cin >> forLocate;
  j = LocateElem_index(mylist, forLocate);
  if (j != -1 && GetElem(mylist, 1, temp)) {
    cout << "找到了，它是第" << j + 1 << "个元素（其中，" << temp << "是第一个元素）====>" << endl;
    cout << "但其实他是" << j + 2 << "如果算头结点的话" << endl;
  } else {
    cout << "没找到这个元素！" << endl;
  }
  //如果你想使用另外一个函数：
  cout << endl << "<====现在执行定位元素操作(返回指针，打印出内容),您要找的元素值？" << endl;
  cout << "请输入：";
  cin >> forLocate;
  LinkList q = LocateElem(mylist, forLocate);
  if (q != NULL) {
    cout << "地址是:" << q << endl;
    cout << "内容是:" << q->data << endl;
  } else {
    cout << "没找到这个元素！" << endl;
  }


  cout << endl << "<====现在执行取元素操作,您要找第几个元素？" << endl;
  cout << "请输入：";
  cin >> forGet;
  if (GetElem(mylist, forGet, temp)) {
    cout << "第" << forGet << "个元素的值是:" << temp << "====>" << endl;

  } else {
    cout << "元素不存在！" << endl;
  }


  cout << endl << "<====现在执行插入操作,您要将什么元素插入顺序表？" << endl;
  cout << "请输入：";
  cin >> forInsert;
  cout << "插入到第几个位置？" << endl;
  cout << "请输入：";
  cin >> temp;
  if (!ListInsert(mylist, temp, forInsert)) {
    cout << "插入失败!" << endl;
    return 0;
  } else {
    cout << "==>插入成功，插入后的链表为：====>" << endl;
  }
  ListPrint(mylist);


  cout << endl << "<====现在执行删除操作,您要删除第几个元素？" << endl;
  cout << "请输入：";
  cin >> forDelete;
  if (!ListDelete(mylist, forDelete, temp)) {
    cout << "删除失败!" << endl;
    return 0;
  } else {
    cout << "删除成功，删除后的链表为：====>" << endl;
  }
  ListPrint(mylist);


  cout << endl << "<====现在执行销毁操作***" << endl;
  DestroyList(mylist);
  cout << "销毁成功====>" << endl;
}