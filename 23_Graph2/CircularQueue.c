#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"
/*  다음과 같은 property 를 만족하는 자료구조의 구현   
 배열의 길이가 N 이라면 data 는 N-1 개 채울수 있도록 구현 
 배열 기반 circular queue 
 FIFO 방식의 자료구조		*/
void QueueInit(Queue * pq)	// 텅빈 경우, F&R 은 동일 위치를 가리킴
{
	pq->front = 0;
	pq->rear = 0;
}

int QIsEmpty(Queue * pq)
{
	if(pq->front == pq->rear)
		return TRUE;
	else
		return FALSE;
}

int NextPosIdx(int pos) // index 값의 회전 구현(circular index) 
{
	if(pos == QUE_LEN-1)	// 배열의 마지막 요소의 index 값이라면 
		return 0;
	else
		return pos+1;
}

void Enqueue(Queue * pq, Data data) // R의 이동을 통해 data 입력 
{
	if(NextPosIdx(pq->rear) == pq->front)
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = data; // F가 가리키는 곳에 데이터 저장
}

Data Dequeue(Queue * pq)	// F의 이동을 통해 data return  
{
	if(QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	pq->front = NextPosIdx(pq->front);
	return pq->queArr[pq->front]; // F가 가리키는 데이터 반환 
}

Data QPeek(Queue * pq)
{
	if(QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	return pq->queArr[NextPosIdx(pq->front)];
}