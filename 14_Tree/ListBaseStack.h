// ExpressionMain.c 에서 쓰기 위해 Stack 자료구조를 가져오기 위해 변형 (빨간점 2부분)
#ifndef __LB_STACK_H__
#define __LB_STACK_H__

#include "BinaryTree.h" // BTreeNode 의 선언이 BinaryTree.h 헤더에 있으므로

#define TRUE	1
#define FALSE	0

//typedef int Data;
typedef BTreeNode * Data; // Data를 BtreeNode type으로 쓰겠다. ★ ExpressionTree 관련 ADT 구현을 위해 필요하다. (스택 관련 연산필요)

typedef struct _node
{
	Data data;
	struct _node * next;
} Node;

typedef struct _listStack
{
	Node * head;
} ListStack;


typedef ListStack Stack; // List 기반 Stack 

void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);

void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);

#endif