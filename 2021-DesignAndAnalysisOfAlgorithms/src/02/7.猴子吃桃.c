#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a[100], m, n, d, i;
    printf("�������Ը���m,��������n,ʣ��������d\n");
    scanf("%d%d%d", &m, &n, &d);
    a[n] = d;
    for (i = n-1; i > 0; i--)
    {
        a[i] = (a[i + 1] + m) * 2;
    }
    printf("��1��ժ��%d������", a[1]);
    return 0;
}
