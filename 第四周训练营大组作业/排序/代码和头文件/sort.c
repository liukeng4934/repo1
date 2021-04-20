#include<stdio.h>
#include"sort.h"
#define MAX_STR_SIZE 1024
#include<ctype.h>
#include <stdlib.h>
//��ջ�����
void EmptyBuff()
{
	char ch;
	while((ch=getchar())!=EOF&&ch!='\n')
		{
			;
		}
}

void menu()
{
	printf("�������ѡ��\n");
	printf("----------------------------------\n");
	printf("1.����10000�������µ�������ʱ(1~100�����)\n");
	printf("2.����50000�������µ�������ʱ(1~100�����)\n");
	printf("3.����200000�������µ�������ʱ(1~100�����)\n");
	printf("4.100*100k������ʱ(1~100�����)\n");
	printf("5.�Զ����������(���ݱ��浽�ļ���)\n");
	printf("6.�Զ����������(���ļ��ж�ȡ����)\n");
	printf("7.�˳�\n");
}

//����ѡ������ 
int getNum()
{
	char str[MAX_STR_SIZE]= {0};
	int pic=0;
	fgets(str,MAX_STR_SIZE,stdin);//ע�⣬fges��ѻس��Խ��ַ����У�����������������
	if(!isValid(str))
		{
			printf("����������ݲ����ϣ�����������\n");
			//EmptyBuff();//�Ѵ�����ݳ���
			pic=getNum();
		}
	else
		sscanf(str,"%d",&pic);
	return pic;
}

//�û�ֻ���������� 
int isValid(const char* str)//�ж������Ƿ���Ч
{
	int sign=0;//�ж����� 
	int digit=0;//���ֳ���
	for(; *str; str++)
		{

			if(((*str)>='0'&&(*str)<='9')||(*str=='+')||(*str=='-')||(*str=='\n')){
				if(*str=='+'||*str=='-'){
					if(sign!=0) return 0;
					if(*str=='+')sign=1;
					else sign=-1;
				}
				else if((*str)>='0'&&(*str)<='9')
				{
					digit++;
					if(digit>5)
						{
							printf("���ݹ���\n");
							return 0;
						}
				}
				
			}
			else return 0; 
			
		}
			return 1;
}

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ���������㷨
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int *a,int n){
	int i;
	int j;
	int temp;
	for(i=1;i<n;i++){
		temp=a[i];
		if(a[i]<a[i-1]){//�ҵ�Ҫ����������� 
			for(j=i;j>0;j--){
				if(j==1){
					a[i]=a[i-1];
					a[i-1]=temp;
				} 
				else {
					if(a[i]<a[j-1]&&a[i]>a[j-2]){
						
						a[j]=a[j-1];
						a[j-1]=temp;
					}else {
						a[j]=a[j-1];
					}
				}
			}
		}
	}
}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp){
	int i=begin;
	int k=0;
	int j=mid+1;
	for(;i<=mid&&j<=end;){
		if(a[i]<=a[j]){
			temp[k++]=a[i++];
		}
		else {
			temp[k++]=a[j++];
		}
	}
	while(i<=mid){
		temp[k++]=a[i++];
	}
	while(j<=end){
		temp[k++]=a[j++];
	}
	for(i=0;i<k;i++){
		a[begin+i]=temp[i];
	}

}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int *a,int begin,int end,int *temp){
		if(begin<end){
		int mid=(begin+end)/2;
		MergeSort(a,begin,mid,temp);
		MergeSort(a,mid+1,end,temp);
		MergeArray(a,begin,mid,end,temp);
	}

}


/**
 *  @name        : void QuicSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuicSort_Recursion(int *a, int begin, int end){
	int par;
	par=Partition(a,begin,end);
	if(par-begin>1){
		QuicSort_Recursion(a,begin,par-1);
	}
	if(end-par>1){
		QuicSort_Recursion(a,par+1,end);
	}
}


/**
 *  @name        : void QuicSort(int *a,int size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void QuicSort(int *a,int begin,int end){
	int *stack=(int *)malloc(end*sizeof(int));
	int begin1=begin;
	int end1=end;
	int i=0;
	int p;
	p= Partition(a, begin1,  end1);
	if(p-begin1>1){
		stack[i++]=p-1;
		stack[i++]=begin1;
	}
	if(end1-p>1){
		stack[i++]=end1;
		stack[i++]=p+1;
	}
	while(i!=0){
		begin1=stack[--i];
		end1=stack[--i];
		p= Partition(a, begin1,  end1);
		if(p-begin1>1){
		stack[i++]=p-1;
		stack[i++]=begin1;
	}
	if(end1-p>1){
		stack[i++]=end1;
		stack[i++]=p+1;
	}
	}
	free(stack);
}



/**
 *  @name        : void QuicSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
 void QuicSort1(int *a,int begin, int end){
	int par=Partition1(a,begin,end);
	if(par-begin>1){
		QuicSort1(a,begin,par-1);
	}
	if(end-par>1){
		QuicSort1(a,par+1,end);
	}
}
 
 int Partition(int *a, int begin, int end){
	int m=a[begin];
	int i,j;//i����߿�ʼ��j���ұ߿�ʼ
	i=begin;
	j=end;
	while(i<j){
		while(j>i&&a[j]>=m){
			j--;
		}
		if(j==i){
			break;
		}
		else {
			a[i]=a[j];
		}
		while(i<j&&a[i]<=m){
			i++;
		}
		if(j==i){
			break;
		}
		else {
			a[j]=a[i];
		}
	} 
	a[i]=m;
	return i;
}

int Partition1(int *a, int begin, int end){
	int mid=(begin+end)/2;
	if(a[end]<a[begin]){
		int temp=a[end];
		a[end]=a[begin];
		a[begin]=temp;
	}
	if(a[end]<a[mid]){
		int temp=a[end];
		a[end]=a[mid];
		a[mid]=temp;
	}
	if(a[begin]<a[mid]){
		int temp=a[begin];
		a[begin]=a[mid];
		a[mid]=temp;
	}
	int m=a[begin];
	int i,j;//i����߿�ʼ��j���ұ߿�ʼ
	i=begin;
	j=end;
	while(i<j){
		while(j>i&&a[j]>=m){
			j--;
		}
		if(j==i){
			break;
		}
		else {
			a[i]=a[j];
		}
		while(i<j&&a[i]<=m){
			i++;
		}
		if(j==i){
			break;
		}
		else {
			a[j]=a[i];
		}
	} 
	a[i]=m;
	return i;
}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int *a, int size , int max){
	int i;
	int j=0;
	int *temp = (int *)malloc(size * sizeof(int));
	int *b=(int *)malloc((max+1)*sizeof(int));
	for(i=0;i<max+1;i++){
		b[i]=0;
	}
	for(i=0;i<size;i++){
		b[a[i]]++;
	}
	for (i = 1; i <= max; i ++)
            b[i] += b[i - 1];
	for(i=0;i<size;i++){
		temp[b[a[i]]-- -1]=a[i];
	}
	for(i=0;i<size;i++){
        	a[i]=temp[i];
		}
	free(temp);
	free(b);
}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void RadixCountSort(int *a,int size){
	
    int *counts=NULL;
	int *temp=NULL;
    int index,pval,i,j,n;
    pval=1;
    int p=0;//���λ�� 
	int max=a[0];
	for(i=1;i<size;i++){
		if(a[i]>max)max=a[i];
	}
	while(max){
		p++;
		max/=10;
	}
    /*����ռ�*/
    if ((counts = (int *)malloc(10 * sizeof(int))) == NULL){
    	printf("�����ڴ�ʧ��\n");
    	return ;
	}
    if ((temp = (int *)malloc(size * sizeof(int))) == NULL){
    	printf("�����ڴ�ʧ��\n");
    	return ;
	}
    for (n = 0; n < p; n++){
    	for(i=0;i<10;i++){
    		counts[i]=0;
		}
        
        for (j = 0; j < size; j ++){
            index = (a[j]/pval)%10;
            counts[index] ++;
        }
        for (i = 1; i < 10; i ++)
            counts[i] += counts[i - 1];
 
        for(j = size - 1; j >= 0; j --){
            index = (a[j]/pval)%10;
            temp[counts[index] - 1] = a[j];
            counts[index]--;
        }
        for(i=0;i<size;i++){
        	a[i]=temp[i];
		}
        pval*=10;
    }
	free(temp);
	free(counts);
}


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */
void ColorSort(int *a,int size){
	int i;
	int temp;
	int p2=size-1;//���2��λ�� 
	int p0=0;//���0��λ�� 
	for(i=0;i<size;i++){
		 if(a[i]==1){
		 	continue;
		 }
		 else if(a[i]==0){
		 	temp=a[i];
		 	a[i]=a[p0];
		 	a[p0]=temp;
		 	p0++;
		 }
		 else if(a[i]==2){
		 	temp=a[i];
		 	a[i]=a[p2];
		 	a[p2]=temp;
		 	p2--;
		 }
	}

} 


/**
 *  @name        : ����
 *  @description : ��һ�������������ҵ��ڴ�/С����
 *  @param       : ����ָ��a�����鳤��size
 */

int searchNum(int *a,int size,int n){
	RadixCountSort(a,size);
	return a[n-1];
}





//����ѡ������ 
long getNum1()
{
	char str[MAX_STR_SIZE]= {0};
	long pic=0;
	fgets(str,MAX_STR_SIZE,stdin);//ע�⣬fges��ѻس��Խ��ַ����У�����������������
	if(!isValid1(str))
		{
			printf("����������ݲ����ϣ�����������\n");
			//EmptyBuff();//�Ѵ�����ݳ���
			pic=getNum1();
		}
	else
		sscanf(str,"%ld",&pic);
	return pic;
}

//�û�ֻ���������� 
int isValid1(const char* str)//�ж������Ƿ���Ч
{
	int sign=0;//�ж����� 
	int digit=0;//���ֳ���
	for(; *str; str++)
		{

			if(((*str)>='0'&&(*str)<='9')||(*str=='+')||(*str=='-')||(*str=='\n')){
				if(*str=='+'||*str=='-'){
					if(sign!=0) return 0;
					if(*str=='+')sign=1;
					else sign=-1;
				}
				else if((*str)>='0'&&(*str)<='9')
				{
					digit++;
					if(digit>10)
						{
							printf("���ݹ���\n");
							return 0;
						}
				}
				
			}
			else return 0; 
			
		}
			return 1;
}

