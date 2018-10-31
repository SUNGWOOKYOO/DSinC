// implementation(������) ���� ; �Լ����� (ADT�� ���� �Ǿ� �ִ�)
#include <stdio.h>
#include "ArrayList.h"

void ListInit(List * plist) // �ʱ�ȭ
{
	(plist->numOfData) = 0; // ����Ʈ�� ����� ������ ���� 0!
	(plist->curPosition) = -1; // ���� �ƹ� ��ġ�� ����Ű�� ����! (�������� ������ ������� �ʾҴ�; LFirst, LNext �Լ��� �����ؾ��� �迭�� ��ġ �����ȵ�)
}

void LInsert(List * plist, LData data)
{
	if(plist->numOfData > LIST_LEN)  // �� �̻� ������ ������ ���ٸ�(����Ʈ �ִ���� �ʰ�)
	{
		puts("������ �Ұ����մϴ�.");
		return;
	}

	plist->arr[plist->numOfData] = data; // ������ ���� 
	(plist->numOfData)++; // ����� �������� �� ���� 
}

int LFirst(List * plist, LData * pdata)
{
	if(plist->numOfData == 0) // ����� �����Ͱ� �ϳ��� ���ٸ�
		return FALSE;

	(plist->curPosition) = 0; // ���� ��ġ �ʱ�ȭ! ù��° ������ ������ �ǹ�! (curPosition=0)
	*pdata = plist->arr[0]; // pdata�� ����Ű�� ������ ������ ���� (arr�� �ڷ����� ����� ���Ǹ� ����; typedef xxx Ldata; Ldata arr[]�� �����)
	printf("LFirst �Լ�ȣ��; ������ ������ ���� �ʱ�ȭ���� ����! \n");
	return TRUE;
}

int LNext(List * plist, LData * pdata)
{
	if(plist->curPosition >= (plist->numOfData)-1)  // ���̻� ������ �����Ͱ� ���ٸ�
		return FALSE;

	(plist->curPosition)++; // ���� ������ġ�� ���� curPosition ����                            - 
	*pdata = plist->arr[plist->curPosition]; // pdata�� ����Ű�� ������ ������ ����             - �� 2�κ��� LFirst �� �ٸ� �κ� 
	printf("LNext �Լ�ȣ��; ������ ������(ù��° ����)�� ���� �����Ͱ� 2�������ڰ� ����Ű�� �޸𸮰� ����ȴ�! \n");
	return TRUE;
}

//�߿�!!
LData LRemove(List * plist) // �ֱ� ��ȸ�� �̷���(LFirst �� LNext�� ���� ������ �̷���) �����͸� �����Ѵ� 
{ //��ȸ�� �̷��� ����Ʈ�� �ɹ� curPosition�� Ȯ���ؼ� ��ȸ�� �̷��� �������� ��ġ�� ���� ������ �����Ѵ�. 
	int rpos = plist->curPosition; // ������ �������� �ε��� �� ����
	int num = plist->numOfData; 
	int i;
	LData rdata = plist->arr[rpos]; //������ �����͸� �ӽ÷� ����

	// ������ ���� �������� �̵��� �����ϴ� �ݺ���(������ �����͸� �������� ��ĭ�� �����͸� ������ �̵�)
	for(i=rpos; i<num-1; i++) 
		plist->arr[i] = plist->arr[i+1];

	(plist->numOfData)--; //�������� �� ����
	(plist->curPosition)--; /* �߿�: ������ �����͸� �����ϰ� ���� �ֱ� ������ ��ġ���� curPosition�� �ǵ���
	                                 ������ġ�� �ϳ� �ǵ�����( ������ ���� ��� ������ �޿������ �����͸� ��ĭ�� ������ �̵���Ŵ; detail�� p91�� �ִ�.) */
	return rdata; //������ ������ ��ȯ
}

int LCount(List * plist)
{
	return plist->numOfData;
}