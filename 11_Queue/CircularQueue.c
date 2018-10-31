#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"
/*  ������ ���� property �� �����ϴ� �ڷᱸ���� ����   
 �迭�� ���̰� N �̶�� data �� N-1 �� ä��� �ֵ��� ���� 
 �迭 ��� circular queue 
 FIFO ����� �ڷᱸ��		*/
void QueueInit(Queue * pq)	// �ֺ� ���, F&R �� ���� ��ġ�� ����Ŵ
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

int NextPosIdx(int pos) // index ���� ȸ�� ����(circular index) 
{
	if(pos == QUE_LEN-1)	// �迭�� ������ ����� index ���̶�� 
		return 0;
	else
		return pos+1;
}

void Enqueue(Queue * pq, Data data) // R�� �̵��� ���� data �Է� 
{
	if(NextPosIdx(pq->rear) == pq->front)
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = data; // F�� ����Ű�� ���� ������ ����
}

Data Dequeue(Queue * pq)	// F�� �̵��� ���� data return  
{
	if(QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	pq->front = NextPosIdx(pq->front);
	return pq->queArr[pq->front]; // F�� ����Ű�� ������ ��ȯ 
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