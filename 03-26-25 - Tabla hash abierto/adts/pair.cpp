#pragma once

template <class T1, class T2>
struct Pair
{
public:
  T1 fst;
  T2 snd;

  Pair() {}
  Pair(T1 fst)
  {
    this->fst = fst;
  }

  Pair(T1 fst, T2 snd)
  {
    this->fst = fst;
    this->snd = snd;
  }

  virtual bool operator==(const Pair<T1, T2> &other) override
  {
    this->fst == other->fst;
  }
};
