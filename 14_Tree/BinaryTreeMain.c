/* [Chap 8] Tree 
 Tree 자료구조는 ADT 사용에 있어 이전 자료구조랑 약간 다르다. 
 BinaryTree.c 에 구현된 함수에서 Traversal 기능을 사용하여 노드의 삭제는 아직 구현되지 않았다. */
#if 0
#include <stdio.h>
#include "BinaryTree.h"

int main(void)
{
	BTreeNode * bt1 = MakeBTreeNode();
	BTreeNode * bt2 = MakeBTreeNode();
	BTreeNode * bt3 = MakeBTreeNode();
	BTreeNode * bt4 = MakeBTreeNode();

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);

	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);

	printf("%d \n",
		GetData(GetLeftSubTree(bt1)));
	printf("%d \n",
		GetData(GetLeftSubTree(GetLeftSubTree(bt1))));

	return 0;
}
#endif

/* BinaryTreeTraverseMain.c
Traversal 순회 방법을 재귀적으로 구현함 */
#if 0 
#include <stdio.h>
#include "BinaryTree.h"

void InorderTraverse(BTreeNode * bt) //★ 순회과정
{
	if (bt == NULL)    // bt가 NULL이면 재귀 탈출! 
		return;

	InorderTraverse(bt->left);
	printf("%d \n", bt->data);
	InorderTraverse(bt->right);
}

int main(void)
{
	BTreeNode * bt1 = MakeBTreeNode();
	BTreeNode * bt2 = MakeBTreeNode();
	BTreeNode * bt3 = MakeBTreeNode();
	BTreeNode * bt4 = MakeBTreeNode();

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);

	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);

	InorderTraverse(bt1);
	return 0;
}
#endif 

/* BinaryTreeTraverseMain2.c 
 typedef 함수포인터 기능을 활용하여 순회 목적에 맞는 함수의 정의만 한다면 노드 방문 목적을 수행할 수 있도록 함 
 ★ 함수 포인터 VisitFunctionPtr 를 헤더에 선언한뒤, Main문에서 이를 정의하여 용도에 맞게 사용할 수 있다
 BinaryTree.h 와 BinaryTree.c 에 순회기능을 위해 뒷부분을 변경함 */
#if 0
#include <stdio.h>
#include "BinaryTree.h"

void ShowIntData(int data); // Travere 목적에 맞는 함수를 사용자가 정의하여 사용할 수 있다.

int main(void)
{
	BTreeNode * bt1 = MakeBTreeNode();
	BTreeNode * bt2 = MakeBTreeNode();
	BTreeNode * bt3 = MakeBTreeNode();
	BTreeNode * bt4 = MakeBTreeNode();
	BTreeNode * bt5 = MakeBTreeNode();
	BTreeNode * bt6 = MakeBTreeNode();

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);
	SetData(bt5, 5);
	SetData(bt6, 6);

	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);
	MakeRightSubTree(bt2, bt5);
	MakeRightSubTree(bt3, bt6);

	PreorderTraverse(bt1, ShowIntData);
	printf("\n");
	InorderTraverse(bt1, ShowIntData);
	printf("\n");
	PostorderTraverse(bt1, ShowIntData);
	printf("\n");

	return 0;
}

void ShowIntData(int data)
{
	printf("%d ", data);
}

#endif 

/* 문제 08-1
Binary tree에서 동적 할당된 node의 free선언이 traverse 하게 선언이 되도록 해야한다! */
#if 0 
#include <stdio.h>
#include "BinaryTree.h"

void ShowIntData(int data);

int main(void)
{
	BTreeNode * bt1 = MakeBTreeNode();
	BTreeNode * bt2 = MakeBTreeNode();
	BTreeNode * bt3 = MakeBTreeNode();
	BTreeNode * bt4 = MakeBTreeNode();
	BTreeNode * bt5 = MakeBTreeNode();
	BTreeNode * bt6 = MakeBTreeNode();

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);
	SetData(bt5, 5);
	SetData(bt6, 6);

	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);
	MakeRightSubTree(bt2, bt5);
	MakeRightSubTree(bt3, bt6);

	PreorderTraverse(bt1, ShowIntData);
	printf("\n");
	InorderTraverse(bt1, ShowIntData);
	printf("\n");
	PostorderTraverse(bt1, ShowIntData);
	printf("\n");

	DeleteTree(bt1); // postorder Traverse 방식으로 동적 할당된 노드가 사라진다. ; 정의부 참조 
	return 0;
}

void ShowIntData(int data)
{
	printf("%d ", data);
}

#endif

/* ExpressionTreeMain.c  +  문제 08-2 (inorder 방식으로 했을때 '(' ')' 표현을 고려하기 위해 예외적 처리필요 )
 ExpressionTree를 구성하는 함수와 traverse 방식에 따라 infix, prefix, postfix notation으로 변환하기 위해 
 ExpressionTree.c 와 ExpressionTree.h 를 이전 stack 관련, Tree 관련 interface 파일과 implementation 파일을 이용하여
 구성하였다.
 - 이진트리관련							BinaryTree.h		BinaryTree.c							
 - 스택관련								ListBaseStack.h		ListBaseStack.c
 - 수식트리관련(위의 2가지 관련 이용)   ExpressionTress.h	ExpressionTree.c   */
#if 1
#include <stdio.h>
#include "ExpressionTree.h"

int main(void)
{
	char exp[] = "12+7*";
	BTreeNode * eTree = MakeExpTree(exp);

	printf("전위 표기법의 수식: ");
	ShowPrefixTypeExp(eTree); printf("\n");

	printf("중위 표기법의 수식: ");
	ShowInfixTypeExp(eTree); printf("\n");

	printf("후위 표기법의 수식: ");
	ShowPostfixTypeExp(eTree); printf("\n");

	printf("연산의 결과: %d \n", EvaluateExpTree(eTree));

	return 0;
}
#endif

