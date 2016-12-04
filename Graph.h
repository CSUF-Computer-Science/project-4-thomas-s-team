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
		if (u >= 0 && u < numOfVertices && v > 0 && v < numOfVertices)
		{
			adj[u][v] = true;
			adj[v][u] = true;
		}
	}

	// TO DO
	// return the set of vertices that are adjacent to v
	std::vector<int> adjacentVertices(int v) {
		std::vector<int> vertices;
		for (int i = 0; i < numOfVertices; i++)
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
		
		std::vector<int> path;
        	std::vector<int> isAdjacent;
        	std::vector<int> current;
        
        	found = 0;
        	path.push_back(v);
        	if (v == w)
        	{
			visited.clear();
            		found = 1;
            		return path;
		}
		else
        	{
			isAdjacent = adjacentVertices(v);
			
			//delete any visited vertex
			for (int j = 0; j < isAdjacent.size() && !isAdjacent.empty(); j++)
                		for (int c = 0; c < visited.size() && !isAdjacent.empty(); c++)
                    			if (visited[c] == isAdjacent[j])
                        			isAdjacent.erase(isAdjacent.begin()+j);
			visited.push_back(v);
			
			for (int i = 0; i < isAdjacent.size(); i++)
            		{
				if(found)
                    			break;
                
				if(isAdjacent.empty())
                    			return isAdjacent;
                		else
                		{
					current = getPath(isAdjacent[i], w);
                    			for(int j = 0; j < current.size(); j++)
                        		path.push_back(current[j]);
                		}
			}
		}
		if(!found)
        	{
			path.pop_back();
            		return path;
        	}
        	else
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
	std::vector<int> visited;
    	bool found;
	bool **adj;
};

