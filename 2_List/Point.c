// Point 자료형을 위한 implementation(구현부) 파일 ; 함수정의 (ADT가 정의 되어 있다)
#include <stdio.h>
#include "Point.h"

void SetPointPos(Point * ppos, int xpos, int ypos)
{
	ppos->xpos = xpos;
	ppos->ypos = ypos;
}

void ShowPointPos(Point * ppos)
{
	printf("[%d, %d] \n", ppos->xpos, ppos->ypos);
}

int PointComp(Point * pos1, Point * pos2)
{
	if(pos1->xpos == pos2->xpos && pos1->ypos == pos2->ypos)
		return 0;
	else if(pos1->xpos == pos2->xpos)
		return 1;
	else if(pos1->ypos == pos2->ypos)
		return 2;
	else
		return -1;
}