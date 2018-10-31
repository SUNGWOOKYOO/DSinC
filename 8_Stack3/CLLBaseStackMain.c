/* ���� 06-1
 ���� ���� ����Ʈ implementation���ϰ� interface������ �̿��ؼ� 
 Stack�� ���� ���� ����Ʈ�� �����غ���
*/
#include <stdio.h>
#include "CLLBaseStack.h" // ���� ���� ����Ʈ�� �ڷᱸ���� ������ ���� ������ �������

int main(void)
{
	// Stack�� ���� �� �ʱ�ȭ ///////
	Stack stack;
	StackInit(&stack);

	// ������ �ֱ� ///////
	SPush(&stack, 1);  SPush(&stack, 2);
	SPush(&stack, 3);  SPush(&stack, 4);
	SPush(&stack, 5);

	// ������ ������ ///////
	while(!SIsEmpty(&stack))
		printf("%d ", SPop(&stack)); 

	return 0;
}