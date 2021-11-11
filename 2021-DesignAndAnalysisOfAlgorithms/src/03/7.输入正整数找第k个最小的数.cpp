#include <stdio.h>
int a[11] = {0, 23, 1, 12, 78, 68, 10, 34, 900, 23, 12};
int recursion(int begin, int end, int k);
int main(int argc, char const *argv[])
{
    int begin = 1, end = 10, k;
    printf("请输入k:\n");
    scanf("%d", &k);
    recursion(begin, end, k);
    printf("第%d个最小的数为%d", k, a[k]);
    return 0;
}
int recursion(int begin, int end, int k)
{
    int i, j;
    if (begin < end)
    {
        i = begin;
        j = end;
        a[0] = a[i];//找第i个数为基准
        while (i != j)//只要起始结束指针没有相等就运行
        {
            // 从右边开始找一个比基准小的数
            while (a[j] >= a[0] && j > i)
                j--;
            // 找到了则将这个小的数填入基准数原来的位置
            if (i < j)
            {
                a[i] = a[j];
                i++;
            }
            // 从左边找一个比基准大的数
            while (a[i] <= a[0] && j > i)
                i++;
            // 找到了则将这个大的数填入之前找的小数原来的位置
            if (i < j)
            {
                a[j] = a[i];
                j--;
            }
        }
        // 将基准数填到大小数之间
        a[i] = a[0];
        if (i == k)
        {
            return a[k];
        }
        //i比k大则在左边区间找,否则在右边区间找
        else if (i > k)
        {
            return recursion(begin, i - 1, k);
        }
        else
        {
            return recursion(i + 1, end, k);
        }
    }
}
