/* �ڷᱸ���� interface �� ; ������� ; Ŭ��������, �Լ� ����
 �� ������� 3�� part�� ���ؼ� ���(interface��)�� �߰� �ϰ� ������Ͽ� ����� �Լ��� ��ɸ� �����Ѵٸ�, ����Ʈ�� ������ �� �ʿ���� application�θ� ����ϱ⸸ �ϸ�ȴ�.
 �߰��� ������ �ڷ����� �ִ°�� ����θ� �������(interface ��)�� �ణ �����ϰ� (typedef ������ ������ �ٽ��̴�.)
 ��, �ҽ�����(implementation ��)�� �����ؼ��� �ȵǵ��� �����ؾ��Ѵ�. */

#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#include "Point.h"     // Point �ڷ��� �߰��� ���� ù ��° ����(Point����߰� )
#include "NameCard.h"

#define TRUE	1
#define FALSE	0

/*** ArrayList�� ���� ****/
#define LIST_LEN	100

#if 1  // �ٽɺκ�! � �ڷ����� ������Ŀ� ���� typedef���� ������ ���ش� ; PointListMain���� �������� ù��°�� ���, NameCardListMain���� �������� 2��°�� ���, �� �ܴ̿� ����°�� ���.  
//typedef Point * LData;     // Point �ڷ��� �߰��� ���� �� ��° ����(Point ����� ���ǵ� ����ü�� �θ��� ���� typedef����; point * �� LData�� ��Ī)
typedef NameCard * LData;
//typedef int LData; // LData�� ���� typedef���� : int��� double, float, string .. main���� �ٲ��� �ʰ�, interface���� ������ ���� �ٸ� �ڷ����� ����� �� �ִ�. 

#endif

typedef struct __ArrayList //�迭 ��� ����Ʈ�� ������ ����ü 
{
	LData arr[LIST_LEN]; //����Ʈ�� ������� �迭(�������� ��������� int arr[] �迭�� ����Ǿ���.)
	int numOfData; // ����� �����ͼ� 
	int curPosition; // ������ ���� ��ġ�� ���(�����ֱٿ� ������ �̷��� �������� �ε��� ����)
} ArrayList;


/*** ArrayList�� ���õ� ����� ****/
typedef ArrayList List; // ArrayList ��� LinkedList ... main���� �ٲ��� �ʰ�, interface���� ������ ���� �ٸ� list ��(structure)�� ����� �� �ִ�.

// List �ڷᱸ���� ADT(abstract data type; ��ü���� ����� �ϼ������� ������� �ʰ�, �����ϰ� �� ����� �������� ������ ��)
// p80 �� ��ɼ����� �����Ǿ� �ִ�.
void ListInit(List * plist);			//�ʱ�ȭ
void LInsert(List * plist, LData data); //����������

int LFirst(List * plist, LData * pdata);//ù ������ ����
int LNext(List * plist, LData * pdata);// �� ��° ���� ������ ����

LData LRemove(List * plist);			//������ ������ ���� ; �̶� ��ȯ�ϴ� ���� �Ҹ�� ������; �� ������ p98�� �����ִ�.(ADT�� ����)
int LCount(List * plist);				//����� ������ �� ��ȯ

#endif