#include<stdio.h>
#include<stdlib.h>
//#include<ctype.h>
#include "linkedList.h"
//#define MAX_STR_SIZE 1024
//int isValid(const char* str);
int main()
{
	void (*visit)(ElemType e)=&Visit;//����ָ��
	int num;//�û����в���ѡ��
	ElemType E;
	Status flag;//���շ���
	LinkedList	p,q,mid;
	LinkedList head=NULL;
	int pick=0;

	while(1)
		{
			Menu();
			/*fgets(str,MAX_STR_SIZE,stdin);
			if(!isValid(str))
				pick=14;
			else
				sscanf(str,"%d",&pick);*/
			switch(InputPick())
				{
					case 1:
						flag=InitList(&head);
						Judge(flag);
						clear();
						break;

					case 2:
						DestroyList(&head);
						clear();
						break;

					case 3:

						printf("��������Ҫ����Ľڵ�λ�ã�\n");
						num=InputPick();
						p=GetNode(&head,num);
						q=(LinkedList)malloc(sizeof(LNode));
						printf("���������ڵ������\n");
						q->data=InputPick();
						//scanf("%d",&q->data);
						flag=InsertList(p,q);
						Judge(flag);
						clear();
						break;

					case 4:
						printf("��������Ҫɾ���Ľڵ�λ�ã�\n");
						num=InputPick();
						p=GetNode(&head,num);
						DeleteList(p,&E);
						clear();
						break;

					case 5:
						TraverseList(head,visit);
						clear();
						break;

					case 6:
						printf("��������Ҫ��ѯ�Ľڵ�����\n");
						E=InputPick();
						flag=SearchList(head,E);
						Judge(flag);
						clear();
						break;

					case 7:
						flag=ReverseList(&head);
						Judge(flag);
						clear();
						break;

					case 8:
						flag=IsLoopList(head);
						Judge(flag);
						clear();
						break;

					case 9:
						mid=FindMidNode(&head);
						clear();
						break;

					case 10:
						head=ReverseEvenList(&head);
						clear();
						break;

					case 11:
						printf("��������Ҫ��ӵĽڵ����");
						num=InputPick();
						//EmptyBuff();����
						AddNode(&head,num);
						clear();
						break;

					case 12:
						if(head==NULL)
							{
								printf("δ��ʼ������\n");
							}
						else
							head->next=ReverseList2(head->next);
						clear();
						break;
					case 13:
						exit(0);

					default:
						printf("�޴������ѡ��\n");
						clear();
						printf("�������������ѡ��\n");
						break;
				}
		}
	return 0;
}

/*int isValid(const char* str)
{
	int isSpaceAppear=0;
	for(; *str; str++)
		{
			if(*str==' ')
				isSpaceAppear=1;
			else if(!isdigit(*str))
				return 0;
			else if(isdigit(*str)&&isSpaceAppear)
				return 0;
		}
	return 1;
}*/
