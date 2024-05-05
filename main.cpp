#include "GraphHW.h"

int main()
{
	GraphHW g;

	Person user1{ "Oleg", 0 };
	Person user2{ "Nikita", 1 };
	Person user3{ "Nastya", 2 };
	Person user4{ "Ivan", 3 };
	Person user5{ "Eugene", 4 };

	g.addVertex(user1);
	g.addVertex(user2);
	g.addVertex(user3);
	g.addVertex(user4);
	g.addVertex(user5);

	g.addEdge(user1, user2, 1);
	g.addEdge(user2, user3, 1);
	g.addEdge(user3, user4, 1);
	g.addEdge(user1, user5, 1);

	g.showShakes(3);

	return 0;
}