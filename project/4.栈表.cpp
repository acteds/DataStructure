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
puts("初始化");L->top=-1;
if(SE(L))printf("栈空\n");
else {printf("栈不空\n");return 0;}
printf("%c进栈\n",'a');push(L,'a');
printf("%c进栈\n",'b');push(L,'b');
printf("%c进栈\n",'c');push(L,'c');
printf("%c进栈\n",'d');push(L,'d');
char x;
gettop(L,x);printf("栈顶元素为%c\n",x);
puts("出栈顺序为：");
while(!SE(L)){
    pop(L,x);cout<<x<<" ";
}

getchar();
}


