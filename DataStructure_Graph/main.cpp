#include "AMGraph.h"
#include "ALGraph.h"

int main()
{
	AMGraph G;
	CreateMap(G);
	BFSMTravel(G);
	DFSMTravel(G);

	adjList a;
	CreateAdjList(a);
	DFSLTravel(a);
	BFSLTravel(a);
	return 0;
}