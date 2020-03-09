#ifndef GRAPH_H
#define GRAPH_H

#include "stdafx.h"

#include "LinkedList.h"

template <typename T>
class Graph
{
public:
	
	Graph(int sz = 0) {
		graph = new LinkedList<T> * [sz];
		size = sz;

		for (int i = 0; i < size; i++)
		{
			graph[i] = new LinkedList<T>();
		}
	}

	~Graph() {}

	void Init(int sz, T c[])
	{
		graph = new LinkedList<T> * [sz]();

		size = sz;
		for (int i = 0; i < size; i++)
		{
			graph[i] = new LinkedList<T>();
			graph[i]->push_back(c[i]);
		}
	}


	
private:
	int size;

	LinkedList<T>** graph;
	
};

#endif
