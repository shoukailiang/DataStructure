//
// Created by liang on 2019/9/28.
//

#ifndef DATASTRUCTURE_HUFFMANTREE_H
#define DATASTRUCTURE_HUFFMANTREE_H

int A[] = {13, 1, 45, 7, 20, 4, 19, 13, 40, 33, 38};  // Ԥ�ȶ����һ��Ȩֵ
int A_length = sizeof(A) / sizeof(A[0]);  // �����䳤��

typedef struct HeapStruct *MinHeap;
typedef struct TreeNode *HuffmanTree;
struct HeapStruct {  // ��Ź��������Ķ�
  HuffmanTree *data;   // ��ֵ������
  int size;   // �ѵĵ�ǰ��С
  int capacity; // �������
};
struct TreeNode { // ��������
  int weight;  //Ȩֵ
  HuffmanTree Left;  // ������
  HuffmanTree right; // ������
};

// ��ʼ����������
HuffmanTree Create() {
  HuffmanTree Huff;
  Huff = (HuffmanTree) malloc(sizeof(struct TreeNode));
  Huff->weight = 0;
  Huff->Left = NULL;
  Huff->right = NULL;
  return Huff;
}

// ��ʼ����
MinHeap create() {
  MinHeap H;
  HuffmanTree Huff;
  H = (MinHeap) malloc(sizeof(struct HeapStruct));
  H->data = (HuffmanTree *) malloc(sizeof(struct TreeNode) * (MaxSize + 1));
  H->capacity = MaxSize;
  H->size = 0;
  // �������ڱ�
  Huff = Create();
  Huff->weight = MinData;
  H->data[0] = Huff;
  return H;
}

// ��������С��
void sort(MinHeap H, int i) {
  int parent, child;
  int tmp = H->data[i]->weight; // ȡ����ǰ"�����"ֵ
  for (parent = i; parent * 2 <= H->size; parent = child) {
    child = 2 * parent;
    if ((child != H->size) && (H->data[child + 1]->weight < H->data[child]->weight))
      child++;
    if (H->data[child]->weight >= tmp)
      break;
    else
      H->data[parent] = H->data[child];
  }
  H->data[parent]->weight = tmp;
}

// ������С��
void adjust(MinHeap H) {
  for (int i = H->size / 2; i > 0; i--)
    sort(H, i);// ÿ��"����С��"����
}

// ����
void BuildMinHeap(MinHeap H) {
  // ��Ȩֵ�������
  HuffmanTree Huff;
  for (int i = 0; i < A_length; i++) {
    Huff = Create();
    Huff->weight = A[i];
    H->data[++H->size] = Huff;
  }
  // ������
  adjust(H);
}


// ɾ����С��Ԫ��
HuffmanTree Delete(MinHeap H) {
  int parent, child;
  HuffmanTree T = H->data[1];  // ȡ�������Ĺ�������
  HuffmanTree tmp = H->data[H->size--]; // ȡ�����һ��������������Ȩֵ
  for (parent = 1; parent * 2 <= H->size; parent = child) {
    child = 2 * parent;
    if ((child != H->size) && (H->data[child + 1]->weight < H->data[child]->weight))
      child++;
    if (H->data[child]->weight >= tmp->weight)
      break;
    else
      H->data[parent] = H->data[child];
  }
  H->data[parent] = tmp;
  // ����һ�� HuffmanTree ��㣬���ϸղ�ȡ������Ȩֵ�����ظý��
  return T;
}

// ����һ����������
void Insert(MinHeap H, HuffmanTree Huff) {
  int weight = Huff->weight; // ȡ��Ȩֵ
  int i = ++H->size;
  for (; H->data[i / 2]->weight > weight; i /= 2)
    H->data[i] = H->data[i / 2];
  H->data[i] = Huff;
}

//����
void PreOrderTraversal(HuffmanTree Huff) {
  if (Huff) {
    cout << Huff->weight << " ";
    PreOrderTraversal(Huff->Left);
    PreOrderTraversal(Huff->right);
  }
}

// ���������Ĺ���
HuffmanTree Huffman(MinHeap H) {
  HuffmanTree T;
  BuildMinHeap(H); // ����
  int times = H->size;
  // �� times-1 �κϲ�
  for (int i = 1; i < times; i++) {
    T = (HuffmanTree) malloc(sizeof(struct TreeNode));
    T->Left = Delete(H);   // �Ӷ���ɾ��һ����㣬��Ϊ�� T �����ӽ��
    T->right = Delete(H);  // �Ӷ���ɾ��һ����㣬��Ϊ�� T �����ӽ��
    T->weight = T->Left->weight + T->right->weight; // ���¼���Ȩֵ
    Insert(H, T);  // �ټӽ�����
  }
  T = Delete(H);
  return T;
}


#endif //DATASTRUCTURE_HUFFMANTREE_H
