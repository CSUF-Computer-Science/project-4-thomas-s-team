#pragma once
#include <vector>
#include <iostream>

class Graph {
public:
	// TO DO
	// initialize an undirected graph that can store at most n vertices
	Graph(const int n) {
		vertices = n;
		adj = new bool*[n];
		for (int i = 0; i < vertices; i++)
		{
			adj[i] = new bool[vertices];
			for (int j = 0; j < vertices; j++)
			{
				adj[i][j] = false;
			}
		}
	}

	// TO DO
	// insert an edge between vertices u and v
	void insertEdge(int u, int v) {
		if (u >= 0 && u < vertices && v > 0 && j < vertices)
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
		for (int i = v; i < w; i++)
		{
			if (adj[v][i] == 1)
			{
				path.push_back(i);
			}
		}
		return path;
	}

private:
	// TO DO
	// member variables and functions to implement the public member functions
	int vertices; //number of vertices
	bool **adj;
};

