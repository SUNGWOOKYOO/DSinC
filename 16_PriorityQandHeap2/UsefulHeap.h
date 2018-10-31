#ifndef __USEFUL_HEAP_H__
#define __USEFUL_HEAP_H__

#define TRUE	1
#define FALSE	0

/*** Heap의 정의 ****/
#define HEAP_LEN	100

#if 1 // ★문제 09-1 을 하기 위해서는 data가 문자열이여야 하기 때문에  char * 형이어야 한다. 
//typedef char HData;
typedef char * HData; 
#endif

// d1의 우선순위가 높다면 0보다 큰 값
// d2의 우선순위가 높다면 0보다 작은 값
// d1과 d2의 우선순위가 같다면 0을 반환
typedef int PriorityComp(HData d1, HData d2);

// 이전에 HeapElem 구조체를 없애고, priority를 programmer가 정할 수 있도록 함수 포인터 comp 를 선언
typedef struct _heap
{
	PriorityComp * comp;		//이제 맴버 포인터 변수 comp를 통해 data간의 우선순위를 비교할 수 있게 됬다.
	int numOfData;
	HData heapArr[HEAP_LEN];
} Heap;

/*** Heap 관련 연산들 ****/
void HeapInit(Heap * ph, PriorityComp pc);
int HIsEmpty(Heap * ph);

void HInsert(Heap * ph, HData data);
HData HDelete(Heap * ph);

#endif