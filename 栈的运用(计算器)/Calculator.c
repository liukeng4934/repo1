#include<stdio.h>
#include"Calculator.h"
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX_STR_SIZE 1024
//输入选择
int getNum()
{
	char str[MAX_STR_SIZE]= {0};
	int pick=0;
	fgets(str,MAX_STR_SIZE,stdin);//注意，fges会把回车吃进字符串中！！！！！！！！！ 
	if(!isValid(str))
	{
		printf("你输入的数据不符合，请重新输入\n");
		//EmptyBuff();//把错的数据吃完
		pick=getNum();
	 } 
	else
	sscanf(str,"%d",&pick);
	return pick;
}



//用户只能输入数字加空格或者只有数字的数据 
int isValid(const char* str)//判断数据是否有效 
{
	int digit=0;//数字长度 
	int isSpaceAppear=0;
	for(; *str; str++)
		{
			
			if(isspace(*str))		isSpaceAppear=1;
			//else if(*str=='-') sign=1;//数据为负 多虑了。sscanf会自己判断有没有负号 
			else if(!isdigit(*str))		return 0;
			else if(isdigit(*str)&&isSpaceAppear)	return 0;
			else if(isdigit(*str)){
				digit++;
				if(digit>4) { 
				printf("数据过大\n");
				return 0; 
			}
		}
	return 1;
}
}




void menu(){
	printf("请输入你的选择:\n");
	printf("1.计算器\n");
	printf("0.结束程序\n");
}
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
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	int calculator(){
	int flag=1;//判断数据正负 
	long long data=0;//接收运算结果 
	Stack num, opt;
	char str[1000] = {0};
	int i = 0, tmp = 0, j;
 
	if (InitStack(&num) != SUCCESS || InitStack(&opt) !=SUCCESS)
	{
		printf("Init Failure!\n");
		exit(0);
	}
 
	printf("请输入计算表达式:\n");
	gets(str);
 	if(!isVaild(str)){
 		printf("表达式不符合\n");
		 printf("请重新输入\n");
		 return 0;
	 } 
	 
	 while (str[i] != '\0' || EmptyStack(&opt) != SUCCESS)//EmptyStack(&opt) != SUCCESS直到没符号 
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
			//进栈不运算
			if((EmptyStack(&opt) == SUCCESS) || (GetTop(&opt) == '(' && str[i] != ')') ||
			Priority(str[i]) > Priority(GetTop(&opt))) 
			{
				Push(&opt, str[i]);
				i++;
				continue;
			}
 
			//出栈不运算
			if (GetTop(&opt) == '(' && str[i] == ')')
			{
				Pop(&opt);
				i++;
				continue;
			}
 
			//出栈运算
			if ((str[i] != '\0' && EmptyStack(&opt) != SUCCESS) || (str[i] == ')' && GetTop(&opt)!= '(') || 
			Priority(str[i]) <= Priority(GetTop(&opt)))
			{
				switch (Pop(&opt))
				{
					case '+':
						data= Pop(&num) + Pop(&num);
						if(data>999999||data<-999999){
							printf("计算数据太大\n");
							return 0; 
						}
						Push(&num,data);
						break;
					case '-':
						j = Pop(&num);
						data=Pop(&num) - j;
						if(data>999999||data<-999999){
							printf("计算数据太大\n");
							return 0; 
						}
						Push(&num,data);
						break;
					case '*':
						data=Pop(&num) * Pop(&num);
						if(data>999999||data<-999999){
							printf("数据太大,无法计算\n");
							return 0; 
						}
						Push(&num,data);
						break;
					case '/':
						j = Pop(&num);
						if(j==0){
							printf("除数不能是0\n");
							return 0;
						}
						data=Pop(&num) / j;
						if(data>999999||data<-999999){
							printf("计算数据太大\n");
							return 0; 
						}
						Push(&num, data);
						break;
				}
				continue;
			}
		}
	}
	printf("结果是:%d\n",Pop(&num));
 	return 0;
}
