#pragma once
#include <iostream>
#include "Person.h"
#define SIZE 6

class GraphHW {
private:

	int matrix[SIZE][SIZE];
	Person vertexes[SIZE];
	int vertexCount;
	bool edgeExists(Person v1, Person v2);
	void findShakes(Person start, Person current, bool visited[], int handshakes, int path);

public:

	GraphHW();
	void addVertex(Person v);
	void addEdge(Person v1, Person v2, int weight);
	int getWeight(Person v1, Person v2);
	void showShakes(int handshakes);
};