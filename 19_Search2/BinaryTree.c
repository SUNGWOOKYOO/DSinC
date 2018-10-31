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
	if(main->left != NULL)	// Left ������ subtree�� �����Ѵٸ�,
		free(main->left);	// �ش�Ʈ���� �����ϰ�

	main->left = sub;		// ���ο� ���� subtree���� 
}

void MakeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
	if(main->right != NULL) // Right ������ subtree�� �����Ѵٸ�, 
		free(main->right);	// �ش�Ʈ���� �����ϰ�

	main->right = sub;		// ���ο� ���� subtree���� 
}

// �ڿ뵵�� ���� �Լ� �����͸� �̿��� ��ȸ ��� �߰� ; BinaryTree2.c
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

// (���߿���)���� 08-1 ���� DeleteTree �Լ��� ���ǰ� �߰� 
#if 1
void DeleteTree(BTreeNode * bt)
{
	if (bt == NULL)
		return;

	DeleteTree(bt->left);
	DeleteTree(bt->right);

	printf("del tree data: %d \n", bt->data);
	free(bt); //postorder traverse ������� node�� free�� ����ȴ�. 
}
#endif 

#endif

// ��BinarySearchTree�� �����ϱ� ���� ADT ��� �߰� ; BinaryTree3.c
#if 1

BTreeNode * RemoveLeftSubTree(BTreeNode * bt)
{
	BTreeNode * delNode = NULL; // �ʱ�ȭ ���� ������ NULL ������ ����

	if (bt != NULL) {
		delNode = bt->left;
		bt->left = NULL;
	}
	return delNode;
}

BTreeNode * RemoveRightSubTree(BTreeNode * bt)
{
	BTreeNode * delNode = NULL; // �ʱ�ȭ ���� ������ NULL ������ ����

	if (bt != NULL) {
		delNode = bt->right;
		bt->right = NULL;
	}
	return delNode;
}

void ChangeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{
	main->left = sub;
}

void ChangeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
	main->right = sub;
}

#endif