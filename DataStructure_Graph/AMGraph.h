#pragma once
/*
	you can delete this HEADER
		1.you NOT use Visual Studio IDE
		2.you think the warning is very important
*/
#include "Define.h"


#define MaxV 100
typedef char vexsType;
typedef int edgesType;

typedef struct
{
	/*
		top Info
		content: top name(char);
	*/
	vexsType vexs[MaxV];
	
	/*
		edges Info
		content: 
			If IsUDMF is TRUE 
				edges is Symmetrical to the main diagonal
			Else 
				is NOT symmetry
	*/
	edgesType edges[MaxV][MaxV];
	
	/*
		vexnum:
			content: how many nums in vexs[];
	*/
	int vexnum;
	
	/*
		edgenum:
			content: how many nums in edges[];
	*/
	int edgenum;
	
	/*
		UnDirectionMapFlag
		true	:UDM
		false	:DM
	*/
	bool IsUDMF;

	/*
		HaveWeightFlag
		true	:Have Weight
		false	:NOT Have Weight
	*/
	bool HWF;
}AMGraph;


/*
	Create Maps
	
	step:
		1.IsUDMF
		2.HWF
		3.vexsnum and edgesnum
		4.set edges[] as 0
		5.vexs[]
		6.edges[]
*/
void CreateMap(AMGraph& G);

/*
	Deepth First Search (Map)
*/
void DFSMTravel(AMGraph&);

/*
	Breadth First Search (Map)
*/
void BFSMTravel(AMGraph&);