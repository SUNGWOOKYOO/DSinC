/* 자료구조(데이터를 담는 그릇)의 interface 부 ; 헤더파일 ; 클래스정의, 함수 선언
잘 만들어진 3개 part에 대해서 헤더(interface부)를 추가 하고 헤더파일에 선언된 함수의 기능만 숙지한다면, 리스트의 구현을 알 필요없이 application부를 사용하기만 하면된다.
추가나 변경할 자료형이 있는경우 선언부만 헤더파일(interface 부)을 약간 변경하고 (typedef 선언의 변경이 핵심이다.)
단, 소스파일(implementation 부)은 변경해서는 안되도록 정의해야한다. */
#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#define TRUE	1
#define FALSE	0

//#include "Point.h"     // Point 자료형 추가를 위한 첫 번째 변경(Point헤더추가 )

#if 1  // 핵심부분! 어떤 자료형을 사용사느냐에 따라 typedef으로 변경을 해준다 ; PointListMain문을 돌릴때는 첫번째꺼 사용 그 이외는 두번째꺼 사용.  
//typedef Point * LData;     // Point 자료형 추가를 위한 두 번째 변경(Point 헤더에 정의된 구조체를 부르기 위해 typedef선언; point * 를 LData로 지칭)
typedef int LData; // LData에 대한 typedef선언 : int대신 double, float, string .. main문을 바꾸지 않고도, interface부의 변경을 통해 다른 자료형을 사용할 수 있다. 
#endif


typedef struct _node
{
	LData data;
	struct _node * next;
} Node;

typedef struct _linkedList
{	// head, cur 과 같은 변수는 전역변수로 사용해서는 안된다. 다수의 자료구조를 사용하는 상황에서 심각한 결과를 초래할 수 있다.

	Node * head; // 더미 노드를 가르키는 멤버 
	Node * cur;	// 참조 및 삭제를 돕는 멤버 
	Node * before; // 삭제를 돕는 멤버
	int numOfData; // 저장된 데이터 수를 기록하기 위한 멤버 
	int (*comp)(LData d1, LData d2); /* 정렬의 기준을 등록하기 위한 멤버 ; 함수 포인터 
										☆ comp가 가리키는 함수는 다음과 같이 동작하도록 설계(정의)해야 한다
										매개변수인 d1에 전달되는 인자가 정렬 순서상 앞서 head에 더 가까워야하는 경우 0 반환
										매개변수인 d2에 전달되는 인자가 정렬 순서상 앞서거나 같은 경우는 1 을 반환           */
} LinkedList;


typedef LinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2));

#endif