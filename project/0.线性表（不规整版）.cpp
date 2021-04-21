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
{if(i>L.length||i<1)cout<<"出现错误";
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
for(int i=0;i<5;++i)if(!csh(a,i+1,i+1))cout<<"错误"<<endl;
pr(a);
cout<<"删除第五元素"<<endl;
del(a,5);//删除第五元素
pr(a);
cout<<"查找元素3是否存在"<<endl;
if(t=cha(a,3)+1)
cout<<"元素三的位置是"<<t<<endl;//查找元素3的位置
else cout<<"元素不存在"<<endl;
cout<<"交换最大最小位置"<<endl;
jh(a);
pr(a);
system("pause");
}

