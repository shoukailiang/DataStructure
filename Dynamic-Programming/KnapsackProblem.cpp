//
// Created by liang on 2019/8/26.
//

#include <iostream>
#include <cstring>

#define ROW 4
#define COL 5

using namespace std;


int main() {

  int w[] = {0, 1, 4, 3};//物品的重量,0用来占位
  int val[] = {0, 1500, 3000, 2000}; //物品的价值 这里val[i]
  int m = 4; //背包的容量

  int n = sizeof(val) / sizeof(val[0]) - 1; //物品的个数 3

  //v[i][j] 表示在前i个物品中能够装入容量为j的背包中的最大价值
  int v[ROW][COL];


  //为了记录放入商品的情况，我们定一个二维数组
  int path[ROW][COL];

  // 全设置为0
  memset(v, 0, sizeof(v));

  for (int i = 1; i < ROW; i++) { //不处理第一行 i是从1开始的
    for (int j = 1; j < COL; j++) {//不处理第一列, j是从1开始的
      //公式
      if (w[i] > j) {
        v[i][j] = v[i - 1][j];
      } else {
        if (v[i - 1][j] < val[i] + v[i - 1][j - w[i]]) {
          v[i][j] = val[i] + v[i - 1][j - w[i]];
          //把当前的情况记录到path
          path[i][j] = 1;
        } else {
          v[i][j] = v[i - 1][j];
        }
      }
    }
  }

  //输出一下v 看看目前的情况
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }

  cout << "============================" << endl;
  //输出最后我们是放入的哪些商品
  //遍历path, 这样输出会把所有的放入情况都得到, 其实我们只需要最后的放入
  int i = n; //行的最大下标
  int j = m;  //列的最大下标
  while (i > 0 && j > 0) { //从path的最后开始找
    if (path[i][j] == 1) {
      printf("第%d个商品放入到背包\n", i);
      j -= w[i];
    }
    i--;
  }
  return 0;
}