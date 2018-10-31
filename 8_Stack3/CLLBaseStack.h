#ifndef __CLL_STACK_H__
#define __CLL_STACK_H__

#include "CLinkedList.h" // ���� ����Ʈ �ڷᱸ���� ����� �״�� ������ 

#define TRUE	1
#define FALSE	0

typedef int Data; // int ���� Data�� ���� �Ͽ���.

typedef struct _listStack
{
	List * plist;
} ListStack;


typedef ListStack Stack; // List�ڷᱸ���� Stack �ڷᱸ���� �����ϱ� ���� ������ 

void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);

void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);

#endif