#include <stdio.h>
#include<malloc.h>
typedef struct node
{char data;
struct node *next;}QT;
typedef struct qptr
{QT *front,*rear;}LQ;
void DQ(LQ *&lq){//���ٶ��У���������
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
int QE(LQ *lq){//�ж϶ӿ�
    return lq->front==NULL?1:0;
}

int EQ(LQ *&lq,char x){//����
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

int DQ(LQ *&lq,char &x){//����
    if(QE(lq))return 0;
    QT *p=lq->front;x=p->data;
    if(lq->front==lq->rear)lq->front=lq->rear=NULL;
    else    lq->front=lq->front->next;
    free(p);
    return 1;
}

int Gethead(LQ *lq,char &x){//ȡ��ͷԪ��
    if(QE(lq))return 0;
    x=lq->front->data;
    return 1;
}
main()
{puts("��ʼ��");
LQ *lq=(LQ *)malloc(sizeof(LQ));
lq->front=lq->rear=NULL;
if(QE(lq))puts("�ӿ�");
else puts("�Ӳ���");
printf("%c����\n",'a');EQ(lq,'a');
printf("%c����\n",'b');EQ(lq,'b');
printf("%c����\n",'c');EQ(lq,'c');
printf("%c����\n",'d');EQ(lq,'d');
char x;
Gethead(lq,x);printf("��ͷԪ��Ϊ%c\n",x);
puts("����˳��Ϊ��");
while(!QE(lq)){
    DQ(lq,x);printf("%c ",x);
}
puts("");
DQ(lq);//���ٶ���
if(QE(lq))puts("�ӿ�");
else puts("�Ӳ���");
getchar();
}