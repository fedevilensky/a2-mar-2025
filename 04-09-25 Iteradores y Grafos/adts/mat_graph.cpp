#pragma once

#include "graph.cpp"
#include <assert.h>
#include "linked_list.cpp"

class MatGraph : public Graph
{
  int **mat;
  int vertices;

public:
  MatGraph(int vertices)
  {
    this->vertices = vertices;
    this->mat = new int *[vertices + 1];
    for (int i = 1; i <= vertices; i++)
    {
      this->mat[i] = new int[vertices + 1];
      for (int j = 1; j <= vertices; j++)
      {
        mat[i][j] = 0;
      }
    }
  }

  virtual Iterator<Edge> *getAllEdges() override
  {
    // TODO: implement
    assert(false);
  }

  virtual int vertexCount() override
  {
    return this->vertices;
  }

  virtual Iterator<Edge> *getNeighbors(int v) override
  {
    assert(v > 0);
    assert(v <= this->vertices);
    List<Edge> *l = new LinkedList<Edge>();
    for (int i = 1; i <= this->vertices; i++)
    {
      if (this->mat[v][i] != 0)
      {
        Edge e = Edge();
        e.from = v;
        e.to = i;
        e.weight = this->mat[v][i];
        l->add(e);
      }
    }

    return l->iterator();
  }

  virtual bool isNeighbor(int v1, int v2) override
  {
    // TODO: implement
    assert(false);
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
    assert(v1 <= this->vertices);
    assert(v1 > 0);
    assert(v2 <= this->vertices);
    assert(v2 > 0);

    this->mat[v1][v2] = w;
  }

  virtual void remove(int v1, int v2) override
  {
    addW(v1, v2, 0);
  }

  virtual int **getAdjMatrix() override
  {
    // TODO: devuelve una copia de la matriz
    assert(false);
  }
};
