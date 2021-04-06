#include <stdio.h>
#include <stdlib.h>
#include"Calculator.h"
int main(){
	while(1){
		menu();
		switch(getNum()){
		
		case 1:
			calculator();
			printf("请输入任意数字清屏\n");
			getNum();
			system("cls");
			break;
			case 0:
				exit(0);
				default:
					printf("无此项选择\n");
					printf("请输入任意数字清屏\n");
					getNum();
					system("cls");	
					break;
				}
	}
 	return 0;
}

