#include<stdio.h>
#include"Calculator.h"
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
/*�жϱ��ʽ�Ƿ���Ч*/
int isVaild(char str[])
{	
	int right,left;//���� 
	right=left=0;
	int i;
	//int digit=0;
	for(i=0; i<strlen(str); i++)
		{
			if((str[i]<'0'||str[i]>'9')&&(str[i]!='/'&&str[i]!='*'&&str[i]!='+'&&str[i]!='-'&&str[i]!='('&&str[i]!=')'))//�����������ʽ���ַ�
				{
					return 0;
				}
			else//�Ǽ�����ʽ���ַ�
				{
					if(str[i]=='/'||str[i]=='*'||str[i]=='+'||str[i]=='-'){
						if(str[i+1]=='+'||str[i+1]=='-'||str[i+1]=='/'||str[i+1]=='*')
						{
							printf("����������������\n");
							return 0; 
						}
					}
					if(str[i]=='/'||str[i]=='*')
						{
							if(i==0)//���������Ҫ�����֣�����+-(��û����ʱ 
								{
									return 0;
								}
								//������ʱ 
							else if((str[i-1]<'0'||str[i-1]>'9')&&(str[i+1]>'0'||str[i+1]<'9'))//i!=0��߲������� 
							{
								if(str[i-1]!=')')return 0;
							}
							else if((str[i-1]>'0'||str[i-1]<'9')&&(str[i+1]<'0'||str[i+1]>'9'))//i!=0�ұ߲������� 
							{
								if(str[i+1]!='(')return 0;
							}
							else if((str[i-1]<'0'||str[i-1]>'9')&&(str[i+1]<'0'||str[i+1]>'9'))//i!=0���߲������� 
							{
								if(str[i+1]!='('&&str[i-1]!=')')return 0;
							}
						}
						//�����������
						 if(str[i]=='(')
						 left++;
						 if(str[i]==')')
						 right++;
				}
			}
			if(left!=right){
				printf("���Ų�ƥ��\n");
				return 0;
			}
			return 1;
		}

	/* ��ʼ��ջ */
	int InitStack(Stack *S)
	{
		S->top = NULL;
		S->count = 0;

		return SUCCESS;
	}

	/* �ж�ջ�� */
	int EmptyStack(Stack *S)
	{
		return (S->count == 0) ? SUCCESS : ERROR;
	}

	/* ��ջ */
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

	/* ��ȡջ�� */
	int GetTop(Stack *S)
	{
		if(NULL == S->top)
			return ERROR;

		return (S->top->data);
	}

	/* �Զ������ȼ� */
	int Priority(char s)
	{
		switch(s)
			{
				case '(':				//�������ȼ����
					return 3;
				case '*':
				case '/':				//�˳���֮
					return 2;
				case '+':
				case '-':				//�Ӽ����
					return 1;
				default :
					return 0;
			}
	}

	/* ��ջ */
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
