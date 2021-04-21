#include<stdio.h>
#include<malloc.h>
#define INF 0x3f3f3f3f
int visited[100];
typedef struct edgenide
{	int adjvex;//�߶����� 
	int weight;//ָ���Ȩֵ 
	struct edgenide *next;//���������߽ڵ� 
}ArcNode;//�߽ڵ� 

typedef struct vexnode{
	char data[10];//������Ϣ 
	ArcNode *first; //ָ��߽ڵ� 
}Head;//���� 

typedef struct tu{
	int n,e;//�ڵ���n������e
	Head adjlist[100];//�������� 
}AdjGraph;//ͼ 

void CreateGraph(AdjGraph *&G,const int A[][100],const int n,const int e){//�����ڽӱ� 
	int i,j;ArcNode *p;
	G=(AdjGraph *)malloc(sizeof(AdjGraph));//Ϊͼ����ռ� 
	G->n=n;G->e=e;
	for(i=0;i<G->n;i++)G->adjlist[i].first=NULL;//��ʼ������ָ�� 
	for(i=0;i<G->n;++i)
		for(j=0;j<G->n;++j)
			if(A[i][j]>0&&A[i][j]<INF){
				p=(ArcNode *)malloc(sizeof(ArcNode));//��ʼ���߶��� 
				p->adjvex=j;
				p->weight=A[i][j];
				p->next=G->adjlist[i].first;//ͷ�巨���Ӷ���ָ��ͱ�ָ�� 
				G->adjlist[i].first=p;
			}
}

void DestroyGraph(AdjGraph *&G){//�����ڽӱ� 
	int i;
	ArcNode *p,*q;
	for(i=0;i<G->n;++i){
		p=G->adjlist[i].first;
		if(p!=NULL){//����ָ����ָ��߽�ָ�� 
			q=p->next;
			while(q!=NULL){//һ��һ������ 
				free(p);
				p=q;
				q=q->next;
			}
			free(p); 
		}
	}
	free(G);//����ͼ 
}

void DispGraph(const AdjGraph *G){//����ڽӱ� 
	ArcNode *p;
	int i;
	for(i=0;i<G->n;++i){
		printf("\t[%2d]",i);
		p=G->adjlist[i].first;
		if(p!=NULL){//������ָ��߶��� 
			printf("->");
			while(p!=NULL){
				printf("��:%d Ȩ:%d  ",p->adjvex,p->weight);
				p=p->next;
			}
		}
		printf("\n");//���һ��������·��� ������ 
	}
}

int Degree1(AdjGraph *G,int v){//����ͼ���
	int s=0;
	if(v<0||v>=G->n)return -1;
	ArcNode *p=G->adjlist[v].first;
	while(p!=NULL){
		++s;
		p=p->next;
	} 
	return s;
}

int Degree2(const AdjGraph *G,const int v){//����ͼ���
	int s1=0,s2=0;
	if(v<0||v>=G->n)return -1;
	ArcNode *p=G->adjlist[v].first;
	while(p!=NULL){//���� 
		++s1;
		p=p->next;
	} 
	for(int i=0;i<G->n;++i){//��� 
		p=G->adjlist[i].first;
		while(p!=NULL){
			if(p->adjvex==v)++s2;
			p=p->next;
		}
	}
	return s1+s2;
}

void DFS(AdjGraph *G,int v){//������ȱ��� 
	int w;
	ArcNode *p=G->adjlist[v].first;
	printf("%d ",v);
	visited[v]=1;
	while(p!=NULL){
		w=p->adjvex;
		if(visited[w]==0)//�Ƿ�û�з��ʹ� 
			DFS(G,w);
		p=p->next;
	}
}

void BFS(AdjGraph *G,int v){//������ȱ��� 
	int i,w,visited[100];
	int Q[100],front=0,rear=1;
	ArcNode *p;
	for(i=0;i<G->n;++i)visited[i]=0;//��ʼ��
	printf("%d ",v);
	visited[v]=1;
	Q[rear]=v;
	while(front!=rear){
		front++;
		w=Q[front];
		p=G->adjlist[w].first;
		while(p!=NULL){
			if(visited[p->adjvex]==0){
				printf("%d ",p->adjvex);
				visited[p->adjvex]=1;
				rear++;
				Q[rear]=p->adjvex;
			}
			p=p->next;
		}
	}
	 
} 

int main(){
	int n=5,e=7,i;//������������ 
	int A[100][100]={{0 ,1  ,2  ,6  ,INF},
					{INF,0  ,INF,4  ,5  },
					{INF,INF,0  ,INF,3  },
					{INF,INF,INF,0  ,INF},
					{INF,INF,INF,7  ,0 }};
	AdjGraph *G;
	CreateGraph(G,A,n,e);
	printf("ͼGΪ��\n");DispGraph(G);
	printf("ͼG�Ķ���Ķȣ�\n");
	printf("	����\t��\n");
	for(i=0;i<G->n;++i)printf("	%d\t%d\n",i,Degree2(G,i));
	printf("������ȱ�����");DFS(G,0);printf("\n");
	printf("������ȱ�����");BFS(G,0);printf("\n");
	DestroyGraph(G);
}
