#include "PriorityQueue.h"
#include "UsefulHeap.h"
// 어떤 특성을 만족하는 Heap(e.g 트리형태의 Min-heap, Max-heap) 이 곧 Priority Queue이다. 따라서 그냥 가져다가 쓰면된다.(이름만 바꾼것)

void PQueueInit(PQueue * ppq, PriorityComp pc)
{
	HeapInit(ppq, pc);
}

int PQIsEmpty(PQueue * ppq)
{
	return HIsEmpty(ppq);
}

void PEnqueue(PQueue * ppq, PQData data)
{
	HInsert(ppq, data);
}

PQData PDequeue(PQueue * ppq)
{
	return HDelete(ppq);
}