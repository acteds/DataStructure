#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define N 10
typedef struct
{	char data[N]; 
	int front,rear;
}Sqq; 
int QE(Sqq*);
int EQ(Sqq *&L,const char x)//进队
{if((L->rear+1)%N==L->front)return 0;
L->rear=(L->rear+1)%N;
L->data[L->rear]=x;
return 1;
}

int DQ(Sqq *&L,char &x)//出队
{if(QE(L))return 0;
L->front=(L->front+1)%N;
x=L->data[L->front];
return 1;
}

int Gethead(Sqq *&L,char &x){//取对头元素
if(QE(L))return 0;
x=L->data[(L->front+1)%N];
return 1;
}

int QE(Sqq *L){
    return L->front==L->rear?1:0;
}

main(){
Sqq Link,*L=&Link;
puts("初始化");L->front=L->rear=0;
if(QE(L))printf("队空\n");
else {printf("队不空\n");return 0;}
printf("%c进队\n",'a');EQ(L,'a');
printf("%c进队\n",'b');EQ(L,'b');
printf("%c进队\n",'c');EQ(L,'c');
printf("%c进队\n",'d');EQ(L,'d');
char x;
Gethead(L,x);printf("队头元素为%c\n",x);
puts("出队顺序为：");
while(!QE(L)){
    DQ(L,x);cout<<x<<" ";
}

getchar();
}

