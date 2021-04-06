#include <stdio.h>
#include <stdlib.h>
#include"Calculator.h"
int main(){
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

