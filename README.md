# 数据结构

## 线性表
- 顺序表示
    - [顺序表示](https://github.com/shoukailiang/DataStructure/blob/dev/List/SqList/SqList.h)
- 链式表示
    - [单链表](https://github.com/shoukailiang/DataStructure/blob/dev/List/LinkList/LinkList.h)
    - 特殊链表
        - [双向链表](https://github.com/shoukailiang/DataStructure/blob/dev/List/DuLinkList/DuLinkList.h)
        - 循环链表
        - 静态链表
## 栈
- 顺序表示
    - [顺序栈](https://github.com/shoukailiang/DataStructure/blob/dev/Stack/SqStack/SqStack.h)
- 链式表示
    - [链式栈](https://github.com/shoukailiang/DataStructure/blob/dev/Stack/LinkStack/LinkStack.h)
- 栈的应用
    - 递归
    - [判断是否是回文](https://github.com/shoukailiang/DataStructure/blob/dev/Stack/example/Palindrome.cpp)
    - [进制转换](https://github.com/shoukailiang/DataStructure/blob/dev/Stack/example/Convert.cpp)
    - 四则运算表达式求值
## 队列
- 顺序表示
    - [顺序队列](https://github.com/shoukailiang/DataStructure/blob/dev/Queue/SqQueue/SqQueue.h)
- 链式表示
    - [链式队列](https://github.com/shoukailiang/DataStructure/blob/dev/Queue/LinkQueue/LinkQueue.h)
## 数组和广义表
## 堆
- [最大堆](https://github.com/shoukailiang/DataStructure/blob/dev/Heap/MaxHeap/MaxHeap.h)
- [最小堆](https://github.com/shoukailiang/DataStructure/blob/dev/Heap/MinHeap/MinHeap.h)
- [堆排序](https://github.com/shoukailiang/DataStructure/blob/dev/Sort/HeapSort/HeapSort2.cpp)
- [最大索引堆](https://github.com/shoukailiang/DataStructure/blob/dev/Heap/IndexMaxHeap/IndexMaxHeap.h)
- [最小索引堆](https://github.com/shoukailiang/DataStructure/blob/dev/Heap/IndexMinHeap/IndexMinHeap.h)
## 树
- [二分搜索树](https://github.com/shoukailiang/DataStructure/blob/dev/Tree/BinarySearchTree/BinarySearchTree.h)
## 图
- [邻接表](https://github.com/shoukailiang/DataStructure/blob/dev/Graph/SparseGraph/SparseGraph.h)
- [邻接矩阵](https://github.com/shoukailiang/DataStructure/blob/dev/Graph/DenseGraph/DenseGraph.h)

## 并查集
- [基于size并查集](https://github.com/shoukailiang/DataStructure/blob/dev/UnionFind/QuickUnion/UnionFind.h)
- [基于rank并查集](https://github.com/shoukailiang/DataStructure/blob/dev/UnionFind/UnionFindByRank/UnionFind.h)
- [路径压缩](https://github.com/shoukailiang/DataStructure/blob/dev/UnionFind/PathCompression/UnionFind.h)

# 常见算法
## 排序算法
- [选择排序](https://github.com/shoukailiang/DataStructure/blob/dev/Sort/SelectionSort/SelectionSort.cpp)
- [冒泡排序](https://github.com/shoukailiang/DataStructure/blob/dev/Sort/BubbleSort/BubbleSort.cpp)
- [插入排序](https://github.com/shoukailiang/DataStructure/blob/dev/Sort/InsertionSort/InsertionSort.cpp)
- [希尔排序](https://github.com/shoukailiang/DataStructure/blob/dev/Sort/ShellSort/ShellSort.cpp)
- [归并排序](https://github.com/shoukailiang/DataStructure/blob/dev/Sort/MergeSort/MergeSort.cpp)
- [快速排序](https://github.com/shoukailiang/DataStructure/blob/dev/Sort/QuickSort/QuickSort.cpp)
- [基数排序](https://github.com/shoukailiang/DataStructure/blob/dev/Sort/RadixSort/RadixSort.cpp)
- [堆排序](https://github.com/shoukailiang/DataStructure/blob/dev/Sort/HeapSort/HeapSort2.cpp)
## 查找算法
- [二分查找](https://github.com/shoukailiang/DataStructure/blob/dev/Search/BinarySearch/BinarySearch.cpp)
- [插值查找](https://github.com/shoukailiang/DataStructure/blob/dev/Search/InsertValueSearch/InsertValueSearch.cpp)
## 分治算法
- [汉诺塔](https://github.com/shoukailiang/DataStructure/blob/dev/Divide-and-Conquer/Hanoitower.cpp)

# 注意事项
在clion中，需要运行哪个就在CmakeLists.txt 中添加进去如
```
add_executable(DataStructure LinkList/LinkList.cpp LinkList/LinkList.h)
```
# 参考
- 啊哈，算法
- 大话数据结构
- https://github.com/liuyubobobo