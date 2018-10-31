// [Chap4]
/* 
매우 간단한 Linked list의 자료구조 구현
배열은 static해서 한번 선언하면 길이 변경을 할 수 없다. 따라서 처음 할당된 배열의 길이의 변화를 줄 수 없다. 
이 단점을 보완하기 위해 Linked list등장! 
dynamic assignment에 대해 이해하기위해 간단한 예제 이해 (ADT에 대해서 구현이 되어있지 않다; main문에 데이터 삽입, 삭제, 조회 기능 집어넣음.)
- 문제 04-1
 newNode를 뒤에서 부터 채우는 방법 vs 앞에서 부터 채우는 방법
 뒤에서 부터 채우면 입력된 데이터가 head에서 tail순으로 입력되지만, tail 변수를 다뤄야 하기 때문에 복잡할 수 있다.
 반면, 앞에서 부터 채우면 head변수만 이용하기 때문에 tail변수는 필요없다. 하지만, 입력에 따른 데이터 순서가 반대가 된다.
Node * newNode 는 newNode라는 Node data type pointer이고 그림화하면  newNode pointer:[newNode의 주소값]->[newNode data|next pointer주소값]->   
														'[newNode data|next pointer주소값]->' 을 간단하게 그림으로 표현 '[newnNode| ]->'
 head = newNode를 하면 
 'head[]-> [newnNode| ]->' 가 된다
*/
# if 0
#include <stdio.h>
#include <stdlib.h>

typedef struct _node /* ┌-----┰----┬ㅡㅡㅡㅡ>    모양의 node를 생각 앞부분은 데이터 뒷부분은 포인터  
					    └data-┻next┘<Node>  		 where	Node를 가르키는 Node 포인터 변수 선언 Node * pnode;   */
                      
{
	int data; // 데이터를 담을 공간 
	struct _node * next; //구조체 node를 가리키는 포인터; 리스트 연결의 도구 
} Node;

int main(void)
{
	Node * head = NULL;    // NULL 포인터 초기화 ; Node형을 가르키는 pointer 
	Node * tail = NULL;
	Node * cur = NULL;

	Node * newNode = NULL;
	int readData;

	/**** 데이터를 입력 받는 과정(insertion) ****/
	while(1)
	{
		printf("자연수 입력: ");
		scanf_s("%d", &readData);
		if(readData < 1)
			break;

		/*** 노드의 추가과정 ***/
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;  /* ┌---------┰----┬ㅡㅡㅡㅡㅡ>NULL  
								  └readData-┻next┘<newNode>        */
#if 0
		if(head == NULL)		//첫번째 노드만 이부분 지남 
			head = newNode;		/*첫번째노드를 head가 가리키게함	┌------┬ㅡㅡㅡㅡ>┌---------┰----┬ㅡㅡㅡㅡㅡ>NULL  
																	└주소값┘<head>   └readData-┻next┘<newNode>      */    
		else					//첫번째 노드는 이 부분 지나지 않고, 두번째 이후 노드들만 이부분 지남 
			tail->next = newNode; // tail이 이동으로 previous node가 newNode를 가르키도록 함!
#endif

#if 1   //☆ 문제04-1; 새노드를 head 쪽으로 추가하기 
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->next = head; // 포인터의 얕은 복사(가르키는 값이 같음)
			head = newNode; // head의 이동으로  previous node가 newNode를 가르키도록 함! 
		}
#endif

		tail = newNode; //이번 루프에서 생긴 newNode를 tail이 가르키도록 함(newNode의 주소를 tail pointer 에게 넘김)
	}
	printf("\n");

	/**** 입력 받은 데이터의 출력과정 ****/
	printf("입력 받은 데이터의 전체출력! \n");
	if(head == NULL) 
	{
		printf("저장된 자연수가 존재하지 않습니다. \n");
	}
	else 
	{
		cur = head; 
		printf("%d  ", cur->data);   // 첫 번째 데이터 출력
		
		while(cur->next != NULL)    // 두 번째 이후의 데이터 출력
		{
			cur = cur->next;
			printf("%d  ", cur->data);
		}
	}
	printf("\n\n");

	/**** 메모리의 해제과정 ****/
	if(head == NULL) 
	{
		return 0;    // 해제할 노드가 존재하지 않는다.
	}
	else 
	{
		Node * delNode = head;
		Node * delNextNode = head->next; // head->Next를 변수로 설정하여 복사 해놓은 이유: head를 그냥 삭제해 버리면, 그 다음 노드에 접근이 불가능하다 

		printf("%d을(를) 삭제합니다. \n", head->data);
		free(delNode);    // 첫 번째 노드의 삭제
		
		while(delNextNode != NULL)    // 두 번째 이후의 노드 삭제 위한 반복문
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next; //★ 이렇게 설정한 이유: line77 의 이유 

			printf("%d을(를) 삭제합니다. \n", delNode->data);
			free(delNode);    // 두 번째 이후의 노드 삭제
		}
	}

	return 0;
}

#endif

// 포인터의 deep copy 구현 예제(성욱 작성)
#if 0
#include <stdio.h>

int main()
{
	// shallow copy in pointer    
	int x = 5;
	int *p = &x;  // p:[]→[x value]
	int *q = p;   // q:[]↗	    q를 바꾸면 p가 가리키는 값이 바뀌어버림 
	(*q)++;
	printf("shallow copy(q만 ++증가후) \n %d \n", *p);
	printf("%d \n", *q);

	// deep copy in pointer 
	int *r = (int*)malloc(sizeof(int));         // p:[]→[x value] 
	*r = *p;                                    // r:[]→[x value]
	(*r)++;
	printf("shallow copy(r만 ++증가후) \n %d \n", *p);
	printf("%d \n", *r);
	free(r);

	return 0;
}

#endif 

/* 문제 04-2
 Dummy node를 사용했을때 코드의 변화를 보기위한 문제 (코드의 일관성이 생김)
 newNode는 tail을 이용하여 뒤에서 부터 추가하는 형태의 문제이다. (앞에서 부터 추가하면 더 간결해 질것이다)
*/
#if 0
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node * next;
} Node;

int main(void)
{
	Node * head = NULL;
	Node * tail = NULL;
	Node * cur = NULL;

	Node * newNode = NULL;
	int readData;

	head = (Node*)malloc(sizeof(Node));    // ★추가 된 문장, 더미 노드 추가
	tail = head;

	/**** 데이터를 입력 받는 과정 ****/
	while (1)
	{
		printf("자연수 입력: ");
		scanf_s("%d", &readData);
		if (readData < 1)
			break;

		/*** 노드의 추가과정 ***/
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		/*
		if(head == NULL)
		head = newNode;
		else
		tail->next = newNode;
		*/
		tail->next = newNode;

		tail = newNode;
	}
	printf("\n");

	/**** 입력 받은 데이터의 출력과정 ****/
	printf("입력 받은 데이터의 전체출력! \n");
	if (head == NULL)
	{
		printf("저장된 자연수가 존재하지 않습니다. \n");
	}
	else
	{
		cur = head;
		//	printf("%d  ", cur->data);   // 첫 번째 데이터 출력

		while (cur->next != NULL)    // 두 번째 이후의 데이터 출력
		{
			cur = cur->next;
			printf("%d  ", cur->data);
		}
	}
	printf("\n\n");

	/**** 메모리의 해제과정 ****/
	if (head == NULL)
	{
		return 0;    // 해제할 노드가 존재하지 않는다.
	}
	else
	{
		Node * delNode = head;
		Node * delNextNode = head->next;

		//	printf("%d을(를) 삭제합니다. \n", head->data);
		//	free(delNode);    // 첫 번째 노드의 삭제

		while (delNextNode != NULL)    // 두 번째 이후의 노드 삭제 위한 반복문
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d을(를) 삭제합니다. \n", delNode->data);
			free(delNode);    // 두 번째 이후의 노드 삭제
		}
	}

	return 0;
}
#endif

/* DLinkedListMain.c
 Linked list 자료구조의 ADT 구현
 Dummy node 의 오른쪽으로 newNode가 생성됨; plist: head[]->[dummy node| ]->[newNode: data n | ]->[previousNode: data n-1 | ]-> ... ->NULL  
*/
#if 0
#include <stdio.h>
#include "DLinkedList.h"

int main(void)
{
	// List의 생성 및 초기화 /////////////////////////////
	List list;
	int data;
	ListInit(&list);

	// 5개의 데이터 저장 /////////////////////////////
	LInsert(&list, 11);  LInsert(&list, 11);
	LInsert(&list, 22);  LInsert(&list, 22);
	LInsert(&list, 33);

	// 저장된 데이터의 전체 출력 /////////////////////////
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &data))    // 첫 번째 데이터 조회
	{
		printf("%d ", data);

		while (LNext(&list, &data))    // 두 번째 이후의 데이터 조회
			printf("%d ", data);
	}
	printf("\n\n");

	// 숫자 22을 검색하여 모두 삭제 //////////////////////////
	if (LFirst(&list, &data))
	{
		if (data == 22)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data == 22)
				LRemove(&list);
		}
	}

	// 삭제 후 남아있는 데이터 전체 출력 ////////////////////////
	printf("현재 데이터의 수: %d \n", LCount(&list));

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

/* 문제 04-3
 Linked list 자료구조를 사용한 point type자료형에 대한 ADT 구현 
 Chap3 에서 PointListMain.c 를 그대로 사용가능 
 (단, 헤더에 typedef선언과 point.h 추가선언 필요! 또한, comp함수를 사용하지 않았으므로 출력결과는 reverse되어 나올것임! )
*/
#if 0
#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "Point.h"

int main(void)
{
	List list;
	Point compPos;
	Point * ppos;

	ListInit(&list);

	// 4개의 데이터 저장  ///////////
	ppos = (Point*)malloc(sizeof(Point));
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

	// 저장된 데이터의 출력 ///////////
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	// xpos가 2인 모든 데이터 삭제  ///////////
	compPos.xpos = 2;
	compPos.ypos = 0;

	if (LFirst(&list, &ppos))
	{
		if (PointComp(ppos, &compPos) == 1)
		{
			ppos = LRemove(&list);
			free(ppos);
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

	// 삭제 후 남은 데이터 전체 출력  ///////////
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

/*  DLinkedListSortMain.c 
 Linked list 자료구조의 ADT 구현2 (data Insetion에 대해서 정렬 순서를 programmer가 정할 수 있다. 즉, 자료구조에 대한 interface부와 implementation부를 건들지 않아도 된다.)
 list의 맴버 comp를 이용하여 SetSortRule을 통해 application부(main루프가 있는 소스파일)에서 정렬 순위를 정할 수 있다. 
*/
#if 0
#include <stdio.h>
#include "DLinkedList.h"

int WhoIsPrecede(int d1, int d2) 
{
	if (d1 < d2)
		return 0;    // d1이 정렬 순서상 앞선다.
	else
		return 1;    // d2가 정렬 순서상 앞서거나 같다.
}

int main(void)
{
	// List의 생성 및 초기화  ////////////
	List list;
	int data;
	ListInit(&list);

	SetSortRule(&list, WhoIsPrecede); // programmer가 정렬순서를 정할 수 있다. ; comp != NULL 이되므로 Sinsert 함수에 의해 list 자료구조에 대한 data에 대한 노드의 삽입, 정렬이 이루어진다.

	// 5개의 데이터 저장  ///////////////
	LInsert(&list, 11);  LInsert(&list, 11);
	LInsert(&list, 22);  LInsert(&list, 22);
	LInsert(&list, 33);

	// 저장된 데이터의 전체 출력 ////////////
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	// 숫자 22을 검색하여 모두 삭제 ////////////
	if (LFirst(&list, &data))
	{
		if (data == 22)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data == 22)
				LRemove(&list);
		}
	}

	// 삭제 후 저장된 데이터 전체 출력 ////////////
	printf("현재 데이터의 수: %d \n", LCount(&list));

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

/* 문제 04-4
Linked list 자료구조를 사용한 point type자료형에 대한 ADT 구현2
문제 04-3 에서 sorting order를 정해보자 
1. x좌표의 값을 기준으로 오름차순 정렬이 되도록
2. x좌표가 같은경우 y좌표를 대상으로 오름차순 정렬이 되도록 
*/
#if 1
#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "Point.h"

int WhoIsPrecede(Point * d1, Point * d2)
{
	if (d1->xpos < d2->xpos)
	{
		return 0;
	}
	else if (d1->xpos == d2->xpos)
	{
		if (d1->ypos < d2->ypos)
			return 0;
		else
			return 1;
	}
	else
		return 1;
}


int main(void)
{
	List list;
	Point comp;
	Point * pPoint;
	ListInit(&list);

	SetSortRule(&list, WhoIsPrecede);     // 정렬기준을 등록!

	pPoint = (Point*)malloc(sizeof(Point));
	SetPointPos(pPoint, 3, 2);
	LInsert(&list, pPoint);

	pPoint = (Point*)malloc(sizeof(Point));
	SetPointPos(pPoint, 3, 1);
	LInsert(&list, pPoint);

	pPoint = (Point*)malloc(sizeof(Point));
	SetPointPos(pPoint, 2, 2);
	LInsert(&list, pPoint);

	pPoint = (Point*)malloc(sizeof(Point));
	SetPointPos(pPoint, 2, 1);
	LInsert(&list, pPoint);

	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &pPoint))
	{
		ShowPointPos(pPoint);

		while (LNext(&list, &pPoint))
			ShowPointPos(pPoint);
	}
	printf("\n");

	// xpos가 2인 모든 데이터 삭제  ////////
	comp.xpos = 2;
	comp.ypos = 0;

	if (LFirst(&list, &pPoint))
	{
		if (PointComp(pPoint, &comp) == 1)
		{
			pPoint = LRemove(&list);
			free(pPoint);
		}

		while (LNext(&list, &pPoint))
		{
			if (PointComp(pPoint, &comp) == 1)
			{
				pPoint = LRemove(&list);
				free(pPoint);
			}
		}
	}

	// 삭제 후 저장된 데이터 출력 ////////
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &pPoint))
	{
		ShowPointPos(pPoint);

		while (LNext(&list, &pPoint))
			ShowPointPos(pPoint);
	}
	printf("\n");

	return 0;
}
#endif 

