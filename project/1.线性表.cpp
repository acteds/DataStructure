#include<stdio.h>
typedef struct node {
	int data[100],length;
} SqL;
int GetElem(SqL L,int i, int &e) { //查找元素
	if(i<1||i>L.length) return 0;
	e=L.data[i-1];
	return 1;
}

int DelElem(SqL &L,int i) { //删除元素
	int j;
	if(i<1||i>L.length) return 0;
	for(j=i; j<L.length; j++)
		L.data[j-1]=L.data[j];
	L.length--;
	return 1;
}

int Locate(SqL L,int x) { //按值查找
	int i=0;
	while(i<L.length&&L.data[i]!=x)i++;
	if(i>=L.length)return 0;
	return 1;
}
int InsElem(SqL &L,int x,int i) { //插入元素运算
	int j;
	if(i<1||i>L.length+1) return 0;
	for(j=L.length; j>i; j--)
		L.data[j]=L.data[j-1];
	L.data[i-1]=x;
	L.length++;
	return 1;
}

int DispList(SqL L) { //输出线性表
	int i;
	for(i=0; i<L.length; ++i)
		printf("%d ",L.data[i]);
	printf("\n");
}

int main() {
	int i;
	int e;
	SqL L;
	L.length=0;//初始化
	InsElem(L,1,1);
	InsElem(L,3,2);
	InsElem(L,1,3);
	InsElem(L,5,4);
	InsElem(L,4,5);
	InsElem(L,2,6);
	printf("线性表：");
	DispList(L);
	printf("长度%d\n",L.length);
	i = 3;
	GetElem(L,i,e);
	printf("第%d个元素：%d\n",i,e);
	e = 1;
	printf("元素%d是第%d个元素\n",e,Locate(L,e));
	i = 4;
	printf("删除第%d个元素\n",i);
	DelElem(L,i);
	printf("线性表：");
	DispList(L);
}


