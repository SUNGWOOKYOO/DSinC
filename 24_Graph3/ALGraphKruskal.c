#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphKruskal.h"
#include "DLinkedList.h"
#if 1							// DFS algorithm ���� �Ҷ� 1
#include "ArrayBaseStack.h"		// stack�� �̿��Ͽ� searching �Ѵ�.
#else							// BFS algorithm �����Ҷ� 0
#include "CircularQueue.h"		// Queue�� �̿��Ͽ� searching �Ѵ�.
#endif

// ���� 2���� �Լ��� Graph�� �켱������ ���ϴ� �Լ��̴�.
int WhoIsPrecede(int data1, int data2);		// List�� vertex�� �̸����� ����� �ξ� �켱������ ���ϴ� �Լ� 
int PQWeightComp(Edge d1, Edge d2);			// MST�� ������ weight���� ����� �ξ� �켱������ ���ϴ� �Լ�

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

	// �켱���� ť�� �ʱ�ȭ
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
	Edge edge = {fromV, toV, weight};     // ������ ���� ����

	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;

	// ������ ������ �켱���� ť�� ����
	PEnqueue(&(pg->pqueue), edge);
}

// ConKruskalMST Helper function
void RecoverEdge(ALGraph * pg, int fromV, int toV, int weight)
{
	// ������ �׷����̹Ƿ� 2�� Insert
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	(pg->numE)++;
}

// ���� ������ ���� �Ҹ�: ConKruskalMST Helper function
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

// ������ �Ҹ�: ConKruskalMST Helper function
void RemoveEdge(ALGraph * pg, int fromV, int toV)
{
	// ������ �׷����̱� ������ ���������(2��) ���������� �������Ѵ�.
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
		printf("%c�� ����� ����: ", i + 65);
		
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

// �湮�� �Ҷ� �켱������ ���ϱ� ���ؼ� �� �Լ��� �����ߴ�.
// ���� 14-2 ���� �켱���� ������ �ϸ� #if 0 ���κ���, 
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

// d1�� �켱������ ���ٸ� 0���� ū ��
// d2�� �켱������ ���ٸ� 0���� ���� ��
// d1�� d2�� �켱������ ���ٸ� 0�� ��ȯ
int PQWeightComp(Edge d1, Edge d2)	
{
	return d1.weight - d2.weight;		// ����ġ�� �������� ������������ ������ ������ ���� �� �ִ�. 
}

int VisitVertex(ALGraph * pg, int visitV)
{
	if(pg->visitInfo[visitV] == 0)
	{
		pg->visitInfo[visitV] = 1;
	//	printf("%c ", visitV + 65);		// ������ �湮������ ���� ����� �ʿ�����Ƿ� �ּ�ó��
		return TRUE;
	}
	
	return FALSE;
}


#if 1	// DFS algorithm ���� �Ҷ� 1

// Depth First Search: ������ ���� ��� 
void DFShowGraphVertex(ALGraph * pg, int startV)
{
	Stack stack;	// seaching Algorithm�� ������ ���� stack�� �̿��� �ʿ��ϴ�. 
	int visitV = startV;
	int nextV;

	// DFS�� ���� ������ �ʱ�ȭ
	StackInit(&stack);

	VisitVertex(pg, visitV);    // ���� ���� �湮 ; ������ TRUE
	SPush(&stack, visitV);		// ������ �̿� (start vertex�� stack�� ��´�)

								// �Ʒ��� while ������ ��� ������ �湮�� �̷������!
								// visitV�� ��� ������ ����� ������ �湮�� �õ��ϴ� while�� ; List������� Graph�� �����Ǿ����Ƿ� pg->adjList[]�� ���� �ִ� �� Ȯ���� �� ����
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		// visitB�� ����� ������ ������ nextV�� ��� ���¿��� ���ϸ� ���� 

		int visitFlag = FALSE;

		if (VisitVertex(pg, nextV) == TRUE)	// �湮�� �����ߴٸ�( �湮���� �迭�� 0 ��, ��������� print�ϰ� �ȴ� ),  
		{
			SPush(&stack, visitV);			//visitV�� ��� ������ ������ Push  (���� vertex �̵����� ���� vertex�� stack�� ��´�)
			visitV = nextV;					//List���� ���� (node)vertex�� �湮 �켱���� vertex
			visitFlag = TRUE;
		}
		else								//�湮�� �������� ���ߴٸ�, ����� �ٸ� �������� ã�´�. 
		{
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
			{
				if (VisitVertex(pg, nextV) == TRUE)
				{
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;	// ��� �湮�Ͽ����Ƿ� while�� Ż��
				}
			}
		}

		if (visitFlag == FALSE)				//�߰��� �湮�� ������ �����ٸ�
		{
			// ������ ��� Ž���� ���������� ���ƿ°� 
			if (SIsEmpty(&stack) == TRUE)    // ������ ��� DFS����
				break;
			else
				visitV = SPop(&stack);	// ������ vertex�� visitInfo[] flag�� ��� 1 �� ���¿��� VisitVertex(pg, - ) == False �� ��Ȳ�̰�, ó������ ���� �ǵ��ư��� �ʾҴٸ� pop! 
		}
	}

	// Ž�� ���� �ʱ�ȭ
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

#else	// BFS algorithm ���� �Ҷ� 0

// Breadth First Search: ������ ���� ���
void BFShowGraphVertex(ALGraph * pg, int startV)
{
	Queue queue;
	int visitV = startV;
	int nextV;

	// DFS�� ���� ť�� �ʱ�ȭ
	QueueInit(&queue);

	// ���� ���� Ž��
	VisitVertex(pg, visitV);

	// while������ visitV�� ����� ��� ������ �湮�Ѵ�.
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		if (VisitVertex(pg, nextV) == TRUE)
			Enqueue(&queue, nextV);				// nextV�� �湮������ ť�� ����

		while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
		{
			if (VisitVertex(pg, nextV) == TRUE)
				Enqueue(&queue, nextV);			// nextV�� �湮������ ť�� ����
		}

		if (QIsEmpty(&queue) == TRUE)    // ť�� ��� BFS ����
			break;
		else
			visitV = Dequeue(&queue);	// ť���� �ϳ� ������ while�� �ٽ� ���� 
	}

	// Ž�� ���� �ʱ�ȭ
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}
#endif

// �� ������ ����Ǿ� �ִٸ� TRUE, �׷��� �ʴٸ� FALSE ��ȯ 
// DFS �˰����� ������ ������ �������� �׷��� ��ü�� �� �� �ִ�. �̸� ������ �Լ��μ� �̿�����!  (Stack�� �̿��Ѵ�)
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

		//������ ���ƴٴϴ� ���߿� ��ǥ�� ã�´ٸ� TRUE��ȯ
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
				//������ ���ƴٴϴ� ���߿� ��ǥ�� ã�´ٸ� TRUE��ȯ
				if(nextV == v2)
				{
					//������ ���ƴٴϴ� ���߿� ��ǥ�� ã�´ٸ� TRUE��ȯ
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
	return FALSE;	// ������� �´ٸ� ��ǥ�� ã�� �����ٴ°�! 
}


// MST ������ �� + 1 == ������ ��
// ũ�罺Į �˰��� ��� �ּ� ��� ���� Ʈ���� ����
void ConKruskalMST(ALGraph * pg)
{
	Edge recvEdge[20];    // ������ ������ ���� ����
	Edge edge;
	int eidx = 0;
	int i;

	// MST�� ������ ������ �Ʒ��� while���� �ݺ�
	while(pg->numE+1 > pg->numV)
	{
		// �켱 ���� ť���� ����ġ�� ���� ���� edge�� ������ ������.
		edge = PDequeue(&(pg->pqueue));		

		// �켱 ���� ť���� ���� edge�� ������ �׷������� �����Ѵ�. 
		RemoveEdge(pg, edge.v1, edge.v2);

		// ������ �����ϰ� ������ �� ������ �����ϴ� ��ΰ� �ִ��� Ȯ���Ѵ�. ;�� ������ ����Ǿ� �ִٸ� TRUE, �׷��� �ʴٸ� FALSE ��ȯ
		if(!IsConnVertex(pg, edge.v1, edge.v2))
		{
			//��ΰ� ���ٸ� ������ ������ �����Ѵ�
			RecoverEdge(pg, edge.v1, edge.v2, edge.weight);

			// ������ ������ ������ ������ �����Ѵ�.	-> ���Ŀ� MST�� ������ �ɰ���! 
			recvEdge[eidx++] = edge;
		}
	}

	// �켱���� ť���� ������ ������ ������ ȸ��	-> MST ������ �����ϴ� ������ ���� ��� �ٽ� Queue�� ���� �ִ´�! 
	for(i=0; i<eidx; i++)
		PEnqueue(&(pg->pqueue), recvEdge[i]);

}