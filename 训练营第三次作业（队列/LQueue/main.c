#include<stdio.h>
#include<stdlib.h>
#include"LQueue.h"

/*
//�û�ѡ��˵�
void menu()
{
	printf("������в���ѡ��\n");
	printf("----------------------------------\n");
	printf("1.��ʼ������                            ");
	printf("2.���ٶ���\n");
	printf("3.�������Ƿ�Ϊ��                      ");
	printf("4.�鿴��ͷԪ��\n");
	printf("5.ȷ�����г���                          ");
	printf("6.��Ӳ���\n");
	printf("7.���Ӳ���                              ");
	printf("8.��ն���\n");
	printf("9.��������                              ");
	printf("10.�˳�\n");
}


*/

int main()
{
	void (*foo)(Node *q)=&LPrint;
	Status flag;//�жϲ����Ƿ�ɹ�
	int pick;//�û�����ѡ��
	int *t;//��������
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
			printf("���������ѡ��\n");
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
						printf("�����������ַ�ˢ��\n");
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
						printf("�����������ַ�ˢ��\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 3:
						flag=IsEmptyLQueue(Q);
						Judge(flag);
						printf("�����������ַ�ˢ��\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 4:
						flag=GetHeadLQueue(Q,e);
						Judge(flag);
						printf("�����������ַ�ˢ��\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 5:
						length=LengthLQueue(Q);
						printf("�����������ַ�ˢ��\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 6:
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
								EnLQueue(Q,data,t);
							}
						else if(*t==2)
							{
								double *a;
								void *data=malloc(sizeof(double));
								a=data;
								printf("����������\n");
								*a=getNum2();
								EnLQueue(Q,data,t);
							}
						else if(*t==3)
							{
								char *a;
								void *data=malloc(sizeof(200));
								a=data;
								printf("����������\n");
								gets(a);
								EnLQueue(Q,data,t);
							}
							printf("�����������ַ�ˢ��\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 7:
						flag=DeLQueue(Q);
						Judge(flag);
						printf("�����������ַ�ˢ��\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 8:
						ClearLQueue(Q);
						printf("�����������ַ�ˢ��\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 9:
						flag=TraverseLQueue(Q,foo);
						Judge(flag);
						printf("�����������ַ�ˢ��\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 10:
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

