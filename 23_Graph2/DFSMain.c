/*	DFSMain.c  and BFSMain.c ���ƴ�.
	searching Algorithm 
	- DFS �� searching �������� statck �ʿ� 
	- BFS �� searching �������� statck �ʿ�
	Graph�� List�� ����Ͽ� ���� 
	< Debugging�ϸ� ���� ��� Ȯ�� �غ��� >
*/
#include <stdio.h>
#include "ALGraphDFS.h"

int main(void)
{
	ALGraph graph;
	GraphInit(&graph, 7);      // A, B, C, D, E, F, G�� ���� ����

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