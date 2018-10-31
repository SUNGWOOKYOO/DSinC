#include <stdio.h>
#include <stdlib.h>
#include "DBDLinkedList.h"

void ListInit(List * plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->tail = (Node*)malloc(sizeof(Node));

	plist->head->prev = NULL;
	plist->head->next = plist->tail;

	plist->tail->next = NULL;
	plist->tail->prev = plist->head;

	plist->numOfData = 0;
}

void LInsert(List * plist, Data data) 
{
	// 1단계 : 새 노드를 생성하고 데이터 저장
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	// 2단계 : 새 노드와 새 노드의 왼쪽에 위치할 노드가 서로를 가르키게한다.  
	newNode->prev = plist->tail->prev;
	plist->tail->prev->next = newNode;

	// 3단계 : 새 노드와 새 노드의 오른쪽에 위치할 노드가 서로를 가르키게한다.  
	newNode->next = plist->tail;
	plist->tail->prev = newNode;

	(plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
	if(plist->head->next == plist->tail)
		return FALSE;

	plist->cur = plist->head->next; // head쪽의 더미노드가 가리키는 node
	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List * plist, Data * pdata)
{
	if(plist->cur->next == plist->tail)
		return FALSE;

	plist->cur = plist->cur->next; 
	*pdata = plist->cur->data;
	return TRUE;
}

Data LRemove(List * plist)
{
	Node * rpos = plist->cur;
	Data remv = rpos->data;

	plist->cur->prev->next = plist->cur->next;
	plist->cur->next->prev = plist->cur->prev;

	plist->cur = plist->cur->prev;    // cur의 위치를 재조정

	free(rpos);
	(plist->numOfData)--;
	return remv;
}

int LCount(List * plist)
{
	return plist->numOfData;
}