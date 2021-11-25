#include <stdio.h>

// 暂存解
int x[10000];
// 临时最优解
int bestx[10000];
// 临时最大价值
int maximumValue = 0;
/**
 * @brief  物品信息与固有属性结构体
 * @note   固有属性
 * @retval None
 */
struct thing
{
    // 物品总个数
    int count;
    // 物品价值
    int value[10000];
    // 物品重量
    int weight[10000];
    // 背包最大承重量
    int backpackMaximumWeight;
} T;
void dfs(int i, int countValue, int countWeight);

int main(int argc, char const *argv[])
{
    // todo 初始化
    int i = 1;
    printf("背包最大承重量:\n");
    scanf("%d", &T.backpackMaximumWeight);

    printf("物品总个数:\n");
    scanf("%d", &T.count);

    // 全部从1开始
    printf("依次输入物品重量:");
    for (i = 1; i <= T.count; i++)
    {
        scanf("%d", &T.weight[i]);
    }

    printf("依次输入物品价值:");
    for (i = 1; i <= T.count; i++)
    {
        scanf("%d", &T.value[i]);
    }

    // todo 执行回溯
    dfs(1, 0, 0);

    printf("背包装的物品最大价值为:%d\n", maximumValue);

    printf("物品选择序列为:\n");
    for (i = 1; i <= T.count; i++)
    {
        printf("%d ", bestx[i]);
    }
    printf("\n");
    return 0;
}

/**
 * @brief  回溯
 * @note
 * @param  i: 物品i
 * @param  countValue: 背包内已有物品总价值
 * @param  countWeight: 背包内已有物品总重量
 * @retval None
 */
void dfs(int i, int countValue, int countWeight)
{
    if (i > T.count) //所有物品都被遍历到了
    {
        // 如果背包内已有物品总价值大于临时最大价值
        // todo 则赋值将之变成临时最大价值
        if (countValue > maximumValue)
        {
            int i; //局部块变量
            for (i = 1; i <= T.count; i++)
            {
                bestx[i] = x[i];
            }
            maximumValue = countValue;
        }
        return;
    }
    // j:1表示选择,0表示不选择
    int j;
    for (j = 1; j >= 0; j--)
    {
        x[i] = j;
        // todo 如果当前背包内已有物品总重量加上(j*当前物品重量)小于等于背包最大承重量
        // todo 则通过判断,可以继续递归选择物品,若没有通过则结束递归
        if (countWeight + j * T.weight[i] <= T.backpackMaximumWeight)
        {
            // todo 选择下一个物品,背包重量加上这次的物品重量,背包价值加上这次物品的价值
            // todo 是否加由j控制
            dfs(i + 1, countValue + j * T.value[i], countWeight + j * T.weight[i]);
        }
    }
}