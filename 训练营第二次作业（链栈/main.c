#include<stdio.h>
#include"LinkStack.h"
#include<stdlib.h>

/*printf("˳��ջ����ѡ��\n");
	printf("----------------------------------\n");
	printf("1.��ʼ��ջ                          ");
	printf("2.�ж�ջ�Ƿ�Ϊ��\n");
	printf("3.�õ�ջ��Ԫ��                      ");
	printf("4.���ջ\n");
	printf("5.����ջ                            ");
	printf("6.���ջ����\n");
	printf("7.��ջ                              ");
	printf("8.��ջ\n");
	printf("9.�˳�                              ");*/
int main()
{
	int data;
	int length;
	ElemType e;
	Status flag;//�жϲ����Ƿ�ɹ�
	int pick;//�û�����ѡ��
	LinkStack s;
	s.count=0;
	s.top=NULL;
	while(1)
		{
			menu();
			printf("���������ѡ��\n");
			switch(getNum())
				{
					case 1:
						flag=initLStack(&s);
						Judge(flag);
						printf("������������������\n");
						getNum();
						system("cls");
						break;
					case 2:
						flag=isEmptyLStack(&s);
						Judge(flag);
						printf("������������������\n");
						getNum();
						system("cls");
						break;
					case 3:
						flag=getTopLStack(&s,&e);
						Judge(flag);
						printf("������������������\n");
						getNum();
						system("cls");
						break;
					case 4:
						flag=clearLStack(&s);
						Judge(flag);
						printf("������������������\n");
						getNum();
						system("cls");
						break;
					case 5:
						flag=destroyLStack(&s);
						Judge(flag);
						printf("������������������\n");
						getNum();
						system("cls");
						break;
					case 6:
						flag=LStackLength(&s,&length);
						Judge(flag);
						clear();
						break;
					case 7:
						printf("����������ջ������\n");
						data=getNum();
						flag=pushLStack(&s,data);
						Judge(flag);
						printf("������������������\n");
						getNum();
						system("cls");
						break;
					case 8:
						flag=popLStack(&s,&data);
						Judge(flag);
						printf("������������������\n");
						getNum();
						system("cls");
						break;
					case 9:
						exit(0);
					default:

						printf("�޴���ѡ��,����������\n");
						printf("������������������\n");
						getNum();
						system("cls");
						break;
				}
		}
	return 0;
}
