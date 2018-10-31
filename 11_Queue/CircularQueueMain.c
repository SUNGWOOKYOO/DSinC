//[Chap 7] Queue 
/* ☆ 다음과 같은 property 를 만족하는 자료구조의 구현
배열의 길이가 N 이라면 data 는 N-1 개 채울수 있도록 구현
배열 기반 circular queue
FIFO 방식의 자료구조		*/
#if 0 
#include <stdio.h>
#include "CircularQueue.h"

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
#endif

/* Simulation Example 
 HamburgerSim.c */
#if 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "CircularQueue.h" // Queuedml 공간이 어느정도면 적당한가에 대해 평가하기 위해서 고정 크기를 사용한 CircularQueue이용

#define	CUS_COME_TERM	15		// 고객의 주문 간격: 초 단위

#define CHE_BUR		0		// 치즈버거 상수 
#define BUL_BUR		1		// 불고기버거 상수
#define DUB_BUR		2		// 더블버거 상수

#define CHE_TERM	12		// 치즈버거 제작 시간: 초 단위
#define BUL_TERM	15		// 불고기버거 제작 시간: 초 단위
#define DUB_TERM	24		// 더블버거 제작 시간: 초 단위

int main(void)
{
	int makeProc = 0;			// 햄버거 제작 진행상황
	int cheOrder = 0, bulOrder = 0, dubOrder = 0;
	int sec;

	Queue que;

	QueueInit(&que);
	srand(time(NULL));

	// 아래 for문의 1회 회전은 1초의 시간 흐름을 의미함
	for (sec = 0; sec<3600; sec++)
	{
		if (sec % CUS_COME_TERM == 0)
		{
			switch (rand() % 3)
			{
			case CHE_BUR:
				Enqueue(&que, CHE_TERM);
				cheOrder += 1;
				break;

			case BUL_BUR:
				Enqueue(&que, BUL_TERM);
				bulOrder += 1;
				break;

			case DUB_BUR:
				Enqueue(&que, DUB_TERM);
				dubOrder += 1;
				break;
			}
		}

		if (makeProc == 0 && !QIsEmpty(&que)) // 햄버거를 만들수 있는 상황이 되면
			makeProc = Dequeue(&que);		// 대기실에서 나오게 된다. 

		makeProc--;
	}

	printf("Simulation Report! \n", QUE_LEN);
	printf(" - Cheese burger: %d \n", cheOrder);
	printf(" - Bulgogi burger: %d \n", bulOrder);
	printf(" - Double burger: %d \n", dubOrder);
	printf(" - Waiting room size: %d \n", QUE_LEN);
	return 0;
}
#endif 