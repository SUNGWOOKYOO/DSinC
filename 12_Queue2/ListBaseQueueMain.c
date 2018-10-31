 /* List 기반 queue 
List를 사용하기 때문에 circular form 일 필요 없다. 
FIFO 방식의 자료구조		*/
#include <stdio.h>
#include "ListBaseQueue.h"

int main(void)
{
	// Queue의 생성 및 초기화 ///////
	Queue q;
	QueueInit(&q);

	// 데이터 넣기 ///////
	Enqueue(&q, 1);  Enqueue(&q, 2);
	Enqueue(&q, 3);  Enqueue(&q, 4);
	Enqueue(&q, 5);

	// 데이터 꺼내기 ///////
	while(!QIsEmpty(&q))
		printf("%d ", Dequeue(&q)); 

	return 0;
}