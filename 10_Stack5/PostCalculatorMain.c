/*  Prog 구현 2 
postfix notation 에 대해 calculation! using EvalRPNExp() 함수 */
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


/*  Prog 구현 3 
InfixCalculatorMain.c 
infix -> postfix -> calculation 
★ 9개의 파일을 통해 동작한다. 
(EvalInfixExp 함수를 사용하기 위해서는 InfixCalculator.c 에  
InfixToPostfix.h, List Base Stack.h 만을 포함하기만 하면 된다!!)
 - 스택의 활용					: List Base Stack.h			ListBaseStack.c
 - 후위 표기법의 수식으로 변환	: InfixToPostfix.h			InfixToPostfix.c
 - 후위 표기법의 수식을 계산	: PostCalculator.h			PostCalculator.c
 - 중위 표기법의 수식을 계산	: InfixCalculator.h			InfixCalculator.c 
 - main 함수					: InfixCalculatorMain.c
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