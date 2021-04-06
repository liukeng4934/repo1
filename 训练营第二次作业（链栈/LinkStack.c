#include<stdio.h>
#include"LinkStack.h"
#include<stdlib.h>
#define MAX_STR_SIZE 1024
#include<ctype.h>
int isValid(const char* str);
//清屏
void clear(){
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}  


//清空缓冲区
void EmptyBuff()
{
	char ch;
	while((ch=getchar())!=EOF&&ch!='\n')
		{
			;
		}
}


//判断操作是否成功
void Judge(Status flag)
{
	if(flag==ERROR)
		{
			printf("操作失败\n");
		}
	else
		{
			printf("操作成功\n");
		}
}


//用户选择菜单 
void menu(){
	printf("顺序栈操作选择：\n");
	printf("----------------------------------\n");
	printf("1.初始化栈                          ");
	printf("2.判断栈是否为空\n");
	printf("3.得到栈顶元素                      ");
	printf("4.清空栈\n"); 
	printf("5.销毁栈                            ");
	printf("6.检测栈长度\n");
	printf("7.入栈                              ");
	printf("8.出栈\n");
	printf("9.退出\n");
}

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







//链栈
//初始化栈
Status initLStack(LinkStack *s){
	if(s->top!=NULL){
		printf("栈已初始化\n");
		return ERROR;
	}
	else {
		s->top=(LinkStackPtr)malloc(sizeof(StackNode));
		if(s->top==NULL){
			printf("分配内存失败\n");
			return ERROR;
		}
		else {
			s->top->next=NULL;//头结点不存放数据 
			return SUCCESS;
		}
	}
}

//判断栈是否为空
Status isEmptyLStack(LinkStack *s){
	if(s->top==NULL){
		printf("未初始化栈\n");
		return ERROR;
	}
	else  if(s->count==0){
		printf("栈为空\n");
		return SUCCESS;
	}
	else if(s->count>0){
		printf("栈不为空\n");
		return SUCCESS;
	}
}

//得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType *e){
	if(s->top==NULL){
		printf("未初始化栈\n");
		return ERROR;
	}
	else  if(s->count==0){
		printf("栈为空\n");
		return ERROR;
	}
	else if(s->count>0){
		*e=s->top->data;
		printf("栈顶元素为:%d\n",*e);
		return SUCCESS;
	}
}

//清空栈
Status clearLStack(LinkStack *s){
	 LinkStackPtr p;//用于指向释放的空节点
	 if(s->top==NULL){
		printf("未初始化栈\n");
		return ERROR;
	}
	else  if(s->count==0){
		printf("栈为空\n");
		free(s->top);
		return ERROR;
	}
	else if(s->count>0){
		p=s->top;
		for(;s->top->next!=NULL;s->top=s->top->next){
			free(p);
			p=s->top;
		}
		s->count=0;
		return SUCCESS;
	}
}

//销毁栈
Status destroyLStack(LinkStack *s){
	LinkStackPtr p;//用于指向释放的空节点
	 if(s->top==NULL){
		printf("未初始化栈\n");
		return ERROR;
	}
	else  if(s->count==0){
		printf("栈为空\n");
		free(s->top);
		s->top=NULL;
		s->count=0;
		return SUCCESS;
	}
	else if(s->count>0){
		p=s->top;
		for(;s->top!=NULL;s->top=s->top->next){
			free(p);
			p=s->top;
		}
		s->top=NULL;
		s->count=0;
		return SUCCESS;
	}
}

//检测栈长度
Status LStackLength(LinkStack *s,int *length){
	 if(s->top==NULL){
		printf("未初始化栈\n");
		return ERROR;
	}
	else  if(s->count==0){
		printf("栈为空\n");
		free(s->top);
		return ERROR;
	}
	else if(s->count>0){
		printf("栈的长度为:%d\n",s->count);
		return SUCCESS;
	}
}

//入栈
Status pushLStack(LinkStack *s,ElemType data){
	if(s->top==NULL){
		printf("未初始化栈\n");
		return ERROR;
	}else {
		LinkStackPtr p;
		p=(LinkStackPtr)malloc(sizeof(StackNode));
		p->data=data;
		p->next=s->top;
		s->top=p;
		s->count++;
		return SUCCESS;
	}
}

//出栈
Status popLStack(LinkStack *s,ElemType *data){
	if(s->top==NULL){
		printf("未初始化栈\n");
		return ERROR;
	}else if(s->count==0){
		printf("栈为空\n");
		return ERROR;
	}else{
		LinkStackPtr p;
		p=s->top;
		*data=p->data;
		s->top=p->next;
		free(p);
		printf("出栈元素为:%d",*data);
		s->count--;
		return SUCCESS;
	}
}


