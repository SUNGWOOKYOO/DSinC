// [Chap 10] ���� Sorting Algorithm �� ���� �˾ƺ���, Time complexity analysis�� �Ѵ�. 

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
			if (arr[j] > arr[j + 1])	// �ٽɿ��� :  n-1 + n-2 + n-3 + ... + 2 +1 �� �� ������ sorting �Ϸ� 
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
		maxIdx = i;    // ���� ������ ���� �ռ��� �������� index

		for (j = i + 1; j<n; j++)   // �ּҰ� Ž��
		{
			if (arr[j] < arr[maxIdx])	// �ּҰ����� ���� element�� �ִٸ�     T(n) = n-1 + n-2 + ... + 2 + 1
				maxIdx = j;				// �� element�� index�� �ּ� ���� index�� �ȴ�. 
		}

		/* ��ȯ ; bubble ���ĺ��� ������ �ణ ����; for�� �ۿ� ���Կ����� ��ġ*/
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

void InserSort(int arr[], int n) // data�� ������ ��ġ�� ã��, �� ��ġ�� ������ �ű�(�� ��ġ�� �������� arr[j + 1] = arr[j]; �� ��� �� ĭ �ڷ� ��)
{
	int i, j;
	int insData;

	for (i = 1; i<n; i++)
	{
		insData = arr[i];   // ���� ����� insData�� ����

		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] > insData)		
				arr[j + 1] = arr[j];    // �� ��� �� ĭ �ڷ� �б� ; T(n) = 1 + 2 + 3 + .. + n-2 + n-1
			else
				break;   // ���� ��ġ ã������ Ż��!
		}

		arr[j + 1] = insData;  // ã�� ��ġ(j+1)�� ���� ��� ����!
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
	Heap �ڷᱸ���� �̿��Ͽ� sorting�ϱ� ������ 
	�ڷᱸ�� ADT ����� ���� UsefulHeap.h, UsefulHeap.c �ʿ� ��Heapsort.c�� ������ �ϱ� ���ؼ��� data�� int�̾�� �Ѵ�. 
	T(n) = O(nlgn) ; �������� ������ Algorithm å�� ����	*/
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

	HeapInit(&heap, pc);	// pc�Լ��� �̿��Ͽ� �켱������ ������ Heap �ڷᱸ���� �����.

	// ���� ����� ������ ���� �����Ѵ�.
	for (i = 0; i<n; i++)
		HInsert(&heap, arr[i]);

	// ������� �ϳ��� ������ ������ �ϼ��Ѵ�.
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
	����� ������ ���� sorting 
	T(n) = O(nlgn)*/
#if 0
#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int fIdx = left;
	int rIdx = mid + 1;
	int i;

	// ������ ����� ���� �迭 sortArr�� �����Ҵ�
	int * sortArr = (int*)malloc(sizeof(int)*(right + 1)); // right�� �ε��� ���� �Ƿ� +1 �� �ؾ� �迭�� ũ�� 
	int sIdx = left;
	
	// 3���� case 

	//Case1; mixed 
	while (fIdx <= mid && rIdx <= right)
	{
		// ���� �� �� ������ �����͵��� ���Ͽ�, ���� ������� sortArr�� �ϳ��� �Ű� ��´�. 
		if (arr[fIdx] <= arr[rIdx])		// �ٽ��� �Ǵ� �񱳿���	�� combine �ܰ躰�� n���� data�� ���ؼ� n�� �񱳿���, ���� combine �� lgn Ƚ�� ��ŭ ���� 
			sortArr[sIdx] = arr[fIdx++];	
		else
			sortArr[sIdx] = arr[rIdx++];

		sIdx++;
	}

	//Case2; �迭 �պκ��� ��� sortArr�� �Ű����ٸ�,
	if (fIdx > mid)		
	{
		for (i = rIdx; i <= right; i++, sIdx++)
			sortArr[sIdx] = arr[i]; // �迭 �޺κп� ���� �����͵��� sortArr�� �״�� �ű��.
	}

	//Case3; �迭 �޺κ��� ��� sortArr�� �Ű����ٸ�,
	else
	{
		for (i = fIdx; i <= mid; i++, sIdx++)
			sortArr[sIdx] = arr[i];	// �迭 �պκп� ���� �����͵��� sortArr�� �״�� �ű��.
	}

	// �ӽ� �迭 sortArr �� ����� ������ ���θ� �̵�! 
	for (i = left; i <= right; i++)
		arr[i] = sortArr[i];

	free(sortArr);
}

void MergeSort(int arr[], int left, int right)
{
	int mid;

	if (left < right)
	{
		// �߰� ������ ����Ѵ�.
		mid = (left + right) / 2;

		// �ѷ� ������ ������ �����Ѵ�.
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		// ���ĵ� �� �迭�� �����Ѵ�.
		MergeTwoArea(arr, left, mid, right);
	}
}

int main(void)
{
	int arr[7] = { 3, 2, 4, 1, 7, 6, 5 };
	int i;

	// �迭 arr�� ��ü ���� ���� 
	MergeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

	for (i = 0; i<7; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}
#endif

/*	QuickSort.c 
	����� ������ ���� sorting
	E[T(n)] = O(nlgn)
	T(n) = O (n^2) , if worst case 
	However,  
	�������� �̵��� ������ ����, ������ �޸� ������ �䱸���� �ʾ� ȿ�����̴�.
	�񱳿����� �̿��� sorting �� �Ѱ�� O(nlgn) 
*/
#if 0
#include <stdio.h>

void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

#if 1 //�ڹ��� 10 - 1 ���� pivot �� worst case�� ���ϵ��� �ϱ� ���� ���� 
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

	int pivot = arr[left];    // �ǹ��� ��ġ�� ���� ����!
	int low = left + 1;
	int high = right;

	#else //�ڹ��� 10 - 1
	int pIdx = MedianOfThree(arr, left, right);   // �ǹ��� ����!
	int pivot = arr[pIdx];

	int low = left + 1;
	int high = right;

	Swap(arr, left, pIdx);    // �ǹ��� ���� �������� �̵�
	#endif

	printf("�ǹ�: %d \n", pivot); // �ǹ��� Ȯ���� ���ؼ� �߰��� ����

	while (low <= high)    // �������� ���� ������ �ݺ�
	{
		
		/* ������ �߻��� �� �ִ� �ڵ�! �迭 ���Ұ� ���� �Ҷ�! 
		while (pivot > arr[low])	// pivot���� ū ���� ã�� ����; �켱������ ���� �����͸� ���� ������ 
			low++;

		while (pivot < arr[high])	// pivot���� ���� ���� ã�� ����; �켱������ ���� �����͸� ���� ������
			high--;
		*/

//		/*	������ �߻��ϵ� �� ������ �� �ֵ��� ���� ����! 
		while(pivot >= arr[low] && low <= right)
		low++;

		while(pivot <= arr[high] && high >= (left+1))
		high--;
//		*/

		if (low <= high)    // �������� ���� ���¶�� Swap ����
			Swap(arr, low, high);    // low�� high�� ����Ű�� ��� ��ȯ
	}

	Swap(arr, left, high);    // �ǹ��� high�� ����Ű�� ��� ��ȯ
	return high;    // �Ű��� �ǹ��� ��ġ ���� ��ȯ
}

void QuickSort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right);    // ���ڸ��� ã�� �ǹ��� �ε����� ��ȯ 
		QuickSort(arr, left, pivot - 1);    // �ѷ� ������, ���� ������ ����
		QuickSort(arr, pivot + 1, right);    // ������ ������ ����
	}
}

int main(void)
{
	//int arr[7] = {3, 2, 4, 1, 7, 6, 5};
	//int arr[3] = { 3, 3, 3 }; // partition �Լ����� while���� �������ü� ����. why? ��� ���Ұ� ������ low <= high�� �׻� ���� �ǹǷ� 
	int arr[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}; // ���� 10-1 �־��� ��Ȳ ���� 

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
	� �迭�� sorting �� ��,
	List ��� Queue �ڷᱸ���� �̿��Ͽ� bucket�� �����ϰ� �̸� �̿��Ͽ� sorting�ϱ� ������ 
	�ڷᱸ�� ADT ����� ���� ListBaseQueue.h, ListBaseQueue.c �ʿ� ��RadixSort.c�� ������ �ϱ� ���ؼ��� data�� int�̾�� �Ѵ�. 
	T(n) = O(n) ; �������� ������ Algorithm å�� ����	*/
#if 1
#include <stdio.h>
#include "ListBaseQueue.h"

#define BUCKET_NUM		10

void RadixSort(int arr[], int num, int maxLen)   // maxLen�� ���� �� �������� ����
{
	Queue buckets[BUCKET_NUM];
	int bi;
	int pos;
	int di;
	int divfac = 1;
	int radix;

	// �� 10���� ��Ŷ �ʱ�ȭ
	for (bi = 0; bi<BUCKET_NUM; bi++)
		QueueInit(&buckets[bi]);

	// ���� �� �������� ���̸�ŭ �ݺ�
	for (pos = 0; pos<maxLen; pos++)
	{
		// ���� ����� ����ŭ �ݺ�
		for (di = 0; di<num; di++)
		{
			// N��° �ڸ��� ���� ����
			radix = (arr[di] / divfac) % 10;

			// ������ ���ڸ� �ٰŷ� ������ ��Ŷ�� ����
			Enqueue(&buckets[radix], arr[di]);
		}

		// ��Ŷ ����ŭ �ݺ�
		for (bi = 0, di = 0; bi<BUCKET_NUM; bi++)
		{
			// ��Ŷ�� ����� �� ������� �� ������ �ٽ� arr�� ����
			while (!QIsEmpty(&buckets[bi]))
				arr[di++] = Dequeue(&buckets[bi]);
		}

		// N��° �ڸ��� ���� ������ ���� �������� ����
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
