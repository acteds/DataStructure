#include<stdio.h>
long recursion(int m, int n);
int main(int argc, char const *argv[])
{
    int m, n;
    printf("输入m,n(m为持有50元的人数,n为持有100元的人数)\n");
    scanf("%d%d", &m, &n);
    printf("f(%d,%d)=%ld",m,n,recursion(m,n));
    return 0;
}
long recursion(int m,int n)
{
    if (n==0)//todo 持有100元的人为0
    {
        return 1;
    }
    if (m<n)//todo 持有100元的人多于50元的人
    {
        return 0;
    }
    return recursion(m - 1, n) + recursion(m,n-1);
}