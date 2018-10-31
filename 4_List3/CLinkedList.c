#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List * plist)
{
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

void LInsertFront(List * plist, Data data) // 머리에 노드를 추가 
{
	Node * newNode = (Node*)malloc(sizeof(Node)); // 새 노드 생성
	newNode->data = data;						

	if(plist->tail == NULL)				// 첫번째 노드라면,
	{
		plist->tail = newNode;			//  tail이 새 녿를 가리키게 한다. 
		newNode->next = newNode;		// 새 노드 자신을 가르키게 한다.
	}
	else // 이 부분이 Linsert와 다르다 
	{
		newNode->next = plist->tail->next;	// newNode가 previousNode를 가리키게 한다. 
		plist->tail->next = newNode;		// newNode를 tail node가 가리키도록 한다. 
	}

	(plist->numOfData)++;
}

void LInsert(List * plist, Data data) // 꼬리에 노드를 추가
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if(plist->tail == NULL) 
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else 
	{
		newNode->next = plist->tail->next; 
		plist->tail->next = newNode;
		plist->tail = newNode;		// LInsertFront 함수와의 유일한 차이점; newNode가 tail node가 된다. 
	}

	(plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
	if(plist->tail == NULL)    // 저장된 노드가 없다면
		return FALSE;

	plist->before = plist->tail; //before 가 꼬리를 가리키게 한다. 
	plist->cur = plist->tail->next; // cur이 머리를 가리키게 한다. 

	*pdata = plist->cur->data; // cur이 가리키는 노드의 데이터 반환 
	return TRUE;
}

int LNext(List * plist, Data * pdata)
{
	if(plist->tail == NULL)    // 저장된 노드가 없다면
		return FALSE;

	plist->before = plist->cur; // before가 다음 노드를 가리키게 한다. 
	plist->cur = plist->cur->next; // cur이 다음 노드를 가리키게 한다. 

	*pdata = plist->cur->data; // cur이 가리키는 노드의 데이터 반환 
	return TRUE;
}

Data LRemove(List * plist)
{
	Node * rpos = plist->cur;
	Data rdata = rpos->data;

	// 더미노드가 없기 때문에 예외적인 상황이 발생한다. (더미가 있고 없고는 장단점이 발생)
	if(rpos == plist->tail)    // 예외상황1: 삭제 대상을 tail이 가리킨다면
	{
		if(plist->tail == plist->tail->next)    // 예외상황2: 그리고 마지막 남은 노드라면
			plist->tail = NULL;
		else
			plist->tail = plist->before;
	}

	plist->before->next = plist->cur->next;  // 핵심연산 1. 삭제할 노드의 이전 노드가, 삭제할 노드의 다음노드를 가리키게 한다. 
	plist->cur = plist->before;				// 핵심연산 2. 포인터 변수 cur을 한칸 뒤로 이동시킨다. 

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List * plist)
{
	return plist->numOfData;
}