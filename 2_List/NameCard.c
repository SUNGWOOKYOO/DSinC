/* NameCard �ڷ����� ���� implementation(������) ���� ; �Լ����� (ADT�� ���� �Ǿ� �ִ�) 
 visual studio 2017 ���� strcpy(����1, ����2)���ϸ� ������ ���� 
						 strcpy_s(����1, ����2, ����3)���� �ٲپ���. 
						 �̶�, ����2�� ���ڿ��� ũ���ε� ������ ���� ���ϱ� ����� 20���� �Ͽ���.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"

NameCard * MakeNameCard(char * name, char * phone)
{
	NameCard * newCard = (NameCard *)malloc(sizeof(NameCard));
	strcpy_s(newCard->name, 20, name);
	strcpy_s(newCard->phone, 20, phone);
	return newCard;
}

void ShowNameCardInfo(NameCard * pcard)
{
	printf("[�̸�] %s \n", pcard->name);
	printf("[��ȣ] %s \n\n", pcard->phone);
}

int NameCompare(NameCard * pcard, char * name)
{
	return strcmp(pcard->name, name);
}

void ChangePhoneNum(NameCard * pcard, char * phone)
{
	strcpy_s(pcard->phone, 20, phone);
}