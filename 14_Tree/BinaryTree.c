#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

BTreeNode * MakeBTreeNode(void)
{
	BTreeNode * nd = (BTreeNode*)malloc(sizeof(BTreeNode));

	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

BTData GetData(BTreeNode * bt)
{
	return bt->data;
}

void SetData(BTreeNode * bt, BTData data)
{
	bt->data = data;
}

BTreeNode * GetLeftSubTree(BTreeNode * bt)
{
	return bt->left;
}

BTreeNode * GetRightSubTree(BTreeNode * bt)
{
	return bt->right;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{
	if(main->left != NULL)	// Left 쪽으로 subtree가 존재한다면,
		free(main->left);	// 해당트리를 삭제하고

	main->left = sub;		// 새로운 왼쪽 subtree연결 
}

void MakeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
	if(main->right != NULL) // Right 쪽으로 subtree가 존재한다면, 
		free(main->right);	// 해당트리를 삭제하고

	main->right = sub;		// 새로운 왼쪽 subtree연결 
}

// ★용도에 따라 함수 포인터를 이용한 순회 기능 추가 
#if 1
void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;

	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}

void InorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;

	InorderTraverse(bt->left, action);
	action(bt->data);
	InorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;

	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);
}

// (★중요기능)문제 08-1 관련 DeleteTree 함수의 정의가 추가
void DeleteTree(BTreeNode * bt)
{
	if (bt == NULL)
		return;

	DeleteTree(bt->left);
	DeleteTree(bt->right);

	printf("del tree data: %d \n", bt->data);
	free(bt); //postorder traverse 방식으로 node의 free가 선언된다. 
}
#endif 
