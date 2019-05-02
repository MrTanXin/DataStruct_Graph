#include "ALGraph.h"
#include <iostream>

//this method be used to flush stdin
inline void flush()
{
	//this "c" be used to flush stdin
	char c = NULL;
	while ((c = getchar() != '\n' && c != EOF));
}

//this method be used to show index-vexName table
inline void showAll(adjList& a)
{
	printf("table:\n");
	for (int i = 0; i < a.vexnum; i++)
	{
		printf("\t%d--%c\n", i, a.adj[i].value);
	}
}

//this method will be return v[] is already all true;
inline bool IsAllVisited(adjList& a,bool *v)
{
	for (int i = 0; i < a.vexnum; i++)
	{
		if (v[i]==false)
		{
			return false;
		}
	}
	return true;
}

//this method be used to find index from a
int GetLocal(adjList& a, char e)
{
	for (int i = 0; i < a.vexnum; i++)
	{
		if (e==a.adj[i].value)
		{
			return i;
		}
	}
	return -1;
}

void CreateAdjList(adjList& a)
{
#pragma region User Input HWF
	printf("有权图吗？(1:是，其他：不是)");
	if (char c=getchar()=='1')
	{
		flush();
		a.HWF = true;
	}
	else
	{
		flush();
		a.HWF = false;
	}

	printf("%s\n", a.HWF ? "有权图" : "无权图");
#pragma endregion

#pragma region User Input vexnum and edgenum
	
	printf("请输入顶点数量和边数:");
	scanf("%d,%d", &a.vexnum, &a.edgenum);
	flush();
#pragma endregion

#pragma region "User Input adj[].value and set first_Node is NULL"

	for (int i = 0; i < a.vexnum; i++)
	{
		printf("第%d个:", i);
		scanf("%c", &a.adj[i].value);
		flush();
		a.adj[i].first_Node = NULL;
	}

#pragma endregion

#pragma region full of edges

	printf("如果是有向图，请在source--时输入dest的序号");
	for (int i = 0; i < a.vexnum; i++)
	{
		int t_info;//index
		
		showAll(a);
		printf("%c--", a.adj[i].value);
		scanf("%d", &t_info);

		while(t_info != -1)
		{
			edges* node = new edges;
			node->Info = t_info;
			if (a.HWF)
			{

				printf("weight:");
				scanf("%d", &node->weight);
			}
			else
			{
				node->weight = 1;
			}
			node->next = a.adj[i].first_Node;	
			a.adj[i].first_Node = node;
			
			showAll(a);
			printf("%c--", a.adj[i].value);			
			scanf("%d", &t_info);
		}
	}

#pragma endregion
}


void BFSL(adjList& a, int i, bool* visited, queue *q)
{
	if (IsAllVisited(a,visited))
	{
		return;
	}

	edges* iterator = a.adj[i].first_Node;
	while (iterator)
	{
		if (!visited[iterator->Info])
		{
			Queue_push(q, a.adj[iterator->Info].value);
			printf("Visit:%c", a.adj[iterator->Info].value);
			visited[iterator->Info] = true;
		}
		iterator = iterator->next;
	}
	BFSL(a, GetLocal(a, Queue_pop(q)), visited, q);
}

void BFSLTravel(adjList& a)
{
	queue *q;
	InitQueue(q);

	bool visited[100];
	for (int i = 0; i < a.vexnum; i++)
	{
		visited[i] = false;
	}

	for (int i = 0; i < a.vexnum; i++)
	{
		if (!visited[i])
		{
			Queue_push(q, a.adj[i].value);
			visited[i] = true;
			printf("Visit:%c", a.adj[i].value);
			BFSL(a, GetLocal(a, Queue_pop(q)), visited, q);
		}
	}
}


void DFSL(adjList& a, int i, bool* visited)
{
	printf("Visit:%c", a.adj[i].value);
	visited[i] = true;

	edges* iterator = a.adj[i].first_Node;
	while (iterator!=NULL)
	{
		if (!visited[iterator->Info])
		{
			DFSL(a, iterator->Info, visited);
		}
		iterator = iterator->next;
	}
}

void DFSLTravel(adjList& a)
{
	bool visited[100];

	for (int i = 0; i < a.vexnum; i++)
	{
		visited[i] = false;
	}

	for (int i = 0; i < a.vexnum; i++)
	{
		if (!visited[i])
		{
			DFSL(a, i, visited);
		}
	}
}


