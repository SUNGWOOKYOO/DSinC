#include "SimpleHeap.h"

void HeapInit(Heap * ph)
{
	ph->numOfData = 0;
}

int HIsEmpty(Heap * ph)
{
	if(ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx) 
{ 
	return idx/2; 
}

int GetLChildIDX(int idx) 
{ 
	return idx*2; 
}

int GetRChildIDX(int idx) 
{ 
	return GetLChildIDX(idx)+1; 
}

int GetHiPriChildIDX(Heap * ph, int idx)
{
	if(GetLChildIDX(idx) > ph->numOfData)    // 자식 노드가 없다면 (L child node의 idx > ph 힙 자료배열의 노드수, 즉 마지막 노드의 인덱스)
		return 0;

	else if(GetLChildIDX(idx) == ph->numOfData)    // 왼쪽 자식 노드가 마지막 노드라면(Left child node's index = 마지막 노드의 index)
		return GetLChildIDX(idx);				  // 왼쪽 자식 노드의 index 값 반환 

	else   // 왼쪽 자식 노드와 오른쪽 자식 노드의 우선순위를 비교 -> 우선순위가 높은(pr 값이 낮은쪽) child의 index 값 반환 
	{
		if(ph->heapArr[GetLChildIDX(idx)].pr 
						> ph->heapArr[GetRChildIDX(idx)].pr)
			return GetRChildIDX(idx);
		else								// 왼쪽이 우선순위가 높거나 양쪽이 같은 경우
			return GetLChildIDX(idx);
	}
}

void HInsert(Heap * ph, HData data, Priority pr)
{
	int idx = ph->numOfData+1;		// 새 노드가 저장될 index 값을 idx에 저장
	HeapElem nelem = {pr, data};	// 새 노드의 생성 및 초기화 

	// 새 노드가 저장될 위치가 루트 노드의 위치가 아니라면 while문 반복 ; 새로운 노드가 저장될 위치를 찾는 과정 
	while(idx != 1)
	{
		if(pr < (ph->heapArr[GetParentIDX(idx)].pr)) // 새 노드의 우선순위가 높다면 
		{
			// 부모 노드를 한 레벨 내림, 실제로 내림 
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			
			// 새 노드를 한 레벨 올림, 실제로는 올리지 않고 인덱스 값만 갱신 
			idx = GetParentIDX(idx);
		}
		else		// 새 노드의 우선 순위가 높지 않다면 
			break;
	}// while 문을 나가면 idx에 우선 순위를 고려한 새로운 노드가 저장될 위치가 저장된다. 
	
	ph->heapArr[idx] = nelem;		// 새 노드를 idx 위치에 저장한다. 
	ph->numOfData += 1;				// data를 insert 할때마다 numOfData 수 증가 
}

HData HDelete(Heap * ph) // 우선순위조건 를 만족해야하므로 가장 우선 순위가 높은 노드를 삭제하고, Heap condition을 hold한다. 
{
	HData retData = (ph->heapArr[1]).data;    // 삭제할 데이터 임시 저장
	HeapElem lastElem = ph->heapArr[ph->numOfData];	// 힙의 마지막 노드의 비교를 위한 저장(복사) ; LastElem을 ph 포인터로 변경 하게됨		

	// ☆아래의 변수 parentIdx에는 마지막 노드가 저장될 위치정보가 담긴다.
	int parentIdx = 1;    // 루트 노드가 위치해야할 Index 값 저장
	int childIdx;

	// 루트 노드의 우선순위가 높은 자식 노드를 시작으로 반복문 시작 -> 마지막 노드의 올바른 위치(Heap 자료구조 규칙을 만족하는) 찾는 과정 
	while(childIdx = GetHiPriChildIDX(ph, parentIdx)) // 자식 노드가 없다면 childidx = 0 된다 
	{
		if(lastElem.pr <= ph->heapArr[childIdx].pr) // ★반복문 탈출조건: 마지막 노드(lastElem.pr)와의 child 노드(heapArr[].pr) 비교 (우선순위 비교) 
			break;									// 마지막 노드의 우선순위가 높으면 탈출! 

		// 마지막 노드보다 child의 우선순위가 높으니, 비교대상의 노드의 위치는 한 Level 올림, 실제로 올린다. (child index가 parent index가 됨) 
		ph->heapArr[parentIdx] = ph->heapArr[childIdx]; 
		//마지막 노드가 저장될 위치정보를 한 Level 내림, 실제로 내리진 않는다. 
		parentIdx = childIdx;  //☆
	}// 반복문 탈출 하면, parentIdx에는 마지막 노드의 위치정보가 저장됨


	ph->heapArr[parentIdx] = lastElem; // 마지막 노드 값을 Heap 조건을 만족하는 최종 위치(☆ parentidx)에 저장 
	ph->numOfData -= 1;				   // node를 하나 삭제; 저장된 node 수 -1 감소 
	return retData;
}