#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List * plist)
{
	plist->head = (Node*)malloc(sizeof(Node)); // 더미 노드의 생성 
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

void FInsert(List * plist, LData data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));	//새 노드 생성
	newNode->data = data;							//새 노드에 데이터 저장	

	newNode->next = plist->head->next;				//새 노드가 다른 노드를 가리키게 함
	plist->head->next = newNode;					//더미노드가 새 노드를 가르키게함

	(plist->numOfData)++;							//저장된 노드의 수를 하나 증가시킴 
}

void SInsert(List * plist, LData data)
{
	Node * newNode = (Node*)malloc(sizeof(Node)); // 새 노드의 생성
	Node * pred = plist->head; // 처음 pred는 더미노드를 가리킴; while문에서 pred를 이동시키며 정렬기준에 따른 위치 결정에 쓰임
	newNode->data = data; // 새 노드에 데이터 저장

	while(pred->next != NULL &&
		plist->comp(data, pred->next->data) != 0) 
	{
		/* 첫번째 조건: pred가 마지막 노드를 가리키는지 물음
		   두번째 조건: 새 노드 데이터와 pred의 다음 노드에 저장된 데이터의 우선순위 비겨를 위한 함수 comp 호출
		   ; pred가 마지막 노드를 가리키는것이 아니고, 새 데이터가 들어갈 자리를 아직 찾지 못했다면 pred를 다음 노드를 가르키도록 한다. 
		   comp :정렬의 기준을 등록하기 위한 멤버 ; 함수 포인터 
										☆ comp가 가리키는 함수는 다음과 같이 동작하도록 설계(정의)해야 한다
										매개변수인 d1에 전달되는 인자가 정렬 순서상 앞서 head에 더 가까워야하는 경우 0 반환
										매개변수인 d2에 전달되는 인자가 정렬 순서상 앞서거나 같은 경우는 1 을 반환         		   */
		pred = pred->next; 
	}

	newNode->next = pred->next; // 새노드의 뒤를 연결
	pred->next = newNode;		// 새 노드의 앞을 연결 

	(plist->numOfData)++;		// 저장된 데이터의 수 하나 증가 
}


void LInsert(List * plist, LData data)
{
	if(plist->comp == NULL)		// 정렬 기준이 마련되지 않았다면 (정렬기준이 없으면 Chap3의 ListMain.c와 똑같은 input을 주었을경우, 뒤집혀 결과나옴)
		FInsert(plist, data);	// 머리에 노드를 추가! 
	else						//☆ 정렬기준이 마련되었다면, 
		SInsert(plist, data);	// 정렬기준에 근거하여 노드를 추가!
}

int LFirst(List * plist, LData * pdata)
{
	if(plist->head->next == NULL)	// 더미노드가 NULL을 가리킨다면
		return FALSE;				// 반환할 데이터가 없다! 

	plist->before = plist->head;	// before은 더미노드를 가리키게 함
	plist->cur = plist->head->next; // cur은 첫번째 노드를 가리키게 함

	*pdata = plist->cur->data; // 첫 번째 노드의 데이터를 전달 
	return TRUE;
}

int LNext(List * plist, LData * pdata)
{
	if(plist->cur->next == NULL)	// 더미 노드가 NULL을 가리킨다면, 
		return FALSE;				// 반환할 데이터가 없다! 

	plist->before = plist->cur;		// cur이 가리키던것을 before가 가리킴
	plist->cur = plist->cur->next;	// cur은 그다음 노드를 가리킴

	*pdata = plist->cur->data;		// cur이 가리키는 노드의 데이터 전달		
	return TRUE;					// 데이터 반환 성공! 
}

LData LRemove(List * plist)
{
	Node * rpos = plist->cur;		// 소멸 대상의 주소값을 rpos에 저장	
	LData rdata = rpos->data;		// 소멸 대상의 데이터를 rdatadp 저장
		
	plist->before->next = plist->cur->next; //소멸 대상을 리스트에서 제거
	plist->cur = plist->before;				//cur이 가리키는 위치를 재조정!

	free(rpos);								// 리스트에서 제거된 노드 소멸
	(plist->numOfData)--;					// 저장된 데이터의 수 하나 감소
	return rdata;							// 제거된 노드의 데이터 반환 
}

int LCount(List * plist)
{
	return plist->numOfData;
}

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2))
{
	plist->comp = comp;
}