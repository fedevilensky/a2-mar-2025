#pragma once
#include "./pair.cpp"
#include "./linked_list.cpp"
#include "./map.cpp"
#include "./hash_func.cpp"

template <class K, class V>
class OpenHashMap : public Map<K, V>
{
private:
  // List<Pair<K,V>>*[] arr
  List<Pair<K, V>> **buckets;
  int bucketsSize;
  int count = 0;
  HashFunc<K> *h;

  int abs(int x)
  {
    if (x < 0)
    {
      return -x;
    }
    return x;
  }

public:
  OpenHashMap(HashFunc<K> *h, int expectedSize)
  {
    // con un factor de carga de ~1.5
    this->bucketsSize = expectedSize * 2 / 3;
    this->buckets = new List<Pair<K, V>> *[this->bucketsSize];
    this->h = h;
  }

  virtual V get(K key) override
  {
    // TODO: implement
  }
  virtual void set(K key, V value) override
  {
    this->remove(key);

    int pos = abs(this->h->hash(key) % this->bucketsSize);

    if (this->buckets[pos] == nullptr)
    {
      this->buckets[pos] = new LinkedList<Pair<K, V>>();
    }

    this->buckets[pos]->add(Pair<K, V>(key, value));
    this->count++;
  }
  virtual int size() override
  {
    return this->count;
  }
  virtual bool contains(K key) override
  {
    // TODO: implement
  }
  virtual void remove(K key) override
  {
    // TODO: implement
  }
  virtual int capacity() override
  {
    return this->bucketsSize;
  }
};
