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
	if(GetLChildIDX(idx) > ph->numOfData)    // �ڽ� ��尡 ���ٸ� (L child node�� idx > ph �� �ڷ�迭�� ����, �� ������ ����� �ε���)
		return 0;

	else if(GetLChildIDX(idx) == ph->numOfData)    // ���� �ڽ� ��尡 ������ �����(Left child node's index = ������ ����� index)
		return GetLChildIDX(idx);				  // ���� �ڽ� ����� index �� ��ȯ 

	else   // ���� �ڽ� ���� ������ �ڽ� ����� �켱������ �� -> �켱������ ����(pr ���� ������) child�� index �� ��ȯ 
	{
		if(ph->heapArr[GetLChildIDX(idx)].pr 
						> ph->heapArr[GetRChildIDX(idx)].pr)
			return GetRChildIDX(idx);
		else								// ������ �켱������ ���ų� ������ ���� ���
			return GetLChildIDX(idx);
	}
}

void HInsert(Heap * ph, HData data, Priority pr)
{
	int idx = ph->numOfData+1;		// �� ��尡 ����� index ���� idx�� ����
	HeapElem nelem = {pr, data};	// �� ����� ���� �� �ʱ�ȭ 

	// �� ��尡 ����� ��ġ�� ��Ʈ ����� ��ġ�� �ƴ϶�� while�� �ݺ� ; ���ο� ��尡 ����� ��ġ�� ã�� ���� 
	while(idx != 1)
	{
		if(pr < (ph->heapArr[GetParentIDX(idx)].pr)) // �� ����� �켱������ ���ٸ� 
		{
			// �θ� ��带 �� ���� ����, ������ ���� 
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			
			// �� ��带 �� ���� �ø�, �����δ� �ø��� �ʰ� �ε��� ���� ���� 
			idx = GetParentIDX(idx);
		}
		else		// �� ����� �켱 ������ ���� �ʴٸ� 
			break;
	}// while ���� ������ idx�� �켱 ������ ����� ���ο� ��尡 ����� ��ġ�� ����ȴ�. 
	
	ph->heapArr[idx] = nelem;		// �� ��带 idx ��ġ�� �����Ѵ�. 
	ph->numOfData += 1;				// data�� insert �Ҷ����� numOfData �� ���� 
}

HData HDelete(Heap * ph) // �켱�������� �� �����ؾ��ϹǷ� ���� �켱 ������ ���� ��带 �����ϰ�, Heap condition�� hold�Ѵ�. 
{
	HData retData = (ph->heapArr[1]).data;    // ������ ������ �ӽ� ����
	HeapElem lastElem = ph->heapArr[ph->numOfData];	// ���� ������ ����� �񱳸� ���� ����(����) ; LastElem�� ph �����ͷ� ���� �ϰԵ�		

	// �پƷ��� ���� parentIdx���� ������ ��尡 ����� ��ġ������ ����.
	int parentIdx = 1;    // ��Ʈ ��尡 ��ġ�ؾ��� Index �� ����
	int childIdx;

	// ��Ʈ ����� �켱������ ���� �ڽ� ��带 �������� �ݺ��� ���� -> ������ ����� �ùٸ� ��ġ(Heap �ڷᱸ�� ��Ģ�� �����ϴ�) ã�� ���� 
	while(childIdx = GetHiPriChildIDX(ph, parentIdx)) // �ڽ� ��尡 ���ٸ� childidx = 0 �ȴ� 
	{
		if(lastElem.pr <= ph->heapArr[childIdx].pr) // �ڹݺ��� Ż������: ������ ���(lastElem.pr)���� child ���(heapArr[].pr) �� (�켱���� ��) 
			break;									// ������ ����� �켱������ ������ Ż��! 

		// ������ ��庸�� child�� �켱������ ������, �񱳴���� ����� ��ġ�� �� Level �ø�, ������ �ø���. (child index�� parent index�� ��) 
		ph->heapArr[parentIdx] = ph->heapArr[childIdx]; 
		//������ ��尡 ����� ��ġ������ �� Level ����, ������ ������ �ʴ´�. 
		parentIdx = childIdx;  //��
	}// �ݺ��� Ż�� �ϸ�, parentIdx���� ������ ����� ��ġ������ �����


	ph->heapArr[parentIdx] = lastElem; // ������ ��� ���� Heap ������ �����ϴ� ���� ��ġ(�� parentidx)�� ���� 
	ph->numOfData -= 1;				   // node�� �ϳ� ����; ����� node �� -1 ���� 
	return retData;
}