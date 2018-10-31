#include "DequeBaseQueue.h"  //Dequeue의 ADT를 이용해 queue를 정의한것이다. 

void QueueInit(Queue * pq)
{
	DequeInit(pq);
}

int QIsEmpty(Queue * pq)
{
	return DQIsEmpty(pq);
}

void Enqueue(Queue * pq, Data data)
{
	DQAddLast(pq, data);
}

Data Dequeue(Queue * pq)
{
	return DQRemoveFirst(pq);
}

Data QPeek(Queue * pq)
{
	return DQGetFirst(pq);
}