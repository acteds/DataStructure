#include<stdio.h>
#include<malloc.h>
typedef struct tnode{
    char data;
    struct tnode *lchild,*rchild;
}BTN;

int Sum(BTN *b){//���
    if(b==NULL)return 0;
    return (b->data+Sum(b->lchild)+Sum(b->rchild));
}

void DBT(BTN *&b){//�ͷ��ڴ�
    if(b!=NULL){
        DBT(b->lchild);
        DBT(b->rchild);
        free(b);
        b=NULL;
    }
}

int  BTH(BTN *b){//��������
    if(b==NULL)return 0;
    int l,r;
    l=BTH(b->lchild);r=BTH(b->rchild);
    return l>r?(l+1):(r+1);
}

int NodeCount(BTN *b){//����ڵ���
    if(b==NULL)return 0;
    return (NodeCount(b->lchild)+NodeCount(b->rchild)+1);
}

int LeafCount(BTN *b){//��Ҷ�ӽڵ���
    if(b==NULL)return 0;
    if(b->lchild==NULL&&b->rchild==NULL)return 1;
    return LeafCount(b->lchild)+LeafCount(b->rchild);
}

void CBT(BTN *&b,const char *s){//�ض���ʽ���ɶ�����
   BTN *st[100],*p=NULL;
    int top=-1,k,i=0;
    b=NULL;
    while(s[i]){
        switch(s[i]){
            case '(':++top;st[top]=p;k=1;break;//��¼���ڵ��ַ������һ�㲢����������ӽڵ�
            case ')':top--;break;//����һ��
            case ',':k=2;break;//����������ӽڵ�
            default:p=(BTN *)malloc(sizeof(BTN));
            p->data=s[i];p->lchild=p->rchild=NULL;
            if(b==NULL)b=p;//����ͷ�ڵ�
            else{if(k==1)st[top]->lchild=p;//���ڵ�ָ��
                 if(k==2)st[top]->rchild=p;//���ڵ�ָ��
            }
        }
    i++;
    }
}

void DispBT(BTN *b){//���
    if(b!=NULL){
        printf("%c",b->data);
        if(b->lchild!=NULL||b->rchild!=NULL){//���ӽڵ�
             printf("(");
             DispBT(b->lchild);
             if(b->rchild!=NULL)printf(",");
             DispBT(b->rchild);
             printf(")");
        }
    }
}

//�����ڵ�

void prabb(BTN *b){
    if(b!=NULL){
        printf("%c ",b->data);
        prabb(b->lchild);
        prabb(b->rchild);
    }
}

void prbab(BTN *b){
    if(b!=NULL){
        prbab(b->lchild);
        printf("%c ",b->data);
        prbab(b->rchild);
    }
    
}

void prbba(BTN *b){
    if(b!=NULL){
        prbba(b->lchild);
        prbba(b->rchild);
        printf("%c ",b->data);
    }
}
/**
 * @brief  ��α���
 * @note   
 * @param  *b: 
 * @retval None
 */
void levelorder(BTN *b){
    BTN *p,*q[100];
    int front=0,rear=1;
    q[rear]=b;
    while(front!=rear){
        p=q[++front];
        printf("%c ",p->data);
        if(p->lchild!=NULL) q[++rear]=p->lchild;
        if(p->rchild!=NULL) q[++rear]=p->rchild;
    }
}

int main(){
    BTN *b;
    CBT(b,"A(B(D,E(G,H)),C(,F(I)))");
    printf("������Ϊ��");DispBT(b);printf("\n");
    printf("��������Ϊ��%d\n",BTH(b));
    printf("�ڵ���Ϊ��%d\n",NodeCount(b));
    printf("Ҷ�ӽڵ���Ϊ��%d\n",LeafCount(b));
    printf("���������");prabb(b);printf("\n");
    printf("���������");prbab(b);printf("\n");
    printf("���������");prbba(b);printf("\n");
    printf("��α�����");levelorder(b);printf("\n");
    printf("���ٶ�����\n"); DBT(b);
    printf("������Ϊ��");DispBT(b);printf("\n");
    getchar();
}
