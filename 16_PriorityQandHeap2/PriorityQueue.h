#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include "UsefulHeap.h"
// 어떤 특성을 만족하는 Heap(e.g 트리형태의 Min-heap, Max-heap) 이 곧 Priority Queue이다. 따라서 그냥 가져다가 쓰면된다. 

typedef Heap PQueue;
typedef HData PQData;

void PQueueInit(PQueue * ppq, PriorityComp pc);
int PQIsEmpty(PQueue * ppq);

void PEnqueue(PQueue * ppq, PQData data);
PQData PDequeue(PQueue * ppq);

#endif