#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define SUCCESS       1
#define ERROR	 0
 
 /*判断表达式是否有效*/
int isVaild(char str[]);
 
/* 定义结点结构体 */
struct node
{
	int data;
	struct node *next;
};
typedef struct node Node;
 
/* 定义栈结构体 */
struct stack
{
	Node *top;
	int count;
};
typedef struct stack Stack;

/* 初始化栈 */
int InitStack(Stack *S);

/* 判断栈空 */
int EmptyStack(Stack *S);

/* 入栈 */
int Push(Stack *S, int e);

/* 获取栈顶 */
int GetTop(Stack *S);

/* 自定义优先级 */
int Priority(char s);

/* 出栈 */
int Pop(Stack *S);






#endif 
