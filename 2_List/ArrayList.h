/* 자료구조의 interface 부 ; 헤더파일 ; 클래스정의, 함수 선언
 잘 만들어진 3개 part에 대해서 헤더(interface부)를 추가 하고 헤더파일에 선언된 함수의 기능만 숙지한다면, 리스트의 구현을 알 필요없이 application부를 사용하기만 하면된다.
 추가나 변경할 자료형이 있는경우 선언부만 헤더파일(interface 부)을 약간 변경하고 (typedef 선언의 변경이 핵심이다.)
 단, 소스파일(implementation 부)은 변경해서는 안되도록 정의해야한다. */

#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#include "Point.h"     // Point 자료형 추가를 위한 첫 번째 변경(Point헤더추가 )
#include "NameCard.h"

#define TRUE	1
#define FALSE	0

/*** ArrayList의 정의 ****/
#define LIST_LEN	100

#if 1  // 핵심부분! 어떤 자료형을 사용사느냐에 따라 typedef으로 변경을 해준다 ; PointListMain문을 돌릴때는 첫번째꺼 사용, NameCardListMain문을 돌릴때는 2번째꺼 사용, 그 이외는 세번째꺼 사용.  
//typedef Point * LData;     // Point 자료형 추가를 위한 두 번째 변경(Point 헤더에 정의된 구조체를 부르기 위해 typedef선언; point * 를 LData로 지칭)
typedef NameCard * LData;
//typedef int LData; // LData에 대한 typedef선언 : int대신 double, float, string .. main문을 바꾸지 않고도, interface부의 변경을 통해 다른 자료형을 사용할 수 있다. 

#endif

typedef struct __ArrayList //배열 기반 리스트를 정의한 구조체 
{
	LData arr[LIST_LEN]; //리스트의 저장소인 배열(데이터의 저장공간이 int arr[] 배열로 선언되었다.)
	int numOfData; // 저장된 데이터수 
	int curPosition; // 데이터 참조 위치를 기록(가장최근에 참조가 이뤄진 데이터의 인덱스 정보)
} ArrayList;


/*** ArrayList와 관련된 연산들 ****/
typedef ArrayList List; // ArrayList 대신 LinkedList ... main문을 바꾸지 않고도, interface부의 변경을 통해 다른 list 형(structure)을 사용할 수 있다.

// List 자료구조의 ADT(abstract data type; 구체적인 기능의 완성과정은 언급하지 않고, 순수하게 그 기능이 무엇인지 나열한 것)
// p80 에 기능설명이 나열되어 있다.
void ListInit(List * plist);			//초기화
void LInsert(List * plist, LData data); //데이터저장

int LFirst(List * plist, LData * pdata);//첫 데이터 참조
int LNext(List * plist, LData * pdata);// 두 번째 이후 데이터 참조

LData LRemove(List * plist);			//참조한 데이터 삭제 ; 이때 반환하는 것은 소멸된 데이터; 그 이유는 p98에 나와있다.(ADT의 구현)
int LCount(List * plist);				//저장된 데이터 수 반환

#endif