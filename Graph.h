#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

class Graph {
public:
	// TO DO
	// initialize an undirected graph that can store at most n vertices
	Graph(const int n) {
		numOfVertices = n;
		adj = new bool*[n];
		for (int i = 1; i <= numOfVertices; i++)
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
		if (u >= 1 && u < numOfVertices && v > 0 && v < numOfVertices)
		{
			adj[u][v] = true;
			adj[v][u] = true;
		}
	}

	// TO DO
	// return the set of vertices that are adjacent to v
	std::vector<int> adjacentVertices(int v) {
		std::vector<int> vertices;
		for (int i = 1; i <= numOfVertices; i++)
		{
			if (adj[v][i] == true)
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

		std::vector<int> path;			//returns the route
		std::vector<int> isAdjacent;		//holds adjacent vertices to current vertex
		std::vector<int> current;		//recieves path

		int size = static_cast<int>(visited.size());
		//if vertex has been visited, return to previous vertex
		for (int i = 0; i < size; i++)
		if (v == visited[i])
			return path;
		visited.push_back(v);			//current vertex has now been visited

		//check if destination has been reached
		//if yes, clear visited and return that vertex
		if (v == w)
		{
			visited.clear();
			path.push_back(v);
			found = 1;			//arrived at destination
			return path;
		}
		else
		{
			found = 0;				//destination not reached
			isAdjacent = adjacentVertices(v);	//get adjacent vertices to current vertex
			int adjacentSize = static_cast<int>(isAdjacent.size());
			//check each vertices to see if it lands on destination
			for (int i = 0; i < adjacentSize; i++)
			{
				//if vertex already found, leave the loop
				if (found)
					break;
				else
				{
					//check adjacent vertices to see if it goes to destination
					current = getPath(isAdjacent[i], w);

					int currentSize = static_cast<int>(current.size());
					//if found copy current to path
					if (found)
					{
						path.push_back(v);
						for (int j = 0; j < currentSize; j++)
							path.push_back(current[j]);
					}
				}
			}
		}

		return path;
	}

	~Graph()
	{
		for (int i = 0; i < numOfVertices; i++)
			delete[] adj[i];
		delete[] adj;
		visited.~vector();
	}
private:
	// TO DO
	// member variables and functions to implement the public member functions
	int numOfVertices; //number of vertices
	std::vector<int> visited;
	bool found;
	bool **adj;
};

