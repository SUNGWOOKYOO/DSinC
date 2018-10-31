#include "PriorityQueue.h"
#include "UsefulHeap.h"
// � Ư���� �����ϴ� Heap(e.g Ʈ�������� Min-heap, Max-heap) �� �� Priority Queue�̴�. ���� �׳� �����ٰ� ����ȴ�.(�̸��� �ٲ۰�)

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