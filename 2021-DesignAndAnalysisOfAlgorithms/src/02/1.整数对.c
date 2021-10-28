#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n, a, b, count = 0, t;
    printf("请输入整数n\n");
    scanf("%d", &n);
    for (a = n / 2; a <= n - 1; a++)
    {
        b = n - a;//todo 假定b
        t = 1;        //todo 控制取数
        while (a > t) //todo 当取数的位数大于a时退出
        {   //去除一个数后与b相等则找到整数对
            if (a / (t * 10) * t + a % t==b)
            {
                printf("第%d个解:a=%d,b=%d\n",++count, a, b);
                break;
            }
            t *= 10;//增加去数的位数.
        }
    }

    return 0;
}
