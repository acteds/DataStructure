#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define N 100
typedef struct
{	char data[N]; 
	int top;
}Sqs; 

int push(Sqs *L,const char x)
{if(L->top==N-1)return 0;
++L->top;
L->data[L->top]=x;
return 1;
}

int pop(Sqs *L,char &x)
{if(L->top==-1)return 0;
x=L->data[L->top];
--L->top;
return 1;
}

int gettop(Sqs *L,char &x){
if(L->top==-1)return 0;
x=L->data[L->top];
return 1;
}

int SE(Sqs *L){
    return L->top==-1?1:0;
}

main(){
Sqs Link,*L=&Link;
puts("��ʼ��");L->top=-1;
if(SE(L))printf("ջ��\n");
else {printf("ջ����\n");return 0;}
printf("%c��ջ\n",'a');push(L,'a');
printf("%c��ջ\n",'b');push(L,'b');
printf("%c��ջ\n",'c');push(L,'c');
printf("%c��ջ\n",'d');push(L,'d');
char x;
gettop(L,x);printf("ջ��Ԫ��Ϊ%c\n",x);
puts("��ջ˳��Ϊ��");
while(!SE(L)){
    pop(L,x);cout<<x<<" ";
}

getchar();
}


