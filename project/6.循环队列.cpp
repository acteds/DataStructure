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
int EQ(Sqq *&L,const char x)//����
{if((L->rear+1)%N==L->front)return 0;
L->rear=(L->rear+1)%N;
L->data[L->rear]=x;
return 1;
}

int DQ(Sqq *&L,char &x)//����
{if(QE(L))return 0;
L->front=(L->front+1)%N;
x=L->data[L->front];
return 1;
}

int Gethead(Sqq *&L,char &x){//ȡ��ͷԪ��
if(QE(L))return 0;
x=L->data[(L->front+1)%N];
return 1;
}

int QE(Sqq *L){
    return L->front==L->rear?1:0;
}

main(){
Sqq Link,*L=&Link;
puts("��ʼ��");L->front=L->rear=0;
if(QE(L))printf("�ӿ�\n");
else {printf("�Ӳ���\n");return 0;}
printf("%c����\n",'a');EQ(L,'a');
printf("%c����\n",'b');EQ(L,'b');
printf("%c����\n",'c');EQ(L,'c');
printf("%c����\n",'d');EQ(L,'d');
char x;
Gethead(L,x);printf("��ͷԪ��Ϊ%c\n",x);
puts("����˳��Ϊ��");
while(!QE(L)){
    DQ(L,x);cout<<x<<" ";
}

getchar();
}

