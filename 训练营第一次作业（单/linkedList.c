#include "linkedList.h"
#include<stdlib.h>
#include<stdio.h>
#define MAX_STR_SIZE 1024
#include<ctype.h>
int isValid(const char* str);
//清屏
void clear(){
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
} 

//判断操作是否成功
void Judge(Status flag)
{
	if(flag==ERROR)
		{
			printf("操作失败\n");
		}
	else
		{
			printf("操作成功\n");
		}
}

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

void Menu()
{
	printf("单链表操作选择：\n");
	printf("----------------------------------\n");
	printf("1.链表初始化                        ");
	printf("2.销毁链表\n");
	printf("3.插入节点                          ");
	printf("4.删除节点\n"); 
	printf("5.遍历链表                          ");
	printf("6.查询节点\n");
	printf("7.反转链表(迭代)                    ");
	//printf("13.反转链表(递归)\n");
	printf("8.判断链表是否成环\n");
	printf("9.找链表的中间节点并返回            ");
	printf("10.调换奇偶顺序\n");
	printf("11.添加链表节点                     ");
	printf("12.反转链表(递归)\n");
	printf("13.退出\n");
	printf("----------------------------------\n");
	printf("请输入你的选择:\n");
}

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */

//初始化链表
Status InitList(LinkedList *L)
{
	if(*L)
		{
			printf("已经初始化过链表.\n");
			return ERROR;
		}
	*L=(LinkedList)malloc(sizeof(LNode)); //产生一个头结点
	if(!(*L))
		{
			printf("分配内存失败.\n");
			return ERROR;//分配内存失败
		}
	(*L)->next=NULL;
	printf("链表初始化完成.\n");
	return  SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
//销毁清单
void DestroyList(LinkedList *L)
{
	if(*L==NULL)
		{
			printf("无链表可销毁\n");
		}
	else
		{
			LinkedList p;//用来指向释放的结点
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
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
//插入清单  把q插到p后面
Status InsertList(LNode *p, LNode *q)
{
	if(p==NULL)
		{
			printf("节点为空\n");
			return ERROR;
		}
	q->next=p->next;//先接后插
	p->next=q;
	printf("插入节点成功\n");
	return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
//删除清单
Status DeleteList(LNode *p, ElemType *e)
{
	LinkedList q;
	if(p==NULL)
		{
			printf("节点为空\n");
			return ERROR;
		}
		else if(p->next==NULL){
			printf("下一个节点为空\n");
			return ERROR; 
		} 
	else
		{
			*e=(p->next)->data;//先取出数据
			q=p->next;
			p->next=p->next->next;//p的下个结点等于他的下下个结点
			free(q);//并且释放空间
			printf("删除节点成功,该节点数据为：%d\n",*e);
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
//遍历列表
void TraverseList(LinkedList L, void (*visit)(ElemType e))
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
			LNode *p=L->next;
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
void Visit(ElemType e)
{
	printf("%d-->",e);//输出结点的数据
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
//搜索清单
Status SearchList(LinkedList L, ElemType e)
{
	if(L==NULL)
		{
			printf("无初始化链表\n");
			return ERROR;
		}
	else
		{
			LinkedList p=L->next;
			if(p==NULL)
				{
					printf("链表为空\n");
					return ERROR;
				}
			while(p)
				{
					if(p->data==e)
						{
							printf("找到所求节点!\n");
							return SUCCESS;
						}
					/*else
						{
							printf("未找到所求节点\n");
							return ERROR;
						}*/
					p=p->next;
				}
				printf("未找到所求节点\n");
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
 
//反转列表
Status ReverseList(LinkedList *L)
{
	if((*L)==NULL)
		{
			printf("无初始化链表\n");
			return ERROR;
		}
	else if((*L)->next==NULL||((*L)->next)->next==NULL)
		{
			printf("无反转链表必要\n");
			return ERROR;//链表不存在或少于2个节点，无反转必要
		}
	else
		{
			LinkedList head,p,q,r;
			head=(*L);
			p=head->next;
			head->next=NULL;
			q=p->next;
			p->next=NULL;
			//相邻节点反向
			while(q)
				{
					r=q->next ;
					q->next=p;
					p=q;
					q=r;
				}
			head->next =p;
			printf("反转链表完成");
			return SUCCESS;
		}

}

//反转列表（递归）//传入初始化后链表的第一个节点 
LinkedList ReverseList2(LinkedList q){
	if(q==NULL||q->next==NULL){
		return q;//递归结束的条件，让他返回反转后链表的第一个节点 
	}
	LinkedList p=ReverseList2(q->next);
	
	//递归到最后一个结束，然后开始反转链表
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
//判断是否有环
Status IsLoopList(LinkedList L)
{
	if(L==NULL)
		{
			printf("无初始化链表\n");
			return ERROR;
		}
	else if(L->next==NULL)
		{
			printf("链表为空\n");
			return ERROR;
		}
	else
		{
			LinkedList slow,fast;//指针赛跑
			slow=fast=L;
			while(slow->next!=NULL&&fast!=NULL&&fast->next->next!=NULL)
				{
					slow=slow->next;
					fast=fast->next->next;
					if(slow==fast)
						{
							printf("该链表成环\n");
							return SUCCESS;
						}
				}
			printf("该链表不成环\n");
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
//奇偶节点交换位置
LNode* ReverseEvenList(LinkedList *L)
{
	if(*L==NULL)
		{
			printf("未初始化链表\n");
			return NULL;
		}
	else if((*L)->next==NULL)
		{
			printf("链表为空");
			return *L;
		}
	else
		{
			LinkedList cur=(*L)->next;
			LinkedList p;
			LinkedList head2=(LinkedList)malloc(sizeof(LNode));//新建一个头结点。用来连接新的链表//后来思考了一下，用旧的头结点好像也一样
			head2->next=NULL;
			LinkedList q=head2;
			while(cur&&cur->next)
				{
					p=cur;
					q->next=p->next;
					q=q->next;
					cur=cur->next->next;//先移开，移到下2位，再反向前面的2个节点，不然移不到下2位
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
//找中间节点并返回
LNode* FindMidNode(LinkedList *L)
{
	if((*L)==NULL)
		{
			printf("无初始化链表\n");
			return *L;
		}
	else if((*L)->next==NULL)
		{
			printf("链表为空\n");
			return *L;
		}
	else
		{
			LinkedList fast, slow;//一个走2步，一个走一步，到NULL就是一半
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

//添加链表节点
void AddNode(LinkedList *L,int num)
{
	LinkedList p,q;
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
					q=(LinkedList)malloc(sizeof(LNode));
					q->next=NULL;
					p->next=q;
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



//获取链表节点
LNode* GetNode(LinkedList *L,int index)
{
	LNode *p=*L;
	if(*L==NULL)
		{
			printf("未初始化链表\n");
			return NULL;
		}
	else if((*L)->next==NULL)
		{
			printf("链表为空\n");
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
