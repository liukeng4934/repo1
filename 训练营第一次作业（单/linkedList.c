#include "linkedList.h"
#include<stdlib.h>
#include<stdio.h>
#define MAX_STR_SIZE 1024
#include<ctype.h>
int isValid(const char* str);
//����
void clear(){
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
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

void Menu()
{
	printf("���������ѡ��\n");
	printf("----------------------------------\n");
	printf("1.�����ʼ��                        ");
	printf("2.��������\n");
	printf("3.����ڵ�                          ");
	printf("4.ɾ���ڵ�\n"); 
	printf("5.��������                          ");
	printf("6.��ѯ�ڵ�\n");
	printf("7.��ת����(����)                    ");
	//printf("13.��ת����(�ݹ�)\n");
	printf("8.�ж������Ƿ�ɻ�\n");
	printf("9.��������м�ڵ㲢����            ");
	printf("10.������ż˳��\n");
	printf("11.�������ڵ�                     ");
	printf("12.��ת����(�ݹ�)\n");
	printf("13.�˳�\n");
	printf("----------------------------------\n");
	printf("���������ѡ��:\n");
}

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */

//��ʼ������
Status InitList(LinkedList *L)
{
	if(*L)
		{
			printf("�Ѿ���ʼ��������.\n");
			return ERROR;
		}
	*L=(LinkedList)malloc(sizeof(LNode)); //����һ��ͷ���
	if(!(*L))
		{
			printf("�����ڴ�ʧ��.\n");
			return ERROR;//�����ڴ�ʧ��
		}
	(*L)->next=NULL;
	printf("�����ʼ�����.\n");
	return  SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
//�����嵥
void DestroyList(LinkedList *L)
{
	if(*L==NULL)
		{
			printf("�����������\n");
		}
	else
		{
			LinkedList p;//����ָ���ͷŵĽ��
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
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
//�����嵥  ��q�嵽p����
Status InsertList(LNode *p, LNode *q)
{
	if(p==NULL)
		{
			printf("�ڵ�Ϊ��\n");
			return ERROR;
		}
	q->next=p->next;//�ȽӺ��
	p->next=q;
	printf("����ڵ�ɹ�\n");
	return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
//ɾ���嵥
Status DeleteList(LNode *p, ElemType *e)
{
	LinkedList q;
	if(p==NULL)
		{
			printf("�ڵ�Ϊ��\n");
			return ERROR;
		}
		else if(p->next==NULL){
			printf("��һ���ڵ�Ϊ��\n");
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
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
//�����б�
void TraverseList(LinkedList L, void (*visit)(ElemType e))
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
			LNode *p=L->next;
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
void Visit(ElemType e)
{
	printf("%d-->",e);//�����������
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
//�����嵥
Status SearchList(LinkedList L, ElemType e)
{
	if(L==NULL)
		{
			printf("�޳�ʼ������\n");
			return ERROR;
		}
	else
		{
			LinkedList p=L->next;
			if(p==NULL)
				{
					printf("����Ϊ��\n");
					return ERROR;
				}
			while(p)
				{
					if(p->data==e)
						{
							printf("�ҵ�����ڵ�!\n");
							return SUCCESS;
						}
					/*else
						{
							printf("δ�ҵ�����ڵ�\n");
							return ERROR;
						}*/
					p=p->next;
				}
				printf("δ�ҵ�����ڵ�\n");
							return ERROR;
		}
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
 
//��ת�б�
Status ReverseList(LinkedList *L)
{
	if((*L)==NULL)
		{
			printf("�޳�ʼ������\n");
			return ERROR;
		}
	else if((*L)->next==NULL||((*L)->next)->next==NULL)
		{
			printf("�޷�ת�����Ҫ\n");
			return ERROR;//�������ڻ�����2���ڵ㣬�޷�ת��Ҫ
		}
	else
		{
			LinkedList head,p,q,r;
			head=(*L);
			p=head->next;
			head->next=NULL;
			q=p->next;
			p->next=NULL;
			//���ڽڵ㷴��
			while(q)
				{
					r=q->next ;
					q->next=p;
					p=q;
					q=r;
				}
			head->next =p;
			printf("��ת�������");
			return SUCCESS;
		}

}

//��ת�б��ݹ飩//�����ʼ��������ĵ�һ���ڵ� 
LinkedList ReverseList2(LinkedList q){
	if(q==NULL||q->next==NULL){
		return q;//�ݹ�������������������ط�ת������ĵ�һ���ڵ� 
	}
	LinkedList p=ReverseList2(q->next);
	
	//�ݹ鵽���һ��������Ȼ��ʼ��ת����
	q->next->next=q;
	q->next=NULL;
	return p; 
}
 


/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
//�ж��Ƿ��л�
Status IsLoopList(LinkedList L)
{
	if(L==NULL)
		{
			printf("�޳�ʼ������\n");
			return ERROR;
		}
	else if(L->next==NULL)
		{
			printf("����Ϊ��\n");
			return ERROR;
		}
	else
		{
			LinkedList slow,fast;//ָ������
			slow=fast=L;
			while(slow->next!=NULL&&fast!=NULL&&fast->next->next!=NULL)
				{
					slow=slow->next;
					fast=fast->next->next;
					if(slow==fast)
						{
							printf("������ɻ�\n");
							return SUCCESS;
						}
				}
			printf("�������ɻ�\n");
			return ERROR;
		}
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
//��ż�ڵ㽻��λ��
LNode* ReverseEvenList(LinkedList *L)
{
	if(*L==NULL)
		{
			printf("δ��ʼ������\n");
			return NULL;
		}
	else if((*L)->next==NULL)
		{
			printf("����Ϊ��");
			return *L;
		}
	else
		{
			LinkedList cur=(*L)->next;
			LinkedList p;
			LinkedList head2=(LinkedList)malloc(sizeof(LNode));//�½�һ��ͷ��㡣���������µ�����//����˼����һ�£��þɵ�ͷ������Ҳһ��
			head2->next=NULL;
			LinkedList q=head2;
			while(cur&&cur->next)
				{
					p=cur;
					q->next=p->next;
					q=q->next;
					cur=cur->next->next;//���ƿ����Ƶ���2λ���ٷ���ǰ���2���ڵ㣬��Ȼ�Ʋ�����2λ
					q->next=p;
					q=q->next;
				}
			q->next=cur;
			return head2;
		}
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
//���м�ڵ㲢����
LNode* FindMidNode(LinkedList *L)
{
	if((*L)==NULL)
		{
			printf("�޳�ʼ������\n");
			return *L;
		}
	else if((*L)->next==NULL)
		{
			printf("����Ϊ��\n");
			return *L;
		}
	else
		{
			LinkedList fast, slow;//һ����2����һ����һ������NULL����һ��
			fast = slow = *L;
			while(fast!=NULL)
				{
					if(fast->next == NULL)
						{
							fast = fast->next;
						}
					else
						{
							fast = fast->next->next;
						}
					slow = slow->next;
				}
			return slow;

		}
}

//�������ڵ�
void AddNode(LinkedList *L,int num)
{
	LinkedList p,q;
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
					q=(LinkedList)malloc(sizeof(LNode));
					q->next=NULL;
					p->next=q;
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



//��ȡ����ڵ�
LNode* GetNode(LinkedList *L,int index)
{
	LNode *p=*L;
	if(*L==NULL)
		{
			printf("δ��ʼ������\n");
			return NULL;
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
