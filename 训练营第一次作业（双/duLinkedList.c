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


//清屏
void clear(){
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
} 

//获取链表节点
DuLNode* GetNode(DuLinkedList *L,int index)
{
	DuLNode *p=*L;
	if(*L==NULL)
		{
			printf("未初始化链表\n");
			return *L;
		}
	else if((*L)->next==NULL)
		{
			printf("链表为空\n");
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
							printf("你输入的数据不符合(请输入大于0的整数)");
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

//判断操作是否成功
void Judge(Status flag)
{
	if(flag==ERROR)
		{
			printf("操作失败\n\n");
		}
	else
		{
			printf("操作成功\n\n");
		}
}

//输入用户的选择
//输入选择
int InputPick()
{
	char str[MAX_STR_SIZE]= {0};
	int pick=0;
	fgets(str,MAX_STR_SIZE,stdin);//注意，fges会把回车吃进字符串中！！！！！！！！！ 
	if(!isValid(str))
	{
		printf("你输入的数据不符合，请重新输入\n");
		//EmptyBuff();//把错的数据吃完
		pick=InputPick();
	 } 
	else
	sscanf(str,"%d",&pick);
	return pick;
}



//清空缓冲区
void EmptyBuff()
{
	char ch;
	while((ch=getchar())!=EOF&&ch!='\n')
		{
			;
		}
}

//菜单
void Menu()
{
	char c;
	printf("双向链表操作选择：\n");
	printf("---------------------------------------------------------------------\n");
	printf("1.链表初始化                          ");
	printf("2.销毁链表\n");
	printf("3.插入节点(在指点位置前)              ");
	printf("4.插入节点(在指点位置后)\n");
	printf("5.删除节点(在指点位置后)              ");
	printf("6.遍历链表\n");
	printf("7.添加链表数据                        ");
	printf("8.退出\n");
	printf("---------------------------------------------------------------------\n");
}
//初始化链表
Status InitList_DuL(DuLinkedList *L)
{
		
		if(*L)
		{
			printf("已经初始化过链表.\n");
			return ERROR;
		}
	*L=(DuLinkedList)malloc(sizeof(DuLNode)); //产生一个头结点
	if(!(*L))
		{
			printf("分配内存失败.\n");
			return ERROR;//分配内存失败
		}
	(*L)->next=NULL;
	(*L)->prior=NULL;
	printf("链表初始化完成.\n");
	return  SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
//销毁链表
void DestroyList_DuL(DuLinkedList *L)
{
		if(*L==NULL)
		{
			printf("无链表可销毁\n");
		}
	else
		{
			DuLinkedList p;//用来指向释放的结点
			while(*L!=NULL)
				{
					p=(*L);
					(*L)=(*L)->next;
					free(p);
				}
			printf("销毁链表完成\n");
		}
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
//插入节点（把q插到p前面
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q)
{
	
		if(p==NULL){
		printf("节点为空\n");
		return ERROR;
	}else if(p->prior==NULL){
		printf("头节点不能插入\n");
		return ERROR;
	}
	else {
		q->prior=p->prior;
		p->prior=q;
		q->next=p;
		if(q->prior!=NULL) {
			q->prior->next=q;
		}
		printf("插入节点成功\n");
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
//插入节点（把q插到p后面
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
{
	if(p==NULL){
		printf("节点为空\n");
		return ERROR;
	}
	else {
		q->next=p->next;
		p->next=q;
		q->prior=p;
		printf("插入节点成功\n");
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
//删除节点（ 把p后面的第一个节点删除，并输出删除的节点数据
Status DeleteList_DuL(DuLNode *p, ElemType *e)
{
	DuLinkedList q;//记录要删除的节点，释放 
	if(p==NULL)
		{
			printf("节点为空\n");
			return ERROR;
		}else if(p->next==NULL){
			printf("下一个节点为空\n");
			return ERROR; 
		} 
	else
		{
			*e=(p->next)->data;//先取出数据
			if(p->next->next!=NULL){
				p->next->next->prior=p;//下2个节点都不是空才进行，如果是空指针则不用管
			}
			q=p->next;
			p->next=p->next->next;//p的下个结点等于他的下下个结点
			free(q);//并且释放空间
			printf("删除节点成功,该节点数据为：%d\n",*e);
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
//遍历链接列表并调用函数visit
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
{
	if(L==NULL)
		{
			printf("无初始化链表\n");

		}
	else if(L->next==NULL)
		{
			printf("链表为空\n");//链表不存在或没数据
		}
	else
		{
			int i=0;//10个数据换一行 
			DuLNode *p=L->next;
			while(p)
				{
					if(i%10==0)printf("\n");
					visit(p->data);
					p=p->next;
					i++;
				}
			printf("\n");
			printf("遍历链表完成\n");
		}
}
void Visit(ElemType e){
	printf("%d<-->",e);
}



//添加链表节点
void AddNode(DuLinkedList *L,int num)
{
	DuLinkedList p,q;
	if(*L==NULL)
		{
			printf("未初始化链表");
		}
	else
		{

			
			for(q=*L; q; q=q->next)
				{
					p=q;
				}
			while(num<=0)
				{
					printf("请输入大于0的整数(添加节点个数)\n");
					num=InputPick();
					EmptyBuff();
				}
			//p是最后一个节点
			while(num>0)
				{
					q=(DuLinkedList)malloc(sizeof(DuLNode));
					q->next=NULL;
					p->next=q;
					q->prior=p; 
					p=q;
					printf("输入节点数据：");
					while(1)
						{

							if(scanf("%d",&q->data)==1)
								{
									printf("数据输入成功\n");
									EmptyBuff();
									break;
								}
							else
								{
									printf("数据输入有误，请重新输入(请输入整数类型数据)\n");
									EmptyBuff();
								}
						}
					num--;
				}
		}
}
//用户只能输入数字加空格或者只有数字的数据 
int isValid(const char* str)//判断数据是否有效 
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


