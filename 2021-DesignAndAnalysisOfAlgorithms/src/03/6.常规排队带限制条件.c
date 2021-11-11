#include <stdio.h>
long recursion(int m, int n);
int main(int argc, char const *argv[])
{
    int m, n;
    printf("输入m,n(m为持有50元的人数,n为持有100元的人数)\nm>n>=8\n");
    scanf("%d%d", &m, &n);
    printf("f(%d,%d)=%ld", m, n, recursion(m, n));
    return 0;
}
long recursion(int m, int n)
{
    if (n == 0 && m < 8) //todo 持有100元的人为0,封锁第八位为100
    {
        return 1;
    }
    if (m < n || (n == 0 && m >= 8)) //todo 持有100元的人多于50元的人,封锁第八位为100
    {
        return 0;
    }
    // todo 第五位为50元
    if ((m == 4 && n == 1) || (m == 3 && n == 2))
    {
        return recursion(m - 1, n);
    }
    // todo 第八位为100元
    if ((m == 7 && n == 1) || (m == 6 && n == 2) || (m == 5 && n == 3))
    {
        return recursion(m, n - 1);
    }

    return recursion(m - 1, n) + recursion(m, n - 1);
}