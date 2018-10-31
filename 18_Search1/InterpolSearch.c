// [Chap11] Search1 

/* interpolSearch.c 
	선행조건 : input 배열은 sorting 되어 있어야 한다.
	recursive call을 통해 값을 찾는다. 
	mid 값을  A : Q = (high - low) : (s - low)  이용하여 구한다는 점을 제외하고는  BinarySearch와 비슷하다
	if(ar[first]>target || ar[last]<target) 구문을 사용해야 탈출조건을 만족시키지 못하는 무한루프의 상황을 피할 수 있다. 
	※ Array의 마지막 인덱스를 구하고 싶을때 : sizeof(arr)/sizeof(int)-1 */
#if 0
#include <stdio.h>

int ISearch(int ar[], int first, int last, int target)
{
	int mid;

#if 0 // 탐색 대상이 존재하지 않는경우, target에 저장된값이 first가 가리키는 값 보다 작아지거나, last가 가리키는 값보다 커지게 된다. 따라서 무한 재귀 루프에 빠진다
	if(first > last)
		return -1;    // -1의 반환은 탐색의 실패를 의미
#else
	if(ar[first]>target || ar[last]<target)	// 따라서 이렇게 바꿔야 제대로된 탈출조건이 완성된다.
		return -1;
#endif

	// 이진 탐색과의 차이점을 반영한 문장
	mid = ((double)(target-ar[first]) / (ar[last]-ar[first]) * (last-first)) + first;

	if(ar[mid] == target)
		return mid;    // 탐색된 타겟의 인덱스 값 반환
	else if(target < ar[mid])
		return ISearch(ar, first, mid-1, target);
	else
		return ISearch(ar, mid+1, last, target);
}

#if 1
int main(void)
{
	int arr[] = {1, 3, 5, 7, 9};
	int idx;
	
	idx = ISearch(arr, 0, sizeof(arr)/sizeof(int)-1, 7);
	if(idx == -1)
		printf("탐색 실패 \n");
	else
		printf("타겟 저장 인덱스: %d \n", idx);

	idx = ISearch(arr, 0, sizeof(arr)/sizeof(int)-1, 2);
	if(idx == -1)
		printf("탐색 실패 \n");
	else
		printf("타겟 저장 인덱스: %d \n", idx);

	return 0;
}

#else
int main(void)
{
	int arr[] = {1, 3, 5, 7, 9};
	int idx;
	
	idx = ISearch(arr, 0, sizeof(arr)/sizeof(int)-1, 2);
	if(idx == -1)
		printf("탐색 실패 \n");
	else
		printf("타겟 저장 인덱스: %d \n", idx);

	return 0;
}
#endif

#endif

/*	BinarySearchTreeMain.c
	아직 탐색트리의 insert와 search 만 구현되었고, 삭제는 구현되지 않았다. */
#if 0
#include <stdio.h>
#include "BinarySearchTree.h"

int main(void)
{
	BTreeNode * bstRoot;
	BTreeNode * sNode;    // search node

	BSTMakeAndInit(&bstRoot);

	BSTInsert(&bstRoot, 9);
	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 6);
	BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 8);
	//	BSTInsert(&bstRoot, 4);
	BSTInsert(&bstRoot, 3);
	BSTInsert(&bstRoot, 5);
	//	BSTInsert(&bstRoot, 7);

	sNode = BSTSearch(bstRoot, 1);
	if (sNode == NULL)
		printf("탐색 실패 \n");
	else
		printf("탐색에 성공한 키의 값: %d \n", BSTGetNodeData(sNode));

	sNode = BSTSearch(bstRoot, 4);
	if (sNode == NULL)
		printf("탐색 실패 \n");
	else
		printf("탐색에 성공한 키의 값: %d \n", BSTGetNodeData(sNode));

	sNode = BSTSearch(bstRoot, 6);
	if (sNode == NULL)
		printf("탐색 실패 \n");
	else
		printf("탐색에 성공한 키의 값: %d \n", BSTGetNodeData(sNode));

	sNode = BSTSearch(bstRoot, 7);
	if (sNode == NULL)
		printf("탐색 실패 \n");
	else
		printf("탐색에 성공한 키의 값: %d \n", BSTGetNodeData(sNode));

	return 0;
}
#endif


/*	BinarySearchTreeDelMain.c
	삭제과정의 구현			*/
#if 1
#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

int main(void)
{
	BTreeNode * bstRoot;
	BTreeNode * sNode;    // search node

	BSTMakeAndInit(&bstRoot);

	BSTInsert(&bstRoot, 5);
	BSTInsert(&bstRoot, 8);
	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 6);
	BSTInsert(&bstRoot, 4);
	BSTInsert(&bstRoot, 9);
	BSTInsert(&bstRoot, 3);
	BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 7);

	BSTShowAll(bstRoot); printf("\n");
	sNode = BSTRemove(&bstRoot, 3);
	free(sNode);

	BSTShowAll(bstRoot); printf("\n");
	sNode = BSTRemove(&bstRoot, 8);
	free(sNode);

	BSTShowAll(bstRoot); printf("\n");
	sNode = BSTRemove(&bstRoot, 1);
	free(sNode);

	BSTShowAll(bstRoot); printf("\n");
	sNode = BSTRemove(&bstRoot, 6);
	free(sNode);

	BSTShowAll(bstRoot); printf("\n");
	return 0;
}
#endif