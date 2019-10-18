//
// Created by liang on 2019/10/10.
//

#include<iostream>
using namespace std;
const int MAXN=1001;
const int MINH=-10001;
int H[MAXN],size;
void Create(){
  size=0;
  H[0]=MINH;// 设置岗哨
}
void Insert(int X){
  // 将x插入到H，这里省略了检查堆是否满
  int i;
  for(i=++size;H[i/2]>X;i/=2){
    H[i]=H[i/2];
  }
  H[i] = X;
}
int main()
{
  int n,m,i,j,x;
  cin>>n>>m;
  Create();
  for(i=0;i<n;i++){
    cin>>x;
    Insert(x);
  }

  for(i=0;i<m;i++){
    cin>>j;
    cout<<H[j];
    while(j>1){
      j/=2;
      cout<<" "<<H[j];
    }
    cout<<endl;
  }

  return 0;
}


