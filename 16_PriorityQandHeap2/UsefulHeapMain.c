/* HeapInit���� �Լ� ������ comp�� Heap ����ü�� �ɹ� ������ programmer�� �����ϰ� �����ν�,
 �� �̻� insert �����Ҷ����� priority���� ������ ���� �ʾƵ� �ȴ�.
 ��, �����ϴ� �켱���� �Լ��� ������ ������ ���ƾ��Ѵ�
 // d1�� �켱������ ���ٸ� 0���� ū ��
 // d2�� �켱������ ���ٸ� 0���� ���� ��
 // d1�� d2�� �켱������ ���ٸ� 0�� ��ȯ
*/
#if 0
#include <stdio.h>
#include "UsefulHeap.h"

int DataPriorityComp(char ch1, char ch2) // programm�� �켱������ �����ߴ�. 
{
	return ch2-ch1;  // ����� ch1�� �켱������ ����!  ex) B - A ; �ƽ�Ű�ڵ尪 ���� 1 ! 
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

// � Ư���� �����ϴ� Heap(e.g Ʈ�������� Min-heap, Max-heap) �� �� Priority Queue�̴�. ���� �׳� �����ٰ� ����ȴ�.
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

/* ���� 09-1
	PQStringMain.c
	programmer�� �켱������ ���ڿ��� ª�� ���� �켱������ ������ �����Ͽ��� 
	���ڿ��� ���忡 ���ؼ� �ڷᱸ���� �켱����ť�� ������ ���̴�.
	���ڿ� �迭�� ���� �ִ� ũ��� 100 �����̴�. HEAP_LEN	100 �̹Ƿ� 
����, UsefulHeap.c����  
	#if 1 // �ڹ��� 09-1 �� �ϱ� ���ؼ��� data�� ���ڿ��̿��� �ϱ� ������  char * ���̾�� �Ѵ�.
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