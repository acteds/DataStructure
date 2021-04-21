#include <stdio.h>
#include<malloc.h>
typedef struct node
{char data;
struct node *next;}QT;
typedef struct qptr
{QT *front,*rear;}LQ;
void DQ(LQ *&lq){//销毁队列，函数重载
    QT *p=lq->front,*q=lq->rear;
    if(p!=NULL){
        if(p==q)free(p);
        else{
            q=p->next;
            while(q){
                free(p);
                p=q;
                q=q->next;
            }
            free(p);
        }
    }
    free(lq);
    lq->rear=lq->front=NULL;
}
int QE(LQ *lq){//判断队空
    return lq->front==NULL?1:0;
}

int EQ(LQ *&lq,char x){//进队
    QT *p=(QT *)malloc(sizeof(QT));
    p->data=x;p->next=NULL;
    if(QE(lq))
        lq->front=lq->rear=p;
    else{
        lq->rear->next=p;
        lq->rear=p;
    }
    return 1;
}

int DQ(LQ *&lq,char &x){//出队
    if(QE(lq))return 0;
    QT *p=lq->front;x=p->data;
    if(lq->front==lq->rear)lq->front=lq->rear=NULL;
    else    lq->front=lq->front->next;
    free(p);
    return 1;
}

int Gethead(LQ *lq,char &x){//取队头元素
    if(QE(lq))return 0;
    x=lq->front->data;
    return 1;
}
main()
{puts("初始化");
LQ *lq=(LQ *)malloc(sizeof(LQ));
lq->front=lq->rear=NULL;
if(QE(lq))puts("队空");
else puts("队不空");
printf("%c进队\n",'a');EQ(lq,'a');
printf("%c进队\n",'b');EQ(lq,'b');
printf("%c进队\n",'c');EQ(lq,'c');
printf("%c进队\n",'d');EQ(lq,'d');
char x;
Gethead(lq,x);printf("队头元素为%c\n",x);
puts("出队顺序为：");
while(!QE(lq)){
    DQ(lq,x);printf("%c ",x);
}
puts("");
DQ(lq);//销毁队列
if(QE(lq))puts("队空");
else puts("队不空");
getchar();
}