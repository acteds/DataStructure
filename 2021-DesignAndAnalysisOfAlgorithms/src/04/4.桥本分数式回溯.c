#include <stdio.h>
//todo a为各个格子的数,count为重复检查.
int a[10], count[10];
long n; //todo 计数
void cycle(int i);
int main(int argc, char const *argv[])
{
    cycle(1);
    printf("共运行%ld次", n);
    return 0;
}
/**
 * @brief  先通过重复判断再进行数字匹配.
 * @note   优化性能
 * @param  i: 数字位
 * @retval None
 */
void cycle(int i)
{
    n++; //todo 计数
    if (10 == i)
    {
        // todo 去除重复项
        if (a[1]>a[4])
        {
            return;
        }

        int m1, m2, m3;
        m1 = a[2] * 10 + a[3];
        m2 = a[5] * 10 + a[6];
        m3 = a[8] * 10 + a[9];
        if (a[1]*m2*m3+a[4]*m1*m3==a[7]*m1*m2)
        {
            printf("轮转次数%8ld : %d/%d + %d/%d = %d/%d\n", n,a[1],m1,a[4],m2,a[7],m3);
        }
        return;
    }
    for (a[i] = 1; a[i] < 10; a[i]++)
    {
        //todo 当前得到的a[i]重复则直接跳过.
        if (count[a[i]] == 1)
        {
            continue;
        }
        count[a[i]] = 1; //todo 数字占用
        cycle(i + 1);
        count[a[i]] = 0; //todo 该轮操作完毕,则重新消除占用
    }
}
