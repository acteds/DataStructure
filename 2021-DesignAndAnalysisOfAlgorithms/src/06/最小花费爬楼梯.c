#include <stdio.h>
#define INF 0x3f3f3f3f
/** * @brief  一共有几层 */
#define N 10
/** * @brief  起点 */
#define START -1
//todo 楼梯格式为:起点-第1层-第2层-...-第N层-顶部
/**
 * @brief  从起点开始(离开起点不消耗体力),爬楼梯,一次可直接爬1-3节楼梯,直到到达顶部(位于最后一节楼梯之上)
 *         每次离开当前楼梯需要消耗体力,若选择爬1节楼梯则需要1倍体力,选择爬2节则消耗2倍体力,3节则3倍
 *         例:cost分别为10,1,15;
 *         则从第1层楼梯爬到第3层需要消耗体力10*2(途中经过未停留的楼梯不需要计算离开消耗体力)
 * @note
 * @param  argc:
 * @param  *argv[]:
 * @retval
 */
int main(int argc, char const *argv[])
{
    /** * @brief  离开每层楼梯的基本代价 */
    int cost[N] = {1, 3, 10, 7, 8, 12, 15, 16, 30, 45};
    /** * @brief  最优解,边界条件,由于从起点离开不需要消耗体力,因此dp的前3项,即到1、2、3层都不用消耗体力 */
    int dp[N + 1] = {0, 0, 0};
    /** * @brief  从哪层来的(数组索引,实际层需要+1),边界条件,前3层之前层都标为START */
    int previous[N + 1] = {START, START, START};
    /** * @brief  临时变量*/
    int i, j;

    // todo 前3层为边界条件,从第4层开始
    for (i = 3; i <= N; i++)
    {
        //todo 开始找最优解
        /** * @brief  临时变量*/
        int temp = INF;
        for (j = 1; j <= 3; j++)
        {
            //todo 当前积累的体力花费,为之前第i-j层的最优解加,到本层的消耗
            int CurrentCost = dp[i - j] + cost[i - j] * j;
            // 取最小值
            if (temp > CurrentCost)
            {
                temp = CurrentCost;
                // 并记录由哪节楼梯走上来
                previous[i] = i - j;
            }
        }
        // 最优解赋值
        dp[i] = temp;
    }

    //todo 数据输出:
    printf("\n当前楼梯层数:");
    for (i = 1; i < N + 1; i++)
    {
        printf("%3d ", i);
    }
    printf(" 顶");

    printf("\n离开基本消耗:");
    for (i = 0; i < N; i++)
    {
        printf("%3d ", cost[i]);
    }

    printf("\n累计最优消耗:");
    for (i = 0; i < N + 1; i++)
    {
        printf("%3d ", dp[i]);
    }

    printf("\n从哪节楼梯来:");
    for (i = 0; i < N + 1; i++)
    {
        printf("%3d ", previous[i] + 1);
    }

    //todo 爬楼梯过程输出
    printf("\n");
    //todo previous[N]为从哪节楼梯到顶的索引,因此+1.
    printf("  %d->顶  花费:%d\n", previous[N] + 1, cost[previous[N]] * (N - previous[N]));
    //todo 从顶的前项开始,依次返回,直到为前3层楼梯.
    for (i = previous[N]; i >= 3; i = previous[i])
    {
        printf("%3d->%-3d 花费:%d\n", previous[i] + 1, i + 1, cost[previous[i]] * (i - previous[i]));
    }
    printf(" 起->%d   花费:%d", i + 1, 0 * (i - START));

    printf("\n\n一共花费体力:%d\n", dp[N]);

    return 0;
}
