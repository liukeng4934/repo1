#include <stdio.h>
#include <stdlib.h>
#include"Calculator.h"
int main(){
	while(1){
		menu();
		switch(getNum()){
		
		case 1:
			calculator();
			printf("������������������\n");
			getNum();
			system("cls");
			break;
			case 0:
				exit(0);
				default:
					printf("�޴���ѡ��\n");
					printf("������������������\n");
					getNum();
					system("cls");	
					break;
				}
	}
 	return 0;
}

