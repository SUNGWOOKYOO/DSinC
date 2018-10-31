/* 문제 06-1
 원형 연결 리스트 implementation파일과 interface파일을 이용해서 
 Stack을 원형 연결 리스트로 구현해보자
*/
#include <stdio.h>
#include "CLLBaseStack.h" // 원형 연결 리스트로 자료구조를 구현한 것을 정의한 헤더파일

int main(void)
{
	// Stack의 생성 및 초기화 ///////
	Stack stack;
	StackInit(&stack);

	// 데이터 넣기 ///////
	SPush(&stack, 1);  SPush(&stack, 2);
	SPush(&stack, 3);  SPush(&stack, 4);
	SPush(&stack, 5);

	// 데이터 꺼내기 ///////
	while(!SIsEmpty(&stack))
		printf("%d ", SPop(&stack)); 

	return 0;
}