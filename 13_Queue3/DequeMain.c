// Deque 자료구조의 구현; 앞으로도 뒤로도 넣을 수 있고, 앞으로도 뒤로도 뺄 수 있는 자료구조
#if 0
#include <stdio.h>
#include "Deque.h"

int main(void)
{
	// Deque의 생성 및 초기화 ///////
	Deque deq;
	DequeInit(&deq);

	// 데이터 넣기 1차 ///////
	DQAddFirst(&deq, 3); 
	DQAddFirst(&deq, 2); 
	DQAddFirst(&deq, 1); 

	DQAddLast(&deq, 4); 
	DQAddLast(&deq, 5); 
	DQAddLast(&deq, 6);

	// 데이터 꺼내기 1차 ///////
	while(!DQIsEmpty(&deq))
		printf("%d ", DQRemoveFirst(&deq));

	printf("\n");

	// 데이터 넣기 2차 ///////
	DQAddFirst(&deq, 3); 
	DQAddFirst(&deq, 2); 
	DQAddFirst(&deq, 1);
	
	DQAddLast(&deq, 4); 
	DQAddLast(&deq, 5); 
	DQAddLast(&deq, 6);

	// 데이터 꺼내기 2차 ///////
	while(!DQIsEmpty(&deq))
		printf("%d ", DQRemoveLast(&deq));

	return 0;
}
#endif

/* Dequeue를 이용한 queue의 구현 
  DequeBaseQueueMain.c*/
#if 1 
#include <stdio.h>
#include "DequeBaseQueue.h" // dequeue를 이용하여 만듦

int main(void)
{
	Queue q;
	QueueInit(&q);

	Enqueue(&q, 1);
	Enqueue(&q, 2);
	Enqueue(&q, 3);
	Enqueue(&q, 4);
	Enqueue(&q, 5);

	while (!QIsEmpty(&q))
		printf("%d ", Dequeue(&q));

	return 0;
}
#endif