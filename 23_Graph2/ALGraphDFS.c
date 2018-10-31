#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphDFS.h"
#include "DLinkedList.h"

#if 0							// DFS algorithm 구현 할때 1
#include "ArrayBaseStack.h"		// stack을 이용하여 searching 한다.
#else							// BFS algorithm 구현할때 0
#include "CircularQueue.h"		// Queue을 이용하여 searching 한다.
#endif
int WhoIsPrecede(int data1, int data2);

// 그래프의 초기화
void GraphInit(ALGraph * pg, int nv)
{
	int i;	

	pg->adjList = (List*)malloc(sizeof(List)*nv);
	pg->numV = nv;
	pg->numE = 0;     // 초기의 간선 수는 0개

	for(i=0; i<nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede); 
	}

	// 탐색 정보 등록을 위한 공간의 할당 및 초기화
	pg->visitInfo= (int *)malloc(sizeof(int) * pg->numV); // 방문정보 배열의 크기는 정점의 그래프의 정점의 크기만큼 할당 

	// 배열의 모든 요소를 0으로 초기화 - memset은 내장함수로서 배열을 어떤 값으로 초기화 한다. 
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

// 그래프의 리소스 해제
void GraphDestroy(ALGraph * pg)
{
	if(pg->adjList != NULL)
		free(pg->adjList);

	if(pg->visitInfo != NULL)
		free(pg->visitInfo);
}

// 간선의 추가
void AddEdge(ALGraph * pg, int fromV, int toV)
{
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;
}

// 유틸리티 함수: 간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph * pg)
{
	int i;
	int vx;

	for(i=0; i<pg->numV; i++)
	{
		printf("%c와 연결된 정점: ", i + 65);
		
		if(LFirst(&(pg->adjList[i]), &vx))
		{
			printf("%c ", vx + 65);
			
			while(LNext(&(pg->adjList[i]), &vx))
				printf("%c ", vx + 65);
		}
		printf("\n");
	}
}

// 방문을 할때 우선순위를 정하기 위해서 이 함수를 정의했다.
// 문제 14-2 에서 우선순위 변경을 하면 #if 0 으로변경, 
int WhoIsPrecede(int data1, int data2)
{
#if 1
	if (data1 < data2)
	{
#else
	if (data1 > data2)
	{
#endif
		return 0;
	}
	else
		return 1;
}

// 정점 방문을 진행; 방문한 vertex를 출력하여 보여준다. 
int VisitVertex(ALGraph * pg, int visitV)
{
	if(pg->visitInfo[visitV] == 0)	// 방문정보가 비어있으면 
	{
		pg->visitInfo[visitV] = 1;
		printf("%c ", visitV + 65);     // 방문 정점 출력 ; ex) A 는 enum에 의해 0 값이 되고, +65 를 하면 ASCII code 값인 A가 출력된다. 
		return TRUE;
	}
	
	return FALSE;	// 방문정보가 있다면 
}

#if 0	// DFS algorithm 구현 할때 1

// Depth First Search: 정점의 정보 출력
void DFShowGraphVertex(ALGraph * pg, int startV)
{
	Stack stack;	// seaching Algorithm의 구현을 위해 stack의 이용이 필요하다. 
	int visitV = startV;
	int nextV;

	// DFS를 위한 스택의 초기화
	StackInit(&stack);

	VisitVertex(pg, visitV);    // 시작 정점 방문 ; 성공시 TRUE
	SPush(&stack, visitV);		// 스택을 이용 (start vertex를 stack에 담는다)

	// 아래의 while 문에서 모든 정점의 방문이 이루어진다!
	// visitV에 담긴 정점과 연결된 정점의 방문을 시도하는 while문 ; List기반으로 Graph가 구현되었으므로 pg->adjList[]에 값이 있는 지 확인한 후 진행
	while(LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		// visitB와 연결된 정점의 정보가 nextV에 담긴 상태에서 이하를 진행 
	
		int visitFlag = FALSE;

		if(VisitVertex(pg, nextV) == TRUE)	// 방문에 성공했다면( 방문정보 배열이 0 즉, 비어있으면 print하게 된다 ),  
		{
			SPush(&stack, visitV);			//visitV에 담긴 정점의 정보를 Push  (다음 vertex 이동전에 이전 vertex를 stack에 담는다)
			visitV = nextV;					//List에서 다음 (node)vertex가 방문 우선순위 vertex
			visitFlag = TRUE;
		}
		else								//방문에 성공하지 못했다면, 연결된 다른 정점들을 찾는다. 
		{
			while(LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
			{
				if(VisitVertex(pg, nextV) == TRUE)
				{
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;	// 모두 방문하였으므로 while문 탈출
				}
			}
		}
		
		if(visitFlag == FALSE)				//추가로 방문한 정점이 없었다면
		{
			// 스택이 비면 탐색의 시작점으로 돌아온것 
			if(SIsEmpty(&stack) == TRUE)    // 스택이 비면 DFS종료
				break;
			else
				visitV = SPop(&stack);	// 인접한 vertex의 visitInfo[] flag가 모두 1 인 상태여서 VisitVertex(pg, - ) == False 인 상황이고, 처음으로 아직 되돌아가지 않았다면 pop! 
		}
	}

	// 탐색 정보 초기화
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

#else	// BFS algorithm 구현 할때 0

// Breadth First Search: 정점의 정보 출력
void BFShowGraphVertex(ALGraph * pg, int startV)
{
	Queue queue;
	int visitV = startV;
	int nextV;

	// DFS를 위한 큐의 초기화
	QueueInit(&queue);

	// 시작 정점 탐색
	VisitVertex(pg, visitV);

	// while문에서 visitV와 연결된 모든 정점에 방문한다.
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		if (VisitVertex(pg, nextV) == TRUE)
			Enqueue(&queue, nextV);				// nextV에 방문했으니 큐에 저장

		while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
		{
			if (VisitVertex(pg, nextV) == TRUE)
				Enqueue(&queue, nextV);			// nextV에 방문했으니 큐에 저장
		}

		if (QIsEmpty(&queue) == TRUE)    // 큐가 비면 BFS 종료
			break;
		else
			visitV = Dequeue(&queue);	// 큐에서 하나 꺼내어 while문 다시 시작 
	}

	// 탐색 정보 초기화
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}
#endif