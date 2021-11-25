#include <stdio.h>
/**
 * @brief  value为数列,length为位数
 * @note
 * @retval None
 */
struct number
{
    int value[10000];
    int length;
} N;
//运行次数
long n = 0;
//解的数量
int count = 0;
void cycle(int location);
int main(int argc, char const *argv[])
{
    printf("请输入n(位数):\n");
    scanf("%d", &N.length);
    cycle(1);
    printf("总轮转次数:%ld,解的个数为%d", n, count);
    return 0;
}
/**
 * @brief  轮转
 * @note
 * @param  location: 数字位
 * @retval None
 */
void cycle(int location)
{
    n++;
    // 所有数字全部处理完毕.
    if (location > N.length)
    {
        printf("轮转次数%ld:", n);
        int i;
        for (i = 1; i <= N.length; i++)
        {
            printf("%d", N.value[i]);
        }
        printf("\n");
        count++;
        return;
    }
    // 为数位1时必定通过整除判断,直接跳过判断
    if (location == 1)
    {
        for (N.value[location] = 1; N.value[location] < 10; N.value[location]++)
        {
            cycle(location + 1);
        }
        return;
    }
    // todo temp为余数
    int j, temp;
    for (N.value[location] = 0; N.value[location] < 10; N.value[location]++)
    {
        temp = 0;
        // 使用除法算式执行除法,判断前location为是否被整除.
        for (j = 1; j <= location; j++)
        {
            temp = temp * 10 + N.value[j];
            temp %= location;
        }

        if (temp == 0)
        {
            cycle(location + 1);
        }
    }
}
