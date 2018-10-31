#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 밑의 2가지 헤더에 정의된 변수와 ADT를 사용하여 Expression Tree 관련 ADT를 구현하겠다. 
#include "ListBaseStack.h"
#include "BinaryTree.h"

BTreeNode * MakeExpTree(char exp[]) // postorder 방식의 Algorithm으로 생각하면 쉽다. 
{
	Stack stack;
	BTreeNode * pnode;

	int expLen = strlen(exp);
	int i;

	StackInit(&stack);

	for(i=0; i<expLen; i++)
	{
		pnode = MakeBTreeNode();

		if(isdigit(exp[i]))		// 피연산자라면...
		{
			SetData(pnode, exp[i]-'0');
		}
		else					// 연산자라면...
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
												
	if(GetLeftSubTree(bt)==NULL && GetRightSubTree(bt)==NULL)		// 재귀 함수 탈출조건: leaves(termination node) 라면
		return GetData(bt);											// 그 노드에 피연산자(숫자)를 반환한다. 

	// 재귀적인 연산을 통해 subtree 연산을 한다 
	op1 = EvaluateExpTree(GetLeftSubTree(bt));	// 첫 번째 피연산자 
	op2 = EvaluateExpTree(GetRightSubTree(bt));	// 두 번쨰 피연산자

	switch(GetData(bt))		// 연산자를 확인하여 연산을 진행
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

/* ★ Expression Tree 에 대해 Traverse 방식만 용도에 따라 함수 포인터를 이용한 순회 기능을 사용하면 
 notation을 쉽게 변경할 수 있다.*/
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

void ShowInfixTypeExp(BTreeNode * bt) // infixType에서는 순회하는 과정중에 '(', ')' 등의 표현이 필요!
									  //=> BinaryTree.c 에 정의된 inorderTraverse 불러오지 않고, 변형 필요
{
	if (bt == NULL)
		return;

	if (bt->left != NULL || bt->right != NULL)
		printf(" ( ");

	ShowInfixTypeExp(bt->left);		// 첫 번째 피연산자 출력
	ShowNodeData(bt->data);			// 연산자 출력
	ShowInfixTypeExp(bt->right);	// 두 번째 피연산자 출력

	if (bt->left != NULL || bt->right != NULL)
		printf(" ) ");
}

void ShowPostfixTypeExp(BTreeNode * bt)
{
	PostorderTraverse(bt, ShowNodeData);
}