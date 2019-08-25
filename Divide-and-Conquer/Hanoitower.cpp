//
// Created by liang on 2019/8/24.
//
#include <iostream>

using namespace std;

void hanoiTower(int num, char a, char b, char c) {
  // 如果只要一个盘
  if (num == 1) {
    cout << "第1个盘从 " << a << "->" << c << endl;
  } else {
    //如果我们有 n >= 2 情况，我们总是可以看做是两个盘 1.最下边的一个盘 2. 上面的所有盘
    //1. 先把 最上面的所有盘 A->B， 移动过程会使用到 c
    hanoiTower(num - 1, a, c, b);
    //2. 把最下边的盘 A->C
    cout << "第" << num << "个盘从 " << a << "->" << c << endl;
    //3. 把B塔的所有盘 从 B->C , 移动过程使用到 a塔
    hanoiTower(num - 1, b, a, c);
  }

}


int main() {
  hanoiTower(5, 'A', 'B', 'C');
}
