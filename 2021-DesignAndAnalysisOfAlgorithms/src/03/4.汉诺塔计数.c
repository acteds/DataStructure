#include <stdio.h>
long recursion(int n);
int main(int argc, char const *argv[])
{
    int n = 1;
    printf("������n:\n");
    scanf("%d", &n);
    printf("���ƶ�%ld��\n", recursion(n));
    return 0;
}
long recursion(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return 2 * recursion(n - 1) + 1;
}