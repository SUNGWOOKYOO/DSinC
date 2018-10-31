//[Chap3] ; List 자료구조 에서의 ADT

/* application 부 main문 정의된 자료형을 가져다 사용한다,  
 interface부 ; 리스트 자료구조의 헤더파일
 implementation부 ; 리스트자료구조의 source파일 
 이 3가지가 있어야 complie이 가능하다 */

// 잘 만들어진 3개 part에 대해서 헤더(interface부)를 추가 하고 헤더파일에 선언된 함수의 기능만 숙지한다면, 리스트의 구현을 알 필요없이 application부를 사용하기만 하면된다.
// 단, 추가나 변경할 자료형이 있는경우 선언부만 헤더파일(interface 부)을 약간 변경하고 (typedef 선언의 변경이 핵심이다.)
// ,소스파일(implementation 부)은 변경해서는 안되도록 정의해야한다.

/* ListMain.c 
 List 자료를 생성하여 데이터를 저장해보고 출력해보고 지워도 본다. */
#if 0
#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	/*** ArrayList의 생성 및 초기화 ***/
	List list; // 변수 list 선언; 데이터를 담을 수 있으므로 이는 '자료구조' 라 할 수 있다. ; 또한 'List'는  데이터를 효율적으로 저장 및 참조할 수있도록 정의할 수 있다.
	int data;
	ListInit(&list);

	/*** 5개의 데이터 저장 ***/
	LInsert(&list, 11);  LInsert(&list, 11);
	LInsert(&list, 22);  LInsert(&list, 22);
	LInsert(&list, 33);

	/*** 저장된 데이터의 전체 출력 ***/
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if(LFirst(&list, &data))    // 첫 번째 데이터 조회
	{
		printf("%d \n", data);
		
		while(LNext(&list, &data))    // 두 번째 이후의 데이터 조회
			printf("%d ", data);
	}
	printf("\n\n");

	/*** 숫자 22을 탐색하여 모두 삭제 ***/
	printf("숫자 22을 탐색하여 모두 삭제\n");

	if(LFirst(&list, &data))
	{
		if(data == 22)
			LRemove(&list);
		
		while(LNext(&list, &data))
		{
			if(data == 22)
				LRemove(&list);
		}
	}

	/*** 삭제 후 저장된 데이터 전체 출력 ***/
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if(LFirst(&list, &data))
	{
		printf("%d ", data);
		
		while(LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}
#endif

/* 문제 03-1 
 ListUseMain.c */
#if 0
#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	/*** ArrayList의 생성 및 초기화 ***/
	List list;
	int data, i;
	int sum = 0;
	ListInit(&list); //초기화 

	/*** 정수 1부터 9까지 저장 ***/
	for (i = 1; i<10; i++)
		LInsert(&list, i);

	/*** 합의 계산 및 출력 ***/
	if (LFirst(&list, &data))
	{
		sum += data;

		while (LNext(&list, &data))
			sum += data;
	}
	printf("SUM = %d \n\n", sum);

	/*** 2의 배수 3의 배수 삭제***/
	if (LFirst(&list, &data))
	{
		if (data % 2 == 0 || data % 3 == 0)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data % 2 == 0 || data % 3 == 0)
				LRemove(&list);
		}
	}

	/*** 삭제 후 저장된 데이터 전체 출력 ***/
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}
#endif

/* PointListMain.c
 Point 자료형을 정의하여 List 자료구조에 담아 보고 사용해 보자*/
#if 0
#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Point.h"

int main(void)
{
	List list;
	Point compPos;
	Point * ppos;

	ListInit(&list);

	/*** 4개의 데이터 저장 ***/
	ppos = (Point*)malloc(sizeof(Point)); //Point 자료형 만큼의 byte 를 힙 영역에서 할당받아 ppos가 가르키도록 함(동적 할당)
	SetPointPos(ppos, 2, 1); 
	LInsert(&list, ppos); 

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);

	/*** 저장된 데이터의 출력 ***/
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	/*** xpos가 2인 모든 데이터 삭제 ***/
	compPos.xpos = 2;
	compPos.ypos = 0;

	if (LFirst(&list, &ppos))
	{
		if (PointComp(ppos, &compPos) == 1)
		{
			ppos = LRemove(&list); /*LRemove는 소멸된 데이터를 반환하여 메모리의 해제의 기회를 줄 수 있어야한다.(메모리 소멸의 책임을 전가해야한다;
									ADT의 구현을 위해; 즉 main문 안에서 할당과 소멸 연산이 이루어지도록 하게 하기위해) */
			free(ppos); //ppos가 가르키는 메모리를 해체한다  
		}

		while (LNext(&list, &ppos))
		{
			if (PointComp(ppos, &compPos) == 1)
			{
				ppos = LRemove(&list);
				free(ppos);
			}
		}
	}

	/*** 삭제 후 남은 데이터 전체 출력 ***/
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	return 0;
}
#endif 

/* 문제 03-2
 NameCardListMain.c
 구현되어있는 자료구조(리스트)를 활용하여 정의된 자료형(Namecard)를 활용하는 연습을 해보자   
*/
#if 1
#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(void)
{
	List list;
	NameCard * pcard;
	ListInit(&list);

	pcard = MakeNameCard("이진수", "010-1111-2222");
	LInsert(&list, pcard);

	pcard = MakeNameCard("한지영", "010-2222-5555");
	LInsert(&list, pcard);

	pcard = MakeNameCard("조수진", "010-3333-7777");
	LInsert(&list, pcard);

	// 한지영의 정보를 조회하여 출력
	if (LFirst(&list, &pcard))
	{
		if (!NameCompare(pcard, "한지영"))
		{
			ShowNameCardInfo(pcard);
		}
		else
		{
			while (LNext(&list, &pcard))
			{
				if (!NameCompare(pcard, "한지영"))
				{
					ShowNameCardInfo(pcard);
					break;
				}
			}
		}
	}

	// 이진수의 정보를 변경
	if (LFirst(&list, &pcard))
	{
		if (!NameCompare(pcard, "이진수"))
		{
			ChangePhoneNum(pcard, "010-9999-9999");
		}
		else
		{
			while (LNext(&list, &pcard))
			{
				if (!NameCompare(pcard, "이진수"))
				{
					ChangePhoneNum(pcard, "010-9999-9999");
					break;
				}
			}
		}
	}

	// 조수진의 정보를 삭제
	if (LFirst(&list, &pcard))
	{
		if (!NameCompare(pcard, "조수진"))
		{
			pcard = LRemove(&list);
			free(pcard);
		}
		else
		{
			while (LNext(&list, &pcard))
			{
				if (!NameCompare(pcard, "조수진"))
				{
					pcard = LRemove(&list);
					free(pcard);
					break;
				}
			}
		}
	}

	// 모든 사람의 정보 출력
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &pcard))
	{
		ShowNameCardInfo(pcard);

		while (LNext(&list, &pcard))
			ShowNameCardInfo(pcard);
	}

	return 0;
}
#endif 