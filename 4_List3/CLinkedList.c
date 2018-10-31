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

void LInsertFront(List * plist, Data data) // �Ӹ��� ��带 �߰� 
{
	Node * newNode = (Node*)malloc(sizeof(Node)); // �� ��� ����
	newNode->data = data;						

	if(plist->tail == NULL)				// ù��° �����,
	{
		plist->tail = newNode;			//  tail�� �� �븦 ����Ű�� �Ѵ�. 
		newNode->next = newNode;		// �� ��� �ڽ��� ����Ű�� �Ѵ�.
	}
	else // �� �κ��� Linsert�� �ٸ��� 
	{
		newNode->next = plist->tail->next;	// newNode�� previousNode�� ����Ű�� �Ѵ�. 
		plist->tail->next = newNode;		// newNode�� tail node�� ����Ű���� �Ѵ�. 
	}

	(plist->numOfData)++;
}

void LInsert(List * plist, Data data) // ������ ��带 �߰�
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
		plist->tail = newNode;		// LInsertFront �Լ����� ������ ������; newNode�� tail node�� �ȴ�. 
	}

	(plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
	if(plist->tail == NULL)    // ����� ��尡 ���ٸ�
		return FALSE;

	plist->before = plist->tail; //before �� ������ ����Ű�� �Ѵ�. 
	plist->cur = plist->tail->next; // cur�� �Ӹ��� ����Ű�� �Ѵ�. 

	*pdata = plist->cur->data; // cur�� ����Ű�� ����� ������ ��ȯ 
	return TRUE;
}

int LNext(List * plist, Data * pdata)
{
	if(plist->tail == NULL)    // ����� ��尡 ���ٸ�
		return FALSE;

	plist->before = plist->cur; // before�� ���� ��带 ����Ű�� �Ѵ�. 
	plist->cur = plist->cur->next; // cur�� ���� ��带 ����Ű�� �Ѵ�. 

	*pdata = plist->cur->data; // cur�� ����Ű�� ����� ������ ��ȯ 
	return TRUE;
}

Data LRemove(List * plist)
{
	Node * rpos = plist->cur;
	Data rdata = rpos->data;

	// ���̳�尡 ���� ������ �������� ��Ȳ�� �߻��Ѵ�. (���̰� �ְ� ����� ������� �߻�)
	if(rpos == plist->tail)    // ���ܻ�Ȳ1: ���� ����� tail�� ����Ų�ٸ�
	{
		if(plist->tail == plist->tail->next)    // ���ܻ�Ȳ2: �׸��� ������ ���� �����
			plist->tail = NULL;
		else
			plist->tail = plist->before;
	}

	plist->before->next = plist->cur->next;  // �ٽɿ��� 1. ������ ����� ���� ��尡, ������ ����� ������带 ����Ű�� �Ѵ�. 
	plist->cur = plist->before;				// �ٽɿ��� 2. ������ ���� cur�� ��ĭ �ڷ� �̵���Ų��. 

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List * plist)
{
	return plist->numOfData;
}