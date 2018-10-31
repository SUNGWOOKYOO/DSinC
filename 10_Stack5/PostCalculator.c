#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

int EvalRPNExp(char exp[]) // ���� ǥ����� ������ ����Ͽ� �� ����� ��ȯ
{
	Stack stack;
	int expLen = strlen(exp);
	int i;
	char tok, op1, op2;

	StackInit(&stack);

	for(i=0; i<expLen; i++)				// ������ �����ϴ� ���� ������ ������� �ݺ�
	{
		tok = exp[i];					// �ѹ��ھ� tok�� �����ϰ�,

		if(isdigit(tok))				//  �� ������ ������ �������� Ȯ��
		{
			SPush(&stack, tok - '0');     // ���ڷ� ��ȯ�Ͽ� stack �� PUSH!
		}
		else
		{
			op2 = SPop(&stack);     // ���� ���� ���� �� ��° �ǿ�����!
			op1 = SPop(&stack);

			switch(tok)			// �����ϰ� �� ����� �ٽ� stack�� push!! 
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
