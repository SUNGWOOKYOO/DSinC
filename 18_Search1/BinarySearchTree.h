#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

// ������ ������ BinaryTree �ڷᱸ���� �̿��Ͽ� Ž���� ���� �ϰ� �� �� �ִ� BinarySearchTree �ڷᱸ���� �����ϰڴ�. 
#include "BinaryTree.h"	 //"BinaryTree2.h", "BinaryTree3.h"

typedef BTData	BSTData;

// BST�� ���� �� �ʱ�ȭ
void BSTMakeAndInit(BTreeNode ** pRoot);

// ��忡 ����� ������ ��ȯ
BSTData BSTGetNodeData(BTreeNode * bst);

// BST�� ������� ������ ����(����� �������� ����)
void BSTInsert(BTreeNode ** pRoot, BSTData data);

// BST�� ������� ������ Ž��
BTreeNode * BSTSearch(BTreeNode * bst, BSTData target);

//"BinarySearchTree2.h"
#if 1 

// Ʈ������ ��带 �����ϰ� ���ŵ� ����� �ּ� ���� ��ȯ�Ѵ�. 
BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target);

// ���� Ž�� Ʈ���� ����� ��� ����� �����͸� ����Ѵ�.
void BSTShowAll(BTreeNode * bst);

#endif

#endif