//
// Created by liang on 2019/9/28.
//

#ifndef DATASTRUCTURE_MAXHEAP_H
#define DATASTRUCTURE_MAXHEAP_H


typedef int ElementType;
typedef struct HeapStruct *MinHeap;
struct HeapStruct {
  ElementType *Elements;   // 存储堆元素的数组
  int Size;      // 堆的当前元素个数
  int Capacity;  // 堆的最大容量
};


// 建堆
MinHeap Create(int MaxSize) {
  MinHeap H = (MinHeap) malloc(sizeof(struct HeapStruct));
  // Elements[0] 作为哨兵，堆元素从  Elements[1] 开始存放
  H->Elements = (ElementType *) malloc((MaxSize + 1) * sizeof(ElementType));
  H->Size = 0;
  H->Capacity = MaxSize;
  // "哨兵"小于堆中所有可能的值
  H->Elements[0] = MinData;
  return H;
}

// 判断是否已经满
bool IsFull(MinHeap H) {
  return (H->Size == H->Capacity);
}

// 判断是否为空
bool IsEmpty(MinHeap H) {
  return !H->Size;
}

// 插入，从完全二叉树的最后一个位置插入
bool Insert(MinHeap H, ElementType item) {
  if (IsFull(H)) {
    printf("堆已满，无法插入！\n");
    return false;
  }
  int i = ++H->Size;  // 指向堆中最后一个位置
  for (; H->Elements[i / 2] > item; i /= 2)    // 向上找比 item 小的结点
    H->Elements[i] = H->Elements[i / 2];  //  向下赋值
  H->Elements[i] = item;  // 找到了，把 item 值放进去
  return true;
}

// 删除，从根结点删除
ElementType DeleteMin(MinHeap H) {
  int parent, child;
  ElementType Min, tmp;
  if (IsEmpty(H)) {
    printf("堆为空，无法删除！\n");
    return ERROR;
  }
  Min = H->Elements[1];  // 拿到最小值
  tmp = H->Elements[H->Size--];  // 拿到完全二叉树最后一个值,后--
  // 判别条件：parent 是否有左孩子结点
  for (parent = 1; parent * 2 <= H->Size; parent = child) {
    // 左右孩子结点中找较大的值
    child = 2 * parent;  // 左孩子结点
    // child!=H->Size 表示 child 不为当前最后一个结点，即 parent 有右孩子结点
    if ((child != H->Size) && (H->Elements[child] > H->Elements[child + 1]))
      child++;
    // 给 tmp 找个合适的位置
    // 如果当前左右孩子结点比 tmp 都大，说明 tmp 位置已经合适
    if (H->Elements[child] >= tmp)
      break;
    else    // 否则把较小的孩子结点提上来，自己继续下去找
      H->Elements[parent] = H->Elements[child];
  }
  H->Elements[parent] = tmp;  // 在合适的位置把 tmp 放进去
  return Min;
}


// 层序遍历
void LevelOrderTraversal(MinHeap H) {
  int i;
  printf("层序遍历的结果是：");
  for (i = 1; i <= H->Size; i++) {
    printf("%d ", H->Elements[i]);
  }
  printf("\n");
}

/**构建最小堆---------------------------------------**/
void percDown(MinHeap H, int i) {
  int child, parent;
  int tmp = H->Elements[i];  // 拿到当前"根结点的值"
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

// 调整
void adjust(MinHeap H) {
  // 最后一个有叶子节点的
  int i;
  for (i = H->Size / 2; i > 0; i--) {
    // 以每个有孩子结点的结点作为根结点，对其子树进行堆排序
    percDown(H, i);
  }
}

// 遍历
void bl(MinHeap H) {
  for (int i = 1; i <= H->Size; i++) {
    cout << H->Elements[i] << " ";
  }
  cout << endl;
}
/**--------------------------------------------**/

#endif //DATASTRUCTURE_MAXHEAP_H
