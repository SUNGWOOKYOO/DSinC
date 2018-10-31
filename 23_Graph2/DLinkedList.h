/* �ڷᱸ��(�����͸� ��� �׸�)�� interface �� ; ������� ; Ŭ��������, �Լ� ����
�� ������� 3�� part�� ���ؼ� ���(interface��)�� �߰� �ϰ� ������Ͽ� ����� �Լ��� ��ɸ� �����Ѵٸ�, ����Ʈ�� ������ �� �ʿ���� application�θ� ����ϱ⸸ �ϸ�ȴ�.
�߰��� ������ �ڷ����� �ִ°�� ����θ� �������(interface ��)�� �ణ �����ϰ� (typedef ������ ������ �ٽ��̴�.)
��, �ҽ�����(implementation ��)�� �����ؼ��� �ȵǵ��� �����ؾ��Ѵ�. */
#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#define TRUE	1
#define FALSE	0

//#include "Point.h"     // Point �ڷ��� �߰��� ���� ù ��° ����(Point����߰� )

#if 1  // �ٽɺκ�! � �ڷ����� ������Ŀ� ���� typedef���� ������ ���ش� ; PointListMain���� �������� ù��°�� ��� �� �ܴ̿� �ι�°�� ���.  
//typedef Point * LData;     // Point �ڷ��� �߰��� ���� �� ��° ����(Point ����� ���ǵ� ����ü�� �θ��� ���� typedef����; point * �� LData�� ��Ī)
typedef int LData; // LData�� ���� typedef���� : int��� double, float, string .. main���� �ٲ��� �ʰ�, interface���� ������ ���� �ٸ� �ڷ����� ����� �� �ִ�. 
#endif


typedef struct _node
{
	LData data;
	struct _node * next;
} Node;

typedef struct _linkedList
{	// head, cur �� ���� ������ ���������� ����ؼ��� �ȵȴ�. �ټ��� �ڷᱸ���� ����ϴ� ��Ȳ���� �ɰ��� ����� �ʷ��� �� �ִ�.

	Node * head; // ���� ��带 ����Ű�� ��� 
	Node * cur;	// ���� �� ������ ���� ��� 
	Node * before; // ������ ���� ���
	int numOfData; // ����� ������ ���� ����ϱ� ���� ��� 
	int (*comp)(LData d1, LData d2); /* ������ ������ ����ϱ� ���� ��� ; �Լ� ������ 
										�� comp�� ����Ű�� �Լ��� ������ ���� �����ϵ��� ����(����)�ؾ� �Ѵ�
										�Ű������� d1�� ���޵Ǵ� ���ڰ� ���� ������ �ռ� head�� �� ��������ϴ� ��� 0 ��ȯ
										�Ű������� d2�� ���޵Ǵ� ���ڰ� ���� ������ �ռ��ų� ���� ���� 1 �� ��ȯ           */
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