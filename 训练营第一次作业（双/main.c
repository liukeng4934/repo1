#include<stdio.h>
#include<stdlib.h>
#include"duLinkedList.h"
int main()
{
	void (*visit)(ElemType e)=&Visit;//����ָ��
	DuLinkedList head,p,q;
	head=p=q=NULL;
	ElemType E;
	Status flag;//���ܷ���
	int num;//�û����в���ѡ��
	while(1)
		{
			
			Menu();
			switch(InputPick())
				{
					case 1:
						flag=InitList_DuL(&head);
						Judge(flag);
						clear();
						break;
					case 2:
						DestroyList_DuL(&head);
						clear();
						break;
					case 3:
						printf("��������Ҫ����Ľڵ�λ�ã�\n");
						num=InputPick();
						p=GetNode(&head,num);
						q=(DuLinkedList)malloc(sizeof(DuLNode));
						printf("���������ڵ������\n");
						q->data=InputPick();
						//scanf("%d",&q->data);
						flag=InsertBeforeList_DuL(p,q);
						Judge(flag);
						clear();
						break;
					case 4:
						printf("��������Ҫ����Ľڵ�λ�ã�\n");
						num=InputPick();
						p=GetNode(&head,num);
						q=(DuLinkedList)malloc(sizeof(DuLNode));
						printf("���������ڵ������\n");
						q->data=InputPick();
						//scanf("%d",&q->data);
						flag=InsertAfterList_DuL(p,q);
						Judge(flag);
						clear();
						break;
					case 5:
						printf("��������Ҫɾ���Ľڵ�λ�ã�\n");
						num=InputPick();
						p=GetNode(&head,num);
						DeleteList_DuL(p,&E);
						clear();
						break;

					case 6:
						TraverseList_DuL(head,visit);
						clear();
						break;
					case 7:

				printf("��������Ҫ��ӵĽڵ����");
				num=InputPick();
				AddNode(&head,num);
				clear();
				break;	
				
				case 8:exit(0);
				default: 
				printf("�޴������\n");
				clear();
				break;	
				}
		}
}





