#ifndef __LB_QUEUE_H__
#define __LB_QUEUE_H__

#define TRUE	1
#define FALSE	0

typedef int Data;

typedef struct _node // 리스트 자료구조는 node 기반으로 구현된다. 
{
	Data data;
	struct _node * next;
} Node;

typedef struct _lQueue // queue 자료구조는 node형 맴버변수를 지니게 된다. 
{
	Node * front;
	Node * rear;
} LQueue;

typedef LQueue Queue;

void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);

void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);

#endif