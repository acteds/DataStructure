#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
typedef struct
{	int data[100];
	int length;
}sss;
void play(sss &L){L.length=0;}

void pr(sss &L){
for(int i=0;i<L.length;++i)
        cout<<L.data[i]<<" ";
cout<<endl;
}

int csh(sss &L,int i,int j)
{if(j>100||j<1)return 0;
L.data[j-1]=i;
L.length++;
return 1;
}

void del(sss &L,int i)
{if(i>L.length||i<1)cout<<"���ִ���";
 else for(int j=i-1;j<L.length;++j)
              L.data[j]=L.data[j+1];
L.length--;
}
int cha(sss &L,int i)
{for(int j=0;j<L.length;++j)
         if(L.data[j]==i)
                         return j;
return 0;}
void jh(sss &L){
int min=0,max=0,t;
for(int i=1;i<L.length;++i){
        if(L.data[min]>L.data[i])min=i;
        if(L.data[max]<L.data[i])max=i;}
t=L.data[min];L.data[min]=L.data[max];L.data[max]=t;}
main(){
sss a;int t;
play(a);
for(int i=0;i<5;++i)if(!csh(a,i+1,i+1))cout<<"����"<<endl;
pr(a);
cout<<"ɾ������Ԫ��"<<endl;
del(a,5);//ɾ������Ԫ��
pr(a);
cout<<"����Ԫ��3�Ƿ����"<<endl;
if(t=cha(a,3)+1)
cout<<"Ԫ������λ����"<<t<<endl;//����Ԫ��3��λ��
else cout<<"Ԫ�ز�����"<<endl;
cout<<"���������Сλ��"<<endl;
jh(a);
pr(a);
system("pause");
}

