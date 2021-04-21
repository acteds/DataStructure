#include <stdio.h>
#include<malloc.h>
typedef struct node
{int data;
struct node *next;}SL;
int insert(SL *&L,const int n,const int k){//顺序写入
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
printf("删除第%d个节点\n",k);
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

int delSL(SL *&L)//销毁链表
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

int find(SL *L,const int k,int &m){//按节点查元素
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

int finddata(SL *L,const int k){//按数值查找
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
printf("输出链表：");
int length=printx(L);
printf("链表长度为：%d\n",length);
del(L,3);
printf("输出链表：");
length=printx(L);
printf("链表长度为：%d\n",length);
puts("插入链表内容38");
insert(L,38,2);
printf("输出链表：");
length=printx(L);
printf("链表长度为：%d\n",length);
int m=0;
if(find(L,3,m))printf("查找到第三个元素为%d\n",m);
else printf("没有查找到第三个元素\n");
if((m=finddata(L,38)))printf("查找到数值38的节点是:%d\n",m);
else printf("没有查找到数值38\n");
puts("测试完毕，销毁链表！");
delSL(L);
printf("输出链表：");
length=printx(L);
printf("链表长度为：%d\n",length);
getchar();
}

