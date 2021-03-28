#include "duLinkedList.h"
#include<stdio.h>
#include<stdlib.h>

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */


//��ȡ����ڵ�
DuLNode* GetNode(DuLinkedList *L,int index)
{
	DuLNode *p;
	if(*L==NULL)
		{
			printf("δ��ʼ������\n");
			return *L;
		}
	else if((*L)->next==NULL)
		{
			printf("����Ϊ��\n");
			return *L;
		}
	else
		{
			p=*L;
			while(1)
				{
					if(index<=0)
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
		}
	return p;
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
int InputPick()
{
	int pick;
	while(1)
		{
			if(	scanf("%d",&pick)==1)
				{
					printf("��������ɹ�\n");
					EmptyBuff();
					break;
				}
			else
				{
					printf("�������Ͳ���ȷ������������(��������)\n");
					EmptyBuff();
				}
		}
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
	printf("----------------------------------\n");
	printf("1.�����ʼ��\n");
	printf("2.��������\n");
	printf("3.����ڵ�(��ָ��λ��ǰ)\n");
	printf("4.����ڵ�(��ָ��λ�ú�)\n");
	printf("5.ɾ���ڵ�(��ָ��λ�ú�)\n");
	printf("6.��������\n");
	printf("7.�����������\n");
	printf("8.�˳�");
	printf("----------------------------------\n");
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
	}
	else {
		q->prior=p->prior;
		p->prior=q;
		q->next=p;
		q->prior->next=q;
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
	DuLinkedList q;
	if(p==NULL)
		{
			printf("�ڵ�Ϊ��\n");
			return ERROR;
		}
	else
		{
			*e=(p->next)->data;//��ȡ������
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
	printf("<--%d-->",e);
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




