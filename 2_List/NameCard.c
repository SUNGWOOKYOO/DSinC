/* NameCard 자료형을 위한 implementation(구현부) 파일 ; 함수정의 (ADT가 정의 되어 있다) 
 visual studio 2017 에서 strcpy(인자1, 인자2)로하면 에러가 나서 
						 strcpy_s(인자1, 인자2, 인자3)으로 바꾸었다. 
						 이때, 인자2는 문자열의 크기인데 적당한 값을 구하기 어려워 20으로 하였다.*/
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
	printf("[이름] %s \n", pcard->name);
	printf("[번호] %s \n\n", pcard->phone);
}

int NameCompare(NameCard * pcard, char * name)
{
	return strcmp(pcard->name, name);
}

void ChangePhoneNum(NameCard * pcard, char * phone)
{
	strcpy_s(pcard->phone, 20, phone);
}