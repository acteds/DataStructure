#include<stdio.h>
int main(int argc, char const *argv[])
{
    int a[10000] = {1},n;
    int p = 0, q = 0,length=1;
    printf("请输入n:\n");
    scanf("%d", &n);
    //todo 只要没有推到指定位数就继续
    while (length<n)
    {
        if (a[p]*2+1>a[q]*5-1)
        {
            a[length] = a[q] * 5 - 1;
            q++;
        }
        else if (a[p] * 2 + 1 < a[q] * 5 - 1)
        {
            a[length] = a[p] * 2 + 1;
            p++;
        }else{//todo 相同则同时位移,避免重复.
            a[length] = a[p] * 2 + 1;
            p++;
            q++;
        }
        length++;
    }
    printf("%d", a[length-1]);
    return 0;
}
