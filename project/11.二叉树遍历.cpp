#include<stdio.h>
#include<malloc.h>
typedef struct tnode{
    char data;
    struct tnode *lchild,*rchild;
}BTN;

int Sum(BTN *b){//求和
    if(b==NULL)return 0;
    return (b->data+Sum(b->lchild)+Sum(b->rchild));
}

void DBT(BTN *&b){//释放内存
    if(b!=NULL){
        DBT(b->lchild);
        DBT(b->rchild);
        free(b);
        b=NULL;
    }
}

int  BTH(BTN *b){//二叉数高
    if(b==NULL)return 0;
    int l,r;
    l=BTH(b->lchild);r=BTH(b->rchild);
    return l>r?(l+1):(r+1);
}

int NodeCount(BTN *b){//计算节点数
    if(b==NULL)return 0;
    return (NodeCount(b->lchild)+NodeCount(b->rchild)+1);
}

int LeafCount(BTN *b){//求叶子节点数
    if(b==NULL)return 0;
    if(b->lchild==NULL&&b->rchild==NULL)return 1;
    return LeafCount(b->lchild)+LeafCount(b->rchild);
}

void CBT(BTN *&b,const char *s){//特定格式生成二叉数
   BTN *st[100],*p=NULL;
    int top=-1,k,i=0;
    b=NULL;
    while(s[i]){
        switch(s[i]){
            case '(':++top;st[top]=p;k=1;break;//记录父节点地址，向下一层并标记生成左子节点
            case ')':top--;break;//向上一层
            case ',':k=2;break;//标记生成右子节点
            default:p=(BTN *)malloc(sizeof(BTN));
            p->data=s[i];p->lchild=p->rchild=NULL;
            if(b==NULL)b=p;//生成头节点
            else{if(k==1)st[top]->lchild=p;//父节点指向
                 if(k==2)st[top]->rchild=p;//父节点指向
            }
        }
    i++;
    }
}

void DispBT(BTN *b){//输出
    if(b!=NULL){
        printf("%c",b->data);
        if(b->lchild!=NULL||b->rchild!=NULL){//有子节点
             printf("(");
             DispBT(b->lchild);
             if(b->rchild!=NULL)printf(",");
             DispBT(b->rchild);
             printf(")");
        }
    }
}

//遍历节点

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
 * @brief  层次遍历
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
    printf("二叉树为：");DispBT(b);printf("\n");
    printf("二叉数高为：%d\n",BTH(b));
    printf("节点数为：%d\n",NodeCount(b));
    printf("叶子节点数为：%d\n",LeafCount(b));
    printf("先序遍历：");prabb(b);printf("\n");
    printf("中序遍历：");prbab(b);printf("\n");
    printf("后序遍历：");prbba(b);printf("\n");
    printf("层次遍历：");levelorder(b);printf("\n");
    printf("销毁二叉树\n"); DBT(b);
    printf("二叉树为：");DispBT(b);printf("\n");
    getchar();
}
