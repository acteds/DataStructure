#include<stdio.h>
#define INF 0x3f3f3f3f
int visited[100];
typedef struct vertex
{	int adjvex;//������
	char data[10];//������Ϣ
}VT;

typedef struct graph{
	int n,e;//nΪ��������eΪ����
	VT vexs[100];//�ڽӾ��� ��������Ϣ
	int edges[100][100];//�ڽӾ���
}MG;

void CG(MG &g,const int A[][100],const int n,const int e){//�����ڽӾ���
	int i,j;
	g.n=n;g.e=e;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			g.edges[i][j]=A[i][j];
}

void DG(const MG g){//����ڽӾ���
	for(int i=0;i<g.n;++i){
		for(int j=0;j<g.n;++j)
			if(g.edges[i][j]!=INF)
				printf("%2d ",g.edges[i][j]);
			else	printf("�� ");
		printf("\n");
	}
}

int DG1(const MG g,int n){//����ͼ��ڵ��
	if(n<0||n>g.n)return -1;
	int s=0;
	for(int i=0;i<g.n;++i)
		if(g.edges[i][n]!=0&&g.edges[i][n]<INF)
			++s;
	return s;
}

int DG2(const MG g,int n){//����ͼ��ڵ��
	if(n<0||n>g.n)return -1;
	int s=0;
	for(int i=0;i<g.n;++i){
		if(g.edges[i][n]!=0&&g.edges[i][n]<INF)++s;
		if(g.edges[n][i]!=0&&g.edges[n][i]<INF)++s;
	}
	return s;
}

int GG(MG &g){//����
}

void DFS(MG G,int v){//������ȱ���
	int w;
	printf("%d ",v);
	visited[v]=1;
	for(w=0;w<G.n;++w){
		if(G.edges[v][w]!=0&&G.edges[v][w]<INF&&visited[w]==0)
			DFS(G,w);
	}
}

void BFS(MG G,int v){//������ȱ���
	int i,w,visited[100];
	int Q[100],front=0,rear=1;
	for(i=0;i<G.n;++i)visited[i]=0;//��ʼ��
	printf("%d ",v);
	visited[v]=1;
	Q[rear]=v;
	while(front!=rear){
		front++;
		w=Q[front];
		for(i=0;i<G.n;i++)
			if(G.edges[w][i]!=0&&G.edges[w][i]<INF&&visited[i]==0){
				printf("%d ",i);
				visited[i]=1;
				rear++;
				Q[rear]=i;
			}
	}
}

int main(){
	MG g;
	int n=5,e=7,i;//������������
	int A[100][100]={{0 ,1  ,2  ,6  ,INF},
					{INF,0  ,INF,4  ,5  },
					{INF,INF,0  ,INF,3  },
					{INF,INF,INF,0  ,INF},
					{INF,INF,INF,7  ,0 }};
	CG(g,A,n,e);
	printf("ͼG�Ĵ洢�ṹ��\n");DG(g);
	printf("ͼG�����ж���Ķ�:\n����\t��\n");
	for(i=0;i<g.n;++i)printf("%d\t%d\n",i,DG2(g,i));
	printf("������ȱ�����");DFS(g,0);printf("\n");
	printf("������ȱ�����");BFS(g,0);printf("\n");
	GG(g);
}
