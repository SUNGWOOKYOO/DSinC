#ifndef __AL_GRAPH_DFS__
#define __AL_GRAPH_DFS__

#include "DLinkedList.h"

// 정점의 이름들을 상수화
enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _ual
{
	int numV;   // 정점의 수
	int numE;   // 간선의 수
	List * adjList;   // 간선의 정보
	int * visitInfo;	//새로 추가된 맴버  - 탐색이 진행된 정점의 정보를 담기 위함(int 자료형 배열). 
} ALGraph;

// 그래프의 초기화
void GraphInit(ALGraph * pg, int nv);

// 그래프의 리소스 해제
void GraphDestroy(ALGraph * pg);

// 간선의 추가
void AddEdge(ALGraph * pg, int fromV, int toV);

// 유틸리티 함수: 간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph * pg);

// Depth First Search: 정점의 정보 출력 ; search 되는 동안 들르게 되는 vertex값을 순서대로 출력하게 된다. ; visitInfo 배열의 정보를 출력 
void DFShowGraphVertex(ALGraph * pg, int startV);

// Breadth First Search: 정점의 정보 출력
void BFShowGraphVertex(ALGraph * pg, int startV);

#endif