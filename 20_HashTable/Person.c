#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Person.h"

int GetSSN(Person * p)
{
	return p->ssn;
}

void ShowPerInfo(Person * p)
{
	printf("�ֹε�Ϲ�ȣ: %d \n", p->ssn);
	printf("�̸�: %s \n", p->name);
	printf("�ּ�: %s \n\n", p->addr);
}

Person * MakePersonData(int ssn, char * name, char * addr)
{
	Person * newP = (Person*)malloc(sizeof(Person));

	newP->ssn = ssn;
	strcpy_s(newP->name, strlen(name)+1, name);
	strcpy_s(newP->addr, strlen(addr)+1, addr);
	return newP;
}