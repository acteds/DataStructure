#include <stdio.h>
int recursion(int n);
int main(int argc, char const *argv[])
{
    int n = 1;
    printf("������n:\n");
    scanf("%d", &n);
    printf("1��%d�ĺ�Ϊ:%d", n, recursion(n));
    return 0;
}
int recursion(int n)
{
    if (n==1)
    {
        return 1;
    }
    return n + recursion(n - 1);
}