#include<stdio.h>
#include<stdlib.h>
#include"AQueue.h"
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


void type(){
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
	printf("3.检查队列是否已满                      ");
	printf("4.检查队列是否为空\n");
	printf("5.查看队头元素                          ");
	printf("6.确定队列长度\n");
	printf("7.入队操作                              ");
	printf("8.出队操作\n");
	printf("9.清空队列                              ");
	printf("10.遍历队列\n");
	printf("11.退出\n");
}

//


//小数输入 
double getNum2(){
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

			if(((*str)>='0'&&(*str)<='9')||(*str=='+')||(*str=='-')||(*str=='\n')){
				if(*str=='+'||*str=='-'){
					if(sign!=0) return 0;
					if(*str=='+')sign=1;
					else sign=-1;
				}
				else if((*str)>='0'&&(*str)<='9')
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

			if(((*str)>='0'&&(*str)<='9')||(*str=='+')||(*str=='-')||(*str=='.')||(*str=='\n')){
				if(*str=='+'||*str=='-'){
					if(sign!=0) return 0;
					else if(*str=='+')sign=1;
					else sign=-1;
				}
				else if((*str)>='0'&&(*str)<='9')
				{
					digit++;
					if(digit>5)
						{
							printf("数据过大\n");
							return 0;
						}
				}
				else if((*str)=='.'){
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
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q)
{
	if(Q->data[(Q->front)%MAXQUEUE]!=NULL)
		{
			printf("已初始化过队列\n");
		}
	else
		{
			Q->front=0;
			Q->rear=0;
			Q->length=0;
			printf("初始化完成\n"); 
		}
}



/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q)
{
	if(Q==NULL)
		{
			printf("无队列,销毁失败\n");
		}
	else
		{
			int i=0;
			for(i=0; i<MAXQUEUE; i++)
				{
					free(Q->data[i]);//释放空间 
					free(Q->type[i]);
					Q->type[i]=NULL;
					Q->data[i]=NULL;
				}
			/*free(Q);
			Q=NULL;*/
			printf("销毁成功\n");
		}
}



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q)
{
	if(Q==NULL)
		{
			printf("未初始化队列\n");
			return FALSE;
		}
	else if(Q->length==MAXQUEUE)
		{
			printf("队列已满\n");
			return TRUE;
		}
	else
		{
			printf("队列未满\n");
			return FALSE;
		}
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q)
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
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, void *e)
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
			e=Q->data[(Q->front)%MAXQUEUE];
			type=Q->type[(Q->front)%MAXQUEUE];
			if(*type==1){
				int *a=Q->data[(Q->front)%MAXQUEUE];
				printf("队头元素为:%d\n",*a);
			}
			else if(*type==2){
				double *a=Q->data[(Q->front)%MAXQUEUE];
				printf("队头元素为:%f\n",*a);
			}
			else if(*type==3){
				char *a=Q->data[(Q->front)%MAXQUEUE];
				printf("队头元素为:%s\n",a);
			}
			return TRUE;
		}
}



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q)
{
	if(Q==NULL)
		{
			printf("未初始化队列\n");
			return FALSE;
		}
	else
		{
			printf("队列长度为:%d\n",Q->length);
			return Q->length;
		}
}



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q, void *data,int *type)
{
	if(Q==NULL)
		{
			printf("未初始化队列\n");
			return FALSE;
		}
	else if(Q->length==MAXQUEUE)
		{
			printf("队列已满,无法入队\n");
			return FALSE;
		}
	else
		{
			Q->type[(Q->rear)%MAXQUEUE]=type;
			Q->data[(Q->rear)%MAXQUEUE]=data;
			Q->rear++;
			Q->length++;
			printf("入队成功\n");
			return TRUE;
		}
}



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q)
{
	if(Q==NULL)
		{
			printf("未初始化队列\n");
			return FALSE;
		}
	else if(Q->length==0)
		{
			printf("队列为空，无法出队\n");
			return FALSE;
		}
	else
		{
			int *type;
			type=Q->type[(Q->front)%MAXQUEUE];
			if(*type==1){
				int *a=Q->data[(Q->front)%MAXQUEUE];
				printf("队头元素为:%d\n",*a);
			}
			else if(*type==2){
				double *a=Q->data[(Q->front)%MAXQUEUE];
				printf("队头元素为:%f\n",*a);
			}
			else if(*type==3){
				char *a=Q->data[(Q->front)%MAXQUEUE];
				printf("队头元素为:%s\n",a);
			}
			Q->front++;
			Q->length--;
			printf("出队成功\n");
			return TRUE;
		}
}



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q)
{
	if(Q==NULL)
		{
			printf("未初始化队列\n");

		}
	else if(Q->length==0)
		{
			printf("无需清空\n");
		}
	else
		{
			int i=0;
			for(i=0; i<MAXQUEUE; i++)
				{
					free(Q->type[i]);
					free(Q->data[i]);//释放空间 
					Q->type[i]=NULL;
					Q->data[i]=NULL;
				}
			Q->length=0;
			Q->front=0;
			Q->rear=0;
		}
}



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q,int *type)){
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
		else {
			int i=0;
			for(i=0;i<Q->length;i++){
				foo(Q->data[(Q->front+i)%MAXQUEUE],Q->type[(Q->front+i)%MAXQUEUE]);
			}
			printf("\n");
			return TRUE;
		}
}



/**
打印指针数据
 *  @name        : void APrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void APrint(void *q,int *type){
			if(*type==1){
				int *a=q;
				printf("%d  <-  ",*a);
			}
			else if(*type==2){
				double *a=q;
				printf("%f  <-  ",*a);
			}
			else if(*type==3){
				char *a=q;
				printf("%s  <-  ",a);
			}
		}


