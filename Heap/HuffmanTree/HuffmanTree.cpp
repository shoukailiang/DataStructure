//
// Created by liang on 2019/9/28.
//

#include<iostream>

using namespace std;

#include<malloc.h>

#define MaxSize 1000
#define MinData -1000

#include "HuffmanTree.h"




int main() {
  MinHeap H;
  HuffmanTree Huff;
  H = create();
  Huff = Huffman(H);
  PreOrderTraversal(Huff);
  return 0;
}