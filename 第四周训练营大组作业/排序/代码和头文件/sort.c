#include<stdio.h>
#include"sort.h"
#define MAX_STR_SIZE 1024
#include<ctype.h>
#include <stdlib.h>
//清空缓冲区
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
	printf("排序操作选择：\n");
	printf("----------------------------------\n");
	printf("1.测试10000大数据下的排序用时(1~100随机数)\n");
	printf("2.测试50000大数据下的排序用时(1~100随机数)\n");
	printf("3.测试200000大数据下的排序用时(1~100随机数)\n");
	printf("4.100*100k排序用时(1~100随机数)\n");
	printf("5.自定义测试数据(数据保存到文件中)\n");
	printf("6.自定义测试数据(从文件中读取数据)\n");
	printf("7.退出\n");
}

//输入选择整数 
int getNum()
{
	char str[MAX_STR_SIZE]= {0};
	int pic=0;
	fgets(str,MAX_STR_SIZE,stdin);//注意，fges会把回车吃进字符串中！！！！！！！！！
	if(!isValid(str))
		{
			printf("你输入的数据不符合，请重新输入\n");
			//EmptyBuff();//把错的数据吃完
			pic=getNum();
		}
	else
		sscanf(str,"%d",&pic);
	return pic;
}

//用户只能输入整数 
int isValid(const char* str)//判断数据是否有效
{
	int sign=0;//判断正负 
	int digit=0;//数字长度
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
							printf("数据过大\n");
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
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a,int n){
	int i;
	int j;
	int temp;
	for(i=1;i<n;i++){
		temp=a[i];
		if(a[i]<a[i-1]){//找到要插入排序的数 
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
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
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
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
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
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
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
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
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
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
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
	int i,j;//i是左边开始，j是右边开始
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
	int i,j;//i是左边开始，j是右边开始
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
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
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
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int *a,int size){
	
    int *counts=NULL;
	int *temp=NULL;
    int index,pval,i,j,n;
    pval=1;
    int p=0;//最大位数 
	int max=a[0];
	for(i=1;i<size;i++){
		if(a[i]>max)max=a[i];
	}
	while(max){
		p++;
		max/=10;
	}
    /*申请空间*/
    if ((counts = (int *)malloc(10 * sizeof(int))) == NULL){
    	printf("分配内存失败\n");
    	return ;
	}
    if ((temp = (int *)malloc(size * sizeof(int))) == NULL){
    	printf("分配内存失败\n");
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
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size){
	int i;
	int temp;
	int p2=size-1;//存放2的位置 
	int p0=0;//存放0的位置 
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
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第大/小的数
 *  @param       : 数组指针a，数组长度size
 */

int searchNum(int *a,int size,int n){
	RadixCountSort(a,size);
	return a[n-1];
}





//输入选择整数 
long getNum1()
{
	char str[MAX_STR_SIZE]= {0};
	long pic=0;
	fgets(str,MAX_STR_SIZE,stdin);//注意，fges会把回车吃进字符串中！！！！！！！！！
	if(!isValid1(str))
		{
			printf("你输入的数据不符合，请重新输入\n");
			//EmptyBuff();//把错的数据吃完
			pic=getNum1();
		}
	else
		sscanf(str,"%ld",&pic);
	return pic;
}

//用户只能输入整数 
int isValid1(const char* str)//判断数据是否有效
{
	int sign=0;//判断正负 
	int digit=0;//数字长度
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
							printf("数据过大\n");
							return 0;
						}
				}
				
			}
			else return 0; 
			
		}
			return 1;
}

