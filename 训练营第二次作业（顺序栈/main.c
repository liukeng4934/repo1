#include<stdio.h>
#include"SqStack.h"
#include<stdlib.h>
/*	printf("1.初始化栈                          ");
	printf("2.判断栈是否为空\n");
	printf("3.得到栈顶元素                      ");
	printf("4.清空栈\n"); 
	printf("5.销毁栈                            ");
	printf("6.检测栈长度\n");
	printf("7.入栈                              ");
	printf("8.出栈\n");*/
	
	
int main(){
	int data;
	int length;
	ElemType e;
	SqStack s;
	s.elem=NULL; 
	Status flag;//判断操作是否成功 
	int pick;//用户输入选择 
	int sizes;//栈的大小 
	while(1){
		menu();
		printf("请输入你的选择\n");
		switch(getNum()){
			case 1:
				printf("请输入栈的最大空间\n");
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
				printf("请输入你进栈数据:\n");
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
				printf("无此项选择");
				clear();
				break;
		}
	}
	return 0;
}
