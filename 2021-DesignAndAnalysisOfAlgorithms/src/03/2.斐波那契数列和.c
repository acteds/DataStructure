#include <stdio.h>
long sum = 0;
int recursion(int n);
int main(int argc, char const *argv[])
{
    int n = 1;
    printf("������n:\n");
    scanf("%d", &n);
    int temp=recursion(n);
    printf("��%d��Ϊ:%d,ǰ%d���Ϊ%ld", n,temp , n, sum);
    return 0;
}
int recursion(int n)
{
    if (n==1||n==2)
    {
        return 1;
    }
    int temp = recursion(n - 1) + recursion(n - 2);
    sum += temp;
    return temp;
}