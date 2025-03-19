#pragma once

#include "./bst.cpp"

template <class T>
class BSTImp : public BST<T>
{
private:
  struct Node
  {
    T data;
    int height;
    Node *left, *right;

    Node(T data)
    {
      this->data = data;
      this->left = nullptr;
      this->right = nullptr;
      this->height = 1;
    }
  }

  Node *root = nullptr;
  int count = 0;

  bool nContains(Node *n, T data)
  {
    if (n == nullptr)
    {
      return false;
    }

    if (n->data == data)
    {
      return true;
    }

    if (data >= n->data)
    {
      return nContains(n->right, data);
    }

    // else
    return nContains(n->left, data);
  }

  Node *nInsert(Node *n, T data)
  {
    if (n == nullptr)
    {
      return new Node(data);
    }

    if (data < n->data)
    {
      n->left = nInsert(n->left, data);
    }
    else
    {
      n->right = nInsert(n->right, data);
    }
    n->height = 1 + max(nHeight(n->left), nHeight(n->right));

    return n;
  }

  int max(int a, int b)
  {
    if (a > b)
    {
      return a;
    }
    return b;
  }

  int nHeight(Node *n)
  {
    if (n == nullptr)
    {
      return 0;
    }

    return n->height
  }

public:
  virtual void insert(T data) override
  {
    this->root = nInsert(this->root, data);
    this->count++;
  }

  virtual bool contains(T data) override
  {
    return nContains(this->root, data);
  }

  virtual T get(T data) override {}

  virtual int size() override
  {
    return this->count;
  }

  virtual int height() override
  {
    return nHeight(this->root)
  }

  virtual void remove(T data) override {}

  virtual T max() override {}

  virtual T min() override {}
};
