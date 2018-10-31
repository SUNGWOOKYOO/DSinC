#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode * left;
	struct _bTreeNode * right;
} BTreeNode;

/*** BTreeNode ���� ����� ****/
BTreeNode * MakeBTreeNode(void);
BTData GetData(BTreeNode * bt);
void SetData(BTreeNode * bt, BTData data);

BTreeNode * GetLeftSubTree(BTreeNode * bt);
BTreeNode * GetRightSubTree(BTreeNode * bt);

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub);
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub);

// �ڿ뵵�� ���� �Լ� �����͸� �̿��� ��ȸ ��� �߰� 
#if 1
typedef void VisitFuncPtr(BTData data); //action �� �Լ������ͷμ� ���Ǳ� ������ Main������ �����Ͽ� ����ϸ� �ȴ�. 

void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode * bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action);

//���� 08-1 ���� DeleteTree �Լ�(ADT)�� ������ �߰�
void DeleteTree(BTreeNode * bt);
#endif 

#endif