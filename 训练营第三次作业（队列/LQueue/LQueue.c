#include<stdio.h>
#include<stdlib.h>
#include"LQueue.h"
#define MAX_STR_SIZE 1024
#include<ctype.h>

//判断操作是否成功
void Judge(Status flag)
{
	if(flag==FALSE)
		{
			;//printf("操作失败\n");
		}
	else
		{
			;//printf("操作成功\n");
		}
}


void type()
{
	printf("1.整数类型\n");
	printf("2.浮点型\n");
	printf("3.字符类型\n");
}

//用户选择菜单
void menu()
{
	printf("数组队列操作选择：\n");
	printf("----------------------------------\n");
	printf("1.初始化队列                            ");
	printf("2.销毁队列\n");
	//printf("3.检查队列是否已满                      ");
	printf("3.检查队列是否为空                      ");
	printf("4.查看队头元素\n");
	printf("5.确定队列长度                          ");
	printf("6.入队操作\n");
	printf("7.出队操作                              ");
	printf("8.清空队列\n");
	printf("9.遍历队列                              ");
	printf("10.退出\n");
}

//


//小数输入
double getNum2()
{
	char str[MAX_STR_SIZE]= {0};
	double pick=0;
	fgets(str,MAX_STR_SIZE,stdin);//注意，fges会把回车吃进字符串中！！！！！！！！！
	if(!isValid2(str))
		{
			printf("你输入的数据不符合，请重新输入\n");
			//EmptyBuff();//把错的数据吃完
			pick=getNum2();
		}
	else
		sscanf(str,"%lf",&pick);
	return pick;
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


//输入选择整数
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

//用户只能输入整数
int isValid(const char* str)//判断数据是否有效
{
	int sign=0;//判断正负
	int digit=0;//数字长度
	for(; *str; str++)
		{

			if((isdigit(*str))||(*str=='+')||(*str=='-')||(*str=='\n'))
				{
					if(*str=='+'||*str=='-')
						{
							if(sign!=0) return 0;
							else if(*str=='+')sign=1;
							else sign=-1;
						}
					else if(isdigit(*str))
						{
							digit++;
							if(digit>5)
								{
									printf("数据过大\n");
									return 0;
								}
						}

				}
			else return 0;

			
		}
		return 1;
}





//用户只能输入小数
int isValid2(const char* str)//判断数据是否有效
{
	int point=0;
	int sign=0;//判断正负
	int digit=0;//数字长度
	for(; *str; str++)
		{

			if((isdigit(*str))||(*str=='+')||(*str=='-')||(*str=='.')||(*str=='\n'))
				{
					if(*str=='+'||*str=='-')
						{
							if(sign!=0) return 0;
							else if(*str=='+')sign=1;
							else sign=-1;
						}
					else if(isdigit(*str))
						{
							digit++;
							if(digit>5)
								{
									printf("数据过大\n");
									return 0;
								}
						}
					else if(*str=='.')
						{
							if(point==1)return 0;
							digit=0;
							point=1;
						}
				}
			else return 0;

			
		}
		return 1;
}



/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q)
{
	if(Q->front!=NULL)
		{
			printf("已初始化过队列\n");
		}
	else
		{
			Q->front=NULL;
			Q->rear=NULL;
			Q->length=0;
			printf("初始化成功\n");
		}
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
	if(Q==NULL)
		{
			printf("无队列,销毁失败\n");
		}
	else
		{
			Node *p;
			for(p=Q->front; p;)
				{
					//p=Q->front;
					Q->front=Q->front->next;
					free(p);
					p=Q->front;
				}
			printf("销毁成功\n");
		}
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 if(Q->length==0)
		{
			printf("队列为空\n");
			return TRUE;
		}
	else
		{
			printf("队列不为空\n");
			return FALSE;
		}
 */
Status IsEmptyLQueue(const LQueue *Q)
{
	if(Q==NULL)
		{
			printf("未初始化队列\n");
			return FALSE;
		}
	else if(Q->length==0)
		{
			printf("队列为空\n");
			return TRUE;
		}
	else
		{
			printf("队列不为空\n");
			return FALSE;
		}
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e)
{
	if(Q==NULL)
		{
			printf("未初始化队列\n");
			return FALSE;
		}
	else if(Q->length==0)
		{
			printf("队列为空\n");
			return FALSE;
		}
	else
		{
			int *type;
			e=Q->front->data;
			type=Q->front->type;
			if(*type==1)
				{
					int *a=Q->front->data;
					printf("队头元素为:%d\n",*a);
				}
			else if(*type==2)
				{
					double *a=Q->front->data;
					printf("队头元素为:%f\n",*a);
				}
			else if(*type==3)
				{
					char *a=Q->front->data;
					printf("队头元素为:%s\n",a);
				}
			return TRUE;
		}
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status LengthLQueue(LQueue *Q)
{
	if(Q==NULL)
		{
			printf("未初始化队列\n");
			return FALSE;
		}
	else
		{
			printf("队列的长度为%d\n",Q->length);
			return TRUE;
		}
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data,int *type)
{
	if(Q==NULL)
		{
			printf("未初始化队列,入队失败\n");
			return FALSE;
		}
	else
		{
			Node *p=(Node *)malloc(sizeof(Node));
			p->data=data;
			p->type=type;
			p->next=NULL;
			if(Q->rear==NULL)
				{
					Q->front=p;
					Q->rear=p;
				}
			else
				{
					Q->rear->next=p;
					Q->rear=p;
				}
			Q->length++;
			printf("入队成功\n");
			return TRUE;
		}
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
	if(Q==NULL)
		{
			printf("未初始化队列,入队失败\n");
			return FALSE;
		}
	else if(Q->length==0)
		{
			printf("队列为空\n");
			return FALSE;
		}
	else
		{
			Node *p;
			int *type;
			type=Q->front->type;
			if(*type==1)
				{
					int *a=Q->front->data;
					printf("队头元素为:%d\n",*a);
				}
			else if(*type==2)
				{
					double *a=Q->front->data;
					printf("队头元素为:%f\n",*a);
				}
			else if(*type==3)
				{
					char *a=Q->front->data;
					printf("队头元素为:%s\n",a);
				}
			p=Q->front;
			Q->front=Q->front->next;
			free(p);
			Q->length--;
			printf("出队成功\n");
			return TRUE;
		}
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
	if(Q==NULL)
		{
			printf("未初始化队列\n");
		}
	else if(Q->length==0)
		{
			printf("队列为空\n");
		}
	else
		{
			/*Node *p,*q;
			q=Q->front->next;
			for(p=Q->front;p;){
				free(p);
				p=q;
				if(q!=NULL)
				{
					q=q->next;
					break;
				}
			}*/
			Node *p;
			for(p=Q->front; p;)
				{
					//p=Q->front;
					Q->front=Q->front->next;
					free(p);
					p=Q->front;
				}
			Q->length=0;
			Q->front=NULL;
			Q->rear=NULL;
		}
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(Node *q))
{
	if(Q==NULL)
		{
			printf("未初始化队列\n");
			return FALSE;
		}
	else if(Q->length==0)
		{
			printf("队列为空\n");
			return FALSE;
		}
	else
		{
			Node *p;
			for(p=Q->front; p; p=p->next)
				{
					foo(p);
				}
				printf("\n");
			return TRUE;
		}
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q

 *  @notice      : None
 */
void LPrint(Node *q)
{
	int *type;
	type=q->type;
	if(*type==1)
		{
			int *a=q->data;
			printf("%d  <-  ",*a);
		}
	else if(*type==2)
		{
			double *a=q->data;
			printf("%f  <-  ",*a);
		}
	else if(*type==3)
		{
			char *a=q->data;
			printf("%s  <-  ",a);
		}
	/*
	if(*type==1){
		int *a=q;
		printf("%d->",*a);
	}
	else if(*type==2){
		double *a=q;
		printf("%f->",*a);
	}
	else if(*type==3){
		char *a=q;
		printf("%s->",a);
	}*/
}
















