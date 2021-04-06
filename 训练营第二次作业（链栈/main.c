#include<stdio.h>
#include"LinkStack.h"
#include<stdlib.h>

/*printf("顺序栈操作选择：\n");
	printf("----------------------------------\n");
	printf("1.初始化栈                          ");
	printf("2.判断栈是否为空\n");
	printf("3.得到栈顶元素                      ");
	printf("4.清空栈\n");
	printf("5.销毁栈                            ");
	printf("6.检测栈长度\n");
	printf("7.入栈                              ");
	printf("8.出栈\n");
	printf("9.退出                              ");*/
int main()
{
	int data;
	int length;
	ElemType e;
	Status flag;//判断操作是否成功
	int pick;//用户输入选择
	LinkStack s;
	s.count=0;
	s.top=NULL;
	while(1)
		{
			menu();
			printf("请输入你的选择\n");
			switch(getNum())
				{
					case 1:
						flag=initLStack(&s);
						Judge(flag);
						printf("请输入任意数字清屏\n");
						getNum();
						system("cls");
						break;
					case 2:
						flag=isEmptyLStack(&s);
						Judge(flag);
						printf("请输入任意数字清屏\n");
						getNum();
						system("cls");
						break;
					case 3:
						flag=getTopLStack(&s,&e);
						Judge(flag);
						printf("请输入任意数字清屏\n");
						getNum();
						system("cls");
						break;
					case 4:
						flag=clearLStack(&s);
						Judge(flag);
						printf("请输入任意数字清屏\n");
						getNum();
						system("cls");
						break;
					case 5:
						flag=destroyLStack(&s);
						Judge(flag);
						printf("请输入任意数字清屏\n");
						getNum();
						system("cls");
						break;
					case 6:
						flag=LStackLength(&s,&length);
						Judge(flag);
						clear();
						break;
					case 7:
						printf("请输入你入栈的数据\n");
						data=getNum();
						flag=pushLStack(&s,data);
						Judge(flag);
						printf("请输入任意数字清屏\n");
						getNum();
						system("cls");
						break;
					case 8:
						flag=popLStack(&s,&data);
						Judge(flag);
						printf("请输入任意数字清屏\n");
						getNum();
						system("cls");
						break;
					case 9:
						exit(0);
					default:

						printf("无此项选择,请重新输入\n");
						printf("请输入任意数字清屏\n");
						getNum();
						system("cls");
						break;
				}
		}
	return 0;
}
