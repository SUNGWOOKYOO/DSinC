// [Chap 10] 여러 Sorting Algorithm 에 대해 알아보고, Time complexity analysis를 한다. 

/*	BubbleSort.c ; Bubble sorting 
	T(n) = O(n^2) */
#if 0
#include <stdio.h>

void BubbleSort(int arr[], int n)
{
	int i, j;
	int temp;

	for (i = 0; i<n - 1; i++)
	{
		for (j = 0; j<(n - i) - 1; j++) 
		{
			if (arr[j] > arr[j + 1])	// 핵심연산 :  n-1 + n-2 + n-3 + ... + 2 +1 번 비교 연산후 sorting 완료 
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


int main(void)
{
	int arr[4] = { 3, 2, 4, 1 };
	int i;

	BubbleSort(arr, sizeof(arr) / sizeof(int));

	for (i = 0; i<4; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}
#endif 

/*  SelectionSort.c 
	T(n) = O(n^2) */
#if 0
#include <stdio.h>

void SelSort(int arr[], int n)
{
	int i, j;
	int maxIdx;
	int temp;

	for (i = 0; i<n - 1; i++)
	{
		maxIdx = i;    // 정렬 순서상 가장 앞서는 데이터의 index

		for (j = i + 1; j<n; j++)   // 최소값 탐색
		{
			if (arr[j] < arr[maxIdx])	// 최소값보다 작은 element가 있다면     T(n) = n-1 + n-2 + ... + 2 + 1
				maxIdx = j;				// 그 element의 index가 최소 값의 index가 된다. 
		}

		/* 교환 ; bubble 정렬보다 성능이 약간 좋다; for문 밖에 대입연산이 위치*/
		temp = arr[i];
		arr[i] = arr[maxIdx];
		arr[maxIdx] = temp;
	}
}


int main(void)
{
	int arr[4] = { 3, 4, 2, 1 };
	int i;

	SelSort(arr, sizeof(arr) / sizeof(int));

	for (i = 0; i<4; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}
#endif

 /*  InsertionSort.c
	T(n) = O(n^2)*/
#if 0
#include <stdio.h>

void InserSort(int arr[], int n) // data를 삽입할 위치를 찾고, 그 위치로 데이터 옮김(그 위치를 기준으로 arr[j + 1] = arr[j]; 비교 대상 한 칸 뒤로 밂)
{
	int i, j;
	int insData;

	for (i = 1; i<n; i++)
	{
		insData = arr[i];   // 정렬 대상을 insData에 저장

		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] > insData)		
				arr[j + 1] = arr[j];    // 비교 대상 한 칸 뒤로 밀기 ; T(n) = 1 + 2 + 3 + .. + n-2 + n-1
			else
				break;   // 삽입 위치 찾았으니 탈출!
		}

		arr[j + 1] = insData;  // 찾은 위치(j+1)에 정렬 대상 삽입!
	}
}


int main(void)
{
	int arr[5] = { 5, 3, 2, 4, 1 };
	int i;

	InserSort(arr, sizeof(arr) / sizeof(int));

	for (i = 0; i<5; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}
#endif

 /*  HeapSort.c
	Heap 자료구조를 이용하여 sorting하기 때문에 
	자료구조 ADT 사용을 위한 UsefulHeap.h, UsefulHeap.c 필요 ★Heapsort.c를 컴파일 하기 위해서는 data가 int이어야 한다. 
	T(n) = O(nlgn) ; 수학적인 증명은 Algorithm 책을 봐라	*/
#if 0
#include <stdio.h>
#include "UsefulHeap.h"

int PriComp(int n1, int n2)
{
	return n2 - n1;
	//	return n1-n2;
}

void HeapSort(int arr[], int n, PriorityComp pc)
{
	Heap heap;
	int i;

	HeapInit(&heap, pc);	// pc함수를 이용하여 우선순위를 설정한 Heap 자료구조를 만든다.

	// 정렬 대상을 가지고 힙을 구성한다.
	for (i = 0; i<n; i++)
		HInsert(&heap, arr[i]);

	// 순서대로 하나씩 꺼내서 정렬을 완성한다.
	for (i = 0; i<n; i++)
		arr[i] = HDelete(&heap);
}

int main(void)
{
	int arr[4] = { 3, 4, 2, 1 };
	int i;

	HeapSort(arr, sizeof(arr) / sizeof(int), PriComp);

	for (i = 0; i<4; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}

#endif

/*	MergeSort.c
	재귀적 연산을 통해 sorting 
	T(n) = O(nlgn)*/
#if 0
#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int fIdx = left;
	int rIdx = mid + 1;
	int i;

	// 병합한 결과를 담을 배열 sortArr의 동적할당
	int * sortArr = (int*)malloc(sizeof(int)*(right + 1)); // right는 인덱스 값이 므로 +1 을 해야 배열을 크기 
	int sIdx = left;
	
	// 3가지 case 

	//Case1; mixed 
	while (fIdx <= mid && rIdx <= right)
	{
		// 병합 할 두 영역의 데이터들을 비교하여, 정렬 순서대로 sortArr에 하나씩 옮겨 담는다. 
		if (arr[fIdx] <= arr[rIdx])		// 핵심이 되는 비교연산	각 combine 단계별로 n개의 data에 대해서 n번 비교연산, 또한 combine 은 lgn 횟수 만큼 있음 
			sortArr[sIdx] = arr[fIdx++];	
		else
			sortArr[sIdx] = arr[rIdx++];

		sIdx++;
	}

	//Case2; 배열 앞부분이 모두 sortArr에 옮겨졌다면,
	if (fIdx > mid)		
	{
		for (i = rIdx; i <= right; i++, sIdx++)
			sortArr[sIdx] = arr[i]; // 배열 뒷부분에 남는 데이터들을 sortArr에 그대로 옮긴다.
	}

	//Case3; 배열 뒷부분이 모두 sortArr에 옮겨졌다면,
	else
	{
		for (i = fIdx; i <= mid; i++, sIdx++)
			sortArr[sIdx] = arr[i];	// 배열 앞부분에 남는 데이터들을 sortArr에 그대로 옮긴다.
	}

	// 임시 배열 sortArr 에 저장된 데이터 전부를 이동! 
	for (i = left; i <= right; i++)
		arr[i] = sortArr[i];

	free(sortArr);
}

void MergeSort(int arr[], int left, int right)
{
	int mid;

	if (left < right)
	{
		// 중간 지점을 계산한다.
		mid = (left + right) / 2;

		// 둘로 나눠서 각각을 정렬한다.
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		// 정렬된 두 배열을 병합한다.
		MergeTwoArea(arr, left, mid, right);
	}
}

int main(void)
{
	int arr[7] = { 3, 2, 4, 1, 7, 6, 5 };
	int i;

	// 배열 arr의 전체 영역 정렬 
	MergeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

	for (i = 0; i<7; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}
#endif

/*	QuickSort.c 
	재귀적 연산을 통해 sorting
	E[T(n)] = O(nlgn)
	T(n) = O (n^2) , if worst case 
	However,  
	데이터의 이동이 현저히 적고, 별도의 메모리 공간을 요구하지 않아 효과적이다.
	비교연산을 이용한 sorting 의 한계는 O(nlgn) 
*/
#if 0
#include <stdio.h>

void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

#if 1 //★문제 10 - 1 에서 pivot 을 worst case를 피하도록 하기 위한 수단 
int MedianOfThree(int arr[], int left, int right)
{
	int samples[3] = { left, (left + right) / 2, right };

	if (arr[samples[0]] > arr[samples[1]])
		Swap(samples, 0, 1);

	if (arr[samples[1]] > arr[samples[2]])
		Swap(samples, 1, 2);

	if (arr[samples[0]] > arr[samples[1]])
		Swap(samples, 0, 1);

	return samples[1];
}
#endif

int Partition(int arr[], int left, int right)
{
	#if 1

	int pivot = arr[left];    // 피벗의 위치는 가장 왼쪽!
	int low = left + 1;
	int high = right;

	#else //★문제 10 - 1
	int pIdx = MedianOfThree(arr, left, right);   // 피벗을 선택!
	int pivot = arr[pIdx];

	int low = left + 1;
	int high = right;

	Swap(arr, left, pIdx);    // 피벗을 가장 왼쪽으로 이동
	#endif

	printf("피벗: %d \n", pivot); // 피벗의 확인을 위해서 추가할 문장

	while (low <= high)    // 교차되지 않을 때까지 반복
	{
		
		/* 문제가 발생할 수 있는 코드! 배열 원소가 동일 할때! 
		while (pivot > arr[low])	// pivot보다 큰 값을 찾는 과정; 우선순위가 낮은 데이터를 만날 때까지 
			low++;

		while (pivot < arr[high])	// pivot보다 작은 값을 찾는 과정; 우선순위가 높은 데이터를 만날 때까지
			high--;
		*/

//		/*	문제가 발생하도 잘 동작할 수 있도록 조건 수정! 
		while(pivot >= arr[low] && low <= right)
		low++;

		while(pivot <= arr[high] && high >= (left+1))
		high--;
//		*/

		if (low <= high)    // 교차되지 않은 상태라면 Swap 실행
			Swap(arr, low, high);    // low와 high가 가리키는 대상 교환
	}

	Swap(arr, left, high);    // 피벗과 high가 가리키는 대상 교환
	return high;    // 옮겨진 피벗의 위치 정보 반환
}

void QuickSort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right);    // 제자리를 찾은 피벗의 인덱스값 반환 
		QuickSort(arr, left, pivot - 1);    // 둘로 나눠서, 왼쪽 영역을 정렬
		QuickSort(arr, pivot + 1, right);    // 오른쪽 영역을 정렬
	}
}

int main(void)
{
	//int arr[7] = {3, 2, 4, 1, 7, 6, 5};
	//int arr[3] = { 3, 3, 3 }; // partition 함수에서 while문을 빠져나올수 없다. why? 모든 원소가 같으면 low <= high가 항상 참이 되므로 
	int arr[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}; // 문제 10-1 최악의 상황 연출 

	int len = sizeof(arr) / sizeof(int);
	int i;

	QuickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

	for (i = 0; i<len; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}
#endif

/*	RadixSort.c
	어떤 배열을 sorting 할 때,
	List 기반 Queue 자료구조를 이용하여 bucket을 구성하고 이를 이용하여 sorting하기 때문에 
	자료구조 ADT 사용을 위한 ListBaseQueue.h, ListBaseQueue.c 필요 ★RadixSort.c를 컴파일 하기 위해서는 data가 int이어야 한다. 
	T(n) = O(n) ; 수학적인 증명은 Algorithm 책을 봐라	*/
#if 1
#include <stdio.h>
#include "ListBaseQueue.h"

#define BUCKET_NUM		10

void RadixSort(int arr[], int num, int maxLen)   // maxLen은 가장 긴 데이터의 길이
{
	Queue buckets[BUCKET_NUM];
	int bi;
	int pos;
	int di;
	int divfac = 1;
	int radix;

	// 총 10개의 버킷 초기화
	for (bi = 0; bi<BUCKET_NUM; bi++)
		QueueInit(&buckets[bi]);

	// 가장 긴 데이터의 길이만큼 반복
	for (pos = 0; pos<maxLen; pos++)
	{
		// 정렬 대상의 수만큼 반복
		for (di = 0; di<num; di++)
		{
			// N번째 자리의 숫자 추출
			radix = (arr[di] / divfac) % 10;

			// 추출한 숫자를 근거로 데이터 버킷에 저장
			Enqueue(&buckets[radix], arr[di]);
		}

		// 버킷 수만큼 반복
		for (bi = 0, di = 0; bi<BUCKET_NUM; bi++)
		{
			// 버킷에 저장된 것 순서대로 다 꺼내서 다시 arr에 저장
			while (!QIsEmpty(&buckets[bi]))
				arr[di++] = Dequeue(&buckets[bi]);
		}

		// N번째 자리의 숫자 추출을 위한 피제수의 증가
		divfac *= 10;
	}
}

int main(void)
{
	int arr[7] = { 13, 212, 14, 7141, 10987, 6, 15 };

	int len = sizeof(arr) / sizeof(int);
	int i;

	RadixSort(arr, len, 5);

	for (i = 0; i<len; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}
#endif 
