//[Chap3] ; List �ڷᱸ�� ������ ADT

/* application �� main�� ���ǵ� �ڷ����� ������ ����Ѵ�,  
 interface�� ; ����Ʈ �ڷᱸ���� �������
 implementation�� ; ����Ʈ�ڷᱸ���� source���� 
 �� 3������ �־�� complie�� �����ϴ� */

// �� ������� 3�� part�� ���ؼ� ���(interface��)�� �߰� �ϰ� ������Ͽ� ����� �Լ��� ��ɸ� �����Ѵٸ�, ����Ʈ�� ������ �� �ʿ���� application�θ� ����ϱ⸸ �ϸ�ȴ�.
// ��, �߰��� ������ �ڷ����� �ִ°�� ����θ� �������(interface ��)�� �ణ �����ϰ� (typedef ������ ������ �ٽ��̴�.)
// ,�ҽ�����(implementation ��)�� �����ؼ��� �ȵǵ��� �����ؾ��Ѵ�.

/* ListMain.c 
 List �ڷḦ �����Ͽ� �����͸� �����غ��� ����غ��� ������ ����. */
#if 0
#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	/*** ArrayList�� ���� �� �ʱ�ȭ ***/
	List list; // ���� list ����; �����͸� ���� �� �����Ƿ� �̴� '�ڷᱸ��' �� �� �� �ִ�. ; ���� 'List'��  �����͸� ȿ�������� ���� �� ������ ���ֵ��� ������ �� �ִ�.
	int data;
	ListInit(&list);

	/*** 5���� ������ ���� ***/
	LInsert(&list, 11);  LInsert(&list, 11);
	LInsert(&list, 22);  LInsert(&list, 22);
	LInsert(&list, 33);

	/*** ����� �������� ��ü ��� ***/
	printf("���� �������� ��: %d \n", LCount(&list));

	if(LFirst(&list, &data))    // ù ��° ������ ��ȸ
	{
		printf("%d \n", data);
		
		while(LNext(&list, &data))    // �� ��° ������ ������ ��ȸ
			printf("%d ", data);
	}
	printf("\n\n");

	/*** ���� 22�� Ž���Ͽ� ��� ���� ***/
	printf("���� 22�� Ž���Ͽ� ��� ����\n");

	if(LFirst(&list, &data))
	{
		if(data == 22)
			LRemove(&list);
		
		while(LNext(&list, &data))
		{
			if(data == 22)
				LRemove(&list);
		}
	}

	/*** ���� �� ����� ������ ��ü ��� ***/
	printf("���� �������� ��: %d \n", LCount(&list));

	if(LFirst(&list, &data))
	{
		printf("%d ", data);
		
		while(LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}
#endif

/* ���� 03-1 
 ListUseMain.c */
#if 0
#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	/*** ArrayList�� ���� �� �ʱ�ȭ ***/
	List list;
	int data, i;
	int sum = 0;
	ListInit(&list); //�ʱ�ȭ 

	/*** ���� 1���� 9���� ���� ***/
	for (i = 1; i<10; i++)
		LInsert(&list, i);

	/*** ���� ��� �� ��� ***/
	if (LFirst(&list, &data))
	{
		sum += data;

		while (LNext(&list, &data))
			sum += data;
	}
	printf("SUM = %d \n\n", sum);

	/*** 2�� ��� 3�� ��� ����***/
	if (LFirst(&list, &data))
	{
		if (data % 2 == 0 || data % 3 == 0)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data % 2 == 0 || data % 3 == 0)
				LRemove(&list);
		}
	}

	/*** ���� �� ����� ������ ��ü ��� ***/
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

/* PointListMain.c
 Point �ڷ����� �����Ͽ� List �ڷᱸ���� ��� ���� ����� ����*/
#if 0
#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Point.h"

int main(void)
{
	List list;
	Point compPos;
	Point * ppos;

	ListInit(&list);

	/*** 4���� ������ ���� ***/
	ppos = (Point*)malloc(sizeof(Point)); //Point �ڷ��� ��ŭ�� byte �� �� �������� �Ҵ�޾� ppos�� ����Ű���� ��(���� �Ҵ�)
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

	/*** ����� �������� ��� ***/
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	/*** xpos�� 2�� ��� ������ ���� ***/
	compPos.xpos = 2;
	compPos.ypos = 0;

	if (LFirst(&list, &ppos))
	{
		if (PointComp(ppos, &compPos) == 1)
		{
			ppos = LRemove(&list); /*LRemove�� �Ҹ�� �����͸� ��ȯ�Ͽ� �޸��� ������ ��ȸ�� �� �� �־���Ѵ�.(�޸� �Ҹ��� å���� �����ؾ��Ѵ�;
									ADT�� ������ ����; �� main�� �ȿ��� �Ҵ�� �Ҹ� ������ �̷�������� �ϰ� �ϱ�����) */
			free(ppos); //ppos�� ����Ű�� �޸𸮸� ��ü�Ѵ�  
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

	/*** ���� �� ���� ������ ��ü ��� ***/
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

/* ���� 03-2
 NameCardListMain.c
 �����Ǿ��ִ� �ڷᱸ��(����Ʈ)�� Ȱ���Ͽ� ���ǵ� �ڷ���(Namecard)�� Ȱ���ϴ� ������ �غ���   
*/
#if 1
#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(void)
{
	List list;
	NameCard * pcard;
	ListInit(&list);

	pcard = MakeNameCard("������", "010-1111-2222");
	LInsert(&list, pcard);

	pcard = MakeNameCard("������", "010-2222-5555");
	LInsert(&list, pcard);

	pcard = MakeNameCard("������", "010-3333-7777");
	LInsert(&list, pcard);

	// �������� ������ ��ȸ�Ͽ� ���
	if (LFirst(&list, &pcard))
	{
		if (!NameCompare(pcard, "������"))
		{
			ShowNameCardInfo(pcard);
		}
		else
		{
			while (LNext(&list, &pcard))
			{
				if (!NameCompare(pcard, "������"))
				{
					ShowNameCardInfo(pcard);
					break;
				}
			}
		}
	}

	// �������� ������ ����
	if (LFirst(&list, &pcard))
	{
		if (!NameCompare(pcard, "������"))
		{
			ChangePhoneNum(pcard, "010-9999-9999");
		}
		else
		{
			while (LNext(&list, &pcard))
			{
				if (!NameCompare(pcard, "������"))
				{
					ChangePhoneNum(pcard, "010-9999-9999");
					break;
				}
			}
		}
	}

	// �������� ������ ����
	if (LFirst(&list, &pcard))
	{
		if (!NameCompare(pcard, "������"))
		{
			pcard = LRemove(&list);
			free(pcard);
		}
		else
		{
			while (LNext(&list, &pcard))
			{
				if (!NameCompare(pcard, "������"))
				{
					pcard = LRemove(&list);
					free(pcard);
					break;
				}
			}
		}
	}

	// ��� ����� ���� ���
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &pcard))
	{
		ShowNameCardInfo(pcard);

		while (LNext(&list, &pcard))
			ShowNameCardInfo(pcard);
	}

	return 0;
}
#endif 