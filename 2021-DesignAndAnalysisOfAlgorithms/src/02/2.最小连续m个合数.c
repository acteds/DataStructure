#include <stdio.h>
#include <math.h>
#include <time.h>
// todo 定义上限为两千四百万
#define N 24000000
#define TYPE long
//!需要声明为全局变量,局部变量是使用栈的.
// todo 素数集合,应为N/lnN,误差为15%
TYPE list2[N / 2 + 1] = {0};
TYPE listCount = 0;
/**
 * @brief  筛选法
 * @note
 * @param  argc:
 * @param  *argv[]:
 * @retval
 */
int main(int argc, char const *argv[])
{
    int m = 0;
    printf("请输入m:\n");
    scanf("%d", &m);

    TYPE i, j;
    // todo 从三开始,并跳过2的倍数
    for (i = 3; i <= N; i += 2)
    {
        // todo 遍历素数集合
        for (j = 0; j < listCount; j++)
        {
            // todo 当除数大于被除数开方时退出
            if (list2[j] > sqrt(i))
            {
                break;
            }
            // todo 被整除时退出
            if (i % list2[j] == 0)
            {
                break;
            }
        }
        // todo 若没有被整除则视为素数,加入素数集合
        if (j >= listCount || list2[j] > sqrt(i))
        {
            list2[listCount] = i;
            // todo 集合内素数数量加1
            listCount++;

            // todo 判断之前区间的大小是否大于等于m.
            if (listCount >= 2 && (list2[listCount - 1] - list2[listCount - 2] - 1) >= m)
            {
                printf("区间为:%ld,%ld\n", list2[listCount - 2] + 1, list2[listCount - 2] +m);
                break;
            }
        }
    }
    return 0;
}
