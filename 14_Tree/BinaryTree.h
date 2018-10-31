#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode * left;
	struct _bTreeNode * right;
} BTreeNode;

/*** BTreeNode 관련 연산들 ****/
BTreeNode * MakeBTreeNode(void);
BTData GetData(BTreeNode * bt);
void SetData(BTreeNode * bt, BTData data);

BTreeNode * GetLeftSubTree(BTreeNode * bt);
BTreeNode * GetRightSubTree(BTreeNode * bt);

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub);
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub);

// ★용도에 따라 함수 포인터를 이용한 순회 기능 추가 
#if 1
typedef void VisitFuncPtr(BTData data); //action 이 함수포인터로서 사용되기 때문에 Main문에서 정의하여 사용하면 된다. 

void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode * bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action);

//문제 08-1 관련 DeleteTree 함수(ADT)의 선언이 추가
void DeleteTree(BTreeNode * bt);
#endif 

#endif