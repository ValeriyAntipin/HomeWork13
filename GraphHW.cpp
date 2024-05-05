#include "GraphHW.h"

GraphHW::GraphHW()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			matrix[i][j] = 0;
		}
	}
	vertexCount = 0;
}

void GraphHW::addVertex(Person v)
{
	vertexes[vertexCount++] = v;
}

void GraphHW::addEdge(Person v1, Person v2, int weight)
{
	matrix[v1.getIndex()][v2.getIndex()] = weight;
	matrix[v2.getIndex()][v1.getIndex()] = weight;
}

bool GraphHW::edgeExists(Person v1, Person v2)
{
	if (matrix[v1.getIndex()][v2.getIndex()] == 0)
		return false;
	else
		return true;
}

int GraphHW::getWeight(Person v1, Person v2)
{
	return matrix[v1.getIndex()][v2.getIndex()];
}

void GraphHW::showShakes(int handshakes)
{
	cout << "Couples of users know each other through three handshakes:" << endl;

	bool visited[SIZE];
	for (int i = 0; i < SIZE; i++)
		visited[i] = false;

	int path = 0;
	for (int i = 0; i < vertexCount - 1; i++)
	{
		findShakes(vertexes[i], vertexes[i], visited, handshakes, path);
		visited[i] = true;
	}
}

void GraphHW::findShakes(Person start, Person current, bool visited[], int handshakes, int path)
{
	if (path <= handshakes && path > 0)
	{
		cout << start.getName() << " and " << current.getName() << endl;
	}

	if (path > handshakes)
		return;

	visited[current.getIndex()] = true;

	for (int i = 0; i < vertexCount; i++)
	{
		if (edgeExists(current, vertexes[i]) && !visited[i])
		{
			path += getWeight(current, vertexes[i]);
			findShakes(start, vertexes[i], visited, handshakes, path);
		}
	}
	visited[current.getIndex()] = false;
}