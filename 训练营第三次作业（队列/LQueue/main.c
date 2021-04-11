#include<stdio.h>
#include<stdlib.h>
#include"LQueue.h"

/*
//用户选择菜单
void menu()
{
	printf("数组队列操作选择：\n");
	printf("----------------------------------\n");
	printf("1.初始化队列                            ");
	printf("2.销毁队列\n");
	printf("3.检查队列是否为空                      ");
	printf("4.查看队头元素\n");
	printf("5.确定队列长度                          ");
	printf("6.入队操作\n");
	printf("7.出队操作                              ");
	printf("8.清空队列\n");
	printf("9.遍历队列                              ");
	printf("10.退出\n");
}


*/

int main()
{
	void (*foo)(Node *q)=&LPrint;
	Status flag;//判断操作是否成功
	int pick;//用户输入选择
	int *t;//数据类型
	int length=0;
	char c;
	void *e;
	void *data;
	LQueue *Q=(LQueue *)malloc(sizeof(LQueue));
	Q->front=NULL;
	Q->rear=NULL;
	Q->length=0;
	while(1)
		{
			menu();
			printf("请输入你的选择\n");
			switch(getNum())
				{
					case 1:
						if(Q==NULL)
							{
								Q=(LQueue *)malloc(sizeof(LQueue));
								Q->front=NULL;
								Q->rear=NULL;
								Q->length=0;
							}
						InitLQueue(Q);
						printf("请输入任意字符刷屏\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 2:
						DestoryLQueue(Q);
						if(Q!=NULL){
							free(Q);
							Q=NULL;
						} 
						printf("请输入任意字符刷屏\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 3:
						flag=IsEmptyLQueue(Q);
						Judge(flag);
						printf("请输入任意字符刷屏\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 4:
						flag=GetHeadLQueue(Q,e);
						Judge(flag);
						printf("请输入任意字符刷屏\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 5:
						length=LengthLQueue(Q);
						printf("请输入任意字符刷屏\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 6:
						type();
						printf("请输入你要存放的数据类型\n");
						t=malloc(sizeof(int));
						*t=getNum();
						while(!(*t<=3&&*t>=1))
							{
								printf("无此项选择,请重新输入\n");
								*t=getNum();
							}
						if(*t==1)
							{
								int *a;
								void *data=malloc(sizeof(int));
								a=data;
								printf("请输入数据\n");
								*a=getNum();
								EnLQueue(Q,data,t);
							}
						else if(*t==2)
							{
								double *a;
								void *data=malloc(sizeof(double));
								a=data;
								printf("请输入数据\n");
								*a=getNum2();
								EnLQueue(Q,data,t);
							}
						else if(*t==3)
							{
								char *a;
								void *data=malloc(sizeof(200));
								a=data;
								printf("请输入数据\n");
								gets(a);
								EnLQueue(Q,data,t);
							}
							printf("请输入任意字符刷屏\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 7:
						flag=DeLQueue(Q);
						Judge(flag);
						printf("请输入任意字符刷屏\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 8:
						ClearLQueue(Q);
						printf("请输入任意字符刷屏\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 9:
						flag=TraverseLQueue(Q,foo);
						Judge(flag);
						printf("请输入任意字符刷屏\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 10:
						exit(0);
					default:
						printf("无此项选择\n");
						printf("请输入任意字符刷屏\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
				}
		}

	return 0;
}

