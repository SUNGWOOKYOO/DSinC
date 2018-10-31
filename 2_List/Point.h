// Point 자료형을 위한 interface 부 ; 헤더파일 ; 클래스정의, 함수 선언
#ifndef __POINT_H__
#define __POINT_H__

typedef struct _point
{
	int xpos;
	int ypos;
} Point;

// Point 변수의 xpos, ypos 값 설정
void SetPointPos(Point * ppos, int xpos, int ypos);

// Point 변수의 xpos, ypos 정보 출력 
void ShowPointPos(Point * ppos);

// 두 Point 변수의 비교 
/*  멤버 xpos 만 같으면 1 반환
	멤버 ypos 만 같으면 2 반환
	멤버 모두 같으면 0 반환
	멤버 모두 다르면 -1 반환 */
int PointComp(Point * pos1, Point * pos2); 

#endif