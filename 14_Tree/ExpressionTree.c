#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ���� 2���� ����� ���ǵ� ������ ADT�� ����Ͽ� Expression Tree ���� ADT�� �����ϰڴ�. 
#include "ListBaseStack.h"
#include "BinaryTree.h"

BTreeNode * MakeExpTree(char exp[]) // postorder ����� Algorithm���� �����ϸ� ����. 
{
	Stack stack;
	BTreeNode * pnode;

	int expLen = strlen(exp);
	int i;

	StackInit(&stack);

	for(i=0; i<expLen; i++)
	{
		pnode = MakeBTreeNode();

		if(isdigit(exp[i]))		// �ǿ����ڶ��...
		{
			SetData(pnode, exp[i]-'0');
		}
		else					// �����ڶ��...
		{
			MakeRightSubTree(pnode, SPop(&stack));
			MakeLeftSubTree(pnode, SPop(&stack));
			SetData(pnode, exp[i]);
		}

		SPush(&stack, pnode);
	}

	return SPop(&stack);
}

int EvaluateExpTree(BTreeNode * bt)
{
	int op1, op2;
												
	if(GetLeftSubTree(bt)==NULL && GetRightSubTree(bt)==NULL)		// ��� �Լ� Ż������: leaves(termination node) ���
		return GetData(bt);											// �� ��忡 �ǿ�����(����)�� ��ȯ�Ѵ�. 

	// ������� ������ ���� subtree ������ �Ѵ� 
	op1 = EvaluateExpTree(GetLeftSubTree(bt));	// ù ��° �ǿ����� 
	op2 = EvaluateExpTree(GetRightSubTree(bt));	// �� ���� �ǿ�����

	switch(GetData(bt))		// �����ڸ� Ȯ���Ͽ� ������ ����
	{
	case '+':
		return op1+op2;
	case '-':
		return op1-op2;
	case '*':
		return op1*op2;
	case '/':
		return op1/op2;
	}

	return 0;
}

/* �� Expression Tree �� ���� Traverse ��ĸ� �뵵�� ���� �Լ� �����͸� �̿��� ��ȸ ����� ����ϸ� 
 notation�� ���� ������ �� �ִ�.*/
void ShowNodeData(int data)
{
	if(0<=data && data<=9)
		printf("%d ", data);
	else
		printf("%c ", data);
}

void ShowPrefixTypeExp(BTreeNode * bt)
{
	PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode * bt) // infixType������ ��ȸ�ϴ� �����߿� '(', ')' ���� ǥ���� �ʿ�!
									  //=> BinaryTree.c �� ���ǵ� inorderTraverse �ҷ����� �ʰ�, ���� �ʿ�
{
	if (bt == NULL)
		return;

	if (bt->left != NULL || bt->right != NULL)
		printf(" ( ");

	ShowInfixTypeExp(bt->left);		// ù ��° �ǿ����� ���
	ShowNodeData(bt->data);			// ������ ���
	ShowInfixTypeExp(bt->right);	// �� ��° �ǿ����� ���

	if (bt->left != NULL || bt->right != NULL)
		printf(" ) ");
}

void ShowPostfixTypeExp(BTreeNode * bt)
{
	PostorderTraverse(bt, ShowNodeData);
}