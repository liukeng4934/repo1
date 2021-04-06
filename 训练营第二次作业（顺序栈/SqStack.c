#include<stdio.h>
#include"SqStack.h"
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


/*
//��ȡ�û����������
int getNum(){
	/*int error=0;//�ж������Ƿ���� 
	char str[1024]={0};
	printf("�������������\n");
	fgets(str,1024,stdin);
	char *p=str;
	int acc=0;//�����ж������Ƿ���� 
	int neg=0,add;//acc�ж��Ƿ�Ϊ������add������������ 
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
			printf("����������ݲ�����Ҫ����������������\n");
			error=1; 
			break;
		}
		add=*p-'0';
		if(acc>INT_MAX/10){
			printf("����������������(С)ֵ\n");
			return neg? INT_MIN:INT_MAX;
		}else if(acc==INT_MAX/10){
			if(neg&&add>8){
			printf("���������������Сֵ\n");
				return INT_MIN;
			}//intռ��4�ֽڵĻ�����Сֵ��λ����8. 
		
			if(!neg&&add>7){
				printf("����������������ֵ\n");
				return INT_MAX;}//ͬ�ϣ���λ����7 
			
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
//���������˳��ջ
//��ʼ��ջ

Status initStack(SqStack *s,int sizes){
	if(s->elem)
		{
			printf("�Ѿ���ʼ����ջ.\n");
			return ERROR;
		}
		if(sizes<=0){
			printf("���������޷��������飬���������0������\n");
			return ERROR;
		}
	s->elem=NULL;
	s->elem=(ElemType*)malloc(sizeof(ElemType)*sizes);
	if(s->elem){
		printf("�����ڴ�����ɹ�\n");
	}
	else {
		printf("��������ڴ�ʧ��\n");
		return ERROR;
	}
	s->size=sizes;
	s->top=-1;
	printf("ջ��ʼ�����.\n");
	return  SUCCESS;
}


//�ж�ջ�Ƿ�Ϊ��
Status isEmptyStack(SqStack *s){
	if(s->elem==NULL){
		printf("δ��ʼ��ջ\n");
		return SUCCESS; 
	}
	else {
		if(s->top==-1){
			printf("ջΪ��\n");
			return SUCCESS;
		}
		else {
			printf("ջ��Ϊ��\n");
			return SUCCESS;
		}
	}
}

//�õ�ջ��Ԫ��
Status getTopStack(SqStack *s,ElemType *e){
	int index;//���ջ�������� 
	if(s->elem==NULL){
		printf("δ��ʼ��ջ\n");
		return ERROR; 
	}
	else {
		if(s->top==-1){
			printf("ջΪ��\n");
			return ERROR;
		}
		index=s->top;
		*e=s->elem[index];
		printf("ջ��Ԫ��Ϊ:%d\n",*e);
		return SUCCESS;
	}
}


//���ջ
Status clearStack(SqStack *s){
	if(s->elem==NULL){
		printf("δ��ʼ��ջ\n");
		return ERROR; 
	}
	else {
	
			free(s->elem);
			s->top=-1;
			s->elem=NULL;
	}
	return SUCCESS;
}

//����ջ
Status destroyStack(SqStack *s){
	if(s->elem==NULL){
		printf("δ��ʼ��ջ\n");
		return ERROR; 
	}
	else {
		free(s->elem);
		s->elem=NULL;
		return SUCCESS;
	}
}

//���ջ����
Status stackLength(SqStack *s,int *length){
	if(s->elem==NULL){
		printf("δ��ʼ��ջ\n");
		return ERROR; 
	}
	else {
		*length=s->top+1;
		printf("ջ�ĳ���Ϊ:%d\n",s->top+1);
		return SUCCESS;
	}
}

//��ջ
Status pushStack(SqStack *s,ElemType data){
	if(s->elem==NULL){
		printf("δ��ʼ��ջ\n");
		return ERROR; 
	} else {
		if(s->top==s->size-1){
			printf("ջ��\n");
			return ERROR;
		}
		else {
			s->top++;
			s->elem[s->top]=data;
			return SUCCESS;
		}
	}
}

//��ջ
Status popStack(SqStack *s,ElemType *data){
	if(s->elem==NULL){
		printf("δ��ʼ��ջ\n");
		return ERROR; 
	} else{
		if(s->top==-1){
			printf("ջΪ��\n");
			return ERROR;
		}
		else {
			*data=s->elem[s->top];
			printf("��ջ����Ϊ:%d\n",*data);
			s->top--;
			return SUCCESS;
		}
	}
}
