#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#define TRUE	1
#define FALSE	0

#include "Employee.h"     // Point 자료형 추가를 위한 첫 번째 변경(Point헤더추가 )

#if 1  // 핵심부분! 어떤 자료형을 사용사느냐에 따라 typedef으로 변경을 해준다 
typedef Employee * Data;     // Point 자료형 추가를 위한 두 번째 변경(Point 헤더에 정의된 구조체를 부르기 위해 typedef선언; point * 를 LData로 지칭)
//typedef int Data;
#endif

typedef struct _node
{
	Data data;
	struct _node * next;
} Node;

typedef struct _CLL
{
	Node * tail;
	Node * cur;
	Node * before;
	int numOfData;
} CList;


typedef CList List;

void ListInit(List * plist);
void LInsert(List * plist, Data data);	// 꼬리에 노드를 추가 
void LInsertFront(List * plist, Data data);	// 머리에 노드를 추가 

int LFirst(List * plist, Data * pdata);
int LNext(List * plist, Data * pdata);
Data LRemove(List * plist);
int LCount(List * plist);

#endif