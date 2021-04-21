#include <stdio.h>

int main() { 
    int a[5][5]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25},t;
     for(int i=0;i<5;++i)
        {for(int j=0;j<5;++j)
            printf("%3d ",a[i][j]);
        printf("\n");
        }
    for(int i=0;i<5;++i)
        for(int j=0;j<i;++j)
            {t=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=t;
            }
     for(int i=0;i<5;++i)
        {for(int j=0;j<5;++j)
            printf("%3d ",a[i][j]);
        printf("\n");
        }
}
