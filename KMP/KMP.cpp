//
// Created by liang on 2019/8/31.
//

#include <vector>
#include <string>
#include <iostream>

using namespace std;

//����ģʽP�Ĳ���ƥ��ֵ��������next������
void kmpNext(const string &P, vector<int> &next) {
  int i, j;
  int m = P.size();//ģʽ�ַ����ĳ���
  next[0] = 0;//���ַ��ĶԳ�ֵ�϶�Ϊ0
  for (i = 1, j = 0; i < m; ++i) {//����ÿһ��λ�õĶԳ�ֵ

    //j����������¼��һ��ǰ׺�����Գ�ֵ
    while (j > 0 && P[i] != P[j]) {
      j = next[j - 1];//j��ѭ���ݼ���ֵ��ע�����next[j]<j���ǳ���
    }

    if (P[i] == P[j]) {
      j++;//����j��Ψһ����
    }

    next[i] = j;//��ȡ����ֵ
  }
}


void KmpMatch(const string &T, const string &P, vector<int> &next) {
  int n, m;
  n = T.size();
  m = P.size();
  kmpNext(P, next);
  for (int i = 0, q = 0; i < n; ++i) {
    while (q > 0 && P[q] != T[i]) {
      q = next[q - 1];
    }
    if (P[q] == T[i]) {
      q++;
    }
    if (q == m) {
      cout << "ģʽ�ı���ƫ��Ϊ��" << (i - m + 1) << endl;
      q = next[q - 1];//Ѱ����һ��ƥ��
    }
  }
}

int main() {
  vector<int> next(20, 0); //����������ַ����Ĳ���ƥ�������ǰ׺�����ĶԳ�ֵ��
  string T = "BBC ABCDAB ABCDABCDABDE";//�ı�
  string P = "ABCDABD";//�������ַ���
  cout << "�ı��ַ�����" << T << endl;
  cout << "ģʽ�ַ�����" << P << endl;
  KmpMatch(T, P, next);
  cout << "ģʽ�ַ�����ǰ׺������" << endl;
  for (int i = 0; i < P.size(); i++) {
    cout << next[i] << " ";
  }
  cout << endl;
  return 0;
}


