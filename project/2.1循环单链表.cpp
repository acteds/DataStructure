#include <stdio.h>
#include<malloc.h>
typedef struct node
{int data;
struct node *next;}SL;
int insert(SL *&L,const int n,const int k){//˳��д��
if(k<1)return 0;
SL *p=L,*q;
int i=1;
while(p->next!=p&&i<k){
    i++;
    p=p->next;
}
q=(SL *)malloc(sizeof(SL));
q->next=p->next;
q->data=n;
p->next=q;
return 1;

}
int printx(const SL *L)
{if(L->next==NULL)return 0;
SL *p=L->next;
int i=0;
while(p!=L){
    printf("%d ",p->data);
    p=p->next;
    i++;
}
printf("\n");
return i;
}
int del(SL *L,const int k){
if(k<1)return 0;
printf("ɾ����%d���ڵ�\n",k);
SL *p=L,*q;
int i=1;
while(p->next!=NULL&&i<k){
    i++;
    p=p->next;
}
q=p->next;
p->next=q->next;
free(q);
return 1;
}

int delSL(SL *&L)//��������
{SL *p=L->next,*q;
while(p!=L){
    q=p;
    p=p->next;
    free(q);
}
free(p);
L->next=NULL;
return 1;
}

int find(SL *L,const int k,int &m){//���ڵ��Ԫ��
if(k<1)return 0;
SL *p=L;
int i=0;
while(p->next!=p&&i<k){
    i++;
    p=p->next;
}
if(p!=p->next){m=p->data; return 1;}
else return 0;
}

int finddata(SL *L,const int k){//����ֵ����
    SL *p=L;
    int i=0;
    while(p->next!=p&&p->data!=k){
        p=p->next;
        ++i;
    }
    if(p->next!=p)return i;
    else return 0;
}
int main(){
SL *L=(SL *)malloc(sizeof(SL));
L->next=L;
insert(L,2,1);
insert(L,3,2);
insert(L,4,3);
insert(L,1,4);
insert(L,8,5);
printf("�������");
int length=printx(L);
printf("������Ϊ��%d\n",length);
del(L,3);
printf("�������");
length=printx(L);
printf("������Ϊ��%d\n",length);
puts("������������38");
insert(L,38,2);
printf("�������");
length=printx(L);
printf("������Ϊ��%d\n",length);
int m=0;
if(find(L,3,m))printf("���ҵ�������Ԫ��Ϊ%d\n",m);
else printf("û�в��ҵ�������Ԫ��\n");
if((m=finddata(L,38)))printf("���ҵ���ֵ38�Ľڵ���:%d\n",m);
else printf("û�в��ҵ���ֵ38\n");
puts("������ϣ���������");
delSL(L);
printf("�������");
length=printx(L);
printf("������Ϊ��%d\n",length);
getchar();
}

