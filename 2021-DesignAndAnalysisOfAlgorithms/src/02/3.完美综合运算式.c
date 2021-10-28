#include <stdio.h>
#include <math.h>
//todo a为各个格子的数,count为重复检查.
int a[10], count[10];
long n;//todo 计数
void cycle(int i);
int main(int argc, char const *argv[])
{
    printf("请输入f:\n");
    scanf("%d", &a[9]);
    count[a[9]] = 1;

    cycle(0);
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
    n++;//todo 计数
    if (i == 9)
    {
        // todo 隐含条件,不能被整除则跳过
        if ((a[2] * 10 + a[3]) % a[4]!=0) { return; }

        int temp = (int)pow(a[0], a[1]) + (a[2] * 10 + a[3]) / a[4] - (a[5] * 100 + a[6] * 10 + a[7]) * a[8];
        if (temp == a[9])
        {
            printf("%d^%d+%d%d/%d-%d%d%d*%d=%d\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
        }
        return;
    }
    for (a[i] = 0; a[i] < 10; a[i]++)
    {
        //todo 位置条件
        if ((a[i] == 0 || a[i] == 1) && (i == 0 || i == 1 || i == 4 || i == 8))
        {
            continue;
        }
        if (a[i] == 0 && (i == 2 || i == 5))
        {
            continue;
        }
        //todo 当前得到的a[i]重复则直接跳过.
        if (count[a[i]] == 1)
        {
            continue;
        }
        count[a[i]] = 1; //todo 数字占用
        cycle(i + 1);
        count[a[i]] = 0;//todo 该轮操作完毕,则重新消除占用
    }
}
