#pragma once

#include "./bst.cpp"

template <class T>
class AVL : public BST<T>
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

    n = rebalance(n);

    return n;
  }

  Node *rebalance(Node *n)
  {
    int bF = nHeight(n->right) - nHeight(n->left);
    if (bF >= -1 && bF <= 1)
    {
      return n;
    }
    if (bF > 1)
    {
      // der-?
      int bF_2 = nHeight(n->right->right) - nHeight(n->right->left);
      if (bF_2 > 0)
      {
        // der-der
        n = leftRot(n);
      }
      else
      {
        // der-izq
        n = rightLeftRot(n);
      }
    }
    else
    {
      // izq-?
      int bF_2 = nHeight(n->left->right) - nHeight(n->left->left);
      if (bF_2 > 0)
      {
        // izq-der
        n = leftRightRot(n);
      }
      else
      {
        // izq-izq
        n = rightRot(n);
      }

      n->height = 1 + max(nHeight(n->left), nHeight(n->right));
      return n;
    }
  }

  Node *rightRot(Node *a)
  {
    Node *b = a->left;

    a->left = b->right;
    b->right = a;

    a->height = 1+max(nHeight(a->left), nHeight(a->right));
    b->height = 1+max(nHeight(b->left), nHeight(b->right));

    return b;
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

    return n->height;
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
