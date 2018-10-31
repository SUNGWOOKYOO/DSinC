/* HeapInit에서 함수 포인터 comp를 Heap 구조체의 맴버 변수를 programmer가 지정하게 둠으로써,
 더 이상 insert 수행할때마다 priority값을 지정해 주지 않아도 된다.
 단, 지정하는 우선순위 함수의 동작은 다음과 같아야한다
 // d1의 우선순위가 높다면 0보다 큰 값
 // d2의 우선순위가 높다면 0보다 작은 값
 // d1과 d2의 우선순위가 같다면 0을 반환
*/
#if 0
#include <stdio.h>
#include "UsefulHeap.h"

int DataPriorityComp(char ch1, char ch2) // programm가 우선순위를 지정했다. 
{
	return ch2-ch1;  // 양수면 ch1이 우선순위가 높다!  ex) B - A ; 아스키코드값 차이 1 ! 
//	return ch1-ch2;
}

int main(void)
{
	Heap heap;
	HeapInit(&heap, DataPriorityComp);

	HInsert(&heap, 'A');
	HInsert(&heap, 'B');
	HInsert(&heap, 'C');
	printf("%c \n", HDelete(&heap));

	HInsert(&heap, 'A');
	HInsert(&heap, 'B');
	HInsert(&heap, 'C');
	printf("%c \n", HDelete(&heap));

	while(!HIsEmpty(&heap))
		printf("%c \n", HDelete(&heap));

	return 0;
}
#endif 

// 어떤 특성을 만족하는 Heap(e.g 트리형태의 Min-heap, Max-heap) 이 곧 Priority Queue이다. 따라서 그냥 가져다가 쓰면된다.
// PriorityQueueMain.c
#if 0
#include <stdio.h>
#include "PriorityQueue.h"

int DataPriorityComp(char ch1, char ch2)
{
	return ch2 - ch1;
}

int main(void)
{
	PQueue pq;
	PQueueInit(&pq, DataPriorityComp);

	PEnqueue(&pq, 'A');
	PEnqueue(&pq, 'B');
	PEnqueue(&pq, 'C');
	printf("%c \n", PDequeue(&pq));

	PEnqueue(&pq, 'A');
	PEnqueue(&pq, 'B');
	PEnqueue(&pq, 'C');
	printf("%c \n", PDequeue(&pq));

	while (!PQIsEmpty(&pq))
		printf("%c \n", PDequeue(&pq));

	return 0;
}
#endif

/* 문제 09-1
	PQStringMain.c
	programmer가 우선순위를 문자열이 짧을 수록 우선순위가 높도록 지정하였고 
	문자열의 저장에 대해서 자료구조를 우선순위큐로 구현한 것이다.
	문자열 배열의 저장 최대 크기는 100 글자이다. HEAP_LEN	100 이므로 
또한, UsefulHeap.c에서  
	#if 1 // ★문제 09-1 을 하기 위해서는 data가 문자열이여야 하기 때문에  char * 형이어야 한다.
	//typedef char HData;
	typedef char * HData;
	#endif
*/
#if 1
#include <stdio.h>
#include <string.h>
#include "PriorityQueue.h"

int DataPriorityComp(char * str1, char * str2)
{
	return strlen(str2) - strlen(str1);
}

int main(void)
{
	PQueue pq;
	PQueueInit(&pq, DataPriorityComp);

	PEnqueue(&pq, "Good morning");
	PEnqueue(&pq, "I am a boy");
	PEnqueue(&pq, "Priority Queue");
	PEnqueue(&pq, "Do you like coffee");
	PEnqueue(&pq, "I am so happy");

	while (!PQIsEmpty(&pq))
		printf("%s \n", PDequeue(&pq));

	return 0;
}
#endif 