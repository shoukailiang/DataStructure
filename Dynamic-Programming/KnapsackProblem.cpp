//
// Created by liang on 2019/8/26.
//

#include <iostream>
#include <cstring>

#define ROW 4
#define COL 5

using namespace std;


int main() {

  int w[] = {0, 1, 4, 3};//��Ʒ������,0����ռλ
  int val[] = {0, 1500, 3000, 2000}; //��Ʒ�ļ�ֵ ����val[i]
  int m = 4; //����������

  int n = sizeof(val) / sizeof(val[0]) - 1; //��Ʒ�ĸ��� 3

  //v[i][j] ��ʾ��ǰi����Ʒ���ܹ�װ������Ϊj�ı����е�����ֵ
  int v[ROW][COL];


  //Ϊ�˼�¼������Ʒ����������Ƕ�һ����ά����
  int path[ROW][COL];

  // ȫ����Ϊ0
  memset(v, 0, sizeof(v));

  for (int i = 1; i < ROW; i++) { //�������һ�� i�Ǵ�1��ʼ��
    for (int j = 1; j < COL; j++) {//�������һ��, j�Ǵ�1��ʼ��
      //��ʽ
      if (w[i] > j) {
        v[i][j] = v[i - 1][j];
      } else {
        if (v[i - 1][j] < val[i] + v[i - 1][j - w[i]]) {
          v[i][j] = val[i] + v[i - 1][j - w[i]];
          //�ѵ�ǰ�������¼��path
          path[i][j] = 1;
        } else {
          v[i][j] = v[i - 1][j];
        }
      }
    }
  }

  //���һ��v ����Ŀǰ�����
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }

  cout << "============================" << endl;
  //�����������Ƿ������Щ��Ʒ
  //����path, �������������еķ���������õ�, ��ʵ����ֻ��Ҫ���ķ���
  int i = n; //�е�����±�
  int j = m;  //�е�����±�
  while (i > 0 && j > 0) { //��path�����ʼ��
    if (path[i][j] == 1) {
      printf("��%d����Ʒ���뵽����\n", i);
      j -= w[i];
    }
    i--;
  }
  return 0;
}