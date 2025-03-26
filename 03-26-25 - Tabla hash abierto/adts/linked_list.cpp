#pragma once

#include "./list.cpp"
#include <assert.h>

template <class T>
class LinkedList : public List<T>
{
private:
  struct Node
  {
    T data;
    Node *next;
  };

  Node *head = nullptr;
  int length = 0;

public:
  virtual void add(T data) override
  {
    assert(false);
    return;
  }
  virtual T get(int pos) override
  {
    assert(pos < this->length);

    Node *curr = head;
    while (pos > 0)
    {
      curr = curr->next;
      pos--;
    }

    return curr->data;
  }

  virtual bool contains(T data) override
  {
    Node *curr = this->head;
    while (curr != nullptr)
    {
      if (curr->data == data)
      {
        return true;
      }
      curr = curr->next;
    }

    return false;
  }

  virtual bool isEmpty() override { return this->length == 0; }

  virtual int size() override { return this->length; }

  virtual void remove(T data) override
  {
    if (this->head == nullptr)
    {
      return;
    }
    if (this->head->data == data)
    {
      Node *toDelete = this->head;
      this->head = this->head->next;
      this->length--;
      delete toDelete;
      return;
    }

    Node *aux = this->head;
    while (aux->next != nullptr)
    {
      if (aux->next->data == data)
      {
        Node *toDelete = aux->next;
        aux->next = aux->next->next;
        delete toDelete;
        this->length--;
        return;
      }

      aux = aux->next;
    }
  }
};
