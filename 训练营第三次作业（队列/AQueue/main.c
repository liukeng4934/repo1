#include<stdio.h>
#include<stdlib.h>
#include"AQueue.h"

/*
//�û�ѡ��˵�
void menu(){
	printf("˳��ջ����ѡ��\n");
	printf("----------------------------------\n");
	printf("1.��ʼ������                            ");
	printf("2.���ٶ���\n");
	printf("3.�������Ƿ�����                      ");
	printf("4.�������Ƿ�Ϊ��\n");
	printf("5.�鿴��ͷԪ��                          ");
	printf("6.ȷ�����г���\n");
	printf("7.��Ӳ���                              ");
	printf("8.���Ӳ���\n");
	printf("9.��ն���                              ");
	printf("10.��������\n");
	printf("11.�˳�\n")
}
*/
int main()
{
	void (*foo)(void *q,int *type)=&APrint;
	int *t;
	int length=0;
	void *e;
	void *data;
	char c;//�ж��Ƿ�Ϊ���з�
	Status flag;//�жϲ����Ƿ�ɹ�
	int pick;//�û�����ѡ��
	AQueue *Q=(AQueue*)malloc(sizeof(AQueue));
		Q->front=0;
			Q->rear=0;
			Q->length=0;
	int i=0;//����ѭ��
	for(i=0; i<MAXQUEUE; i++)
		{
			Q->data[i]=NULL;
			Q->type[i]=NULL;
		}
	while(1)
		{
			menu();
			printf("���������ѡ��\n");
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
						printf("�����������ַ�ˢ��\n");
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
						printf("�����������ַ�ˢ��\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 3:
						flag=IsFullAQueue(Q);
						Judge(flag);
						printf("�����������ַ�ˢ��\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 4:
						flag=IsEmptyAQueue(Q);
						Judge(flag);
						printf("�����������ַ�ˢ��\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 5:
						flag=GetHeadAQueue(Q,e);
						Judge(flag);
						printf("�����������ַ�ˢ��\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 6:
						length=LengthAQueue(Q);
						printf("�����������ַ�ˢ��\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 7:
						type();
						printf("��������Ҫ��ŵ���������\n");
						t=malloc(sizeof(int));
						*t=getNum();
						while(!(*t<=3&&*t>=1))
							{
								printf("�޴���ѡ��,����������\n");
								*t=getNum();
							}
						if(*t==1)
							{
								int *a;
								void *data=malloc(sizeof(int));
								a=data;
								printf("����������\n");
								*a=getNum();
								EnAQueue(Q,data,t);
							}
						else if(*t==2)
							{
								double *a;
								void *data=malloc(sizeof(double));
								a=data;
								printf("����������\n");
								*a=getNum2();
								EnAQueue(Q,data,t);
							}
						else if(*t==3)
							{
								char *a;
								void *data=malloc(sizeof(200));
								a=data;
								printf("����������\n");
								gets(a);
								EnAQueue(Q,data,t);
							}
							printf("�����������ַ�ˢ��\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 8:
						flag=DeAQueue(Q);
						Judge(flag);
						printf("�����������ַ�ˢ��\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 9:
						ClearAQueue(Q);
						printf("�����������ַ�ˢ��\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 10:
						flag=TraverseAQueue(Q,foo);
						Judge(flag);
						printf("�����������ַ�ˢ��\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 11:
						exit(0);
					default:
						printf("�޴���ѡ��\n");
						printf("�����������ַ�ˢ��\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
				}
		}


	return 0;
}
