// [Chap11] Search1 

/* interpolSearch.c 
	�������� : input �迭�� sorting �Ǿ� �־�� �Ѵ�.
	recursive call�� ���� ���� ã�´�. 
	mid ����  A : Q = (high - low) : (s - low)  �̿��Ͽ� ���Ѵٴ� ���� �����ϰ��  BinarySearch�� ����ϴ�
	if(ar[first]>target || ar[last]<target) ������ ����ؾ� Ż�������� ������Ű�� ���ϴ� ���ѷ����� ��Ȳ�� ���� �� �ִ�. 
	�� Array�� ������ �ε����� ���ϰ� ������ : sizeof(arr)/sizeof(int)-1 */
#if 0
#include <stdio.h>

int ISearch(int ar[], int first, int last, int target)
{
	int mid;

#if 0 // Ž�� ����� �������� �ʴ°��, target�� ����Ȱ��� first�� ����Ű�� �� ���� �۾����ų�, last�� ����Ű�� ������ Ŀ���� �ȴ�. ���� ���� ��� ������ ������
	if(first > last)
		return -1;    // -1�� ��ȯ�� Ž���� ���и� �ǹ�
#else
	if(ar[first]>target || ar[last]<target)	// ���� �̷��� �ٲ�� ����ε� Ż�������� �ϼ��ȴ�.
		return -1;
#endif

	// ���� Ž������ �������� �ݿ��� ����
	mid = ((double)(target-ar[first]) / (ar[last]-ar[first]) * (last-first)) + first;

	if(ar[mid] == target)
		return mid;    // Ž���� Ÿ���� �ε��� �� ��ȯ
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
		printf("Ž�� ���� \n");
	else
		printf("Ÿ�� ���� �ε���: %d \n", idx);

	idx = ISearch(arr, 0, sizeof(arr)/sizeof(int)-1, 2);
	if(idx == -1)
		printf("Ž�� ���� \n");
	else
		printf("Ÿ�� ���� �ε���: %d \n", idx);

	return 0;
}

#else
int main(void)
{
	int arr[] = {1, 3, 5, 7, 9};
	int idx;
	
	idx = ISearch(arr, 0, sizeof(arr)/sizeof(int)-1, 2);
	if(idx == -1)
		printf("Ž�� ���� \n");
	else
		printf("Ÿ�� ���� �ε���: %d \n", idx);

	return 0;
}
#endif

#endif

/*	BinarySearchTreeMain.c
	���� Ž��Ʈ���� insert�� search �� �����Ǿ���, ������ �������� �ʾҴ�. */
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
		printf("Ž�� ���� \n");
	else
		printf("Ž���� ������ Ű�� ��: %d \n", BSTGetNodeData(sNode));

	sNode = BSTSearch(bstRoot, 4);
	if (sNode == NULL)
		printf("Ž�� ���� \n");
	else
		printf("Ž���� ������ Ű�� ��: %d \n", BSTGetNodeData(sNode));

	sNode = BSTSearch(bstRoot, 6);
	if (sNode == NULL)
		printf("Ž�� ���� \n");
	else
		printf("Ž���� ������ Ű�� ��: %d \n", BSTGetNodeData(sNode));

	sNode = BSTSearch(bstRoot, 7);
	if (sNode == NULL)
		printf("Ž�� ���� \n");
	else
		printf("Ž���� ������ Ű�� ��: %d \n", BSTGetNodeData(sNode));

	return 0;
}
#endif


/*	BinarySearchTreeDelMain.c
	���������� ����			*/
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