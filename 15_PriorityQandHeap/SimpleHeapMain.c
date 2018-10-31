/* [Chap9]  
 priority Queue 와 Heap  
 우선 순위를 고려한 Queue 자료구조는 우선 순위를 고려하여 insert, delete이 되는 자료구조다 
 이 자료구조는 Heap 이라는 어떤 특성을 만족하는 Tree 형태의 자료구조를 의미하며,  
 특히, 어떤 특성을 만족하는 Heap의 구현은 배열 기반 Tree 를 이용하게 된다.
 이 예제는 simple 한 case의 우선순위 큐의 구현이며 
 programmer가 insert를 할때마다 우선순위를 정해줘야하는 번거로움이 있다. */
#include <stdio.h>
#include "SimpleHeap.h"

int main(void)
{
	Heap heap;
	HeapInit(&heap);

	HInsert(&heap, 'A', 1); // 우선순위를 정해줘야하는 번거로움 발생 
	HInsert(&heap, 'B', 2);
	HInsert(&heap, 'C', 3);
	printf("%c \n", HDelete(&heap));

	HInsert(&heap, 'A', 1);
	HInsert(&heap, 'B', 2);
	HInsert(&heap, 'C', 3);
	printf("%c \n", HDelete(&heap));

	while(!HIsEmpty(&heap))
		printf("%c \n", HDelete(&heap));

	return 0;
}
