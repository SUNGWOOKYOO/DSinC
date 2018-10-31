/*	DFSMain.c  and BFSMain.c 합쳤다.
	searching Algorithm 
	- DFS 은 searching 과정에서 statck 필요 
	- BFS 은 searching 과정에서 statck 필요
	Graph를 List를 사용하여 구현 
	< Debugging하며 실행 결과 확인 해보자 >
*/
#include <stdio.h>
#include "ALGraphDFS.h"

int main(void)
{
	ALGraph graph;
	GraphInit(&graph, 7);      // A, B, C, D, E, F, G의 정점 생성

	AddEdge(&graph, A, B);
	AddEdge(&graph, A, D);
	AddEdge(&graph, B, C);
	AddEdge(&graph, D, C);
	AddEdge(&graph, D, E);
	AddEdge(&graph, E, F);
	AddEdge(&graph, E, G);


#if 0
	ShowGraphEdgeInfo(&graph);

	DFShowGraphVertex(&graph, A); printf("\n");
	DFShowGraphVertex(&graph, C); printf("\n");
	DFShowGraphVertex(&graph, E); printf("\n");
	DFShowGraphVertex(&graph, G); printf("\n");

	GraphDestroy(&graph);
#else
	ShowGraphEdgeInfo(&graph);

	BFShowGraphVertex(&graph, A); printf("\n");
	BFShowGraphVertex(&graph, C); printf("\n");
	BFShowGraphVertex(&graph, E); printf("\n");
	BFShowGraphVertex(&graph, G); printf("\n");

	GraphDestroy(&graph);
#endif
	return 0;
}