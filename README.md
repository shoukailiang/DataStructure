# DataStructure
浙江大学数据结构
# 线性表
- 顺序表示
    - [顺序表示](https://github.com/shoukailiang/DataStructure/blob/zju/List/SqList/SqList.h)
- 链式表示
    - [单链表](https://github.com/shoukailiang/DataStructure/blob/zju/List/LinkList/LinkList.h)
## 栈
- 顺序表示
    - [顺序栈](https://github.com/shoukailiang/DataStructure/blob/zju/Stack/SqStack/SqStack.h)
- 链式表示
    - [链式栈](https://github.com/shoukailiang/DataStructure/blob/zju/Stack/LinkStack/LinkStack.h)
- 栈的应用
    - 递归
    - [判断是否是回文](https://github.com/shoukailiang/DataStructure/blob/dev/Stack/example/Palindrome.cpp)
    - [进制转换](https://github.com/shoukailiang/DataStructure/blob/dev/Stack/example/Convert.cpp)
    - 四则运算表达式求值
## 队列
- 顺序表示
    - [顺序队列](https://github.com/shoukailiang/DataStructure/blob/zju/Queue/SqQueue/SqQueue.h)
- 链式表示
    - [链式队列](https://github.com/shoukailiang/DataStructure/blob/zju/Queue/LinkQueue/LinkQueue.h)
## 树
- [二分搜索树](https://github.com/shoukailiang/DataStructure/blob/zju/Tree/BinarySearchTree/BinarySearchTree.h)
## 堆
- [最大堆](https://github.com/shoukailiang/DataStructure/blob/zju/Heap/MaxHeap/MaxHeap.h)
# 注意事项

在clion中，需要运行哪个就在CmakeLists.txt 中添加进去如
```
add_executable(DataStructure LinkList/LinkList.cpp LinkList/LinkList.h)
```