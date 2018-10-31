#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphKruskal.h"
#include "DLinkedList.h"
#if 1							// DFS algorithm 구현 할때 1
#include "ArrayBaseStack.h"		// stack을 이용하여 searching 한다.
#else							// BFS algorithm 구현할때 0
#include "CircularQueue.h"		// Queue을 이용하여 searching 한다.
#endif

// 밑의 2개의 함수는 Graph의 우선순위를 정하는 함수이다.
int WhoIsPrecede(int data1, int data2);		// List의 vertex의 이름값에 기반을 두어 우선순위를 정하는 함수 
int PQWeightComp(Edge d1, Edge d2);			// MST를 구성할 weight값의 기반을 두어 우선순위를 정하는 함수

void GraphInit(ALGraph * pg, int nv)
{
	int i;	

	pg->adjList = (List*)malloc(sizeof(List)*nv);
	pg->numV = nv;
	pg->numE = 0;

	for(i=0; i<nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede); 
	}

	pg->visitInfo= (int *)malloc(sizeof(int) * pg->numV);
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);

	// 우선순위 큐의 초기화
	PQueueInit(&(pg->pqueue), PQWeightComp);
}

void GraphDestroy(ALGraph * pg)
{
	if(pg->adjList != NULL)
		free(pg->adjList);

	if(pg->visitInfo != NULL)
		free(pg->visitInfo);
}

void AddEdge(ALGraph * pg, int fromV, int toV, int weight)
{
	Edge edge = {fromV, toV, weight};     // 간선의 정보 생성

	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;

	// 간선의 정보를 우선순위 큐에 저장
	PEnqueue(&(pg->pqueue), edge);
}

// ConKruskalMST Helper function
void RecoverEdge(ALGraph * pg, int fromV, int toV, int weight)
{
	// 무방향 그래프이므로 2번 Insert
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	(pg->numE)++;
}

// 한쪽 방향의 간선 소멸: ConKruskalMST Helper function
void RemoveWayEdge(ALGraph * pg, int fromV, int toV)
{
	int edge;

	if(LFirst(&(pg->adjList[fromV]), &edge))
	{
		if(edge == toV)
		{
			LRemove(&(pg->adjList[fromV]));
			return;
		}

		while(LNext(&(pg->adjList[fromV]), &edge))
		{
			if(edge == toV)
			{
				LRemove(&(pg->adjList[fromV]));
				return;
			}
		}
	}
}

// 간선의 소멸: ConKruskalMST Helper function
void RemoveEdge(ALGraph * pg, int fromV, int toV)
{
	// 무방향 그래프이기 때문에 양방향으로(2번) 간선정보를 지워야한다.
	RemoveWayEdge(pg, fromV, toV);
	RemoveWayEdge(pg, toV, fromV);
	(pg->numE)--;
}
 
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

void ShowGraphEdgeWeightInfo(ALGraph * pg)
{
	PQueue copyPQ = pg->pqueue;
	Edge edge;

	while(!PQIsEmpty(&copyPQ))
	{
		edge = PDequeue(&copyPQ);
		printf("(%c-%c), w:%d \n", edge.v1+65, edge.v2+65, edge.weight);
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

// d1의 우선순위가 높다면 0보다 큰 값
// d2의 우선순위가 높다면 0보다 작은 값
// d1과 d2의 우선순위가 같다면 0을 반환
int PQWeightComp(Edge d1, Edge d2)	
{
	return d1.weight - d2.weight;		// 가중치를 기준으로 내림차순으로 간선의 정보를 꺼낼 수 있다. 
}

int VisitVertex(ALGraph * pg, int visitV)
{
	if(pg->visitInfo[visitV] == 0)
	{
		pg->visitInfo[visitV] = 1;
	//	printf("%c ", visitV + 65);		// 정점을 방문했을때 굳이 출력할 필요없으므로 주석처리
		return TRUE;
	}
	
	return FALSE;
}


#if 1	// DFS algorithm 구현 할때 1

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
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		// visitB와 연결된 정점의 정보가 nextV에 담긴 상태에서 이하를 진행 

		int visitFlag = FALSE;

		if (VisitVertex(pg, nextV) == TRUE)	// 방문에 성공했다면( 방문정보 배열이 0 즉, 비어있으면 print하게 된다 ),  
		{
			SPush(&stack, visitV);			//visitV에 담긴 정점의 정보를 Push  (다음 vertex 이동전에 이전 vertex를 stack에 담는다)
			visitV = nextV;					//List에서 다음 (node)vertex가 방문 우선순위 vertex
			visitFlag = TRUE;
		}
		else								//방문에 성공하지 못했다면, 연결된 다른 정점들을 찾는다. 
		{
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
			{
				if (VisitVertex(pg, nextV) == TRUE)
				{
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;	// 모두 방문하였으므로 while문 탈출
				}
			}
		}

		if (visitFlag == FALSE)				//추가로 방문한 정점이 없었다면
		{
			// 스택이 비면 탐색의 시작점으로 돌아온것 
			if (SIsEmpty(&stack) == TRUE)    // 스택이 비면 DFS종료
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

// 두 정점이 연결되어 있다면 TRUE, 그렇지 않다면 FALSE 반환 
// DFS 알고리즘은 임의의 정점을 시작으로 그래프 전체를 돌 수 있다. 이를 변형한 함수로서 이용하자!  (Stack을 이용한다)
int IsConnVertex(ALGraph * pg, int v1, int v2)
{
	Stack stack;
	int visitV = v1;
	int nextV;

	StackInit(&stack);
	VisitVertex(pg, visitV);
	SPush(&stack, visitV);

	while(LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		int visitFlag = FALSE;

		//정점을 돌아다니던 도중에 목표를 찾는다면 TRUE반환
		if(nextV == v2)
		{
			memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
			return TRUE;
		}

		if(VisitVertex(pg, nextV) == TRUE)
		{
			SPush(&stack, visitV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		else
		{
			while(LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
			{
				//정점을 돌아다니던 도중에 목표를 찾는다면 TRUE반환
				if(nextV == v2)
				{
					//정점을 돌아다니던 도중에 목표를 찾는다면 TRUE반환
					memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
					return TRUE;
				}

				if(VisitVertex(pg, nextV) == TRUE)
				{
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}
		
		if(visitFlag == FALSE)
		{
			if(SIsEmpty(&stack) == TRUE)
				break;
			else
				visitV = SPop(&stack);	
		}
	}

	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
	return FALSE;	// 여기까지 온다면 목표를 찾지 못헀다는것! 
}


// MST 간선의 수 + 1 == 정점의 수
// 크루스칼 알고리즘 기반 최소 비용 신장 트리의 구성
void ConKruskalMST(ALGraph * pg)
{
	Edge recvEdge[20];    // 복원할 간선의 정보 저장
	Edge edge;
	int eidx = 0;
	int i;

	// MST를 형성할 때까지 아래의 while문을 반복
	while(pg->numE+1 > pg->numV)
	{
		// 우선 순위 큐에서 가중치가 제일 높은 edge의 정보를 꺼낸다.
		edge = PDequeue(&(pg->pqueue));		

		// 우선 순위 큐에서 꺼낸 edge를 실제로 그래프에서 삭제한다. 
		RemoveEdge(pg, edge.v1, edge.v2);

		// 간선을 삭제하고 나서도 두 정점을 연결하는 경로가 있는지 확인한다. ;두 정점이 연결되어 있다면 TRUE, 그렇지 않다면 FALSE 반환
		if(!IsConnVertex(pg, edge.v1, edge.v2))
		{
			//경로가 없다면 삭제한 간선을 복원한다
			RecoverEdge(pg, edge.v1, edge.v2, edge.weight);

			// 복원한 간선의 정보를 별도로 저장한다.	-> 차후에 MST의 간선이 될것임! 
			recvEdge[eidx++] = edge;
		}
	}

	// 우선순위 큐에서 삭제된 간선의 정보를 회복	-> MST 조건을 만족하는 간선만 따로 모아 다시 Queue에 집어 넣는다! 
	for(i=0; i<eidx; i++)
		PEnqueue(&(pg->pqueue), recvEdge[i]);

}