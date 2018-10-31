#ifndef __CLL_STACK_H__
#define __CLL_STACK_H__

#include "CLinkedList.h" // 원형 리스트 자료구조의 헤더를 그대로 가져옴 

#define TRUE	1
#define FALSE	0

typedef int Data; // int 형을 Data로 정의 하였다.

typedef struct _listStack
{
	List * plist;
} ListStack;


typedef ListStack Stack; // List자료구조로 Stack 자료구조를 구현하기 위해 정의함 

void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);

void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);

#endif