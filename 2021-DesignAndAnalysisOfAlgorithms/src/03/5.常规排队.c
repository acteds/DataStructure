#include<stdio.h>
long recursion(int m, int n);
int main(int argc, char const *argv[])
{
    int m, n;
    printf("����m,n(mΪ����50Ԫ������,nΪ����100Ԫ������)\n");
    scanf("%d%d", &m, &n);
    printf("f(%d,%d)=%ld",m,n,recursion(m,n));
    return 0;
}
long recursion(int m,int n)
{
    if (n==0)//todo ����100Ԫ����Ϊ0
    {
        return 1;
    }
    if (m<n)//todo ����100Ԫ���˶���50Ԫ����
    {
        return 0;
    }
    return recursion(m - 1, n) + recursion(m,n-1);
}