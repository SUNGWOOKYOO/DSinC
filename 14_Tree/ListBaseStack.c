// ExpressionMain.c 에서 쓰기 위해 Stack 자료구조를 가져오기 위해 소스파일에 추가(전혀 변형할 필요없다)
// Stack 자료구조를 구현하는데 사용하기 위한 ADT
#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h" // 리스트 자료구조를 이용하여 구현하였다.

void StackInit(Stack * pstack)
{
	pstack->head = NULL;
}

int SIsEmpty(Stack * pstack) // 비었나 안비었나 확인 masking 기능
{
	if(pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = pstack->head;

	pstack->head = newNode;
}

Data SPop(Stack * pstack)
{
	Data rdata;
	Node * rnode;

	if(SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	rdata = pstack->head->data;
	rnode = pstack->head;

	pstack->head = pstack->head->next;
	free(rnode);

	return rdata;
}

Data SPeek(Stack * pstack) // Stack이 비었는지 확인하고 Stack 영역의 data 알려줌; 비교등의 연산을 위해 쓰임
{
	if(SIsEmpty(pstack)) 
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->head->data;
}