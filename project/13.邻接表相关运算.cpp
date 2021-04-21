#include<stdio.h>
#include<malloc.h>
#define INF 0x3f3f3f3f
int visited[100];
typedef struct edgenide
{	int adjvex;//边顶点编号 
	int weight;//指向的权值 
	struct edgenide *next;//链接其他边节点 
}ArcNode;//边节点 

typedef struct vexnode{
	char data[10];//顶点信息 
	ArcNode *first; //指向边节点 
}Head;//顶点 

typedef struct tu{
	int n,e;//节点数n，边数e
	Head adjlist[100];//顶点数组 
}AdjGraph;//图 

void CreateGraph(AdjGraph *&G,const int A[][100],const int n,const int e){//建立邻接表 
	int i,j;ArcNode *p;
	G=(AdjGraph *)malloc(sizeof(AdjGraph));//为图分配空间 
	G->n=n;G->e=e;
	for(i=0;i<G->n;i++)G->adjlist[i].first=NULL;//初始化顶点指针 
	for(i=0;i<G->n;++i)
		for(j=0;j<G->n;++j)
			if(A[i][j]>0&&A[i][j]<INF){
				p=(ArcNode *)malloc(sizeof(ArcNode));//初始化边顶点 
				p->adjvex=j;
				p->weight=A[i][j];
				p->next=G->adjlist[i].first;//头插法链接顶点指针和边指针 
				G->adjlist[i].first=p;
			}
}

void DestroyGraph(AdjGraph *&G){//销毁邻接表 
	int i;
	ArcNode *p,*q;
	for(i=0;i<G->n;++i){
		p=G->adjlist[i].first;
		if(p!=NULL){//顶点指针有指向边界指针 
			q=p->next;
			while(q!=NULL){//一个一个销毁 
				free(p);
				p=q;
				q=q->next;
			}
			free(p); 
		}
	}
	free(G);//销毁图 
}

void DispGraph(const AdjGraph *G){//输出邻接表 
	ArcNode *p;
	int i;
	for(i=0;i<G->n;++i){
		printf("\t[%2d]",i);
		p=G->adjlist[i].first;
		if(p!=NULL){//顶点有指向边顶点 
			printf("->");
			while(p!=NULL){
				printf("名:%d 权:%d  ",p->adjvex,p->weight);
				p=p->next;
			}
		}
		printf("\n");//输出一个顶点链路完毕 ，换行 
	}
}

int Degree1(AdjGraph *G,int v){//无向图求度
	int s=0;
	if(v<0||v>=G->n)return -1;
	ArcNode *p=G->adjlist[v].first;
	while(p!=NULL){
		++s;
		p=p->next;
	} 
	return s;
}

int Degree2(const AdjGraph *G,const int v){//无向图求度
	int s1=0,s2=0;
	if(v<0||v>=G->n)return -1;
	ArcNode *p=G->adjlist[v].first;
	while(p!=NULL){//出度 
		++s1;
		p=p->next;
	} 
	for(int i=0;i<G->n;++i){//入度 
		p=G->adjlist[i].first;
		while(p!=NULL){
			if(p->adjvex==v)++s2;
			p=p->next;
		}
	}
	return s1+s2;
}

void DFS(AdjGraph *G,int v){//深度优先遍历 
	int w;
	ArcNode *p=G->adjlist[v].first;
	printf("%d ",v);
	visited[v]=1;
	while(p!=NULL){
		w=p->adjvex;
		if(visited[w]==0)//是否没有访问过 
			DFS(G,w);
		p=p->next;
	}
}

void BFS(AdjGraph *G,int v){//广度优先遍历 
	int i,w,visited[100];
	int Q[100],front=0,rear=1;
	ArcNode *p;
	for(i=0;i<G->n;++i)visited[i]=0;//初始化
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
	int n=5,e=7,i;//顶点数，边数 
	int A[100][100]={{0 ,1  ,2  ,6  ,INF},
					{INF,0  ,INF,4  ,5  },
					{INF,INF,0  ,INF,3  },
					{INF,INF,INF,0  ,INF},
					{INF,INF,INF,7  ,0 }};
	AdjGraph *G;
	CreateGraph(G,A,n,e);
	printf("图G为：\n");DispGraph(G);
	printf("图G的顶点的度：\n");
	printf("	顶点\t度\n");
	for(i=0;i<G->n;++i)printf("	%d\t%d\n",i,Degree2(G,i));
	printf("深度优先遍历：");DFS(G,0);printf("\n");
	printf("广度优先遍历：");BFS(G,0);printf("\n");
	DestroyGraph(G);
}
