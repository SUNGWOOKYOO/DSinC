// implementation(구현부) 파일 ; 함수정의 (ADT가 정의 되어 있다)
#include <stdio.h>
#include "ArrayList.h"

void ListInit(List * plist) // 초기화
{
	(plist->numOfData) = 0; // 리스트에 저장된 데이터 수는 0!
	(plist->curPosition) = -1; // 현재 아무 위치도 가리키지 않음! (데이터의 참조가 진행되지 않았다; LFirst, LNext 함수가 참조해야할 배열의 위치 결정안됨)
}

void LInsert(List * plist, LData data)
{
	if(plist->numOfData > LIST_LEN)  // 더 이상 저장할 공간이 없다면(리스트 최대길이 초과)
	{
		puts("저장이 불가능합니다.");
		return;
	}

	plist->arr[plist->numOfData] = data; // 데이터 저장 
	(plist->numOfData)++; // 자장된 데이터의 수 증가 
}

int LFirst(List * plist, LData * pdata)
{
	if(plist->numOfData == 0) // 저장된 데이터가 하나도 없다면
		return FALSE;

	(plist->curPosition) = 0; // 참조 위치 초기화! 첫번째 데이터 참조를 의미! (curPosition=0)
	*pdata = plist->arr[0]; // pdata가 가리키는 공간에 데이터 저장 (arr의 자료형은 헤더의 정의를 따름; typedef xxx Ldata; Ldata arr[]로 선언됨)
	printf("LFirst 함수호출; 데이터 참조를 위한 초기화진행 성공! \n");
	return TRUE;
}

int LNext(List * plist, LData * pdata)
{
	if(plist->curPosition >= (plist->numOfData)-1)  // 더이상 참조할 데이터가 없다면
		return FALSE;

	(plist->curPosition)++; // 다음 참조위치를 위해 curPosition 증가                            - 
	*pdata = plist->arr[plist->curPosition]; // pdata가 가리키는 공간에 데이터 저장             - 이 2부분이 LFirst 랑 다른 부분 
	printf("LNext 함수호출; 참조된 데이터(첫번째 인자)의 다음 데이터가 2번자인자가 가르키는 메모리가 저장된다! \n");
	return TRUE;
}

//중요!!
LData LRemove(List * plist) // 최근 조회가 이뤄진(LFirst 와 LNext에 의해 참조가 이뤄진) 데이터를 삭제한다 
{ //조회가 이뤄진 리스트의 맴버 curPosition을 확인해서 조회가 이뤄진 데이터의 위치에 대해 삭제를 진행한다. 
	int rpos = plist->curPosition; // 삭제할 데이터의 인덱스 값 참조
	int num = plist->numOfData; 
	int i;
	LData rdata = plist->arr[rpos]; //삭제할 데이터를 임시로 저장

	// 삭제를 위한 데이터의 이동을 진행하는 반복문(삭제한 데이터를 기준으로 한칸씩 데이터를 앞으로 이동)
	for(i=rpos; i<num-1; i++) 
		plist->arr[i] = plist->arr[i+1];

	(plist->numOfData)--; //데이터의 수 감소
	(plist->curPosition)--; /* 중요: 삭제한 데이터를 제외하고 가장 최근 참조한 위치값이 curPosition이 되도록
	                                 참조위치를 하나 되돌린다( 삭제로 인해 비는 공간을 메우기위해 데이터를 한칸식 앞으로 이동시킴; detail은 p91에 있다.) */
	return rdata; //삭제된 데이터 반환
}

int LCount(List * plist)
{
	return plist->numOfData;
}