#include <iostream>
#include <algorithm>

class Node {
public:
  int data;
  Node *left, *right;
  int height;

  Node(int data) {
    this->data = data;
    this->left = this->right = nullptr;
    this->height = 0;
  }
};

class AVLTree {
private:
  Node* root;

  int getLevel(Node* node) {
    if (node == nullptr)
      return -1;
    return node->height;
  }

  int getBalance(Node* node) {
    if (node == nullptr)
      return 0;
    return getLevel(node->left) - getLevel(node->right);
  }

  Node* RR(Node* y) {
    Node* x = y->left;
    Node* tmp = x->right;

    x->right = y;
    y->left = tmp;

    y->height = std::max(getLevel(y->left), getLevel(y->right)) + 1;
    x->height = std::max(getLevel(x->left), getLevel(x->right)) + 1;

    return x;
  }

  Node* LR(Node* x) {
    Node* y = x->right;
    Node* tmp = y->left;

    y->left = x;
    x->right = tmp;

    x->height = std::max(getLevel(x->left), getLevel(x->right)) + 1;
    y->height = std::max(getLevel(y->left), getLevel(y->right)) + 1;

    return y;
  }

  Node* insert(Node* node, int data) {
    if (node == nullptr)
      return new Node(data);

    if (data < node->data)
      node->left = insert(node->left, data);
    else if (data > node->data)
      node->right = insert(node->right, data);
    else
      return node;

    node->height = 1 + std::max(getLevel(node->left), getLevel(node->right));
    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data)
      return RR(node);

    if (balance < -1 && data > node->right->data)
      return LR(node);

    if (balance > 1 && data > node->left->data) {
      node->left = LR(node->left);
      return RR(node);
    }

    if (balance < -1 && data < node->right->data) {
      node->right = RR(node->right);
      return LR(node);
    }

    return node;
  }

  void preOrder(Node* root) {
    if (root != nullptr) {
      printf("%d ", root->data);
      preOrder(root->left);
      preOrder(root->right);
    }
  }

public:
  AVLTree() {
    root = nullptr;
  }

  void insert(int data) {
    root = insert(root, data);
  }

  void traverse() {
    if (root == nullptr) {
      printf("트리가 비어있습니다.\n");
    } else {
      preOrder(root);
      printf("\n");
    }
  }
};

int main() {
  AVLTree tree;

  char c;
  int x;
  while (true) {
    scanf("%c", &c);
    if (c == 'i') {
      scanf(" %d", &x);
      tree.insert(x);
      tree.traverse();
    }
    else if (c == 'q') {
      break;
    }
  }
  return 0;
}
