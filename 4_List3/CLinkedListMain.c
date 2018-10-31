// [Chap5]
/* circular Linked list ���� ADT����
 ����: LNext�� ������ ����� ���� ����, ��ȸ ����
 dummy node�� ���� ���(�� ������ ����, ���� LRemove���� ���ܻ�Ȳó���� ���� �ڵ� �� ����)
 LRemove, LInsert ����������. ������, LNext�������� ���� ��� ó���� ���� �ڵ� �����ؾ��� 
*/
#if 0
#include <stdio.h>
#include "CLinkedList.h"

int main(void)
{
	// ���� ���� ����Ʈ�� ���� �� �ʱ�ȭ ///////
	List list;
	int data, i, nodeNum;
	ListInit(&list);

	// ����Ʈ�� 5���� �����͸� ���� ///////  tail�߰� 3 4 5, front �߰� 2 1 input���� ��   ; result:  front ->1 2 3 4 5<- tail
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsertFront(&list, 2);
	LInsertFront(&list, 1);
	
	// ����Ʈ�� ����� �����͸� ���� 3ȸ ��� ///////
	if(LFirst(&list, &data))
	{
		printf("%d ", data);
		
		for(i=0; i<LCount(&list)*3-1; i++)
		{
			if(LNext(&list, &data))
				printf("%d ", data);
		}
	}
	printf("\n");

	// 2�� ����� ã�Ƽ� ��� ���� ///////
	nodeNum = LCount(&list);

	if(nodeNum != 0)
	{
		LFirst(&list, &data);
		if(data%2 == 0)
			LRemove(&list);
		
		for(i=0; i < nodeNum-1; i++) //2�� ����� �ִ��� LNext �� ����Ͽ� �˻� 
		{
			LNext(&list, &data);
			if(data%2 == 0)
				LRemove(&list);
		}
	}

	// ��ü ������ 1ȸ ��� ///////
	if(LFirst(&list, &data))
	{
		printf("%d ", data);
		
		for(i=0; i<LCount(&list)-1; i++)
		{
			if(LNext(&list, &data))
				printf("%d ", data);
		}
	}
	return 0;
}
#endif

/* ���� 05-1
visual studio 2017 ���� strcpy(����1, ����2)���ϸ� ������ ����
strcpy_s(����1, ����2, ����3)���� �ٲپ���.
�̶�, ����2�� ���ڿ��� ũ���ε� ������ ���� ���ϱ� ����� 20���� �Ͽ���.
build�� �Ǵµ� complie���� ��������. ���� �𸣰ڴ� */
#if 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedList.h"
#include "Employee.h"

Employee * WhosNightDuty(List * plist, char * name, int day);
void ShowEmployeeInfo(Employee * emp);

int main(void)
{
	int i;
	Employee * pemp;

	// List�� ���� �� �ʱ�ȭ ///////
	List list;
	ListInit(&list);

	// 4���� ������ ���� ///////
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 11111;
	strcpy_s(pemp->name, 30, "Terry");
	LInsert(&list, pemp);

	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 2222;
	strcpy_s(pemp->name, 30, "Jery");
	LInsert(&list, pemp);

	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 3333;
	strcpy_s(pemp->name, 30, "Hary");
	LInsert(&list, pemp);

	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 4444;
	strcpy_s(pemp->name, 30, "Sunny");
	LInsert(&list, pemp);

	// Terry �ڷ� 3�� �� �����ڴ�? ///////
	pemp = WhosNightDuty(&list, "Tery", 3);
	ShowEmployeeInfo(pemp);

	// Sunny �ڷ� 15�� �� �����ڴ�? ///////
	pemp = WhosNightDuty(&list, "Sunny", 15);
	ShowEmployeeInfo(pemp);

	// �Ҵ�� �޸��� ��ü �Ҹ� ///////
	if (LFirst(&list, &pemp))
	{
		free(pemp);

		for (i = 0; i<LCount(&list) - 1; i++)
		{
			if (LNext(&list, &pemp))
				free(pemp);
		}
	}

	return 0;
}

Employee * WhosNightDuty(List * plist, char * name, int day)
{
	int i, num;
	Employee *ret;

	num = LCount(plist);

	// �̸� ã�� ///////
	LFirst(plist, &ret);

	if (strncmp(ret->name, name, 30) != 0) // ��ġ�ϴ� �̸��� �ִ��� Ȯ�� 
	{
		for (i = 0; i<num - 1; i++)
		{
			LNext(plist, &ret);

			if (strncmp(ret->name, name, 30) == 0)
				break;
		}
		if (i >= num - 1)     // �ش��ϴ� �̸��� �������� ������
			return NULL;
	}

	// �� �ڷ� ��ĥ �� /////// ; day��¥��ŭ Next�� �̵�! 
 	for (i = 0; i<day; i++) 
		LNext(plist, &ret);

	return ret;
}

void ShowEmployeeInfo(Employee * emp)
{
	printf("Employee name: %s \n", emp->name);
	printf("Employee number: %d \n\n", emp->empNum);
}
#endif

