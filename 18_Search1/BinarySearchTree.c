#include <stdio.h>
#include "BinaryTree.h"	// ������ ������ BinaryTree �ڷᱸ���� �̿��Ͽ� Ž���� ���� �ϰ� �� �� �ִ� BinarySearchTree �ڷᱸ���� �����ϰڴ�. 
#include "BinarySearchTree.h"

void BSTMakeAndInit(BTreeNode ** pRoot)
{
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode * bst)
{
	return GetData(bst);
}

void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
	BTreeNode * pNode = NULL;    // parent node
	BTreeNode * cNode = *pRoot;    // current node
	BTreeNode * nNode = NULL;    // new node

	// ���ο� ��尡 �߰��� ��ġ�� ã�´�. 
	while(cNode != NULL)
	{
		if(data == GetData(cNode))
			return;    // Ű�� �ߺ��� ������� ����; BST�� �⺻ ��Ģ ���� �˻� 

		pNode = cNode;

		if(GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);	// �ְ��� �ϴ� data�� current node�� key���� ������� Leftsubtree������ �̵�
		else
			cNode = GetRightSubTree(cNode); // ū��� Rightsubstree������ �̵�
	} // while ���� ������ cNode���� �� ��尡 ����� ��ġ������ ����. 

	
	// pNode�� ���� ��忡 �߰��� �� ����� ����
	nNode = MakeBTreeNode();    // �� ����� ����
	SetData(nNode, data);    // �� ��忡 ������ ����

	// pNode�� ���� ��忡 �� ��带 �߰�
	if(pNode != NULL)    // �� ��尡 ��Ʈ ��尡 �ƴ϶��,
	{
		if(data < GetData(pNode))			// �ְ��� �ϴ� data�� pnode�� key���� �������
			MakeLeftSubTree(pNode, nNode); // Leftsubtree������ �̵� nNode�� ����
		else								// �ְ��� �ϴ� data�� pnode�� key���� ū ���
			MakeRightSubTree(pNode, nNode);	// Rightsubtree������ �̵� nNode�� ����
	}
	else    // �� ��尡 ��Ʈ �����,
	{
		*pRoot = nNode;
	}
}

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
	BTreeNode * cNode = bst;    // current node
	BSTData cd;    // current data

	while(cNode != NULL) // subtree�� ���� ������ Ž���ߴµ� �����Ͱ� ���� ��� Ż��! 
	{
		cd = GetData(cNode);

		if(target == cd) // Ż������ 
			return cNode;
		else if(target < cd)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	} 

	return NULL;
}

//"BinarySearchTree2.c"
#if 1

BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target)
{
	// ���� ����� ��Ʈ ����� ��츦 ������ ����ؾ� �Ѵ�.
	BTreeNode * pVRoot = MakeBTreeNode();    // ���� ��Ʈ ���;

	BTreeNode * pNode = pVRoot;    // parent node
	BTreeNode * cNode = *pRoot;    // current node
	BTreeNode * dNode;    // delete node

						  // ��Ʈ ��带 pVRoot�� ����Ű�� ����� ������ ���� ��尡 �ǰ� �Ѵ�.
	ChangeRightSubTree(pVRoot, *pRoot);

	/* ���� ����� ������ ��� Ž�� ; while���� ������ 
	cNode�� ����Ű�� node�� ������ Data�� ���� ��尡 �ǰ�, 
	pNode�� ����Ű�� node�� ������ ����� Parent Node�� �ȴ�. */
	while (cNode != NULL && GetData(cNode) != target)
	{
		pNode = cNode;

		if (target < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	if (cNode == NULL)    // ���� ����� �������� �ʴ´ٸ�,
		return NULL;

	dNode = cNode;    // ���� ����� dNode�� ����Ű�� �Ѵ�.
	
	// [3���� Case ������ ���]
	// ù ��° ���: ������ ��尡 �ܸ� ����� ���
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
	{
		if (GetLeftSubTree(pNode) == dNode)	// ������ ��尡 ���� �ڽĳ����, 
			RemoveLeftSubTree(pNode);		// ���� �ڽ� ��� Ʈ������ ����
		else
			RemoveRightSubTree(pNode);
	}

	// �� ��° ���: �ϳ��� �ڽ� ��带 ���� ���
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
	{
		BTreeNode * dcNode;    // delete node�� �ڽ� ���

		// ���� ����� ��ü�� �ڽ� ��带 ã�´�. 
		if (GetLeftSubTree(dNode) != NULL)	// �ڽ� ��尡 ���ʿ� �ִٸ�, 
			dcNode = GetLeftSubTree(dNode);
		else								// �ڽ� ��尡 �����ʿ� �ִٸ� 
			dcNode = GetRightSubTree(dNode);

		// ��������� �θ� ���� �ڽ� ��带 �����Ѵ�.
		if (GetLeftSubTree(pNode) == dNode)	// ���� ����� ���� �ڽ� ����̸�, 
			ChangeLeftSubTree(pNode, dcNode);	// �������� ���� 
		else									// ���� ����� ������ �ڽ� ����̸�, 
			ChangeRightSubTree(pNode, dcNode);	// ���������� ���� 
	}

	// �� ��° ���: �� ���� �ڽ� ��带 ��� ���� ���  ; �� ��ü��带 ���ؼ� ���� ������ �Ѵ�.  
	else
	{
		BTreeNode * mNode = GetRightSubTree(dNode);    // mininum node ; mNode�� ��ü��带 ����Ŵ, ������ subtree�� �������� �ϰڴ�. 
		BTreeNode * mpNode = dNode;    // mininum node�� �θ� ��� ; mpNode�� ��ü ����� �θ��带 ����Ŵ 
		int delData;

		// Step1. ������ ��带 ��ü�� ��带 ã�´�.
		// ; ���� �� ����� ������ subtree�� ���� ���ʳ��(���� ��庸�� ū �ּҰ��� ���� ���)�� ��ü ���� �Ѵ�.
		while (GetLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;						
			mNode = GetLeftSubTree(mNode);
		}// while���� ������, mNode�� ��ü ��尡 �� Node�� ����Ű�� �ǰ�, mpNode�� ��ü ����� �θ��带 ����Ű�� �ȴ�. 

		// Step2. ��ü�� ��忡 ����� ���� ������ ��忡 �����Ѵ�.
		delData = GetData(dNode);    // ���� �� ������ ���
		SetData(dNode, GetData(mNode));

		// Step3. ��ü�� ����� �θ� ���� �ڽ� ��带 �����Ѵ�. (��ü���� ������ ����� �ּڰ����� ���! )
		if (GetLeftSubTree(mpNode) == mNode)					// ��ü�� ��尡 ���� �ڽ� ����� 
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));	// ��ü�� ����� �ڽ� ��带 �θ����� ���ʿ� ���� (������ Subtree �ۿ� ���� �� ����. ��ü����̱� ������)
		else													// ��ü�� ��尡 ������ �ڽ� ����� 
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));	// ��ü�� ����� �ڽ� ��带 �θ����� �����ʿ� ����

		dNode = mNode;
		SetData(dNode, delData);    // ��� ������ ����
	}

	// ������ ��尡 ��Ʈ ����� ��쿡 ���� ó��
	if (GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot);

	free(pVRoot);
	return dNode;
}

void ShowIntData(int data)
{
	printf("%d ", data);
}

void BSTShowAll(BTreeNode * bst)
{
	InorderTraverse(bst, ShowIntData);
}

#endif