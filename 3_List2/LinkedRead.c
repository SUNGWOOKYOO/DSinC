// [Chap4]
/* 
�ſ� ������ Linked list�� �ڷᱸ�� ����
�迭�� static�ؼ� �ѹ� �����ϸ� ���� ������ �� �� ����. ���� ó�� �Ҵ�� �迭�� ������ ��ȭ�� �� �� ����. 
�� ������ �����ϱ� ���� Linked list����! 
dynamic assignment�� ���� �����ϱ����� ������ ���� ���� (ADT�� ���ؼ� ������ �Ǿ����� �ʴ�; main���� ������ ����, ����, ��ȸ ��� �������.)
- ���� 04-1
 newNode�� �ڿ��� ���� ä��� ��� vs �տ��� ���� ä��� ���
 �ڿ��� ���� ä��� �Էµ� �����Ͱ� head���� tail������ �Էµ�����, tail ������ �ٷ�� �ϱ� ������ ������ �� �ִ�.
 �ݸ�, �տ��� ���� ä��� head������ �̿��ϱ� ������ tail������ �ʿ����. ������, �Է¿� ���� ������ ������ �ݴ밡 �ȴ�.
Node * newNode �� newNode��� Node data type pointer�̰� �׸�ȭ�ϸ�  newNode pointer:[newNode�� �ּҰ�]->[newNode data|next pointer�ּҰ�]->   
														'[newNode data|next pointer�ּҰ�]->' �� �����ϰ� �׸����� ǥ�� '[newnNode| ]->'
 head = newNode�� �ϸ� 
 'head[]-> [newnNode| ]->' �� �ȴ�
*/
# if 0
#include <stdio.h>
#include <stdlib.h>

typedef struct _node /* ��-----��----���ѤѤѤ�>    ����� node�� ���� �պκ��� ������ �޺κ��� ������  
					    ��data-��next��<Node>  		 where	Node�� ����Ű�� Node ������ ���� ���� Node * pnode;   */
                      
{
	int data; // �����͸� ���� ���� 
	struct _node * next; //����ü node�� ����Ű�� ������; ����Ʈ ������ ���� 
} Node;

int main(void)
{
	Node * head = NULL;    // NULL ������ �ʱ�ȭ ; Node���� ����Ű�� pointer 
	Node * tail = NULL;
	Node * cur = NULL;

	Node * newNode = NULL;
	int readData;

	/**** �����͸� �Է� �޴� ����(insertion) ****/
	while(1)
	{
		printf("�ڿ��� �Է�: ");
		scanf_s("%d", &readData);
		if(readData < 1)
			break;

		/*** ����� �߰����� ***/
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;  /* ��---------��----���ѤѤѤѤ�>NULL  
								  ��readData-��next��<newNode>        */
#if 0
		if(head == NULL)		//ù��° ��常 �̺κ� ���� 
			head = newNode;		/*ù��°��带 head�� ����Ű����	��------���ѤѤѤ�>��---------��----���ѤѤѤѤ�>NULL  
																	���ּҰ���<head>   ��readData-��next��<newNode>      */    
		else					//ù��° ���� �� �κ� ������ �ʰ�, �ι�° ���� ���鸸 �̺κ� ���� 
			tail->next = newNode; // tail�� �̵����� previous node�� newNode�� ����Ű���� ��!
#endif

#if 1   //�� ����04-1; ����带 head ������ �߰��ϱ� 
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->next = head; // �������� ���� ����(����Ű�� ���� ����)
			head = newNode; // head�� �̵�����  previous node�� newNode�� ����Ű���� ��! 
		}
#endif

		tail = newNode; //�̹� �������� ���� newNode�� tail�� ����Ű���� ��(newNode�� �ּҸ� tail pointer ���� �ѱ�)
	}
	printf("\n");

	/**** �Է� ���� �������� ��°��� ****/
	printf("�Է� ���� �������� ��ü���! \n");
	if(head == NULL) 
	{
		printf("����� �ڿ����� �������� �ʽ��ϴ�. \n");
	}
	else 
	{
		cur = head; 
		printf("%d  ", cur->data);   // ù ��° ������ ���
		
		while(cur->next != NULL)    // �� ��° ������ ������ ���
		{
			cur = cur->next;
			printf("%d  ", cur->data);
		}
	}
	printf("\n\n");

	/**** �޸��� �������� ****/
	if(head == NULL) 
	{
		return 0;    // ������ ��尡 �������� �ʴ´�.
	}
	else 
	{
		Node * delNode = head;
		Node * delNextNode = head->next; // head->Next�� ������ �����Ͽ� ���� �س��� ����: head�� �׳� ������ ������, �� ���� ��忡 ������ �Ұ����ϴ� 

		printf("%d��(��) �����մϴ�. \n", head->data);
		free(delNode);    // ù ��° ����� ����
		
		while(delNextNode != NULL)    // �� ��° ������ ��� ���� ���� �ݺ���
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next; //�� �̷��� ������ ����: line77 �� ���� 

			printf("%d��(��) �����մϴ�. \n", delNode->data);
			free(delNode);    // �� ��° ������ ��� ����
		}
	}

	return 0;
}

#endif

// �������� deep copy ���� ����(���� �ۼ�)
#if 0
#include <stdio.h>

int main()
{
	// shallow copy in pointer    
	int x = 5;
	int *p = &x;  // p:[]��[x value]
	int *q = p;   // q:[]��	    q�� �ٲٸ� p�� ����Ű�� ���� �ٲ����� 
	(*q)++;
	printf("shallow copy(q�� ++������) \n %d \n", *p);
	printf("%d \n", *q);

	// deep copy in pointer 
	int *r = (int*)malloc(sizeof(int));         // p:[]��[x value] 
	*r = *p;                                    // r:[]��[x value]
	(*r)++;
	printf("shallow copy(r�� ++������) \n %d \n", *p);
	printf("%d \n", *r);
	free(r);

	return 0;
}

#endif 

/* ���� 04-2
 Dummy node�� ��������� �ڵ��� ��ȭ�� �������� ���� (�ڵ��� �ϰ����� ����)
 newNode�� tail�� �̿��Ͽ� �ڿ��� ���� �߰��ϴ� ������ �����̴�. (�տ��� ���� �߰��ϸ� �� ������ �����̴�)
*/
#if 0
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node * next;
} Node;

int main(void)
{
	Node * head = NULL;
	Node * tail = NULL;
	Node * cur = NULL;

	Node * newNode = NULL;
	int readData;

	head = (Node*)malloc(sizeof(Node));    // ���߰� �� ����, ���� ��� �߰�
	tail = head;

	/**** �����͸� �Է� �޴� ���� ****/
	while (1)
	{
		printf("�ڿ��� �Է�: ");
		scanf_s("%d", &readData);
		if (readData < 1)
			break;

		/*** ����� �߰����� ***/
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		/*
		if(head == NULL)
		head = newNode;
		else
		tail->next = newNode;
		*/
		tail->next = newNode;

		tail = newNode;
	}
	printf("\n");

	/**** �Է� ���� �������� ��°��� ****/
	printf("�Է� ���� �������� ��ü���! \n");
	if (head == NULL)
	{
		printf("����� �ڿ����� �������� �ʽ��ϴ�. \n");
	}
	else
	{
		cur = head;
		//	printf("%d  ", cur->data);   // ù ��° ������ ���

		while (cur->next != NULL)    // �� ��° ������ ������ ���
		{
			cur = cur->next;
			printf("%d  ", cur->data);
		}
	}
	printf("\n\n");

	/**** �޸��� �������� ****/
	if (head == NULL)
	{
		return 0;    // ������ ��尡 �������� �ʴ´�.
	}
	else
	{
		Node * delNode = head;
		Node * delNextNode = head->next;

		//	printf("%d��(��) �����մϴ�. \n", head->data);
		//	free(delNode);    // ù ��° ����� ����

		while (delNextNode != NULL)    // �� ��° ������ ��� ���� ���� �ݺ���
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d��(��) �����մϴ�. \n", delNode->data);
			free(delNode);    // �� ��° ������ ��� ����
		}
	}

	return 0;
}
#endif

/* DLinkedListMain.c
 Linked list �ڷᱸ���� ADT ����
 Dummy node �� ���������� newNode�� ������; plist: head[]->[dummy node| ]->[newNode: data n | ]->[previousNode: data n-1 | ]-> ... ->NULL  
*/
#if 0
#include <stdio.h>
#include "DLinkedList.h"

int main(void)
{
	// List�� ���� �� �ʱ�ȭ /////////////////////////////
	List list;
	int data;
	ListInit(&list);

	// 5���� ������ ���� /////////////////////////////
	LInsert(&list, 11);  LInsert(&list, 11);
	LInsert(&list, 22);  LInsert(&list, 22);
	LInsert(&list, 33);

	// ����� �������� ��ü ��� /////////////////////////
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &data))    // ù ��° ������ ��ȸ
	{
		printf("%d ", data);

		while (LNext(&list, &data))    // �� ��° ������ ������ ��ȸ
			printf("%d ", data);
	}
	printf("\n\n");

	// ���� 22�� �˻��Ͽ� ��� ���� //////////////////////////
	if (LFirst(&list, &data))
	{
		if (data == 22)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data == 22)
				LRemove(&list);
		}
	}

	// ���� �� �����ִ� ������ ��ü ��� ////////////////////////
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}
#endif 

/* ���� 04-3
 Linked list �ڷᱸ���� ����� point type�ڷ����� ���� ADT ���� 
 Chap3 ���� PointListMain.c �� �״�� ��밡�� 
 (��, ����� typedef����� point.h �߰����� �ʿ�! ����, comp�Լ��� ������� �ʾ����Ƿ� ��°���� reverse�Ǿ� ���ð���! )
*/
#if 0
#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "Point.h"

int main(void)
{
	List list;
	Point compPos;
	Point * ppos;

	ListInit(&list);

	// 4���� ������ ����  ///////////
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);

	// ����� �������� ��� ///////////
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	// xpos�� 2�� ��� ������ ����  ///////////
	compPos.xpos = 2;
	compPos.ypos = 0;

	if (LFirst(&list, &ppos))
	{
		if (PointComp(ppos, &compPos) == 1)
		{
			ppos = LRemove(&list);
			free(ppos);
		}

		while (LNext(&list, &ppos))
		{
			if (PointComp(ppos, &compPos) == 1)
			{
				ppos = LRemove(&list);
				free(ppos);
			}
		}
	}

	// ���� �� ���� ������ ��ü ���  ///////////
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	return 0;
}
#endif

/*  DLinkedListSortMain.c 
 Linked list �ڷᱸ���� ADT ����2 (data Insetion�� ���ؼ� ���� ������ programmer�� ���� �� �ִ�. ��, �ڷᱸ���� ���� interface�ο� implementation�θ� �ǵ��� �ʾƵ� �ȴ�.)
 list�� �ɹ� comp�� �̿��Ͽ� SetSortRule�� ���� application��(main������ �ִ� �ҽ�����)���� ���� ������ ���� �� �ִ�. 
*/
#if 0
#include <stdio.h>
#include "DLinkedList.h"

int WhoIsPrecede(int d1, int d2) 
{
	if (d1 < d2)
		return 0;    // d1�� ���� ������ �ռ���.
	else
		return 1;    // d2�� ���� ������ �ռ��ų� ����.
}

int main(void)
{
	// List�� ���� �� �ʱ�ȭ  ////////////
	List list;
	int data;
	ListInit(&list);

	SetSortRule(&list, WhoIsPrecede); // programmer�� ���ļ����� ���� �� �ִ�. ; comp != NULL �̵ǹǷ� Sinsert �Լ��� ���� list �ڷᱸ���� ���� data�� ���� ����� ����, ������ �̷������.

	// 5���� ������ ����  ///////////////
	LInsert(&list, 11);  LInsert(&list, 11);
	LInsert(&list, 22);  LInsert(&list, 22);
	LInsert(&list, 33);

	// ����� �������� ��ü ��� ////////////
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	// ���� 22�� �˻��Ͽ� ��� ���� ////////////
	if (LFirst(&list, &data))
	{
		if (data == 22)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data == 22)
				LRemove(&list);
		}
	}

	// ���� �� ����� ������ ��ü ��� ////////////
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}
#endif

/* ���� 04-4
Linked list �ڷᱸ���� ����� point type�ڷ����� ���� ADT ����2
���� 04-3 ���� sorting order�� ���غ��� 
1. x��ǥ�� ���� �������� �������� ������ �ǵ���
2. x��ǥ�� ������� y��ǥ�� ������� �������� ������ �ǵ��� 
*/
#if 1
#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "Point.h"

int WhoIsPrecede(Point * d1, Point * d2)
{
	if (d1->xpos < d2->xpos)
	{
		return 0;
	}
	else if (d1->xpos == d2->xpos)
	{
		if (d1->ypos < d2->ypos)
			return 0;
		else
			return 1;
	}
	else
		return 1;
}


int main(void)
{
	List list;
	Point comp;
	Point * pPoint;
	ListInit(&list);

	SetSortRule(&list, WhoIsPrecede);     // ���ı����� ���!

	pPoint = (Point*)malloc(sizeof(Point));
	SetPointPos(pPoint, 3, 2);
	LInsert(&list, pPoint);

	pPoint = (Point*)malloc(sizeof(Point));
	SetPointPos(pPoint, 3, 1);
	LInsert(&list, pPoint);

	pPoint = (Point*)malloc(sizeof(Point));
	SetPointPos(pPoint, 2, 2);
	LInsert(&list, pPoint);

	pPoint = (Point*)malloc(sizeof(Point));
	SetPointPos(pPoint, 2, 1);
	LInsert(&list, pPoint);

	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &pPoint))
	{
		ShowPointPos(pPoint);

		while (LNext(&list, &pPoint))
			ShowPointPos(pPoint);
	}
	printf("\n");

	// xpos�� 2�� ��� ������ ����  ////////
	comp.xpos = 2;
	comp.ypos = 0;

	if (LFirst(&list, &pPoint))
	{
		if (PointComp(pPoint, &comp) == 1)
		{
			pPoint = LRemove(&list);
			free(pPoint);
		}

		while (LNext(&list, &pPoint))
		{
			if (PointComp(pPoint, &comp) == 1)
			{
				pPoint = LRemove(&list);
				free(pPoint);
			}
		}
	}

	// ���� �� ����� ������ ��� ////////
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &pPoint))
	{
		ShowPointPos(pPoint);

		while (LNext(&list, &pPoint))
			ShowPointPos(pPoint);
	}
	printf("\n");

	return 0;
}
#endif 

