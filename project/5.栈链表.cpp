#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct node
{char data;
struct node *next;}SL;
int Push(SL *&L,char x){//��ջ
SL *q=(SL *)malloc(sizeof(SL));
q->next=L;
q->data=x;
L=q;
return 1;
}

int Pop(SL *&L,char &x){//��ջ
if(L==NULL)return 0;
SL *p=L;
x=p->data;
L=p->next;
free(p);
return 1;
}


int Gettop(SL *L,char &x){//ȡջ��Ԫ��
    if(L==NULL)return 0;
    x=L->data;
    return 1;
}

int SE(SL *L){//�ж�ջ��
    if(L==NULL)return 1;
    return 0;
}

int printx(SL *L)//�鿴ջ
{SL *p=L;
int i=0;
while(p!=NULL){
    printf("%c-",p->data);
    p=p->next;
    i++;
}
printf("<ջ��\n");
return i;
}

int delSL(SL *&L)//����ջ
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
if(SE(L))printf("ջ��\n");else printf("ջ����\n");
puts("��ջabcde");
Push(L,'a');
Push(L,'b');
Push(L,'c');
Push(L,'d');
Push(L,'e');
if(SE(L))printf("ջ��\n");else printf("ջ����\n");
printf("���ջ��");
int length=printx(L);
printf("ջ��Ϊ��%d\n",length);
char x;
if(Gettop(L,x))printf("ջ��Ԫ��Ϊ%c\n",x);else printf("ջ��\n");
printf("��ջ˳��Ϊ��");
while(Pop(L,x))printf("%c ",x);
printf("\n");
puts("������ϣ�����ջ��");
if(SE(L))printf("ջ�ѿղ���Ҫ����\n");else delSL(L);
printf("���ջ��");
length=printx(L);
printf("ջ��Ϊ��%d\n",length);
system("pause");
}
