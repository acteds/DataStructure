#include <stdio.h>
long sum = 0;
int recursion(int n);
int main(int argc, char const *argv[])
{
    int n = 1, i;
    printf("������n:\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        sum += recursion(i);
    }
    printf("��%d��Ϊ:%d,ǰ%d���Ϊ%ld", n, recursion(n), n, sum);
    return 0;
}
int recursion(int n)
{
    if (n == 1)
    {
        return 1;
    }
    //todo Ϊ2�ı�����ʹ��a(2i)=a(i)+1;
    if (n % 2 == 0)
    {
        return recursion(n / 2) + 1;
    }
    else
    { //todo ��Ϊ2�ı�����ʹ��a(2i+1)=a(i)+a(i+1)
        return recursion((n - 1) / 2) + recursion((n - 1) / 2 + 1);
    }
}