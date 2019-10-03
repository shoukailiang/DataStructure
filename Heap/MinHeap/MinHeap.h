//
// Created by liang on 2019/9/28.
//

#ifndef DATASTRUCTURE_MAXHEAP_H
#define DATASTRUCTURE_MAXHEAP_H


typedef int ElementType;
typedef struct HeapStruct *MinHeap;
struct HeapStruct {
  ElementType *Elements;   // �洢��Ԫ�ص�����
  int Size;      // �ѵĵ�ǰԪ�ظ���
  int Capacity;  // �ѵ��������
};


// ����
MinHeap Create(int MaxSize) {
  MinHeap H = (MinHeap) malloc(sizeof(struct HeapStruct));
  // Elements[0] ��Ϊ�ڱ�����Ԫ�ش�  Elements[1] ��ʼ���
  H->Elements = (ElementType *) malloc((MaxSize + 1) * sizeof(ElementType));
  H->Size = 0;
  H->Capacity = MaxSize;
  // "�ڱ�"С�ڶ������п��ܵ�ֵ
  H->Elements[0] = MinData;
  return H;
}

// �ж��Ƿ��Ѿ���
bool IsFull(MinHeap H) {
  return (H->Size == H->Capacity);
}

// �ж��Ƿ�Ϊ��
bool IsEmpty(MinHeap H) {
  return !H->Size;
}

// ���룬����ȫ�����������һ��λ�ò���
bool Insert(MinHeap H, ElementType item) {
  if (IsFull(H)) {
    printf("���������޷����룡\n");
    return false;
  }
  int i = ++H->Size;  // ָ��������һ��λ��
  for (; H->Elements[i / 2] > item; i /= 2)    // �����ұ� item С�Ľ��
    H->Elements[i] = H->Elements[i / 2];  //  ���¸�ֵ
  H->Elements[i] = item;  // �ҵ��ˣ��� item ֵ�Ž�ȥ
  return true;
}

// ɾ�����Ӹ����ɾ��
ElementType DeleteMin(MinHeap H) {
  int parent, child;
  ElementType Min, tmp;
  if (IsEmpty(H)) {
    printf("��Ϊ�գ��޷�ɾ����\n");
    return ERROR;
  }
  Min = H->Elements[1];  // �õ���Сֵ
  tmp = H->Elements[H->Size--];  // �õ���ȫ���������һ��ֵ,��--
  // �б�������parent �Ƿ������ӽ��
  for (parent = 1; parent * 2 <= H->Size; parent = child) {
    // ���Һ��ӽ�����ҽϴ��ֵ
    child = 2 * parent;  // ���ӽ��
    // child!=H->Size ��ʾ child ��Ϊ��ǰ���һ����㣬�� parent ���Һ��ӽ��
    if ((child != H->Size) && (H->Elements[child] > H->Elements[child + 1]))
      child++;
    // �� tmp �Ҹ����ʵ�λ��
    // �����ǰ���Һ��ӽ��� tmp ����˵�� tmp λ���Ѿ�����
    if (H->Elements[child] >= tmp)
      break;
    else    // ����ѽ�С�ĺ��ӽ�����������Լ�������ȥ��
      H->Elements[parent] = H->Elements[child];
  }
  H->Elements[parent] = tmp;  // �ں��ʵ�λ�ð� tmp �Ž�ȥ
  return Min;
}


// �������
void LevelOrderTraversal(MinHeap H) {
  int i;
  printf("��������Ľ���ǣ�");
  for (i = 1; i <= H->Size; i++) {
    printf("%d ", H->Elements[i]);
  }
  printf("\n");
}

/**������С��---------------------------------------**/
void percDown(MinHeap H, int i) {
  int child, parent;
  int tmp = H->Elements[i];  // �õ���ǰ"������ֵ"
  for (parent = i; parent * 2 <= H->Size; parent = child) {
    child = 2 * parent;
    if ((child != H->Size) && (H->Elements[child] > H->Elements[child + 1]))
      child++;
    if (tmp <= H->Elements[child])
      break;
    else
      H->Elements[parent] = H->Elements[child];
  }
  H->Elements[parent] = tmp;
}

// ����
void adjust(MinHeap H) {
  // ���һ����Ҷ�ӽڵ��
  int i;
  for (i = H->Size / 2; i > 0; i--) {
    // ��ÿ���к��ӽ��Ľ����Ϊ����㣬�����������ж�����
    percDown(H, i);
  }
}

// ����
void bl(MinHeap H) {
  for (int i = 1; i <= H->Size; i++) {
    cout << H->Elements[i] << " ";
  }
  cout << endl;
}
/**--------------------------------------------**/

#endif //DATASTRUCTURE_MAXHEAP_H
