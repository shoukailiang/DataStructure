//
// Created by liang on 2019/8/24.
//
#include <iostream>

using namespace std;

void hanoiTower(int num, char a, char b, char c) {
  // ���ֻҪһ����
  if (num == 1) {
    cout << "��1���̴� " << a << "->" << c << endl;
  } else {
    //��������� n >= 2 ������������ǿ��Կ����������� 1.���±ߵ�һ���� 2. �����������
    //1. �Ȱ� ������������� A->B�� �ƶ����̻�ʹ�õ� c
    hanoiTower(num - 1, a, c, b);
    //2. �����±ߵ��� A->C
    cout << "��" << num << "���̴� " << a << "->" << c << endl;
    //3. ��B���������� �� B->C , �ƶ�����ʹ�õ� a��
    hanoiTower(num - 1, b, a, c);
  }

}


int main() {
  hanoiTower(5, 'A', 'B', 'C');
}
