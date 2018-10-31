/* Rebalance ���� �Լ����� �����Ͽ���. �� �Լ����� �̿��Ͽ� AVLTree�� ������ �ϴµ� 
BinarySearchTree���� insert �� delete�� �Կ� �־ Rebalance ����� �ڵ����� �����ϵ��� �ϰڴ�. */
#include <stdio.h>
#include "BinaryTree.h"

// LL ȸ��
BTreeNode * RotateLL(BTreeNode * bst)
{
	BTreeNode * pNode;
	BTreeNode * cNode;

	// pNode��  cNode�� LLȸ���� ���� ������ ��ġ�� ����Ű�� �Ѵ�. 
	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	// ���� LL ȸ���� ����ϴ� 2���� ����
	ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
	ChangeRightSubTree(cNode, pNode);

	// LLȸ������ ���� ����� ��Ʈ ����� �ּ� �� ��ȯ 
	return cNode;
}

// RR ȸ��
BTreeNode * RotateRR(BTreeNode * bst)
{
	BTreeNode * pNode;
	BTreeNode * cNode;

	pNode = bst;
	cNode = GetRightSubTree(pNode);

	ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
	ChangeLeftSubTree(cNode, pNode);
	return cNode;
}

// RL ȸ��
BTreeNode * RotateRL(BTreeNode * bst)
{
	BTreeNode * pNode;
	BTreeNode * cNode;

	// pNode��  cNode�� RLȸ���� ���� ������ ��ġ�� ����Ű�� �Ѵ�. 
	pNode = bst;
	cNode = GetRightSubTree(pNode);

	// ���� RLȸ���� ����ϴ� 2���� ���� 
	ChangeRightSubTree(pNode, RotateLL(cNode));   // �κ��� LL ȸ��
	return RotateRR(pNode);     // RR ȸ��
}

// LR ȸ��
BTreeNode * RotateLR(BTreeNode * bst)
{
	BTreeNode * pNode;
	BTreeNode * cNode;

	pNode = bst;
	cNode = GetLeftSubTree(pNode);
	
	ChangeLeftSubTree(pNode, RotateRR(cNode));   // �κ��� RR ȸ��
	return RotateLL(pNode);     // LL ȸ��
}

// Ʈ���� ���̸� ����Ͽ� ��ȯ ; recursive call�� ���� ��� 
int GetHeight(BTreeNode * bst) 
{
	int leftH;		// left height
	int rightH;		// right height

	if(bst == NULL)
		return 0;

	// ���� ���� Ʈ�� ���� ���
	leftH = GetHeight(GetLeftSubTree(bst));

	// ������ ���� Ʈ�� ���� ���
	rightH = GetHeight(GetRightSubTree(bst));

	// ū ���� ���̸� ��ȯ�Ѵ�.
	if(leftH > rightH)
		return leftH + 1;
	else
		return rightH + 1;
}

// �� ���� Ʈ���� ������ ���� ��ȯ
int GetHeightDiff(BTreeNode * bst)
{
	int lsh;    // left sub tree height
	int rsh;    // right sub tree height

	if(bst == NULL)
		return 0;

	lsh = GetHeight(GetLeftSubTree(bst));	 //���� ����Ʈ���� ����
	rsh = GetHeight(GetRightSubTree(bst));	// ������ ����Ʈ���� ����

	return lsh - rsh;
}

// Ʈ���� ������ ��´�.
BTreeNode * Rebalance(BTreeNode ** pRoot)
{
	int hDiff = GetHeightDiff(*pRoot);	// �����μ� ��� 

	if(hDiff > 1)     // ���� ���� Ʈ�� �������� ���̰� 2 �̻� ũ�ٸ�
	{
		if(GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)	//LL���¶��,
			*pRoot = RotateLL(*pRoot);					//LLȸ��! 
		else											//LR���¶��,
			*pRoot = RotateLR(*pRoot);					//LRȸ��! 
	}
	
	if(hDiff < -1)     // ������ ���� Ʈ�� �������� 2 �̻� ũ�ٸ�
	{
		if(GetHeightDiff(GetRightSubTree(*pRoot)) < 0)
			*pRoot = RotateRR(*pRoot);
		else
			*pRoot = RotateRL(*pRoot);
	}
	
	return *pRoot;
}