#include<stdio.h>
#include<stdlib.h>
#include"LQueue.h"
#define MAX_STR_SIZE 1024
#include<ctype.h>

//�жϲ����Ƿ�ɹ�
void Judge(Status flag)
{
	if(flag==FALSE)
		{
			;//printf("����ʧ��\n");
		}
	else
		{
			;//printf("�����ɹ�\n");
		}
}


void type()
{
	printf("1.��������\n");
	printf("2.������\n");
	printf("3.�ַ�����\n");
}

//�û�ѡ��˵�
void menu()
{
	printf("������в���ѡ��\n");
	printf("----------------------------------\n");
	printf("1.��ʼ������                            ");
	printf("2.���ٶ���\n");
	//printf("3.�������Ƿ�����                      ");
	printf("3.�������Ƿ�Ϊ��                      ");
	printf("4.�鿴��ͷԪ��\n");
	printf("5.ȷ�����г���                          ");
	printf("6.��Ӳ���\n");
	printf("7.���Ӳ���                              ");
	printf("8.��ն���\n");
	printf("9.��������                              ");
	printf("10.�˳�\n");
}

//


//С������
double getNum2()
{
	char str[MAX_STR_SIZE]= {0};
	double pick=0;
	fgets(str,MAX_STR_SIZE,stdin);//ע�⣬fges��ѻس��Խ��ַ����У�����������������
	if(!isValid2(str))
		{
			printf("����������ݲ����ϣ�����������\n");
			//EmptyBuff();//�Ѵ�����ݳ���
			pick=getNum2();
		}
	else
		sscanf(str,"%lf",&pick);
	return pick;
}

//��ջ�����
void EmptyBuff()
{
	char ch;
	while((ch=getchar())!=EOF&&ch!='\n')
		{
			;
		}
}


//����ѡ������
int getNum()
{
	char str[MAX_STR_SIZE]= {0};
	int pick=0;
	fgets(str,MAX_STR_SIZE,stdin);//ע�⣬fges��ѻس��Խ��ַ����У�����������������
	if(!isValid(str))
		{
			printf("����������ݲ����ϣ�����������\n");
			//EmptyBuff();//�Ѵ�����ݳ���
			pick=getNum();
		}
	else
		sscanf(str,"%d",&pick);
	return pick;
}

//�û�ֻ����������
int isValid(const char* str)//�ж������Ƿ���Ч
{
	int sign=0;//�ж�����
	int digit=0;//���ֳ���
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
									printf("���ݹ���\n");
									return 0;
								}
						}

				}
			else return 0;

			
		}
		return 1;
}





//�û�ֻ������С��
int isValid2(const char* str)//�ж������Ƿ���Ч
{
	int point=0;
	int sign=0;//�ж�����
	int digit=0;//���ֳ���
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
									printf("���ݹ���\n");
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
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q)
{
	if(Q->front!=NULL)
		{
			printf("�ѳ�ʼ��������\n");
		}
	else
		{
			Q->front=NULL;
			Q->rear=NULL;
			Q->length=0;
			printf("��ʼ���ɹ�\n");
		}
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
	if(Q==NULL)
		{
			printf("�޶���,����ʧ��\n");
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
			printf("���ٳɹ�\n");
		}
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 if(Q->length==0)
		{
			printf("����Ϊ��\n");
			return TRUE;
		}
	else
		{
			printf("���в�Ϊ��\n");
			return FALSE;
		}
 */
Status IsEmptyLQueue(const LQueue *Q)
{
	if(Q==NULL)
		{
			printf("δ��ʼ������\n");
			return FALSE;
		}
	else if(Q->length==0)
		{
			printf("����Ϊ��\n");
			return TRUE;
		}
	else
		{
			printf("���в�Ϊ��\n");
			return FALSE;
		}
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void *e)
{
	if(Q==NULL)
		{
			printf("δ��ʼ������\n");
			return FALSE;
		}
	else if(Q->length==0)
		{
			printf("����Ϊ��\n");
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
					printf("��ͷԪ��Ϊ:%d\n",*a);
				}
			else if(*type==2)
				{
					double *a=Q->front->data;
					printf("��ͷԪ��Ϊ:%f\n",*a);
				}
			else if(*type==3)
				{
					char *a=Q->front->data;
					printf("��ͷԪ��Ϊ:%s\n",a);
				}
			return TRUE;
		}
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status LengthLQueue(LQueue *Q)
{
	if(Q==NULL)
		{
			printf("δ��ʼ������\n");
			return FALSE;
		}
	else
		{
			printf("���еĳ���Ϊ%d\n",Q->length);
			return TRUE;
		}
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data,int *type)
{
	if(Q==NULL)
		{
			printf("δ��ʼ������,���ʧ��\n");
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
			printf("��ӳɹ�\n");
			return TRUE;
		}
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
	if(Q==NULL)
		{
			printf("δ��ʼ������,���ʧ��\n");
			return FALSE;
		}
	else if(Q->length==0)
		{
			printf("����Ϊ��\n");
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
					printf("��ͷԪ��Ϊ:%d\n",*a);
				}
			else if(*type==2)
				{
					double *a=Q->front->data;
					printf("��ͷԪ��Ϊ:%f\n",*a);
				}
			else if(*type==3)
				{
					char *a=Q->front->data;
					printf("��ͷԪ��Ϊ:%s\n",a);
				}
			p=Q->front;
			Q->front=Q->front->next;
			free(p);
			Q->length--;
			printf("���ӳɹ�\n");
			return TRUE;
		}
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
	if(Q==NULL)
		{
			printf("δ��ʼ������\n");
		}
	else if(Q->length==0)
		{
			printf("����Ϊ��\n");
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
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(Node *q))
{
	if(Q==NULL)
		{
			printf("δ��ʼ������\n");
			return FALSE;
		}
	else if(Q->length==0)
		{
			printf("����Ϊ��\n");
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
 *    @description : ��������
 *    @param         q ָ��q

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
















