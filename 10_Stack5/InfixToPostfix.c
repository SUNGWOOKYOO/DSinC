#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ListBaseStack.h"

int GetOpPrec(char op) // 연산자의 연산 우선순위 정보를 반환
{
	switch(op)
	{
	case '*':
	case '/':
		return 5;
	case '+':
	case '-':
		return 3;
	case '(':  // ')'연산자는 반환값을 정의 할 필요 없다. 소괄호 끝을 의미하는 연산자 이기 때문에 우선순위 비교할 필요 없기 때문
		return 1;
	}

	return -1;   // 등록되지 않은 연산자
}

int WhoPrecOp(char op1, char op2) // 연산자의 우선순위 비교 
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

void ConvToRPNExp(char exp[]) // 후위 표기법의 수식으로 변환 
{
	Stack stack;
	int expLen = strlen(exp);
	char * convExp = (char*)malloc(expLen+1);

	int i, idx=0;
	char tok, popOp;
	
	/*memset 내장함수
	memset함수는 어떤 메모리의 시작점부터 연속된 범위를 어떤 값으로(바이트 단위) 모두 지정하고 싶을 때 사용하는 함수이다.
		void * memset ( void * ptr, int value, size_t num );
		ptr : 채우고자 하는 메모리의 시작 포인터(시작 주소)
		value : 메모리에 채우고자하는 값. int형이지만 내부에서는 unsigned char(1 byte)로 변환되어서 저장된다.
		num : 채우고자 하는 바이트의 수. 즉, 채우고자 하는 메모리의 크기  */
	memset(convExp, 0, sizeof(char)*expLen+1); // 할당된 배열을 0 으로 초기화 
	StackInit(&stack);

	for(i=0; i<expLen; i++) // 전체 연산을 한 문자씩 수행하게 된다. 
	{
		tok = exp[i]; // exp로 전달된 수식을 한 문자씩 tok에 저장 
		if(isdigit(tok)) // tok에 저장된 문자가 숫자인지 확인 ; isdigit(문자) : 문자('')가 숫자 0~9 사이에 속하는지 검사하는 함수 
		{
			convExp[idx++] = tok;  // 숫자이면 배열 convExp에 그냥 저장 
		}
		else // 숫자가 아니라면 
		{
			switch(tok)
			{
			// '('와 ')' 는 special case 
			case '(':				// 여는 소괄호라면
				SPush(&stack, tok); // 스택에 쌓는다. 
				break;

			case ')':				// 닫는 소괄호라면, 
				while(1)			// 반복해서	
				{
					popOp = SPop(&stack);	// 스택에서 연산자를 꺼내어
					if(popOp == '(')		// 연산자 ( 를 만날때 까지, 
						break;
					convExp[idx++] = popOp; // 배열 convExp에 저장한다(동적할당 공간) 
				}
				break;

			case '+': case '-': 
			case '*': case '/':
				while(!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0) 
					/* ★ stack에 연산자 있는지 확인 && WhoPrecOp return값이 양수인가 확인(연산자 우선순위 확인)(masking)
					 stack의 연산자와 tok 연산의 우선순위를 비교해서, stack이 더 우선순위가 높은경우, stack의 연산자들을 convExp로 옮긴다. */
					convExp[idx++] = SPop(&stack);  

				SPush(&stack, tok); // 나머지 연산자를 stack 에 쌓는다. 
				break;
			}
		}
	}

	while(!SIsEmpty(&stack))			// 스택에 남아있는 모든 연산자를
		convExp[idx++] = SPop(&stack);	// 배열 convExp로 이동한다. 

	// Visual studio 2017 버전에서는 strcpy 함수를 사용하면 error가 발생하므로 strcpy_s 사용을 함
	strcpy_s(exp, sizeof(char)*expLen + 1, convExp);	// 변환된 수식을 exp에 복사하고, 
	free(convExp);	// convExp는 소멸한다. 
}