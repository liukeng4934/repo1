#include<stdio.h>
#include"SqStack.h"
#include<stdlib.h>
/*	printf("1.��ʼ��ջ                          ");
	printf("2.�ж�ջ�Ƿ�Ϊ��\n");
	printf("3.�õ�ջ��Ԫ��                      ");
	printf("4.���ջ\n"); 
	printf("5.����ջ                            ");
	printf("6.���ջ����\n");
	printf("7.��ջ                              ");
	printf("8.��ջ\n");*/
	
	
int main(){
	int data;
	int length;
	ElemType e;
	SqStack s;
	s.elem=NULL; 
	Status flag;//�жϲ����Ƿ�ɹ� 
	int pick;//�û�����ѡ�� 
	int sizes;//ջ�Ĵ�С 
	while(1){
		menu();
		printf("���������ѡ��\n");
		switch(getNum()){
			case 1:
				printf("������ջ�����ռ�\n");
				sizes=getNum();
				flag=initStack(&s,sizes);
				Judge(flag);
				clear();
				break;
			case 2:
				flag=isEmptyStack(&s);
				Judge(flag);
				clear();
				break;
			case 3:
				flag=getTopStack(&s,&e);
				Judge(flag);
				clear();
				break;
			case 4:
				flag=clearStack(&s);
				Judge(flag);
				clear();
				break;
			case 5:
				flag=destroyStack(&s);
				Judge(flag);
				clear();
				break;
			case 6:
				flag=stackLength(&s,&length);
				Judge(flag);
				clear();
				break;
			case 7:
				printf("���������ջ����:\n");
				data=getNum();
				flag=pushStack(&s,data);
				Judge(flag);
				clear();
				break;
			case 8:
				flag=popStack(&s,&data);
				Judge(flag);
				clear();
				break;
			case 9:
				exit(0);
			default: 
				printf("�޴���ѡ��");
				clear();
				break;
		}
	}
	return 0;
}
