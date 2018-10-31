// [Chap5]
/* circular Linked list 예제 ADT구현
 장점: LNext의 연속적 사용을 통해 삽입, 조회 가능
 dummy node가 있을 경우(이 예제는 없다, 따라서 LRemove에서 예외상황처리를 위한 코드 부 있음)
 LRemove, LInsert 간단해진다. 하지만, LNext구현에서 더미 노드 처리를 위한 코드 삽입해야함 
*/
#if 0
#include <stdio.h>
#include "CLinkedList.h"

int main(void)
{
	// 원형 연결 리스트의 생성 및 초기화 ///////
	List list;
	int data, i, nodeNum;
	ListInit(&list);

	// 리스트에 5개의 데이터를 저장 ///////  tail추가 3 4 5, front 추가 2 1 input으로 줌   ; result:  front ->1 2 3 4 5<- tail
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsertFront(&list, 2);
	LInsertFront(&list, 1);
	
	// 리스트에 저장된 데이터를 연속 3회 출력 ///////
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

	// 2의 배수를 찾아서 모두 삭제 ///////
	nodeNum = LCount(&list);

	if(nodeNum != 0)
	{
		LFirst(&list, &data);
		if(data%2 == 0)
			LRemove(&list);
		
		for(i=0; i < nodeNum-1; i++) //2의 배수가 있는지 LNext 를 사용하여 검색 
		{
			LNext(&list, &data);
			if(data%2 == 0)
				LRemove(&list);
		}
	}

	// 전체 데이터 1회 출력 ///////
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

/* 문제 05-1
visual studio 2017 에서 strcpy(인자1, 인자2)로하면 에러가 나서
strcpy_s(인자1, 인자2, 인자3)으로 바꾸었다.
이때, 인자2는 문자열의 크기인데 적당한 값을 구하기 어려워 20으로 하였다.
build는 되는데 complie에서 에러가뜸. 이유 모르겠다 */
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

	// List의 생성 및 초기화 ///////
	List list;
	ListInit(&list);

	// 4명의 데이터 저장 ///////
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

	// Terry 뒤로 3일 뒤 당직자는? ///////
	pemp = WhosNightDuty(&list, "Tery", 3);
	ShowEmployeeInfo(pemp);

	// Sunny 뒤로 15일 뒤 당직자는? ///////
	pemp = WhosNightDuty(&list, "Sunny", 15);
	ShowEmployeeInfo(pemp);

	// 할당된 메모리의 전체 소멸 ///////
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

	// 이름 찾기 ///////
	LFirst(plist, &ret);

	if (strncmp(ret->name, name, 30) != 0) // 일치하는 이름이 있는지 확인 
	{
		for (i = 0; i<num - 1; i++)
		{
			LNext(plist, &ret);

			if (strncmp(ret->name, name, 30) == 0)
				break;
		}
		if (i >= num - 1)     // 해당하는 이름이 존재하지 않으면
			return NULL;
	}

	// 그 뒤로 며칠 뒤 /////// ; day날짜만큼 Next로 이동! 
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

