// ExpressionMain.c ���� ���� ���� Stack �ڷᱸ���� �������� ���� �ҽ����Ͽ� �߰�(���� ������ �ʿ����)
// Stack �ڷᱸ���� �����ϴµ� ����ϱ� ���� ADT
#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h" // ����Ʈ �ڷᱸ���� �̿��Ͽ� �����Ͽ���.

void StackInit(Stack * pstack)
{
	pstack->head = NULL;
}

int SIsEmpty(Stack * pstack) // ����� �Ⱥ���� Ȯ�� masking ���
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

Data SPeek(Stack * pstack) // Stack�� ������� Ȯ���ϰ� Stack ������ data �˷���; �񱳵��� ������ ���� ����
{
	if(SIsEmpty(pstack)) 
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->head->data;
}