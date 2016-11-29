#pragma once
#include <vector>
#include <iostream>

class Graph {
public:
	// TO DO
	// initialize an undirected graph that can store at most n vertices
	Graph(const int n) {
		v = n;
		adj = new int*[n];
		for (int i = 0; i < n; i++)
		{
			adj[i] = new int[n];
			for (int j = 0; j < n; j++)
			{
				adj[i][j] = 0;
			}
		}
	}

	// TO DO
	// insert an edge between vertices u and v
	void insertEdge(int u, int v) {
		if (u > this->v || v > this->v || u < 0 || v < 0)
		{
			throw invalid_argument("invalid vertices");
		}
		else
			adj[u - 1][v - 1] = 1;
	}

	// TO DO
	// return the set of vertices that are adjacent to v
	std::vector<int> adjacentVertices(int v) {
		std::vector<int> vertices;
		for (int i = 0; i < v; i++)
		{
			if (adj[i][v] == 1)
			{
				vertices.push_back(i);
			}
		}

		return vertices;
	}

	// TO DO
	// return a list of vertices that appear between v and w, starting with v and ending with w
	// vertices should not be repeated
	std::vector<int> getPath(int v, int w) {
		std::vector<int> path;
		
		return path;
	}

private:
	// TO DO
	// member variables and functions to implement the public member functions
	int v; //number of vertices
	int **adj;
};

