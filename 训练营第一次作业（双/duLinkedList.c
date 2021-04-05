#include "duLinkedList.h"
#include<stdio.h>
#include<stdlib.h>
#define MAX_STR_SIZE 1024
#include<ctype.h>
int isValid(const char* str);
/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */


//����
void clear(){
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
} 

//��ȡ����ڵ�
DuLNode* GetNode(DuLinkedList *L,int index)
{
	DuLNode *p=*L;
	if(*L==NULL)
		{
			printf("δ��ʼ������\n");
			return *L;
		}
	else if((*L)->next==NULL)
		{
			printf("����Ϊ��\n");
			if(index>0)return NULL;
			return *L;
		}
	else
		{
			p=*L;
			while(1)
				{
					if(index<0)
						{
							printf("����������ݲ�����(���������0������)");
							index=InputPick();
							EmptyBuff();
						}
					else break;
				}
			for(; index>0; --index)
				{
					p=p->next ;
					if(p==NULL){
						return NULL;
					}
				}
				return p;
		}

}

//�жϲ����Ƿ�ɹ�
void Judge(Status flag)
{
	if(flag==ERROR)
		{
			printf("����ʧ��\n\n");
		}
	else
		{
			printf("�����ɹ�\n\n");
		}
}

//�����û���ѡ��
//����ѡ��
int InputPick()
{
	char str[MAX_STR_SIZE]= {0};
	int pick=0;
	fgets(str,MAX_STR_SIZE,stdin);//ע�⣬fges��ѻس��Խ��ַ����У����������������� 
	if(!isValid(str))
	{
		printf("����������ݲ����ϣ�����������\n");
		//EmptyBuff();//�Ѵ�����ݳ���
		pick=InputPick();
	 } 
	else
	sscanf(str,"%d",&pick);
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

//�˵�
void Menu()
{
	char c;
	printf("˫���������ѡ��\n");
	printf("---------------------------------------------------------------------\n");
	printf("1.�����ʼ��                          ");
	printf("2.��������\n");
	printf("3.����ڵ�(��ָ��λ��ǰ)              ");
	printf("4.����ڵ�(��ָ��λ�ú�)\n");
	printf("5.ɾ���ڵ�(��ָ��λ�ú�)              ");
	printf("6.��������\n");
	printf("7.�����������                        ");
	printf("8.�˳�\n");
	printf("---------------------------------------------------------------------\n");
}
//��ʼ������
Status InitList_DuL(DuLinkedList *L)
{
		
		if(*L)
		{
			printf("�Ѿ���ʼ��������.\n");
			return ERROR;
		}
	*L=(DuLinkedList)malloc(sizeof(DuLNode)); //����һ��ͷ���
	if(!(*L))
		{
			printf("�����ڴ�ʧ��.\n");
			return ERROR;//�����ڴ�ʧ��
		}
	(*L)->next=NULL;
	(*L)->prior=NULL;
	printf("�����ʼ�����.\n");
	return  SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
//��������
void DestroyList_DuL(DuLinkedList *L)
{
		if(*L==NULL)
		{
			printf("�����������\n");
		}
	else
		{
			DuLinkedList p;//����ָ���ͷŵĽ��
			while(*L!=NULL)
				{
					p=(*L);
					(*L)=(*L)->next;
					free(p);
				}
			printf("�����������\n");
		}
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
//����ڵ㣨��q�嵽pǰ��
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q)
{
	
		if(p==NULL){
		printf("�ڵ�Ϊ��\n");
		return ERROR;
	}else if(p->prior==NULL){
		printf("ͷ�ڵ㲻�ܲ���\n");
		return ERROR;
	}
	else {
		q->prior=p->prior;
		p->prior=q;
		q->next=p;
		if(q->prior!=NULL) {
			q->prior->next=q;
		}
		printf("����ڵ�ɹ�\n");
		return SUCCESS;
	}
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
//����ڵ㣨��q�嵽p����
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
{
	if(p==NULL){
		printf("�ڵ�Ϊ��\n");
		return ERROR;
	}
	else {
		q->next=p->next;
		p->next=q;
		q->prior=p;
		printf("����ڵ�ɹ�\n");
		return SUCCESS;
	}
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
//ɾ���ڵ㣨 ��p����ĵ�һ���ڵ�ɾ���������ɾ���Ľڵ�����
Status DeleteList_DuL(DuLNode *p, ElemType *e)
{
	DuLinkedList q;//��¼Ҫɾ���Ľڵ㣬�ͷ� 
	if(p==NULL)
		{
			printf("�ڵ�Ϊ��\n");
			return ERROR;
		}else if(p->next==NULL){
			printf("��һ���ڵ�Ϊ��\n");
			return ERROR; 
		} 
	else
		{
			*e=(p->next)->data;//��ȡ������
			if(p->next->next!=NULL){
				p->next->next->prior=p;//��2���ڵ㶼���ǿղŽ��У�����ǿ�ָ�����ù�
			}
			q=p->next;
			p->next=p->next->next;//p���¸��������������¸����
			free(q);//�����ͷſռ�
			printf("ɾ���ڵ�ɹ�,�ýڵ�����Ϊ��%d\n",*e);
			return SUCCESS;
		}
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
//���������б����ú���visit
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
{
	if(L==NULL)
		{
			printf("�޳�ʼ������\n");

		}
	else if(L->next==NULL)
		{
			printf("����Ϊ��\n");//�������ڻ�û����
		}
	else
		{
			int i=0;//10�����ݻ�һ�� 
			DuLNode *p=L->next;
			while(p)
				{
					if(i%10==0)printf("\n");
					visit(p->data);
					p=p->next;
					i++;
				}
			printf("\n");
			printf("�����������\n");
		}
}
void Visit(ElemType e){
	printf("%d<-->",e);
}



//�������ڵ�
void AddNode(DuLinkedList *L,int num)
{
	DuLinkedList p,q;
	if(*L==NULL)
		{
			printf("δ��ʼ������");
		}
	else
		{

			
			for(q=*L; q; q=q->next)
				{
					p=q;
				}
			while(num<=0)
				{
					printf("���������0������(��ӽڵ����)\n");
					num=InputPick();
					EmptyBuff();
				}
			//p�����һ���ڵ�
			while(num>0)
				{
					q=(DuLinkedList)malloc(sizeof(DuLNode));
					q->next=NULL;
					p->next=q;
					q->prior=p; 
					p=q;
					printf("����ڵ����ݣ�");
					while(1)
						{

							if(scanf("%d",&q->data)==1)
								{
									printf("��������ɹ�\n");
									EmptyBuff();
									break;
								}
							else
								{
									printf("����������������������(������������������)\n");
									EmptyBuff();
								}
						}
					num--;
				}
		}
}
//�û�ֻ���������ּӿո����ֻ�����ֵ����� 
int isValid(const char* str)//�ж������Ƿ���Ч 
{
	int isSpaceAppear=0;
	for(; *str; str++)
		{
			
			if(isspace(*str))		isSpaceAppear=1;
			else if(!isdigit(*str))		return 0;
			else if(isdigit(*str)&&isSpaceAppear)	return 0;
		}
	return 1;
}


