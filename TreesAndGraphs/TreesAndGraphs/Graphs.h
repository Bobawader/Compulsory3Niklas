#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>
#include <unordered_set>
#include <stack>

using namespace std;


class Graph
{
private:
	int numVertices;
	vector<vector<int>> adjLists;
	int vertices;
	int edgeCount;
	vector<bool> visited;

	/*void dfsRecursive(int currentVertex, std::unordered_set<int>& visited) {
		visited.insert(currentVertex);
		cout << "Visited vertex: " << currentVertex << endl;

		for (int adjacentVertex : adjLists[currentVertex]) {
			if (visited.find(adjacentVertex) == visited.end()) {
				dfsRecursive(adjacentVertex, visited);
			}
		}
	}*/

	//void dfs(int currentVertex) {
	//	visited[currentVertex] = true; // Mark the current vertex as visited
	//	cout << "Visited vertex: " << currentVertex << endl; // Process the current vertex

	//	for (int adjacentVertex : adjLists[currentVertex]) {
	//		if (!visited[adjacentVertex]) {
	//			dfs(adjacentVertex); // Recur for unvisited adjacent vertices
	//		}
	//	}
	//}

public:

	//constructor
	Graph(int numVertices) : numVertices(numVertices), vertices(numVertices), edgeCount(0) {
		adjLists.resize(numVertices); 
		visited.resize(numVertices, false);
	}

	// Destructor
	~Graph() {
	}


	//the DFS function which is supposed to work but doesnt
	void DFS(int start, vector<bool>& visited) {
		// Create a stack for DFS
		stack<int> stack;

		
		stack.push(start);

		while (!stack.empty())
		{
			// Pop a vertex from stack and print it
			start = stack.top();
			stack.pop();
			if (!visited[start])
			{
				cout << start << " ";
				visited[start] = true;
			}

			
			for (auto i = adjLists[start].begin(); i != adjLists[start].end(); ++i)
				if (!visited[*i])
					stack.push(*i);
		}
	}

	
	//generate random graph
	void generateRandomGraph(int maxEdgeWeight) {
		srand(static_cast<unsigned>(time(nullptr)));

		for (int i = 1; i <= vertices; i++) {
			createRandomNode(i);
		}

		for (int i = 1; i <= vertices; i++) {
			for (int j = i + 1; j <= vertices; j++) {
				int edgeWeight = 1 + rand() % maxEdgeWeight;
				addEdge(i, j, edgeWeight);
			}
		}
	}

	//randomNode
	int createRandomNode(int value) {
		return value;
	}

	//return Amount of Vertices
	int getNumVertices() {
		return vertices;
	}

	//generate vertices
	vector<int> getGraphVertices() {
		vector<int> graphVertices;
		for (int i = 1; i <= vertices; ++i) {
			graphVertices.push_back(i);
		}
		return graphVertices;
	}

	//deleteNode
	void deleteNode(int nodeToDelete) {
		if (nodeToDelete < 1 || nodeToDelete > vertices) {
			cerr << "Invalid node to delete." << endl;
			return;
		}

		for (int i = 1; i <= vertices; i++) {
			if (i != nodeToDelete) {
				adjLists[i - 1].erase(std::remove(adjLists[i - 1].begin(), adjLists[i - 1].end(), nodeToDelete), adjLists[i - 1].end());
			}
		}

		adjLists[nodeToDelete - 1].clear();
		vertices--;
	}

	//insert Node
	void insertNodeWithEdges(int newNode, const vector<int>& connectedNodes) {
		if (newNode < 1 || newNode > vertices + 1) {
			cerr << "Invalid position to insert a node." << endl;
			return;
		}

		if (newNode > vertices) {
			adjLists.resize(newNode);
			vertices = newNode;
		}

		for (int i : connectedNodes) {
			if (i >= 1 && i <= vertices && i != newNode) {
				adjLists[i - 1].push_back(newNode);
				adjLists[newNode - 1].push_back(i);
			}
		}
	}

	
	int getNumEdges() {
		return edgeCount;
	}
	
	int size() {
		return vertices;
	}

	//adds edge
	void addEdge(int from, int to, int weight) {
		if (from >= 1 && from <= vertices && to >= 1 && to <= vertices) {
			
			adjLists[from - 1].push_back(to);
			adjLists[to - 1].push_back(from); 
			edgeCount++; 
			cout << "Edge between " << from << " and " << to << " with weight " << weight << endl;
		}
		else {
			cerr << "Invalid vertex numbers. Edge not added." << endl;
		}
	}

	//checks if its empty
	bool isEmpty() const {
		return vertices == 0;
	}

	//prints the awnser
	void printIsEmpty() {
		if (isEmpty()) {
			cout << "The graph is empty." << endl;
		}
		else {
			cout << "The Graph is not empty." << endl;
		}
	}


};



