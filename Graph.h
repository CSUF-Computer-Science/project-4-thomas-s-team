#pragma once
#include <vector>
#include <iostream>

class Graph {
public:
	// TO DO
	// initialize an undirected graph that can store at most n vertices
	Graph(const int n) {
		numOfVertices = n;
		adj = new bool*[n];
		for (int i = 0; i < numOfVertices; i++)
		{
			adj[i] = new bool[numOfVertices];
			for (int j = 0; j < numOfVertices; j++)
			{
				adj[i][j] = false;
			}
		}
	}

	// TO DO
	// insert an edge between vertices u and v
	void insertEdge(int u, int v) {
		if (u >= 0 && u < numOfVertices && v > 0 && j < numOfVertices)
		{
			adj[u][v] = true;
			adj[v][u] = true;
		}
		else
			throw invalid_argument("invalid vertices");
	}

	// TO DO
	// return the set of vertices that are adjacent to v
	std::vector<int> adjacentVertices(int v) {
		std::vector<int> vertices;
		

		return vertices;
	}

	// TO DO
	// return a list of vertices that appear between v and w, starting with v and ending with w
	// vertices should not be repeated
	std::vector<int> getPath(int v, int w) {
		std::vector<int> path;
		for (int i = v; i < w; i++)
		{
			if (adj[v][i] == 1)
			{
				path.push_back(i);
			}
		}
		return path;
	}

	~Graph()
	{
		for (int i = 0; i < numOfVertices; i++)
			delete[] adj[i];
		delete[] adj;
	}
private:
	// TO DO
	// member variables and functions to implement the public member functions
	int numOfVertices; //number of vertices
	bool **adj;
};

