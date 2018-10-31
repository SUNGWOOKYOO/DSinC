/*  Prog ���� 2 
postfix notation �� ���� calculation! using EvalRPNExp() �Լ� */
#if 0
#include <stdio.h>
#include "PostCalculator.h"

int main(void)
{
	char postExp1[] = "42*8+";
	char postExp2[] = "123+*4/";

	printf("%s = %d \n", postExp1, EvalRPNExp(postExp1));
	printf("%s = %d \n", postExp2, EvalRPNExp(postExp2));

	return 0;
}
#endif 


/*  Prog ���� 3 
InfixCalculatorMain.c 
infix -> postfix -> calculation 
�� 9���� ������ ���� �����Ѵ�. 
(EvalInfixExp �Լ��� ����ϱ� ���ؼ��� InfixCalculator.c ��  
InfixToPostfix.h, List Base Stack.h ���� �����ϱ⸸ �ϸ� �ȴ�!!)
 - ������ Ȱ��					: List Base Stack.h			ListBaseStack.c
 - ���� ǥ����� �������� ��ȯ	: InfixToPostfix.h			InfixToPostfix.c
 - ���� ǥ����� ������ ���	: PostCalculator.h			PostCalculator.c
 - ���� ǥ����� ������ ���	: InfixCalculator.h			InfixCalculator.c 
 - main �Լ�					: InfixCalculatorMain.c
*/
#if 1
#include <stdio.h>
#include "InfixCalculator.h"

int main(void)
{
	char exp1[] = "1+2*3";
	char exp2[] = "(1+2)*3";
	char exp3[] = "((1-2)+3)*(5-2)";

	printf("%s = %d \n", exp1, EvalInfixExp(exp1));
	printf("%s = %d \n", exp2, EvalInfixExp(exp2));
	printf("%s = %d \n", exp3, EvalInfixExp(exp3));
	return 0;
}
#endif