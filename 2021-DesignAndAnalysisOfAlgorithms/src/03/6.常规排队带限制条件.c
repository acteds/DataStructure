#include <stdio.h>
long recursion(int m, int n);
int main(int argc, char const *argv[])
{
    int m, n;
    printf("����m,n(mΪ����50Ԫ������,nΪ����100Ԫ������)\nm>n>=8\n");
    scanf("%d%d", &m, &n);
    printf("f(%d,%d)=%ld", m, n, recursion(m, n));
    return 0;
}
long recursion(int m, int n)
{
    if (n == 0 && m < 8) //todo ����100Ԫ����Ϊ0,�����ڰ�λΪ100
    {
        return 1;
    }
    if (m < n || (n == 0 && m >= 8)) //todo ����100Ԫ���˶���50Ԫ����,�����ڰ�λΪ100
    {
        return 0;
    }
    // todo ����λΪ50Ԫ
    if ((m == 4 && n == 1) || (m == 3 && n == 2))
    {
        return recursion(m - 1, n);
    }
    // todo �ڰ�λΪ100Ԫ
    if ((m == 7 && n == 1) || (m == 6 && n == 2) || (m == 5 && n == 3))
    {
        return recursion(m, n - 1);
    }

    return recursion(m - 1, n) + recursion(m, n - 1);
}