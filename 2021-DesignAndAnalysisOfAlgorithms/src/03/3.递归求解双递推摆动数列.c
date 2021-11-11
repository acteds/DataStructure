#include <stdio.h>
long sum = 0;
int recursion(int n);
int main(int argc, char const *argv[])
{
    int n = 1, i;
    printf("请输入n:\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        sum += recursion(i);
    }
    printf("第%d项为:%d,前%d项和为%ld", n, recursion(n), n, sum);
    return 0;
}
int recursion(int n)
{
    if (n == 1)
    {
        return 1;
    }
    //todo 为2的倍数则使用a(2i)=a(i)+1;
    if (n % 2 == 0)
    {
        return recursion(n / 2) + 1;
    }
    else
    { //todo 不为2的倍数则使用a(2i+1)=a(i)+a(i+1)
        return recursion((n - 1) / 2) + recursion((n - 1) / 2 + 1);
    }
}