#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

void StackInit(Stack * pstack)
{ /* 스텍의 초기화를 진행한다. 
	스택 생성 후 제일 먼저 호출되어야하는 함수 */
	pstack->topIndex = -1;
}

int SIsEmpty(Stack * pstack)
{/* 스텍이 빈경우 T
	그렇지 않은 경우 F	*/
	if(pstack->topIndex == -1)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data)
{/* 스텍에 데이터 저장, 매개변수 data로 전달된 값을 저장한다. */
	pstack->topIndex += 1;
	pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack * pstack)
{/* 마지막에 저장된 요소를 삭제(topIndex--)
	삭제된 데이터는 반환 
	본 함수의 호출을 위해 데이터 하나 이상 존재함이 보장 되어야함 */
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
{/* 마지막에 저장된 요소를 반환하되 삭제하지 않는다(topIndex 내리지 않음)
	본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야 한다. */
	if(SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->stackArr[pstack->topIndex];
}