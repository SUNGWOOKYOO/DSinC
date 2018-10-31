#ifndef __USEFUL_HEAP_H__
#define __USEFUL_HEAP_H__

#define TRUE	1
#define FALSE	0

/*** Heap�� ���� ****/
#define HEAP_LEN	100

#if 1 // ��Heapsort.c�� ������ �ϱ� ���ؼ��� data�� int�̾�� �Ѵ�. 
//typedef char HData;
//typedef char * HData; 
typedef int HData;

#endif

// d1�� �켱������ ���ٸ� 0���� ū ��
// d2�� �켱������ ���ٸ� 0���� ���� ��
// d1�� d2�� �켱������ ���ٸ� 0�� ��ȯ
typedef int PriorityComp(HData d1, HData d2);

// ������ HeapElem ����ü�� ���ְ�, priority�� programmer�� ���� �� �ֵ��� �Լ� ������ comp �� ����
typedef struct _heap
{
	PriorityComp * comp;		//���� �ɹ� ������ ���� comp�� ���� data���� �켱������ ���� �� �ְ� ���.
	int numOfData;
	HData heapArr[HEAP_LEN];
} Heap;

/*** Heap ���� ����� ****/
void HeapInit(Heap * ph, PriorityComp pc);
int HIsEmpty(Heap * ph);

void HInsert(Heap * ph, HData data);
HData HDelete(Heap * ph);

#endif