#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

void StackInit(Stack * pstack)
{ /* ������ �ʱ�ȭ�� �����Ѵ�. 
	���� ���� �� ���� ���� ȣ��Ǿ���ϴ� �Լ� */
	pstack->topIndex = -1;
}

int SIsEmpty(Stack * pstack)
{/* ������ ���� T
	�׷��� ���� ��� F	*/
	if(pstack->topIndex == -1)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data)
{/* ���ؿ� ������ ����, �Ű����� data�� ���޵� ���� �����Ѵ�. */
	pstack->topIndex += 1;
	pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack * pstack)
{/* �������� ����� ��Ҹ� ����(topIndex--)
	������ �����ʹ� ��ȯ 
	�� �Լ��� ȣ���� ���� ������ �ϳ� �̻� �������� ���� �Ǿ���� */
	int rIdx;

	if(SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	rIdx = pstack->topIndex;
	pstack->topIndex -= 1;

	return pstack->stackArr[rIdx];
}

Data SPeek(Stack * pstack)
{/* �������� ����� ��Ҹ� ��ȯ�ϵ� �������� �ʴ´�(topIndex ������ ����)
	�� �Լ��� ȣ���� ���ؼ��� �����Ͱ� �ϳ� �̻� �������� ����Ǿ�� �Ѵ�. */
	if(SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->stackArr[pstack->topIndex];
}