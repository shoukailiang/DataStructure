//
// Created by liang on 2019/8/10.
//

#ifndef DATASTRUCTURE_BINARYSEARCHTREE_H
#define DATASTRUCTURE_BINARYSEARCHTREE_H

#include <iostream>
#include <queue>
#include <cassert>

using namespace std;

template<typename Key, typename Value>
class BinarySearchTree {
private:

  struct Node {
    Key key;
    Value value;
    Node *left;
    Node *right;

    Node(Key key, Value value) {
      this->key = key;
      this->value = value;
      this->left = this->right = NULL;
    }


    Node(Node *node) {
      this->key = node->key;
      this->value = node->value;
      this->left = node->left;
      this->right = node->right;
    }
  };

  Node *root;
  int count;

public:
  BinarySearchTree() {
    root = NULL;
    count = 0;
  }

  ~BinarySearchTree() {
    destroy(root);
  }

  int size() {
    return count;
  }

  bool isEmpty() {
    return count == 0;
  }

  void insert(Key key, Value value) {
    root = insert(root, key, value);
  }

  bool contain(Key key) {
    return contain(root, key);
  }

  Value *search(Key key) {
    return search(root, key);
  }

  // ǰ�����
  void preOrder() {
    preOrder(root);
  }

  // �������
  void inOrder() {
    inOrder(root);
  }

  // �������
  void postOrder() {
    postOrder(root);
  }

  // ����������������Ĺ�����ȱ�����
  // ��Ҫ�õõ�����
  void levelOrder() {
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
      Node *node = q.front();
      q.pop();
      cout << node->key << endl;
      if (node->left) {
        q.push(node->left);
      }
      if (node->right) {
        q.push(node->right);
      }
    }
  }

  // Ѱ����С�ļ�ֵ
  Key minimum() {
    assert(count != 0);
    Node *minNode = minimum(root);
    return minNode->key;
  }

  // Ѱ�����ļ�ֵ
  Key maximum() {
    assert(count != 0);
    Node *maxNode = maximum(root);
    return maxNode->key;
  }

  // �Ӷ�������ɾ����Сֵ���ڽڵ�
  void removeMin() {
    if (root) {
      root = removeMin(root);
    }
  }

  // �Ӷ�������ɾ�����ֵ���ڽڵ�
  void removeMax() {
    if (root)
      root = removeMax(root);
  }

  // �Ӷ�������ɾ����ֵΪkey�Ľڵ�
  void remove(Key key) {
    root = remove(root, key);
  }

private:
  /**
   * ����nodeΪ���Ķ�����������,����ڵ�(key, value)
   * @param node
   * @param key
   * @param value
   * @return  ���ز����½ڵ��Ķ����������ĸ�
   */
  Node *insert(Node *node, Key key, Value value) {
    if (node == NULL) {  // �����ǿյ�
      count++;
      return new Node(key, value);
    }

    // ���key��ͬ������valueֵ
    if (key == node->key) {
      node->value = value;
    } else if (key < node->key) {
      node->left = insert(node->left, key, value);
    } else { // key>node->key
      node->right = insert(node->right, key, value);
    }
    return node;
  }

  /**
   * �鿴��nodeΪ���Ķ������������Ƿ������ֵΪkey�Ľڵ�
   * @param node
   * @param key
   * @return
   */
  bool contain(Node *node, Key key) {
    if (node == NULL) {
      return false;
    }
    if (key == node->key) {
      return true;
    } else if (key < node->key) {
      return contain(node->left, key);
    } else {// key > node->key
      return contain(node->right, key);
    }
  }

  /**
   * ����nodeΪ���Ķ����������в���key����Ӧ��value
   * @param node
   * @param key
   * @return
   */
  Value *search(Node *node, Key key) {
    if (node == NULL) {
      return NULL;
    }
    if (key == node->key) {
      return &(node->value);
    } else if (key < node->key) {
      return search(node->left, key);
    } else {// key > node->key
      return search(node->right, key);
    }
  }

  /**
   * ����nodeΪ���Ķ�������������ǰ�����
   * @param node
   */
  void preOrder(Node *node) {
    if (node != NULL) {
      cout << node->key << endl;
      preOrder(node->left);
      preOrder(node->right);
    }
  }

  /**
   * ����nodeΪ���Ķ��������������������
   * @param node
   */
  void inOrder(Node *node) {
    if (node != NULL) {
      inOrder(node->left);
      cout << node->key << endl;
      inOrder(node->right);
    }
  }

  /**
   * ����nodeΪ���Ķ������������к������
   * @param node
   */
  void postOrder(Node *node) {
    if (node != NULL) {
      postOrder(node->left);
      postOrder(node->right);
      cout << node->key << endl;
    }
  }

  /**
   * ֻ����ɾ����������������������ɾ����ǰ�ڵ�
   * @param node
   */
  void destroy(Node *node) {
    if (node != NULL) {
      destroy(node->left);
      destroy(node->right);
      delete node;
      count--;
    }
  }

  /**
   * ����nodeΪ���Ķ�����������,������С��ֵ�Ľڵ�
   * @param node
   * @return
   */
  Node *minimum(Node *node) {
    if (node->left == NULL) {
      return node;
    }
    return minimum(node->left);
  }

  /**
   * ����nodeΪ���Ķ�����������,��������ֵ�Ľڵ�
   * @param node
   * @return
   */
  Node *maximum(Node *node) {
    if (node->right == NULL)
      return node;

    return maximum(node->right);
  }


  /**
   * ɾ������nodeΪ���Ķ����������е���С�ڵ�
   * @param node
   * @return ����ɾ���ڵ���µĶ����������ĸ�
   */
  Node *removeMin(Node *node) {
    if (node->left == NULL) {  // ���Ҫɾ���Ľڵ�������Ϊ�գ���������������
      Node *rightNode = node->right;
      delete (node);
      count--;
      return rightNode;
    }
    node->left = removeMin(node->left);
    return node;
  }

  /**
   * ɾ������nodeΪ���Ķ����������е����ڵ�
   * @param node
   * @return  ����ɾ���ڵ���µĶ����������ĸ�
   */
  Node *removeMax(Node *node) {
    if (node->right == NULL) {
      Node *leftNode = node->left;
      delete node;
      count--;
      return leftNode;
    }
    node->right = removeMax(node->right);
    return node;
  }

  /**
   * ɾ������nodeΪ���Ķ����������м�ֵΪkey�Ľڵ�
   * @param node
   * @param key
   * @return   ����ɾ���ڵ���µĶ����������ĸ�
   */
  Node *remove(Node *node, Key key) {
    if (node == NULL) {
      return NULL;
    }
    if (key < node->key) {
      node->left = remove(node->left, key);
      return node;
    } else if (key > node->key) {
      node->right = remove(node->right, key);
      return node;
    } else {   // key == node->key
      if (node->left == NULL) {
        Node *rightNode = node->right;
        delete node;
        count--;
        return rightNode;
      }

      if (node->right == NULL) {
        Node *leftNode = node->left;
        delete node;
        count--;
        return leftNode;
      }

      // node->left != NULL && node->right != NULL
      // ��ʱ����Ҫ��һ����̽ڵ��������ɾ���Ľڵ�
      Node *successor = new Node(minimum(node->right));
      count++;
      successor->right = removeMin(node->right);
      successor->left = node->left;

      delete node;
      count--;
      return successor;
    }
  }
};


#endif //DATASTRUCTURE_BINARYSEARCHTREE_H
