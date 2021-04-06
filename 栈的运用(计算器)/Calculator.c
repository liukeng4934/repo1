#include<stdio.h>
#include"Calculator.h"
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
/*判断表达式是否有效*/
int isVaild(char str[])
{	
	int right,left;//括号 
	right=left=0;
	int i;
	//int digit=0;
	for(i=0; i<strlen(str); i++)
		{
			if((str[i]<'0'||str[i]>'9')&&(str[i]!='/'&&str[i]!='*'&&str[i]!='+'&&str[i]!='-'&&str[i]!='('&&str[i]!=')'))//不是算术表达式的字符
				{
					return 0;
				}
			else//是计算表达式的字符
				{
					if(str[i]=='/'||str[i]=='*'||str[i]=='+'||str[i]=='-'){
						if(str[i+1]=='+'||str[i+1]=='-'||str[i+1]=='/'||str[i+1]=='*')
						{
							printf("连续运算符请加括号\n");
							return 0; 
						}
					}
					if(str[i]=='/'||str[i]=='*')
						{
							if(i==0)//运算符左右要有数字，除了+-(在没括号时 
								{
									return 0;
								}
								//有括号时 
							else if((str[i-1]<'0'||str[i-1]>'9')&&(str[i+1]>'0'||str[i+1]<'9'))//i!=0左边不是数字 
							{
								if(str[i-1]!=')')return 0;
							}
							else if((str[i-1]>'0'||str[i-1]<'9')&&(str[i+1]<'0'||str[i+1]>'9'))//i!=0右边不是数字 
							{
								if(str[i+1]!='(')return 0;
							}
							else if((str[i-1]<'0'||str[i-1]>'9')&&(str[i+1]<'0'||str[i+1]>'9'))//i!=0两边不是数字 
							{
								if(str[i+1]!='('&&str[i-1]!=')')return 0;
							}
						}
						//括号配对问题
						 if(str[i]=='(')
						 left++;
						 if(str[i]==')')
						 right++;
				}
			}
			if(left!=right){
				printf("括号不匹配\n");
				return 0;
			}
			return 1;
		}

	/* 初始化栈 */
	int InitStack(Stack *S)
	{
		S->top = NULL;
		S->count = 0;

		return SUCCESS;
	}

	/* 判断栈空 */
	int EmptyStack(Stack *S)
	{
		return (S->count == 0) ? SUCCESS : ERROR;
	}

	/* 进栈 */
	int Push(Stack *S, int e)
	{
		Node *p = (Node *)malloc(sizeof(Node));
		if(p == NULL)
			{
				return ERROR;
			}
		p->data = e;
		p->next = S->top;
		S->top = p;
		S->count++;

		return SUCCESS;
	}

	/* 获取栈顶 */
	int GetTop(Stack *S)
	{
		if(NULL == S->top)
			return ERROR;

		return (S->top->data);
	}

	/* 自定义优先级 */
	int Priority(char s)
	{
		switch(s)
			{
				case '(':				//括号优先级最高
					return 3;
				case '*':
				case '/':				//乘除次之
					return 2;
				case '+':
				case '-':				//加减最低
					return 1;
				default :
					return 0;
			}
	}

	/* 出栈 */
	int Pop(Stack *S)
	{
		int e;

		if (NULL == S->top)
			return ERROR;

		Node *p = S->top;
		e = p->data;
		S->top = p->next;
		free(p);
		S->count--;

		return e;
	}
