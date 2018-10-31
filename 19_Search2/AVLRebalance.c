/* Rebalance 관련 함수들을 정의하였다. 이 함수들을 이용하여 AVLTree의 구현을 하는데 
BinarySearchTree에서 insert 과 delete를 함에 있어서 Rebalance 기능을 자동으로 수행하도록 하겠다. */
#include <stdio.h>
#include "BinaryTree.h"

// LL 회전
BTreeNode * RotateLL(BTreeNode * bst)
{
	BTreeNode * pNode;
	BTreeNode * cNode;

	// pNode와  cNode가 LL회전을 위해 적절한 위치를 가리키게 한다. 
	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	// 실제 LL 회전을 담당하는 2개의 문장
	ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
	ChangeRightSubTree(cNode, pNode);

	// LL회전으로 인해 변경된 루트 노드의 주소 값 반환 
	return cNode;
}

// RR 회전
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

// RL 회전
BTreeNode * RotateRL(BTreeNode * bst)
{
	BTreeNode * pNode;
	BTreeNode * cNode;

	// pNode와  cNode가 RL회전을 위해 적절한 위치를 가리키게 한다. 
	pNode = bst;
	cNode = GetRightSubTree(pNode);

	// 실제 RL회전을 담당하는 2개의 문장 
	ChangeRightSubTree(pNode, RotateLL(cNode));   // 부분적 LL 회전
	return RotateRR(pNode);     // RR 회전
}

// LR 회전
BTreeNode * RotateLR(BTreeNode * bst)
{
	BTreeNode * pNode;
	BTreeNode * cNode;

	pNode = bst;
	cNode = GetLeftSubTree(pNode);
	
	ChangeLeftSubTree(pNode, RotateRR(cNode));   // 부분적 RR 회전
	return RotateLL(pNode);     // LL 회전
}

// 트리의 높이를 계산하여 반환 ; recursive call을 통해 계산 
int GetHeight(BTreeNode * bst) 
{
	int leftH;		// left height
	int rightH;		// right height

	if(bst == NULL)
		return 0;

	// 왼쪽 서브 트리 높이 계산
	leftH = GetHeight(GetLeftSubTree(bst));

	// 오른쪽 서브 트리 높이 계산
	rightH = GetHeight(GetRightSubTree(bst));

	// 큰 값의 높이를 반환한다.
	if(leftH > rightH)
		return leftH + 1;
	else
		return rightH + 1;
}

// 두 서브 트리의 높이의 차를 반환
int GetHeightDiff(BTreeNode * bst)
{
	int lsh;    // left sub tree height
	int rsh;    // right sub tree height

	if(bst == NULL)
		return 0;

	lsh = GetHeight(GetLeftSubTree(bst));	 //왼쪽 서브트리의 높이
	rsh = GetHeight(GetRightSubTree(bst));	// 오른쪽 서브트리의 높이

	return lsh - rsh;
}

// 트리의 균형을 잡는다.
BTreeNode * Rebalance(BTreeNode ** pRoot)
{
	int hDiff = GetHeightDiff(*pRoot);	// 균형인수 계산 

	if(hDiff > 1)     // 왼쪽 서브 트리 방향으로 높이가 2 이상 크다면
	{
		if(GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)	//LL상태라면,
			*pRoot = RotateLL(*pRoot);					//LL회전! 
		else											//LR상태라면,
			*pRoot = RotateLR(*pRoot);					//LR회전! 
	}
	
	if(hDiff < -1)     // 오른쪽 서브 트리 방향으로 2 이상 크다면
	{
		if(GetHeightDiff(GetRightSubTree(*pRoot)) < 0)
			*pRoot = RotateRR(*pRoot);
		else
			*pRoot = RotateRL(*pRoot);
	}
	
	return *pRoot;
}