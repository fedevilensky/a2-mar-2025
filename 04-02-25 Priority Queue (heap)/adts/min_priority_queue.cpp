#pragma once

template <class E, class P>
class MinPriorityQueue
{
public:
  virtual void enqueue(E elem, P prio) = 0;
  virtual E dequeue() = 0;
  virtual E top() = 0;
  virtual int size() = 0;
};
