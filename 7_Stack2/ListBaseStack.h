#ifndef __LB_STACK_H__
#define __LB_STACK_H__

#define TRUE	1
#define FALSE	0

typedef int Data;

typedef struct _node //연결 리스트의 노드를 표현한 구조체 
{
	Data data;
	struct _node * next;
} Node;

typedef struct _listStack // 연결 리스트 기반 스택을 표현한 구조체 
{
	Node * head;
} ListStack;


typedef ListStack Stack;

void StackInit(Stack * pstack); 
int SIsEmpty(Stack * pstack);

void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);

#endif