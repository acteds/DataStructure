#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a[100], m, n, d, i;
    printf("请输入多吃个数m,最后的天数n,剩的桃子数d\n");
    scanf("%d%d%d", &m, &n, &d);
    a[n] = d;
    for (i = n-1; i > 0; i--)
    {
        a[i] = (a[i + 1] + m) * 2;
    }
    printf("第1天摘了%d个桃子", a[1]);
    return 0;
}
