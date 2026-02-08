#pragma once

#include "graph.cpp"
#include "linked_list2.cpp"
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
    LinkedList<Edge> *edges = new LinkedList<Edge>();
    for (int i = 1; i <= this->vertices; i++)
    {
      Iterator<Edge> *it = this->adjL[i]->iterator();
      while (it->hasNext())
      {
        edges->add(it->next());
      }
    }
    return edges->iterator();
  }

  virtual int vertexCount() override
  {
    return this->vertices;
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
        return e.weight;
      }
    }
    return -1;
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
    int **matrix = new int *[this->vertices + 1];
    for (int i = 0; i <= this->vertices; i++)
    {
      matrix[i] = new int[this->vertices + 1];
      for (int j = 0; j <= this->vertices; j++)
      {
        matrix[i][j] = -1;
      }
    }

    for (int i = 1; i <= this->vertices; i++)
    {
      Iterator<Edge> *it = this->adjL[i]->iterator();
      while (it->hasNext())
      {
        Edge e = it->next();
        matrix[e.from][e.to] = e.weight;
      }
    }
    return matrix;
  }
};