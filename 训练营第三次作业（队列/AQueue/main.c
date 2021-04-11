#include<stdio.h>
#include<stdlib.h>
#include"AQueue.h"

/*
//用户选择菜单
void menu(){
	printf("顺序栈操作选择：\n");
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
	printf("11.退出\n")
}
*/
int main()
{
	void (*foo)(void *q,int *type)=&APrint;
	int *t;
	int length=0;
	void *e;
	void *data;
	char c;//判断是否为换行符
	Status flag;//判断操作是否成功
	int pick;//用户输入选择
	AQueue *Q=(AQueue*)malloc(sizeof(AQueue));
		Q->front=0;
			Q->rear=0;
			Q->length=0;
	int i=0;//用于循环
	for(i=0; i<MAXQUEUE; i++)
		{
			Q->data[i]=NULL;
			Q->type[i]=NULL;
		}
	while(1)
		{
			menu();
			printf("请输入你的选择\n");
			switch(getNum())
				{
					case 1:
						if(Q!=NULL)
							{
								InitAQueue(Q);
							}
						else
							{
								Q=(AQueue*)malloc(sizeof(AQueue));
								for(i=0; i<MAXQUEUE; i++)
									{
										Q->type[i]=NULL;
										Q->data[i]=NULL;
									}
								InitAQueue(Q);
							}
						printf("请输入任意字符刷屏\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;

					case 2:
						DestoryAQueue(Q);
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
						flag=IsFullAQueue(Q);
						Judge(flag);
						printf("请输入任意字符刷屏\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 4:
						flag=IsEmptyAQueue(Q);
						Judge(flag);
						printf("请输入任意字符刷屏\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 5:
						flag=GetHeadAQueue(Q,e);
						Judge(flag);
						printf("请输入任意字符刷屏\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 6:
						length=LengthAQueue(Q);
						printf("请输入任意字符刷屏\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 7:
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
								EnAQueue(Q,data,t);
							}
						else if(*t==2)
							{
								double *a;
								void *data=malloc(sizeof(double));
								a=data;
								printf("请输入数据\n");
								*a=getNum2();
								EnAQueue(Q,data,t);
							}
						else if(*t==3)
							{
								char *a;
								void *data=malloc(sizeof(200));
								a=data;
								printf("请输入数据\n");
								gets(a);
								EnAQueue(Q,data,t);
							}
							printf("请输入任意字符刷屏\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 8:
						flag=DeAQueue(Q);
						Judge(flag);
						printf("请输入任意字符刷屏\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 9:
						ClearAQueue(Q);
						printf("请输入任意字符刷屏\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 10:
						flag=TraverseAQueue(Q,foo);
						Judge(flag);
						printf("请输入任意字符刷屏\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 11:
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
