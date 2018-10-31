/* [Chap 8] Tree 
 Tree �ڷᱸ���� ADT ��뿡 �־� ���� �ڷᱸ���� �ణ �ٸ���. 
 BinaryTree.c �� ������ �Լ����� Traversal ����� ����Ͽ� ����� ������ ���� �������� �ʾҴ�. */
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
Traversal ��ȸ ����� ��������� ������ */
#if 0 
#include <stdio.h>
#include "BinaryTree.h"

void InorderTraverse(BTreeNode * bt) //�� ��ȸ����
{
	if (bt == NULL)    // bt�� NULL�̸� ��� Ż��! 
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
 typedef �Լ������� ����� Ȱ���Ͽ� ��ȸ ������ �´� �Լ��� ���Ǹ� �Ѵٸ� ��� �湮 ������ ������ �� �ֵ��� �� 
 �� �Լ� ������ VisitFunctionPtr �� ����� �����ѵ�, Main������ �̸� �����Ͽ� �뵵�� �°� ����� �� �ִ�
 BinaryTree.h �� BinaryTree.c �� ��ȸ����� ���� �޺κ��� ������ */
#if 0
#include <stdio.h>
#include "BinaryTree.h"

void ShowIntData(int data); // Travere ������ �´� �Լ��� ����ڰ� �����Ͽ� ����� �� �ִ�.

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

/* ���� 08-1
Binary tree���� ���� �Ҵ�� node�� free������ traverse �ϰ� ������ �ǵ��� �ؾ��Ѵ�! */
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

	DeleteTree(bt1); // postorder Traverse ������� ���� �Ҵ�� ��尡 �������. ; ���Ǻ� ���� 
	return 0;
}

void ShowIntData(int data)
{
	printf("%d ", data);
}

#endif

/* ExpressionTreeMain.c  +  ���� 08-2 (inorder ������� ������ '(' ')' ǥ���� ����ϱ� ���� ������ ó���ʿ� )
 ExpressionTree�� �����ϴ� �Լ��� traverse ��Ŀ� ���� infix, prefix, postfix notation���� ��ȯ�ϱ� ���� 
 ExpressionTree.c �� ExpressionTree.h �� ���� stack ����, Tree ���� interface ���ϰ� implementation ������ �̿��Ͽ�
 �����Ͽ���.
 - ����Ʈ������							BinaryTree.h		BinaryTree.c							
 - ���ð���								ListBaseStack.h		ListBaseStack.c
 - ����Ʈ������(���� 2���� ���� �̿�)   ExpressionTress.h	ExpressionTree.c   */
#if 1
#include <stdio.h>
#include "ExpressionTree.h"

int main(void)
{
	char exp[] = "12+7*";
	BTreeNode * eTree = MakeExpTree(exp);

	printf("���� ǥ����� ����: ");
	ShowPrefixTypeExp(eTree); printf("\n");

	printf("���� ǥ����� ����: ");
	ShowInfixTypeExp(eTree); printf("\n");

	printf("���� ǥ����� ����: ");
	ShowPostfixTypeExp(eTree); printf("\n");

	printf("������ ���: %d \n", EvaluateExpTree(eTree));

	return 0;
}
#endif

