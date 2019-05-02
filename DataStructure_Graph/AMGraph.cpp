#include "AMGraph.h"
#include "Queue.h"
#include <iostream>

//this method be used to judge all vexs has been visited
inline bool IsAllVisit(AMGraph G, bool* visit)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (visit[i]==false)
		{
			return false;
		}
	}
	return true;
}

//this method be used to flush stdin
inline void flush()
{ 
	//this "c" be used to flush stdin
	char c=NULL;
	while ((c = getchar()!='\n' && c != EOF));
}

//this method be used to show Vexs top Info(name)
inline void showVexs(AMGraph &g) 
{
	for (int i = 0; i < g.vexnum; i++)
	{
		printf("%d--%c\n", i, g.vexs[i]);
	}
}

void CreateMap(AMGraph& G)
{
	//this "temp" be used to get USER INPUT
	int temp;

#pragma region User Input IsUDMF
	
	printf("是无向图吗？（1：是,其他：不是）:");
	scanf("%d", &temp);
	G.IsUDMF = temp == 1 ? true : false;
	printf("%s\n", G.IsUDMF == true ? "是无向图" : "是有向图");

	flush();
#pragma endregion
	
#pragma region User Input HWF

	printf("是有权的？（1：是，其他：不是）:");
	scanf("%d", &temp);
	G.HWF = temp == 1 ? true : false;
	printf("%s\n", G.HWF == true ? "是有权图" : "是无权图");

	flush();
#pragma endregion

#pragma region User Input vexnum and edgenum

	printf("请输入vexsnum,edgenum:");
	scanf("%d,%d", &G.vexnum, &G.edgenum);
	
	flush();
#pragma endregion

#pragma region set edges[] as 0

	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
		{
			G.edges[i][j] = 0;
		}
	}

#pragma endregion

#pragma region user Input vexs[]

	for (int i = 0; i < G.vexnum; i++)
	{
		printf("第%d个:",i + 1);
		scanf("%c", &G.vexs[i]);
		flush();
	}
	printf("顶点数组输入完成\n");
#pragma endregion


#pragma region user Input edges[]

	for (int i = 0; i < G.edgenum; i++)
	{
		showVexs(G);
		if (G.HWF)
		{
			int z, x, w;
			
			if (G.IsUDMF==false)
				printf("请输入v1,v2,weight   v1,v2为序号,遵循v1->v2的顺序,均为int类型");
			else
				printf("请输入v1,v2,weight   v1,v2为序号,均为int类型");

			scanf("%d,%d,%d", &z, &x, &w);
			G.edges[z][x] = w;
			
			if (G.IsUDMF)
			{
				G.edges[x][z] = G.edges[z][x];
			}
			
		}
		else
		{
			int z, x;

			if (G.IsUDMF == false)
				printf("请输入v1,v2   v1,v2为序号,遵循v1->v2的顺序,均为int类型");
			else
				printf("请输入v1,v2   v1,v2为序号,均为int类型");

			scanf("%d,%d", &z, &x);
			G.edges[z][x] = 1;

			if (G.IsUDMF)
			{
				G.edges[x][z] = G.edges[z][x];
			}
		}
	}

#pragma endregion
}

//	find Postion In 'G.vexs'
int GetLocate(AMGraph &G,vexsType e)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.vexs[i]==e)
		{
			return i;
		}
	}
	return -1;
}


#pragma region Deepth-First Search in Map

void DFSM(AMGraph &G,int i,bool *visited)
{
	

	/*
		set visited[i] to TRUE because it has been visited
	*/
	visited[i] = 1;
	printf("Visited:%c",G.vexs[i]);

	/*
		To find the top which is in edges[i] rows and haven't been visited
	*/
	for (int j = 0; j < G.vexnum; j++)
	{
		if (G.edges[i][j]!=0&&!visited[j])
		{
			DFSM(G, j, visited);
		}
	}
}

void DFSMTravel(AMGraph &G)
{
	/*
		IF any top has been visited,visited[] will change its state
	*/
	bool visited[MaxV];
	
	/*
		set visited[] to all false
	*/
	for (int i = 0; i < G.vexnum; i++)
	{
		visited[i] = false;
	}

	for (int i = 0; i < G.vexnum; i++)
	{
		if (!visited[i])
		{
			printf("从%c开始遍历", G.vexs[i]);
			DFSM(G, i, visited);
		}
	}
}

#pragma endregion



#pragma region Breadth-first Search in Map

void BFSM(AMGraph &G,int i,bool *visited,queue *q)
{
	if (IsAllVisit(G,visited))
	{
		return;
	}
	
	for (int j = 0; j < G.vexnum; j++)
	{
		if (!visited[j]&&G.edges[i][j]!=0)
		{
			printf("Visit:%c", G.vexs[j]);	
			visited[j] = 1;

			Queue_push(q, G.vexs[j]);
		}
	}

	BFSM(G, GetLocate(G, Queue_pop(q)), visited, q);
}

void BFSMTravel(AMGraph &G)
{
	//define queue<vexsType> and initialization
	queue *q;
	InitQueue(q);

	//define visited[] and initialization
	bool visited[MaxV];
	for (int i = 0; i < G.vexnum; i++)
	{
		visited[i] = false;
	}


	for (int i = 0; i < G.vexnum; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			printf("Visit:%c", G.vexs[i]);
			Queue_push(q, G.vexs[i]);
			BFSM(G,GetLocate(G, Queue_pop(q)), visited, q);
		}
	}
}

#pragma endregion
