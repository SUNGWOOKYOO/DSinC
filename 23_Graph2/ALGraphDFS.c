#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphDFS.h"
#include "DLinkedList.h"

#if 0							// DFS algorithm ���� �Ҷ� 1
#include "ArrayBaseStack.h"		// stack�� �̿��Ͽ� searching �Ѵ�.
#else							// BFS algorithm �����Ҷ� 0
#include "CircularQueue.h"		// Queue�� �̿��Ͽ� searching �Ѵ�.
#endif
int WhoIsPrecede(int data1, int data2);

// �׷����� �ʱ�ȭ
void GraphInit(ALGraph * pg, int nv)
{
	int i;	

	pg->adjList = (List*)malloc(sizeof(List)*nv);
	pg->numV = nv;
	pg->numE = 0;     // �ʱ��� ���� ���� 0��

	for(i=0; i<nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede); 
	}

	// Ž�� ���� ����� ���� ������ �Ҵ� �� �ʱ�ȭ
	pg->visitInfo= (int *)malloc(sizeof(int) * pg->numV); // �湮���� �迭�� ũ��� ������ �׷����� ������ ũ�⸸ŭ �Ҵ� 

	// �迭�� ��� ��Ҹ� 0���� �ʱ�ȭ - memset�� �����Լ��μ� �迭�� � ������ �ʱ�ȭ �Ѵ�. 
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

// �׷����� ���ҽ� ����
void GraphDestroy(ALGraph * pg)
{
	if(pg->adjList != NULL)
		free(pg->adjList);

	if(pg->visitInfo != NULL)
		free(pg->visitInfo);
}

// ������ �߰�
void AddEdge(ALGraph * pg, int fromV, int toV)
{
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;
}

// ��ƿ��Ƽ �Լ�: ������ ���� ���
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

// ���� �湮�� ����; �湮�� vertex�� ����Ͽ� �����ش�. 
int VisitVertex(ALGraph * pg, int visitV)
{
	if(pg->visitInfo[visitV] == 0)	// �湮������ ��������� 
	{
		pg->visitInfo[visitV] = 1;
		printf("%c ", visitV + 65);     // �湮 ���� ��� ; ex) A �� enum�� ���� 0 ���� �ǰ�, +65 �� �ϸ� ASCII code ���� A�� ��µȴ�. 
		return TRUE;
	}
	
	return FALSE;	// �湮������ �ִٸ� 
}

#if 0	// DFS algorithm ���� �Ҷ� 1

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
	while(LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		// visitB�� ����� ������ ������ nextV�� ��� ���¿��� ���ϸ� ���� 
	
		int visitFlag = FALSE;

		if(VisitVertex(pg, nextV) == TRUE)	// �湮�� �����ߴٸ�( �湮���� �迭�� 0 ��, ��������� print�ϰ� �ȴ� ),  
		{
			SPush(&stack, visitV);			//visitV�� ��� ������ ������ Push  (���� vertex �̵����� ���� vertex�� stack�� ��´�)
			visitV = nextV;					//List���� ���� (node)vertex�� �湮 �켱���� vertex
			visitFlag = TRUE;
		}
		else								//�湮�� �������� ���ߴٸ�, ����� �ٸ� �������� ã�´�. 
		{
			while(LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
			{
				if(VisitVertex(pg, nextV) == TRUE)
				{
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;	// ��� �湮�Ͽ����Ƿ� while�� Ż��
				}
			}
		}
		
		if(visitFlag == FALSE)				//�߰��� �湮�� ������ �����ٸ�
		{
			// ������ ��� Ž���� ���������� ���ƿ°� 
			if(SIsEmpty(&stack) == TRUE)    // ������ ��� DFS����
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