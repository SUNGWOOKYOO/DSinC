#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#define TRUE	1
#define FALSE	0

#include "Employee.h"     // Point �ڷ��� �߰��� ���� ù ��° ����(Point����߰� )

#if 1  // �ٽɺκ�! � �ڷ����� ������Ŀ� ���� typedef���� ������ ���ش� 
typedef Employee * Data;     // Point �ڷ��� �߰��� ���� �� ��° ����(Point ����� ���ǵ� ����ü�� �θ��� ���� typedef����; point * �� LData�� ��Ī)
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
void LInsert(List * plist, Data data);	// ������ ��带 �߰� 
void LInsertFront(List * plist, Data data);	// �Ӹ��� ��带 �߰� 

int LFirst(List * plist, Data * pdata);
int LNext(List * plist, Data * pdata);
Data LRemove(List * plist);
int LCount(List * plist);

#endif