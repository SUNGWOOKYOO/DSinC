#ifndef __AL_GRAPH_DFS__
#define __AL_GRAPH_DFS__

#include "DLinkedList.h"

// ������ �̸����� ���ȭ
enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _ual
{
	int numV;   // ������ ��
	int numE;   // ������ ��
	List * adjList;   // ������ ����
	int * visitInfo;	//���� �߰��� �ɹ�  - Ž���� ����� ������ ������ ��� ����(int �ڷ��� �迭). 
} ALGraph;

// �׷����� �ʱ�ȭ
void GraphInit(ALGraph * pg, int nv);

// �׷����� ���ҽ� ����
void GraphDestroy(ALGraph * pg);

// ������ �߰�
void AddEdge(ALGraph * pg, int fromV, int toV);

// ��ƿ��Ƽ �Լ�: ������ ���� ���
void ShowGraphEdgeInfo(ALGraph * pg);

// Depth First Search: ������ ���� ��� ; search �Ǵ� ���� �鸣�� �Ǵ� vertex���� ������� ����ϰ� �ȴ�. ; visitInfo �迭�� ������ ��� 
void DFShowGraphVertex(ALGraph * pg, int startV);

// Breadth First Search: ������ ���� ���
void BFShowGraphVertex(ALGraph * pg, int startV);

#endif