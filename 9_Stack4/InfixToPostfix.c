#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ListBaseStack.h"

int GetOpPrec(char op) // �������� ���� �켱���� ������ ��ȯ
{
	switch(op)
	{
	case '*':
	case '/':
		return 5;
	case '+':
	case '-':
		return 3;
	case '(':  // ')'�����ڴ� ��ȯ���� ���� �� �ʿ� ����. �Ұ�ȣ ���� �ǹ��ϴ� ������ �̱� ������ �켱���� ���� �ʿ� ���� ����
		return 1;
	}

	return -1;   // ��ϵ��� ���� ������
}

int WhoPrecOp(char op1, char op2) // �������� �켱���� �� 
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if(op1Prec > op2Prec)
		return 1;
	else if(op1Prec < op2Prec)
		return -1;
	else
		return 0;
}

void ConvToRPNExp(char exp[]) // ���� ǥ����� �������� ��ȯ 
{
	Stack stack;
	int expLen = strlen(exp);
	char * convExp = (char*)malloc(expLen+1);

	int i, idx=0;
	char tok, popOp;
	
	/*memset �����Լ�
	memset�Լ��� � �޸��� ���������� ���ӵ� ������ � ������(����Ʈ ����) ��� �����ϰ� ���� �� ����ϴ� �Լ��̴�.
		void * memset ( void * ptr, int value, size_t num );
		ptr : ä����� �ϴ� �޸��� ���� ������(���� �ּ�)
		value : �޸𸮿� ä������ϴ� ��. int�������� ���ο����� unsigned char(1 byte)�� ��ȯ�Ǿ ����ȴ�.
		num : ä����� �ϴ� ����Ʈ�� ��. ��, ä����� �ϴ� �޸��� ũ��  */
	memset(convExp, 0, sizeof(char)*expLen+1); // �Ҵ�� �迭�� 0 ���� �ʱ�ȭ 
	StackInit(&stack);

	for(i=0; i<expLen; i++) // ��ü ������ �� ���ھ� �����ϰ� �ȴ�. 
	{
		tok = exp[i]; // exp�� ���޵� ������ �� ���ھ� tok�� ���� 
		if(isdigit(tok)) // tok�� ����� ���ڰ� �������� Ȯ�� ; isdigit(����) : ����('')�� ���� 0~9 ���̿� ���ϴ��� �˻��ϴ� �Լ� 
		{
			convExp[idx++] = tok;  // �����̸� �迭 convExp�� �׳� ���� 
		}
		else // ���ڰ� �ƴ϶�� 
		{
			switch(tok)
			{
			// '('�� ')' �� special case 
			case '(':				// ���� �Ұ�ȣ���
				SPush(&stack, tok); // ���ÿ� �״´�. 
				break;

			case ')':				// �ݴ� �Ұ�ȣ���, 
				while(1)			// �ݺ��ؼ�	
				{
					popOp = SPop(&stack);	// ���ÿ��� �����ڸ� ������
					if(popOp == '(')		// ������ ( �� ������ ����, 
						break;
					convExp[idx++] = popOp; // �迭 convExp�� �����Ѵ�(�����Ҵ� ����) 
				}
				break;

			case '+': case '-': 
			case '*': case '/':
				while(!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0) 
					/* �� stack�� ������ �ִ��� Ȯ�� && WhoPrecOp return���� ����ΰ� Ȯ��(������ �켱���� Ȯ��)(masking)
					 stack�� �����ڿ� tok ������ �켱������ ���ؼ�, stack�� �� �켱������ �������, stack�� �����ڵ��� convExp�� �ű��. */
					convExp[idx++] = SPop(&stack);  

				SPush(&stack, tok); // ������ �����ڸ� stack �� �״´�. 
				break;
			}
		}
	}

	while(!SIsEmpty(&stack))			// ���ÿ� �����ִ� ��� �����ڸ�
		convExp[idx++] = SPop(&stack);	// �迭 convExp�� �̵��Ѵ�. 

	// Visual studio 2017 ���������� strcpy �Լ��� ����ϸ� error�� �߻��ϹǷ� strcpy_s ����� ��
	strcpy_s(exp, sizeof(char)*expLen + 1, convExp);	// ��ȯ�� ������ exp�� �����ϰ�, 
	free(convExp);	// convExp�� �Ҹ��Ѵ�. 
}