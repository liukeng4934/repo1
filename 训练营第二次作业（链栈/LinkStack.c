#include<stdio.h>
#include"LinkStack.h"
#include<stdlib.h>
#define MAX_STR_SIZE 1024
#include<ctype.h>
int isValid(const char* str);
//����
void clear(){
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
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


//�жϲ����Ƿ�ɹ�
void Judge(Status flag)
{
	if(flag==ERROR)
		{
			printf("����ʧ��\n");
		}
	else
		{
			printf("�����ɹ�\n");
		}
}


//�û�ѡ��˵� 
void menu(){
	printf("˳��ջ����ѡ��\n");
	printf("----------------------------------\n");
	printf("1.��ʼ��ջ                          ");
	printf("2.�ж�ջ�Ƿ�Ϊ��\n");
	printf("3.�õ�ջ��Ԫ��                      ");
	printf("4.���ջ\n"); 
	printf("5.����ջ                            ");
	printf("6.���ջ����\n");
	printf("7.��ջ                              ");
	printf("8.��ջ\n");
	printf("9.�˳�\n");
}

//����ѡ��
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



//�û�ֻ���������ּӿո����ֻ�����ֵ����� 
int isValid(const char* str)//�ж������Ƿ���Ч 
{
	int digit=0;//���ֳ��� 
	int isSpaceAppear=0;
	for(; *str; str++)
		{
			
			if(isspace(*str))		isSpaceAppear=1;
			//else if(*str=='-') sign=1;//����Ϊ�� �����ˡ�sscanf���Լ��ж���û�и��� 
			else if(!isdigit(*str))		return 0;
			else if(isdigit(*str)&&isSpaceAppear)	return 0;
			else if(isdigit(*str)){
				digit++;
				if(digit>4) { 
				printf("���ݹ���\n");
				return 0; 
			}
		}
	return 1;
}
}







//��ջ
//��ʼ��ջ
Status initLStack(LinkStack *s){
	if(s->top!=NULL){
		printf("ջ�ѳ�ʼ��\n");
		return ERROR;
	}
	else {
		s->top=(LinkStackPtr)malloc(sizeof(StackNode));
		if(s->top==NULL){
			printf("�����ڴ�ʧ��\n");
			return ERROR;
		}
		else {
			s->top->next=NULL;//ͷ��㲻������� 
			return SUCCESS;
		}
	}
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s){
	if(s->top==NULL){
		printf("δ��ʼ��ջ\n");
		return ERROR;
	}
	else  if(s->count==0){
		printf("ջΪ��\n");
		return SUCCESS;
	}
	else if(s->count>0){
		printf("ջ��Ϊ��\n");
		return SUCCESS;
	}
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType *e){
	if(s->top==NULL){
		printf("δ��ʼ��ջ\n");
		return ERROR;
	}
	else  if(s->count==0){
		printf("ջΪ��\n");
		return ERROR;
	}
	else if(s->count>0){
		*e=s->top->data;
		printf("ջ��Ԫ��Ϊ:%d\n",*e);
		return SUCCESS;
	}
}

//���ջ
Status clearLStack(LinkStack *s){
	 LinkStackPtr p;//����ָ���ͷŵĿսڵ�
	 if(s->top==NULL){
		printf("δ��ʼ��ջ\n");
		return ERROR;
	}
	else  if(s->count==0){
		printf("ջΪ��\n");
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

//����ջ
Status destroyLStack(LinkStack *s){
	LinkStackPtr p;//����ָ���ͷŵĿսڵ�
	 if(s->top==NULL){
		printf("δ��ʼ��ջ\n");
		return ERROR;
	}
	else  if(s->count==0){
		printf("ջΪ��\n");
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

//���ջ����
Status LStackLength(LinkStack *s,int *length){
	 if(s->top==NULL){
		printf("δ��ʼ��ջ\n");
		return ERROR;
	}
	else  if(s->count==0){
		printf("ջΪ��\n");
		free(s->top);
		return ERROR;
	}
	else if(s->count>0){
		printf("ջ�ĳ���Ϊ:%d\n",s->count);
		return SUCCESS;
	}
}

//��ջ
Status pushLStack(LinkStack *s,ElemType data){
	if(s->top==NULL){
		printf("δ��ʼ��ջ\n");
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

//��ջ
Status popLStack(LinkStack *s,ElemType *data){
	if(s->top==NULL){
		printf("δ��ʼ��ջ\n");
		return ERROR;
	}else if(s->count==0){
		printf("ջΪ��\n");
		return ERROR;
	}else{
		LinkStackPtr p;
		p=s->top;
		*data=p->data;
		s->top=p->next;
		free(p);
		printf("��ջԪ��Ϊ:%d",*data);
		s->count--;
		return SUCCESS;
	}
}


