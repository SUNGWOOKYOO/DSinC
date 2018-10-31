#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

int EvalRPNExp(char exp[]) // 후위 표기법의 수식을 계산하여 그 결과를 반환
{
	Stack stack;
	int expLen = strlen(exp);
	int i;
	char tok, op1, op2;

	StackInit(&stack);

	for(i=0; i<expLen; i++)				// 수식을 구성하는 문자 각각을 대상으로 반복
	{
		tok = exp[i];					// 한문자씩 tok에 저장하고,

		if(isdigit(tok))				//  그 문자의 내용이 정수인지 확인
		{
			SPush(&stack, tok - '0');     // 숫자로 변환하여 stack 에 PUSH!
		}
		else
		{
			op2 = SPop(&stack);     // 먼저 꺼낸 값이 두 번째 피연산자!
			op1 = SPop(&stack);

			switch(tok)			// 연산하고 그 결과를 다시 stack에 push!! 
			{
			case '+':
				SPush(&stack, op1+op2);
				break;
			case '-':
				SPush(&stack, op1-op2);
				break;
			case '*':
				SPush(&stack, op1*op2);
				break;
			case '/':
				SPush(&stack, op1/op2);
				break;
			}
		}
	}
	return SPop(&stack);
}
