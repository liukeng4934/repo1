#include<stdio.h>
#include<stdlib.h>
#include"duLinkedList.h"
int main()
{
	void (*visit)(ElemType e)=&Visit;//函数指针
	DuLinkedList head,p,q;
	head=p=q=NULL;
	ElemType E;
	Status flag;//接受反馈
	int num;//用户进行操作选择
	while(1)
		{
			printf("双向链表操作选择：\n");
			Menu();
			switch(InputPick())
				{
					case 1:
						flag=InitList_DuL(&head);
						Judge(flag);
						break;
					case 2:
						DestroyList_DuL(&head);
						break;
					case 3:
						printf("请输入你要插入的节点位置：\n");
						num=InputPick();
						p=GetNode(&head,num);
						q=(DuLinkedList)malloc(sizeof(DuLNode));
						printf("请输入插入节点的数据\n");
						q->data=InputPick();
						//scanf("%d",&q->data);
						flag=InsertBeforeList_DuL(p,q);
						Judge(flag);
						break;
					case 4:
						printf("请输入你要插入的节点位置：\n");
						num=InputPick();
						p=GetNode(&head,num);
						q=(DuLinkedList)malloc(sizeof(DuLNode));
						printf("请输入插入节点的数据\n");
						q->data=InputPick();
						//scanf("%d",&q->data);
						flag=InsertAfterList_DuL(p,q);
						Judge(flag);
						break;
					case 5:
						printf("请输入你要删除的节点位置：\n");
						num=InputPick();
						p=GetNode(&head,num);
						DeleteList_DuL(p,&E);
						break;

					case 6:
						TraverseList_DuL(head,visit);
						break;
					case 7:

				printf("请输入你要添加的节点个数");
				num=InputPick();
				AddNode(&head,num);
				break;	
				
				case 8:exit(0);
				default: break;	
				}
		}
}





