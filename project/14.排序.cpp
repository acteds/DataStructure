#include <stdio.h>
void paixu(int a[],int n){
    int i,j,t;
    for(i=0;i<n;++i)
        for(j=i+1;j<n;++j)
            if(a[i]>a[j]){t=a[i];a[i]=a[j];a[j]=t;}
}

int zb(int a[],int l,int r,int key){
int m=(l+r)/2;
if (l>r)return -1;
if (a[m]==key)return m; 
else if (a[m]>key)return zb(a,l,m-1,key);
else    return zb(a,m+1,r,key);
}

int shunxu(int a[],int n,int key){
    for(int i=0;i<n;++i)
        if(a[i]==key) return i;
    return -1;
}

int main(){
    int a[10]={3,4,2,5,6,7,9,8,1,0};
    paixu(a,10);
    for(int i=0;i<10;++i)
    printf("%d ",a[i]);printf("\n");
    printf("6在数组的位置为%d\n",zb(a,0,9,6));
    printf("8在数组的位置为%d",shunxu(a,10,8));
    getchar();
}
