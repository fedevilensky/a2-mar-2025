#pragma once
#include "min_priority_queue.cpp"
#include "pair.cpp"
#include <assert.h>

template <class E, class P>
class MinHeap : public MinPriorityQueue<E, P>
{
private:
  Pair<E, P> *arr;
  int arrSize;
  int count = 0;

  void siftUp(int pos)
  {
    if (pos == 1)
    {
      return;
    }
    int parentPos = pos / 2;
    if (this->arr[parentPos].snd > this->arr[pos].snd)
    {
      swap(pos, parentPos);
      siftUp(parentPos);
    }
  }

  void swap(int posA, int posB)
  {
    Pair<E, P> aux = this->arr[posA];
    this->arr[posA] = this->arr[posB];
    this->arr[posB] = aux;
  }

public:
  MinHeap(int expectedSize)
  {
    this->arr = new Pair<E, P>[expectedSize + 1];
    this->arrSize = expectedSize + 1;
  }

  virtual void enqueue(E elem, P prio)
  {
    this->count++;
    if (this->count >= this->arrSize)
    {
      Pair<E, P> *newArr = new Pair<E, P>[this->arrSize * 2];
      for (int i = 1; i < this->arrSize; i++)
      {
        newArr[i] = arr[i];
      }
      this->arrSize *= 2;
      delete[] this->arr;
      this->arr = newArr;
    }

    this->arr[count] = Pair<E, P>(elem, prio);
    siftUp(count);
  }

  virtual E dequeue()
  {
    // TODO: implementar
  }
  virtual E top()
  {
    assert(this->count > 0);
    return this->arr[1].fst;
  }
  virtual int size()
  {
    // TODO: implementar
  }
};
