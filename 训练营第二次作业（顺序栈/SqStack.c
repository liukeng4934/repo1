#include<stdio.h>
#include"SqStack.h"
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


/*
//获取用户输入的数据
int getNum(){
	/*int error=0;//判断数据是否错误 
	char str[1024]={0};
	printf("请输入你的数据\n");
	fgets(str,1024,stdin);
	char *p=str;
	int acc=0;//用来判断数据是否溢出 
	int neg=0,add;//acc判断是否为负数。add用来接收数字 
	while(*p==' '){
		++p;
	} 
	if(*p=='-'){
		neg=1;
		++p;
	}
	else if(*p=='+'){
		++p;
	}
	while(*p){
		if(*p!='\n'&&(*p<'0'||*p>'9')){
			printf("你输入的数据不符合要求，请输入整型数据\n");
			error=1; 
			break;
		}
		add=*p-'0';
		if(acc>INT_MAX/10){
			printf("数据溢出，返回最大(小)值\n");
			return neg? INT_MIN:INT_MAX;
		}else if(acc==INT_MAX/10){
			if(neg&&add>8){
			printf("数据溢出，返回最小值\n");
				return INT_MIN;
			}//int占用4字节的话，最小值个位数是8. 
		
			if(!neg&&add>7){
				printf("数据溢出，返回最大值\n");
				return INT_MAX;}//同上，个位数是7 
			
		}
		acc=10*acc+add;
		++p;
	}
	if(neg)
	acc=-acc;
	if(error==1){
	acc=getNum();
	}
	return acc;
}
*/
//基于数组的顺序栈
//初始化栈

Status initStack(SqStack *s,int sizes){
	if(s->elem)
		{
			printf("已经初始化过栈.\n");
			return ERROR;
		}
		if(sizes<=0){
			printf("数据有误，无法创建数组，请输入大于0的整数\n");
			return ERROR;
		}
	s->elem=NULL;
	s->elem=(ElemType*)malloc(sizeof(ElemType)*sizes);
	if(s->elem){
		printf("数组内存申请成功\n");
	}
	else {
		printf("数组分配内存失败\n");
		return ERROR;
	}
	s->size=sizes;
	s->top=-1;
	printf("栈初始化完成.\n");
	return  SUCCESS;
}


//判断栈是否为空
Status isEmptyStack(SqStack *s){
	if(s->elem==NULL){
		printf("未初始化栈\n");
		return SUCCESS; 
	}
	else {
		if(s->top==-1){
			printf("栈为空\n");
			return SUCCESS;
		}
		else {
			printf("栈不为空\n");
			return SUCCESS;
		}
	}
}

//得到栈顶元素
Status getTopStack(SqStack *s,ElemType *e){
	int index;//获得栈顶的索引 
	if(s->elem==NULL){
		printf("未初始化栈\n");
		return ERROR; 
	}
	else {
		if(s->top==-1){
			printf("栈为空\n");
			return ERROR;
		}
		index=s->top;
		*e=s->elem[index];
		printf("栈顶元素为:%d\n",*e);
		return SUCCESS;
	}
}


//清空栈
Status clearStack(SqStack *s){
	if(s->elem==NULL){
		printf("未初始化栈\n");
		return ERROR; 
	}
	else {
	
			free(s->elem);
			s->top=-1;
			s->elem=NULL;
	}
	return SUCCESS;
}

//销毁栈
Status destroyStack(SqStack *s){
	if(s->elem==NULL){
		printf("未初始化栈\n");
		return ERROR; 
	}
	else {
		free(s->elem);
		s->elem=NULL;
		return SUCCESS;
	}
}

//检测栈长度
Status stackLength(SqStack *s,int *length){
	if(s->elem==NULL){
		printf("未初始化栈\n");
		return ERROR; 
	}
	else {
		*length=s->top+1;
		printf("栈的长度为:%d\n",s->top+1);
		return SUCCESS;
	}
}

//入栈
Status pushStack(SqStack *s,ElemType data){
	if(s->elem==NULL){
		printf("未初始化栈\n");
		return ERROR; 
	} else {
		if(s->top==s->size-1){
			printf("栈满\n");
			return ERROR;
		}
		else {
			s->top++;
			s->elem[s->top]=data;
			return SUCCESS;
		}
	}
}

//出栈
Status popStack(SqStack *s,ElemType *data){
	if(s->elem==NULL){
		printf("未初始化栈\n");
		return ERROR; 
	} else{
		if(s->top==-1){
			printf("栈为空\n");
			return ERROR;
		}
		else {
			*data=s->elem[s->top];
			printf("出栈数据为:%d\n",*data);
			s->top--;
			return SUCCESS;
		}
	}
}
