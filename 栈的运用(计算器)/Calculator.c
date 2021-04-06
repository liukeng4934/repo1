#include<stdio.h>
#include"Calculator.h"
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX_STR_SIZE 1024
//����ѡ��
int getNum()
{
	char str[MAX_STR_SIZE]= {0};
	int pick=0;
	fgets(str,MAX_STR_SIZE,stdin);//ע�⣬fges��ѻس��Խ��ַ����У����������������� 
	if(!isValid(str))
	{
		printf("����������ݲ����ϣ�����������\n");
		//EmptyBuff();//�Ѵ�����ݳ���
		pick=getNum();
	 } 
	else
	sscanf(str,"%d",&pick);
	return pick;
}



//�û�ֻ���������ּӿո����ֻ�����ֵ����� 
int isValid(const char* str)//�ж������Ƿ���Ч 
{
	int digit=0;//���ֳ��� 
	int isSpaceAppear=0;
	for(; *str; str++)
		{
			
			if(isspace(*str))		isSpaceAppear=1;
			//else if(*str=='-') sign=1;//����Ϊ�� �����ˡ�sscanf���Լ��ж���û�и��� 
			else if(!isdigit(*str))		return 0;
			else if(isdigit(*str)&&isSpaceAppear)	return 0;
			else if(isdigit(*str)){
				digit++;
				if(digit>4) { 
				printf("���ݹ���\n");
				return 0; 
			}
		}
	return 1;
}
}




void menu(){
	printf("���������ѡ��:\n");
	printf("1.������\n");
	printf("0.��������\n");
}
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
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	int calculator(){
	int flag=1;//�ж��������� 
	long long data=0;//���������� 
	Stack num, opt;
	char str[1000] = {0};
	int i = 0, tmp = 0, j;
 
	if (InitStack(&num) != SUCCESS || InitStack(&opt) !=SUCCESS)
	{
		printf("Init Failure!\n");
		exit(0);
	}
 
	printf("�����������ʽ:\n");
	gets(str);
 	if(!isVaild(str)){
 		printf("���ʽ������\n");
		 printf("����������\n");
		 return 0;
	 } 
	 
	 while (str[i] != '\0' || EmptyStack(&opt) != SUCCESS)//EmptyStack(&opt) != SUCCESSֱ��û���� 
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			if((i-1==0)&&(str[i-1]=='+'||str[i-1]=='-')){
				if(str[i-1]=='-')flag=-1;
				Pop(&opt);
			}
			else if((i-1!=0)&&(str[i-1]=='+'||str[i-1]=='-')&&(i-2!=0)&&(str[i-2]=='(')){
					if(str[i-1]=='-')flag=-1;
					Pop(&opt);
			}
			tmp = tmp *10 + str[i] -'0';
			i++;
			if(str[i] < '0' || str[i] > '9')
			{
				Push(&num, (tmp*flag));
				tmp = 0;
				flag=1;
			}
		}
		else
		{
			//��ջ������
			if((EmptyStack(&opt) == SUCCESS) || (GetTop(&opt) == '(' && str[i] != ')') ||
			Priority(str[i]) > Priority(GetTop(&opt))) 
			{
				Push(&opt, str[i]);
				i++;
				continue;
			}
 
			//��ջ������
			if (GetTop(&opt) == '(' && str[i] == ')')
			{
				Pop(&opt);
				i++;
				continue;
			}
 
			//��ջ����
			if ((str[i] != '\0' && EmptyStack(&opt) != SUCCESS) || (str[i] == ')' && GetTop(&opt)!= '(') || 
			Priority(str[i]) <= Priority(GetTop(&opt)))
			{
				switch (Pop(&opt))
				{
					case '+':
						data= Pop(&num) + Pop(&num);
						if(data>999999||data<-999999){
							printf("��������̫��\n");
							return 0; 
						}
						Push(&num,data);
						break;
					case '-':
						j = Pop(&num);
						data=Pop(&num) - j;
						if(data>999999||data<-999999){
							printf("��������̫��\n");
							return 0; 
						}
						Push(&num,data);
						break;
					case '*':
						data=Pop(&num) * Pop(&num);
						if(data>999999||data<-999999){
							printf("����̫��,�޷�����\n");
							return 0; 
						}
						Push(&num,data);
						break;
					case '/':
						j = Pop(&num);
						if(j==0){
							printf("����������0\n");
							return 0;
						}
						data=Pop(&num) / j;
						if(data>999999||data<-999999){
							printf("��������̫��\n");
							return 0; 
						}
						Push(&num, data);
						break;
				}
				continue;
			}
		}
	}
	printf("�����:%d\n",Pop(&num));
 	return 0;
}
