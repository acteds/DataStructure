#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct node
{char data;
struct node *next;}SL;
int Push(SL *&L,char x){//进栈
SL *q=(SL *)malloc(sizeof(SL));
q->next=L;
q->data=x;
L=q;
return 1;
}

int Pop(SL *&L,char &x){//出栈
if(L==NULL)return 0;
SL *p=L;
x=p->data;
L=p->next;
free(p);
return 1;
}


int Gettop(SL *L,char &x){//取栈顶元素
    if(L==NULL)return 0;
    x=L->data;
    return 1;
}

int SE(SL *L){//判断栈空
    if(L==NULL)return 1;
    return 0;
}

int printx(SL *L)//查看栈
{SL *p=L;
int i=0;
while(p!=NULL){
    printf("%c-",p->data);
    p=p->next;
    i++;
}
printf("<栈底\n");
return i;
}

int delSL(SL *&L)//销毁栈
{SL *p=L,*q;
while(p!=NULL){
    q=p;
    p=p->next;
    free(q);
}
L=L->next=NULL;
return 1;
}

int main(){
SL *L=(SL *)malloc(sizeof(SL));
L=NULL;
if(SE(L))printf("栈空\n");else printf("栈不空\n");
puts("进栈abcde");
Push(L,'a');
Push(L,'b');
Push(L,'c');
Push(L,'d');
Push(L,'e');
if(SE(L))printf("栈空\n");else printf("栈不空\n");
printf("输出栈表：");
int length=printx(L);
printf("栈高为：%d\n",length);
char x;
if(Gettop(L,x))printf("栈顶元素为%c\n",x);else printf("栈空\n");
printf("出栈顺序为：");
while(Pop(L,x))printf("%c ",x);
printf("\n");
puts("测试完毕，销毁栈！");
if(SE(L))printf("栈已空不需要销毁\n");else delSL(L);
printf("输出栈表：");
length=printx(L);
printf("栈高为：%d\n",length);
system("pause");
}
