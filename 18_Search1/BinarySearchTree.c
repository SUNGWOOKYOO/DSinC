#include <stdio.h>
#include "BinaryTree.h"	// 이전에 구현한 BinaryTree 자료구조를 이용하여 탐색에 용이 하게 쓸 수 있는 BinarySearchTree 자료구조를 구현하겠다. 
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

	// 새로운 노드가 추가될 위치를 찾는다. 
	while(cNode != NULL)
	{
		if(data == GetData(cNode))
			return;    // 키의 중복을 허용하지 않음; BST의 기본 규칙 위반 검사 

		pNode = cNode;

		if(GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);	// 넣고자 하는 data가 current node의 key보다 작은경우 Leftsubtree쪽으로 이동
		else
			cNode = GetRightSubTree(cNode); // 큰경우 Rightsubstree쪽으로 이동
	} // while 문을 나오면 cNode에는 새 노드가 저장될 위치정보가 담긴다. 

	
	// pNode의 서브 노드에 추가할 새 노드의 생성
	nNode = MakeBTreeNode();    // 새 노드의 생성
	SetData(nNode, data);    // 새 노드에 데이터 저장

	// pNode의 서브 노드에 새 노드를 추가
	if(pNode != NULL)    // 새 노드가 루트 노드가 아니라면,
	{
		if(data < GetData(pNode))			// 넣고자 하는 data가 pnode의 key보다 작은경우
			MakeLeftSubTree(pNode, nNode); // Leftsubtree쪽으로 이동 nNode를 연결
		else								// 넣고자 하는 data가 pnode의 key보다 큰 경우
			MakeRightSubTree(pNode, nNode);	// Rightsubtree쪽으로 이동 nNode를 연결
	}
	else    // 새 노드가 루트 노드라면,
	{
		*pRoot = nNode;
	}
}

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
	BTreeNode * cNode = bst;    // current node
	BSTData cd;    // current data

	while(cNode != NULL) // subtree를 따라 끝까지 탐색했는데 데이터가 없는 경우 탈출! 
	{
		cd = GetData(cNode);

		if(target == cd) // 탈출조건 
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
	// 삭제 대상이 루트 노드인 경우를 별도로 고려해야 한다.
	BTreeNode * pVRoot = MakeBTreeNode();    // 가상 루트 노드;

	BTreeNode * pNode = pVRoot;    // parent node
	BTreeNode * cNode = *pRoot;    // current node
	BTreeNode * dNode;    // delete node

						  // 루트 노드를 pVRoot가 가리키는 노드의 오른쪽 서브 노드가 되게 한다.
	ChangeRightSubTree(pVRoot, *pRoot);

	/* 삭제 대상을 저장한 노드 탐색 ; while문을 나가면 
	cNode는 가리키는 node가 삭제할 Data를 가진 노드가 되고, 
	pNode는 가리키는 node가 삭제할 노드의 Parent Node가 된다. */
	while (cNode != NULL && GetData(cNode) != target)
	{
		pNode = cNode;

		if (target < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	if (cNode == NULL)    // 삭제 대상이 존재하지 않는다면,
		return NULL;

	dNode = cNode;    // 삭제 대상을 dNode가 가리키게 한다.
	
	// [3가지 Case 삭제할 노드]
	// 첫 번째 경우: 삭제할 노드가 단말 노드인 경우
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
	{
		if (GetLeftSubTree(pNode) == dNode)	// 삭제할 노드가 왼쪽 자식노드라면, 
			RemoveLeftSubTree(pNode);		// 왼쪽 자식 노드 트리에서 제거
		else
			RemoveRightSubTree(pNode);
	}

	// 두 번째 경우: 하나의 자식 노드를 갖는 경우
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
	{
		BTreeNode * dcNode;    // delete node의 자식 노드

		// 삭제 대상을 대체할 자식 노드를 찾는다. 
		if (GetLeftSubTree(dNode) != NULL)	// 자식 노드가 왼쪽에 있다면, 
			dcNode = GetLeftSubTree(dNode);
		else								// 자식 노드가 오른쪽에 있다면 
			dcNode = GetRightSubTree(dNode);

		// 삭제대상의 부모 노드와 자식 노드를 연결한다.
		if (GetLeftSubTree(pNode) == dNode)	// 삭제 대상이 왼쪽 자식 노드이면, 
			ChangeLeftSubTree(pNode, dcNode);	// 왼쪽으로 연결 
		else									// 삭제 대상이 오른쪽 자식 노드이면, 
			ChangeRightSubTree(pNode, dcNode);	// 오른쪽으로 연결 
	}

	// 세 번째 경우: 두 개의 자식 노드를 모두 갖는 경우  ; ★ 대체노드를 통해서 값의 대입을 한다.  
	else
	{
		BTreeNode * mNode = GetRightSubTree(dNode);    // mininum node ; mNode는 대체노드를 가리킴, 오른쪽 subtree를 기준으로 하겠다. 
		BTreeNode * mpNode = dNode;    // mininum node의 부모 노드 ; mpNode는 대체 노드의 부모노드를 가리킴 
		int delData;

		// Step1. 삭제할 노드를 대체할 노드를 찾는다.
		// ; 삭제 할 노드의 오른쪽 subtree의 가장 왼쪽노드(삭제 노드보다 큰 최소값을 가진 노드)를 대체 노드로 한다.
		while (GetLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;						
			mNode = GetLeftSubTree(mNode);
		}// while문을 나가면, mNode는 대체 노드가 될 Node를 가리키게 되고, mpNode는 대체 노드의 부모노드를 가리키게 된다. 

		// Step2. 대체할 노드에 저장된 값을 삭제할 노드에 대입한다.
		delData = GetData(dNode);    // 대입 전 데이터 백업
		SetData(dNode, GetData(mNode));

		// Step3. 대체할 노드의 부모 노드와 자식 노드를 연결한다. (대체노드는 오른쪽 노드의 최솟값임을 기억! )
		if (GetLeftSubTree(mpNode) == mNode)					// 대체할 노드가 왼쪽 자식 노드라면 
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));	// 대체할 노드의 자식 노드를 부모노드의 왼쪽에 연결 (오른쪽 Subtree 밖에 있을 수 없다. 대체노드이기 떄문에)
		else													// 대체할 노드가 오른쪽 자식 노드라면 
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));	// 대체할 노드의 자식 노드를 부모노드의 오른쪽에 연결

		dNode = mNode;
		SetData(dNode, delData);    // 백업 데이터 복원
	}

	// 삭제된 노드가 루트 노드인 경우에 대한 처리
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