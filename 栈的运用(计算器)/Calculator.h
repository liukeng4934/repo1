#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define SUCCESS       1
#define ERROR	 0
 
 /*�жϱ��ʽ�Ƿ���Ч*/
int isVaild(char str[]);
 
/* ������ṹ�� */
struct node
{
	int data;
	struct node *next;
};
typedef struct node Node;
 
/* ����ջ�ṹ�� */
struct stack
{
	Node *top;
	int count;
};
typedef struct stack Stack;

/* ��ʼ��ջ */
int InitStack(Stack *S);

/* �ж�ջ�� */
int EmptyStack(Stack *S);

/* ��ջ */
int Push(Stack *S, int e);

/* ��ȡջ�� */
int GetTop(Stack *S);

/* �Զ������ȼ� */
int Priority(char s);

/* ��ջ */
int Pop(Stack *S);






#endif 
