#pragma once

#include "graph.cpp"
#include "linked_list.cpp"
#include <assert.h>

class ListGraph : public Graph
{
private:
  List<Edge> **adjL;
  int vertices;

public:
  ListGraph(int vertices)
  {
    this->vertices = vertices;
    this->adjL = new List<Edge> *[vertices + 1];
    for (int i = 1; i <= vertices; i++)
    {
      this->adjL[i] = new LinkedList<Edge>();
    }
  }

  virtual Iterator<Edge> *getAllEdges() override
  {
    // TODO: implement
    assert(false);
  }

  virtual int vertexCount() override
  {
    // TODO: implement
    assert(false);
  }

  virtual Iterator<Edge> *getNeighbors(int v) override
  {
    assert(v > 0);
    assert(v <= this->vertices);

    return this->adjL[v]->iterator();
  }

  virtual bool isNeighbor(int v1, int v2) override
  {
    assert(v1 > 0);
    assert(v1 <= this->vertices);
    assert(v2 > 0);
    assert(v2 <= this->vertices);

    Iterator<Edge> *it = this->adjL[v1]->iterator();
    while (it->hasNext())
    {
      Edge e = it->next();
      if (e.to == v2)
      {
        return true;
      }
    }
    return false;
  }

  virtual int getWeight(int v1, int v2) override
  {
    // TODO: implement
    assert(false);
  }

  virtual void add(int v1, int v2) override
  {
    addW(v1, v2, 1);
  }

  virtual void addW(int v1, int v2, int w) override
  {
    assert(v1 > 0);
    assert(v1 <= this->vertices);
    assert(v2 > 0);
    assert(v2 <= this->vertices);

    remove(v1, v2);

    Edge e;
    e.from = v1;
    e.to = v2;
    e.weight = w;

    adjL[v1]->add(e);
  }

  virtual void remove(int v1, int v2) override
  {
    assert(v1 > 0);
    assert(v1 <= this->vertices);
    assert(v2 > 0);
    assert(v2 <= this->vertices);

    Edge e = Edge();
    e.from = v1;
    e.to = v2;
    this->adjL[v1]->remove(e);
  }

  virtual int **getAdjMatrix() override
  {
    // TODO: implement
    assert(false);
  }
};
