#pragma once
#include "./hash_func.cpp"

class IdentityHashFunc : public HashFunc<int>
{

public:
  virtual int hash(int data) override
  {
    return data;
  }
};
