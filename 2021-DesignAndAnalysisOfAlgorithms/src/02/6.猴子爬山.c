#include<stdio.h>
int main(int argc, char const *argv[])
{
    //todo �����ʼ����
    int a[100] = {1, 1, 2},i,n;
    printf("������n:\n");
    scanf("%d", &n);
    for (i = 3; i < n; i++)
    {
        a[i] = a[i - 1] + a[i - 3];
    }
    printf("%d", a[n-1]);
    return 0;
}
