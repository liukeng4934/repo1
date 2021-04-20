#include<stdio.h>
#include"sort.h"
#include<time.h>
#include <stdlib.h>
int main()
{
	double all=0;//��ʱ��
	char c;
	int a[200000];
	int b[200000];
	int *q;
	int *p;
	double begin, end;
	double  cost;
	FILE *f1;
	int i;
	int size;
	long round;
	long number;//��������
	while(1)
		{
			menu();
			printf("���������ѡ��\n");
			switch(getNum())
				{
					case 1:
						for(i=0; i<10000; i++)
							{
								a[i]=rand()%100+1;
							}
						begin=clock();
						insertSort(a,10000);
						end=clock();
						cost=(double)(end-begin)/1000;
						printf("�������򻨷�ʱ��:%fs\n",cost);
						for(i=0; i<10000; i++)
							{
								a[i]=rand()%100+1;
							}
						begin=clock();
						MergeSort(a,0,10000-1,b);
						end=clock();
						cost=(double)(end-begin)/1000;
						printf("�鲢���򻨷�ʱ��:%fs\n",cost);
						for(i=0; i<10000; i++)
							{
								a[i]=rand()%100+1;
							}
						begin=clock();
						QuicSort_Recursion(a,0, 10000-1);
						end=clock();
						cost=(double)(end-begin)/1000;
						printf("��������(�ݹ�)����ʱ��:%fs\n",cost);
						for(i=0; i<10000; i++)
							{
								a[i]=rand()%100+1;
							}
						begin=clock();
						QuicSort(a,0,10000-1);
						end=clock();
						cost=(double)(end-begin)/1000;
						printf("��������(�ǵݹ�)����ʱ��:%fs\n",cost);
						for(i=0; i<10000; i++)
							{
								a[i]=rand()%100+1;
							}
						begin=clock();
						QuicSort1(a,0,10000-1);
						end=clock();
						cost=(double)(end-begin)/1000;
						printf("��������(������)����ʱ��:%fs\n",cost);
						for(i=0; i<10000; i++)
							{
								a[i]=rand()%100+1;
							}
						begin=clock();
						CountSort(a,10000 ,100);
						end=clock();
						cost=(double)(end-begin)/1000;
						printf("�������򻨷�ʱ��:%fs\n",cost);
						for(i=0; i<10000; i++)
							{
								a[i]=rand()%100+1;
							}
						begin=clock();
						RadixCountSort(a,10000);
						end=clock();
						cost=(double)(end-begin)/1000;
						printf("�����������򻨷�ʱ��:%fs\n",cost);
						printf("�����������ַ�ˢ��\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 2:
						for(i=0; i<50000; i++)
							{
								a[i]=rand()%100+1;
							}
						begin=clock();
						insertSort(a,50000);
						end=clock();
						cost=(double)(end-begin)/1000;
						printf("�������򻨷�ʱ��:%fs\n",cost);
						for(i=0; i<50000; i++)
							{
								a[i]=rand()%100+1;
							}
						begin=clock();
						MergeSort(a,0,50000-1,b);
						end=clock();
						cost=(double)(end-begin)/1000;
						printf("�鲢���򻨷�ʱ��:%fs\n",cost);
						for(i=0; i<50000; i++)
							{
								a[i]=rand()%100+1;
							}
						begin=clock();
						QuicSort_Recursion(a,0, 50000-1);
						end=clock();
						cost=(double)(end-begin)/1000;
						printf("��������(�ݹ�)����ʱ��:%fs\n",cost);
						for(i=0; i<50000; i++)
							{
								a[i]=rand()%100+1;
							}
						begin=clock();
						QuicSort(a,0,50000-1);
						end=clock();
						cost=(double)(end-begin)/1000;
						printf("��������(�ǵݹ�)����ʱ��:%fs\n",cost);
						for(i=0; i<50000; i++)
							{
								a[i]=rand()%100+1;
							}
						begin=clock();
						QuicSort1(a,0,50000-1);
						end=clock();
						cost=(double)(end-begin)/1000;
						printf("��������(������)����ʱ��:%fs\n",cost);
						for(i=0; i<50000; i++)
							{
								a[i]=rand()%100+1;
							}
						begin=clock();
						CountSort(a,50000 ,100);
						end=clock();
						cost=(double)(end-begin)/1000;
						printf("�������򻨷�ʱ��:%fs\n",cost);
						for(i=0; i<50000; i++)
							{
								a[i]=rand()%100+1;
							}
						begin=clock();
						RadixCountSort(a,50000);
						end=clock();
						cost=(double)(end-begin)/1000;
						printf("�����������򻨷�ʱ��:%fs\n",cost);
						printf("�����������ַ�ˢ��\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 3:
						for(i=0; i<200000; i++)
							{
								a[i]=rand()%100+1;
							}
						begin=clock();
						insertSort(a,200000);
						end=clock();
						cost=(double)(end-begin)/1000;
						printf("�������򻨷�ʱ��:%fs\n",cost);
						for(i=0; i<200000; i++)
							{
								a[i]=rand()%100+1;
							}
						begin=clock();
						MergeSort(a,0,200000-1,b);
						end=clock();
						cost=(double)(end-begin)/1000;
						printf("�鲢���򻨷�ʱ��:%fs\n",cost);
						for(i=0; i<200000; i++)
							{
								a[i]=rand()%100+1;
							}
						begin=clock();
						QuicSort_Recursion(a,0, 200000-1);
						end=clock();
						cost=(double)(end-begin)/1000;
						printf("��������(�ݹ�)����ʱ��:%fs\n",cost);
						for(i=0; i<200000; i++)
							{
								a[i]=rand()%100+1;
							}
						begin=clock();
						QuicSort(a,0,200000-1);
						end=clock();
						cost=(double)(end-begin)/1000;
						printf("��������(�ǵݹ�)����ʱ��:%fs\n",cost);
						for(i=0; i<200000; i++)
							{
								a[i]=rand()%100+1;
							}
						begin=clock();
						QuicSort1(a,0,200000-1);
						end=clock();
						cost=(double)(end-begin)/1000;
						printf("��������(������)����ʱ��:%fs\n",cost);
						for(i=0; i<200000; i++)
							{
								a[i]=rand()%100+1;
							}
						begin=clock();
						CountSort(a,200000 ,100);
						end=clock();
						cost=(double)(end-begin)/1000;
						printf("�������򻨷�ʱ��:%fs\n",cost);
						for(i=0; i<200000; i++)
							{
								a[i]=rand()%100+1;
							}
						begin=clock();
						RadixCountSort(a,200000);
						end=clock();
						cost=(double)(end-begin)/1000;
						printf("�����������򻨷�ʱ��:%fs\n",cost);
						printf("�����������ַ�ˢ��\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
					case 4:
						p=(int *)malloc(100*sizeof(int));
						for(i=0; i<100000; i++)
							{
								memcpy(p,a,100*sizeof(int));
								begin=clock();
								insertSort(p,100);
								end=clock();
								cost=(double)(end-begin)/1000;
								all+=cost;
							}
						printf("�������򻨷�ʱ��:%fs\n",all);
						all=0;
						for(i=0; i<100000; i++)
							{
								memcpy(p,a,100*sizeof(int));
								begin=clock();
								MergeSort(p,0,100-1,b);
								end=clock();
								cost=(double)(end-begin)/1000;
								all+=cost;
							}
						printf("�鲢���򻨷�ʱ��:%fs\n",all);
						all=0;
						for(i=0; i<100000; i++)
							{
								memcpy(p,a,100*sizeof(int));
								begin=clock();
								QuicSort_Recursion(p,0, 100-1);
								end=clock();
								cost=(double)(end-begin)/1000;
								all+=cost;
							}

						printf("��������(�ݹ�)����ʱ��:%fs\n",all);
						all=0;
						for(i=0; i<100000; i++)
							{
								memcpy(p,a,100*sizeof(int));
								begin=clock();
								QuicSort(p,0,100-1);
								end=clock();
								cost=(double)(end-begin)/1000;
								all+=cost;
							}

						printf("��������(�ǵݹ�)����ʱ��:%fs\n",all);
						all=0;
						for(i=0; i<100000; i++)
							{
								memcpy(p,a,100*sizeof(int));
								begin=clock();
								QuicSort1(p,0,100-1);
								end=clock();
								cost=(double)(end-begin)/1000;
								all+=cost;
							}

						printf("��������(������)����ʱ��:%fs\n",all);
						all=0;
						for(i=0; i<100000; i++)
							{
								memcpy(p,a,100*sizeof(int));
								begin=clock();
								CountSort(p,100 ,100);
								end=clock();
								cost=(double)(end-begin)/1000;
								all+=cost;
							}

						printf("�������򻨷�ʱ��:%fs\n",all);
						all=0;
						for(i=0; i<100000; i++)
							{
								memcpy(p,a,100*sizeof(int));
								begin=clock();
								RadixCountSort(p,100);
								end=clock();
								cost=(double)(end-begin)/1000;
								all+=cost;
							}

						printf("�����������򻨷�ʱ��:%fs\n",all);
						all=0;
						printf("�����������ַ�ˢ��\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						free(p);
						break;
					case 5:
						printf("������������������С\n");
						size=getNum1();
						printf("����������������\n");
						round=getNum1();
						q=(int *)malloc(size*sizeof(int));
						p=(int *)malloc(size*sizeof(int));
						if((f1=fopen("number.txt","ab"))==NULL)
							{
								printf("cannont open file\n");
								exit(0);
							}
						for(i=0; i<size; i++)
							{
								number=rand()%100+1;
								q[i]=number;
								fwrite(&number,sizeof(int),1,f1);
							}
						fclose(f1);
						/*if((f1=fopen("number.txt","rb"))==NULL)
							{
								printf("cannot open file\n");
								exit(0);
							}
							for(i=0; i<size; i++)
							{
								fread(&q[i],sizeof(int),1,f1);
							}
						
						fclose(f1);*/
						for(i=0; i<round; i++)
							{
								memcpy(p,q,size*sizeof(int));
								begin=clock();
								insertSort(p,size);
								end=clock();
								cost=(double)(end-begin)/1000;
								all+=cost;
							}
						printf("�������򻨷�ʱ��:%fs\n",all);
						all=0;
						for(i=0; i<round; i++)
							{
								memcpy(p,q,size*sizeof(int));
      								begin=clock();
								MergeSort(p,0,size-1,b);
								end=clock();
								cost=(double)(end-begin)/1000;
								all+=cost;
							}
						printf("�鲢���򻨷�ʱ��:%fs\n",all);
						all=0;
						for(i=0; i<round; i++)
							{
								memcpy(p,q,size*sizeof(int));
								begin=clock();
								QuicSort_Recursion(p,0, size-1);
								end=clock();
								cost=(double)(end-begin)/1000;
								all+=cost;
							}

						printf("��������(�ݹ�)����ʱ��:%fs\n",all);
						all=0;
						for(i=0; i<round; i++)
							{
								memcpy(p,q,size*sizeof(int));
								begin=clock();
								QuicSort(p,0,size-1);
								end=clock();
								cost=(double)(end-begin)/1000;
								all+=cost;
							}

						printf("��������(�ǵݹ�)����ʱ��:%fs\n",all);
						all=0;
						for(i=0; i<round; i++)
							{
								memcpy(p,q,size*sizeof(int));
								begin=clock();
								QuicSort1(p,0,size-1);
								end=clock();
								cost=(double)(end-begin)/1000;
								all+=cost;
							}

						printf("��������(������)����ʱ��:%fs\n",all);
						all=0;
						for(i=0; i<round; i++)
							{
								memcpy(p,q,size*sizeof(int));
								begin=clock();
								CountSort(p,size ,100);
								end=clock();
								cost=(double)(end-begin)/1000;
								all+=cost;
							}

						printf("�������򻨷�ʱ��:%fs\n",all);
						all=0;
						for(i=0; i<round; i++)
							{
								memcpy(p,q,size*sizeof(int));
								begin=clock();
								RadixCountSort(p,(int)size);
								end=clock();
								cost=(double)(end-begin)/1000;
								all+=cost;
							}

						printf("�����������򻨷�ʱ��:%fs\n",all);
						all=0;
						printf("�����������ַ�ˢ��\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						free(p);
						free(q);
						break;
					case 6:
						printf("������������������С\n");
						size=getNum1();
						printf("����������������\n");
						round=getNum1();
						q=(int *)malloc(size*sizeof(int));
						p=(int *)malloc(size*sizeof(int));
						/*if((f1=fopen("number.txt","ab"))==NULL)
							{
								printf("cannont open file\n");
								exit(0);
							}
						for(i=0; i<size; i++)
							{
								number=rand()%100+1;
								q[i]=number;
								fwrite(&number,sizeof(int),1,f1);
							}
						fclose(f1);*/
						if((f1=fopen("number.txt","rb"))==NULL)
							{
								printf("cannot open file\n");
								exit(0);
							}
							for(i=0; i<size; i++)
							{
								fread(&q[i],sizeof(int),1,f1);
							}
						
						fclose(f1);
						for(i=0; i<round; i++)
							{
								memcpy(p,q,size*sizeof(int));
								begin=clock();
								insertSort(p,size);
								end=clock();
								cost=(double)(end-begin)/1000;
								all+=cost;
							}
						printf("�������򻨷�ʱ��:%fs\n",all);
						all=0;
						for(i=0; i<round; i++)
							{
								memcpy(p,q,size*sizeof(int));
      								begin=clock();
								MergeSort(p,0,size-1,b);
								end=clock();
								cost=(double)(end-begin)/1000;
								all+=cost;
							}
						printf("�鲢���򻨷�ʱ��:%fs\n",all);
						all=0;
						for(i=0; i<round; i++)
							{
								memcpy(p,q,size*sizeof(int));
								begin=clock();
								QuicSort_Recursion(p,0, size-1);
								end=clock();
								cost=(double)(end-begin)/1000;
								all+=cost;
							}

						printf("��������(�ݹ�)����ʱ��:%fs\n",all);
						all=0;
						for(i=0; i<round; i++)
							{
								memcpy(p,q,size*sizeof(int));
								begin=clock();
								QuicSort(p,0,size-1);
								end=clock();
								cost=(double)(end-begin)/1000;
								all+=cost;
							}

						printf("��������(�ǵݹ�)����ʱ��:%fs\n",all);
						all=0;
						for(i=0; i<round; i++)
							{
								memcpy(p,q,size*sizeof(int));
								begin=clock();
								QuicSort1(p,0,size-1);
								end=clock();
								cost=(double)(end-begin)/1000;
								all+=cost;
							}

						printf("��������(������)����ʱ��:%fs\n",all);
						all=0;
						for(i=0; i<round; i++)
							{
								memcpy(p,q,size*sizeof(int));
								begin=clock();
								CountSort(p,size ,100);
								end=clock();
								cost=(double)(end-begin)/1000;
								all+=cost;
							}

						printf("�������򻨷�ʱ��:%fs\n",all);
						all=0;
						for(i=0; i<round; i++)
							{
								memcpy(p,q,size*sizeof(int));
								begin=clock();
								RadixCountSort(p,(int)size);
								end=clock();
								cost=(double)(end-begin)/1000;
								all+=cost;
							}

						printf("�����������򻨷�ʱ��:%fs\n",all);
						all=0;
						printf("�����������ַ�ˢ��\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						free(p);
						free(q);
						break;
					case 7:
						exit(0);
					default:
						printf("�޴���ѡ��\n");
						printf("�����������ַ�ˢ��\n");
						c=getchar();
						if(c!='\n')EmptyBuff();
						system("cls");
						break;
				}
		}
	return 0;
}
