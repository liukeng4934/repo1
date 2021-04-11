#include<stdio.h>
#include<stdlib.h>
#include"AQueue.h"
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


void type(){
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
	printf("3.�������Ƿ�����                      ");
	printf("4.�������Ƿ�Ϊ��\n");
	printf("5.�鿴��ͷԪ��                          ");
	printf("6.ȷ�����г���\n");
	printf("7.��Ӳ���                              ");
	printf("8.���Ӳ���\n");
	printf("9.��ն���                              ");
	printf("10.��������\n");
	printf("11.�˳�\n");
}

//


//С������ 
double getNum2(){
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
							printf("���ݹ���\n");
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
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q)
{
	if(Q->data[(Q->front)%MAXQUEUE]!=NULL)
		{
			printf("�ѳ�ʼ��������\n");
		}
	else
		{
			Q->front=0;
			Q->rear=0;
			Q->length=0;
			printf("��ʼ�����\n"); 
		}
}



/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q)
{
	if(Q==NULL)
		{
			printf("�޶���,����ʧ��\n");
		}
	else
		{
			int i=0;
			for(i=0; i<MAXQUEUE; i++)
				{
					free(Q->data[i]);//�ͷſռ� 
					free(Q->type[i]);
					Q->type[i]=NULL;
					Q->data[i]=NULL;
				}
			/*free(Q);
			Q=NULL;*/
			printf("���ٳɹ�\n");
		}
}



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : �������Ƿ�����
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q)
{
	if(Q==NULL)
		{
			printf("δ��ʼ������\n");
			return FALSE;
		}
	else if(Q->length==MAXQUEUE)
		{
			printf("��������\n");
			return TRUE;
		}
	else
		{
			printf("����δ��\n");
			return FALSE;
		}
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q)
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
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q ����ָ��Q�����Ԫ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadAQueue(AQueue *Q, void *e)
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
			e=Q->data[(Q->front)%MAXQUEUE];
			type=Q->type[(Q->front)%MAXQUEUE];
			if(*type==1){
				int *a=Q->data[(Q->front)%MAXQUEUE];
				printf("��ͷԪ��Ϊ:%d\n",*a);
			}
			else if(*type==2){
				double *a=Q->data[(Q->front)%MAXQUEUE];
				printf("��ͷԪ��Ϊ:%f\n",*a);
			}
			else if(*type==3){
				char *a=Q->data[(Q->front)%MAXQUEUE];
				printf("��ͷԪ��Ϊ:%s\n",a);
			}
			return TRUE;
		}
}



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : ���г���count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q)
{
	if(Q==NULL)
		{
			printf("δ��ʼ������\n");
			return FALSE;
		}
	else
		{
			printf("���г���Ϊ:%d\n",Q->length);
			return Q->length;
		}
}



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ����˻�Ϊ��
 */
Status EnAQueue(AQueue *Q, void *data,int *type)
{
	if(Q==NULL)
		{
			printf("δ��ʼ������\n");
			return FALSE;
		}
	else if(Q->length==MAXQUEUE)
		{
			printf("��������,�޷����\n");
			return FALSE;
		}
	else
		{
			Q->type[(Q->rear)%MAXQUEUE]=type;
			Q->data[(Q->rear)%MAXQUEUE]=data;
			Q->rear++;
			Q->length++;
			printf("��ӳɹ�\n");
			return TRUE;
		}
}



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q)
{
	if(Q==NULL)
		{
			printf("δ��ʼ������\n");
			return FALSE;
		}
	else if(Q->length==0)
		{
			printf("����Ϊ�գ��޷�����\n");
			return FALSE;
		}
	else
		{
			int *type;
			type=Q->type[(Q->front)%MAXQUEUE];
			if(*type==1){
				int *a=Q->data[(Q->front)%MAXQUEUE];
				printf("��ͷԪ��Ϊ:%d\n",*a);
			}
			else if(*type==2){
				double *a=Q->data[(Q->front)%MAXQUEUE];
				printf("��ͷԪ��Ϊ:%f\n",*a);
			}
			else if(*type==3){
				char *a=Q->data[(Q->front)%MAXQUEUE];
				printf("��ͷԪ��Ϊ:%s\n",a);
			}
			Q->front++;
			Q->length--;
			printf("���ӳɹ�\n");
			return TRUE;
		}
}



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q)
{
	if(Q==NULL)
		{
			printf("δ��ʼ������\n");

		}
	else if(Q->length==0)
		{
			printf("�������\n");
		}
	else
		{
			int i=0;
			for(i=0; i<MAXQUEUE; i++)
				{
					free(Q->type[i]);
					free(Q->data[i]);//�ͷſռ� 
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
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q,int *type)){
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
��ӡָ������
 *  @name        : void APrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
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


