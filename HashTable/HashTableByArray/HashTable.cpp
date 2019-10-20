//
// Created by liang on 2019/10/20.
//

#include <bits/stdc++.h>
using namespace std;
#include "HashTable.h"

int main(){
  HashTable H = CreateTable(9);
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
    int tmp;
    cin>>tmp;
    Insert(H,tmp,i);
  }
  output(H);
  return 0;
}
