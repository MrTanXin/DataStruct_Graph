#pragma once
/*
	you can delete this HEADER 
		1.you NOT use Visual Studio IDE
		2.you think the warning is very important
*/
#include "Define.h"


#include "Queue.h"

typedef char vexType;
typedef int edgeType;

//edges is Edge Info
typedef struct edges
{
	//this Info is direct connect to its vexs value
	edgeType Info;
	//edges weight
	int weight;
	//next Node
	struct edges* next;
}edges;

//vexs is Top Info
typedef struct vexs
{
	//value is Top Info Value
	vexType value;
	//this pointer is link to the first Node
	edges* first_Node;
}vexs;

//Adjacent list struct
typedef struct adjList
{
	//Top Node 
	vexs adj[100];
	
	//vexnum:how many nums in all adj[];
	int vexnum;

	//edgenum:how many nums in all adj[];
	int edgenum;

	/*
		Have Weight Flag
		TURE:	Have Weight
		FALSE:	NOT Have Weight
	*/
	bool HWF;
}adjList;

/*
	To create Adjacent List

	step:
		1.User Input HWF
		2.User Input vexnum and edgenum
		3.User Input adj[].value and set first_Node is NULL
		4.full of edges
*/
void CreateAdjList(adjList& a);

void BFSLTravel(adjList& a);

void DFSLTravel(adjList& a);