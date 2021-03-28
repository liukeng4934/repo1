#include<stdio.h>
#include<stdlib.h>
#include "linkedList.h"
int main() {
	void (*visit)(ElemType e)=&Visit;//函数指针 
	int num;//用户进行操作选择
	ElemType E; 
	Status flag;//接收反馈 
	LinkedList	p,q,mid;
	LinkedList head=NULL;
	while(1) {
		printf("单链表操作选择：\n");
		Menu();
		switch(InputPick()) {
			case 1:
				flag=InitList(&head);
				Judge(flag);
				break;

			case 2:
				DestroyList(&head);
				break;

			case 3:
			
				printf("请输入你要插入的节点位置：\n");
				num=InputPick();
				p=GetNode(&head,num);
				q=(LinkedList)malloc(sizeof(LNode));
				printf("请输入插入节点的数据\n");
				q->data=InputPick();
				//scanf("%d",&q->data);
				flag=InsertList(p,q);
				Judge(flag);
				break;

			case 4:
				printf("请输入你要删除的节点位置：\n");
				num=InputPick();
				p=GetNode(&head,num);
				DeleteList(p,&E);
				break;

			case 5:
				TraverseList(head,visit);
				break;

			case 6:
				printf("请输入你要查询的节点数据\n");
				E=InputPick();
				flag=SearchList(head,E);
				Judge(flag);
				break;

			case 7:
				flag=ReverseList(&head);
				Judge(flag);
				break;

			case 8:
				flag=IsLoopList(head);
				Judge(flag);
				break;

			case 9:
				mid=FindMidNode(&head);
				break;

			case 10:
			    head=ReverseEvenList(&head);
				break;

			case 11:
				printf("请输入你要添加的节点个数");
				num=InputPick();
				//EmptyBuff();多余 
				AddNode(&head,num);
				break;

				case 12:
					if(head==NULL){
						printf("未初始化链表\n");
					}
					else 
					head->next=ReverseList2(head->next);
					break;
			case 13:
			    exit(0);
				
				default:
				 break;
		}
	}
	return 0;
}
