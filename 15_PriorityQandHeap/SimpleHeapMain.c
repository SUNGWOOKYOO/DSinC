/* [Chap9]  
 priority Queue �� Heap  
 �켱 ������ ����� Queue �ڷᱸ���� �켱 ������ ����Ͽ� insert, delete�� �Ǵ� �ڷᱸ���� 
 �� �ڷᱸ���� Heap �̶�� � Ư���� �����ϴ� Tree ������ �ڷᱸ���� �ǹ��ϸ�,  
 Ư��, � Ư���� �����ϴ� Heap�� ������ �迭 ��� Tree �� �̿��ϰ� �ȴ�.
 �� ������ simple �� case�� �켱���� ť�� �����̸� 
 programmer�� insert�� �Ҷ����� �켱������ ��������ϴ� ���ŷο��� �ִ�. */
#include <stdio.h>
#include "SimpleHeap.h"

int main(void)
{
	Heap heap;
	HeapInit(&heap);

	HInsert(&heap, 'A', 1); // �켱������ ��������ϴ� ���ŷο� �߻� 
	HInsert(&heap, 'B', 2);
	HInsert(&heap, 'C', 3);
	printf("%c \n", HDelete(&heap));

	HInsert(&heap, 'A', 1);
	HInsert(&heap, 'B', 2);
	HInsert(&heap, 'C', 3);
	printf("%c \n", HDelete(&heap));

	while(!HIsEmpty(&heap))
		printf("%c \n", HDelete(&heap));

	return 0;
}
