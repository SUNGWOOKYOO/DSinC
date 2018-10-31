#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List * plist)
{
	plist->head = (Node*)malloc(sizeof(Node)); // ���� ����� ���� 
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

void FInsert(List * plist, LData data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));	//�� ��� ����
	newNode->data = data;							//�� ��忡 ������ ����	

	newNode->next = plist->head->next;				//�� ��尡 �ٸ� ��带 ����Ű�� ��
	plist->head->next = newNode;					//���̳�尡 �� ��带 ����Ű����

	(plist->numOfData)++;							//����� ����� ���� �ϳ� ������Ŵ 
}

void SInsert(List * plist, LData data)
{
	Node * newNode = (Node*)malloc(sizeof(Node)); // �� ����� ����
	Node * pred = plist->head; // ó�� pred�� ���̳�带 ����Ŵ; while������ pred�� �̵���Ű�� ���ı��ؿ� ���� ��ġ ������ ����
	newNode->data = data; // �� ��忡 ������ ����

	while(pred->next != NULL &&
		plist->comp(data, pred->next->data) != 0) 
	{
		/* ù��° ����: pred�� ������ ��带 ����Ű���� ����
		   �ι�° ����: �� ��� �����Ϳ� pred�� ���� ��忡 ����� �������� �켱���� ��ܸ� ���� �Լ� comp ȣ��
		   ; pred�� ������ ��带 ����Ű�°��� �ƴϰ�, �� �����Ͱ� �� �ڸ��� ���� ã�� ���ߴٸ� pred�� ���� ��带 ����Ű���� �Ѵ�. 
		   comp :������ ������ ����ϱ� ���� ��� ; �Լ� ������ 
										�� comp�� ����Ű�� �Լ��� ������ ���� �����ϵ��� ����(����)�ؾ� �Ѵ�
										�Ű������� d1�� ���޵Ǵ� ���ڰ� ���� ������ �ռ� head�� �� ��������ϴ� ��� 0 ��ȯ
										�Ű������� d2�� ���޵Ǵ� ���ڰ� ���� ������ �ռ��ų� ���� ���� 1 �� ��ȯ         		   */
		pred = pred->next; 
	}

	newNode->next = pred->next; // ������� �ڸ� ����
	pred->next = newNode;		// �� ����� ���� ���� 

	(plist->numOfData)++;		// ����� �������� �� �ϳ� ���� 
}


void LInsert(List * plist, LData data)
{
	if(plist->comp == NULL)		// ���� ������ ���õ��� �ʾҴٸ� (���ı����� ������ Chap3�� ListMain.c�� �Ȱ��� input�� �־������, ������ �������)
		FInsert(plist, data);	// �Ӹ��� ��带 �߰�! 
	else						//�� ���ı����� ���õǾ��ٸ�, 
		SInsert(plist, data);	// ���ı��ؿ� �ٰ��Ͽ� ��带 �߰�!
}

int LFirst(List * plist, LData * pdata)
{
	if(plist->head->next == NULL)	// ���̳�尡 NULL�� ����Ų�ٸ�
		return FALSE;				// ��ȯ�� �����Ͱ� ����! 

	plist->before = plist->head;	// before�� ���̳�带 ����Ű�� ��
	plist->cur = plist->head->next; // cur�� ù��° ��带 ����Ű�� ��

	*pdata = plist->cur->data; // ù ��° ����� �����͸� ���� 
	return TRUE;
}

int LNext(List * plist, LData * pdata)
{
	if(plist->cur->next == NULL)	// ���� ��尡 NULL�� ����Ų�ٸ�, 
		return FALSE;				// ��ȯ�� �����Ͱ� ����! 

	plist->before = plist->cur;		// cur�� ����Ű������ before�� ����Ŵ
	plist->cur = plist->cur->next;	// cur�� �״��� ��带 ����Ŵ

	*pdata = plist->cur->data;		// cur�� ����Ű�� ����� ������ ����		
	return TRUE;					// ������ ��ȯ ����! 
}

LData LRemove(List * plist)
{
	Node * rpos = plist->cur;		// �Ҹ� ����� �ּҰ��� rpos�� ����	
	LData rdata = rpos->data;		// �Ҹ� ����� �����͸� rdatadp ����
		
	plist->before->next = plist->cur->next; //�Ҹ� ����� ����Ʈ���� ����
	plist->cur = plist->before;				//cur�� ����Ű�� ��ġ�� ������!

	free(rpos);								// ����Ʈ���� ���ŵ� ��� �Ҹ�
	(plist->numOfData)--;					// ����� �������� �� �ϳ� ����
	return rdata;							// ���ŵ� ����� ������ ��ȯ 
}

int LCount(List * plist)
{
	return plist->numOfData;
}

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2))
{
	plist->comp = comp;
}