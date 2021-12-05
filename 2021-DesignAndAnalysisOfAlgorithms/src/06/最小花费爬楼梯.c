#include <stdio.h>
#define INF 0x3f3f3f3f
/** * @brief  һ���м��� */
#define N 10
/** * @brief  ��� */
#define START -1
//todo ¥�ݸ�ʽΪ:���-��1��-��2��-...-��N��-����
/**
 * @brief  ����㿪ʼ(�뿪��㲻��������),��¥��,һ�ο�ֱ����1-3��¥��,ֱ�����ﶥ��(λ�����һ��¥��֮��)
 *         ÿ���뿪��ǰ¥����Ҫ��������,��ѡ����1��¥������Ҫ1������,ѡ����2��������2������,3����3��
 *         ��:cost�ֱ�Ϊ10,1,15;
 *         ��ӵ�1��¥��������3����Ҫ��������10*2(;�о���δͣ����¥�ݲ���Ҫ�����뿪��������)
 * @note
 * @param  argc:
 * @param  *argv[]:
 * @retval
 */
int main(int argc, char const *argv[])
{
    /** * @brief  �뿪ÿ��¥�ݵĻ������� */
    int cost[N] = {1, 3, 10, 7, 8, 12, 15, 16, 30, 45};
    /** * @brief  ���Ž�,�߽�����,���ڴ�����뿪����Ҫ��������,���dp��ǰ3��,����1��2��3�㶼������������ */
    int dp[N + 1] = {0, 0, 0};
    /** * @brief  ���Ĳ�����(��������,ʵ�ʲ���Ҫ+1),�߽�����,ǰ3��֮ǰ�㶼��ΪSTART */
    int previous[N + 1] = {START, START, START};
    /** * @brief  ��ʱ����*/
    int i, j;

    // todo ǰ3��Ϊ�߽�����,�ӵ�4�㿪ʼ
    for (i = 3; i <= N; i++)
    {
        //todo ��ʼ�����Ž�
        /** * @brief  ��ʱ����*/
        int temp = INF;
        for (j = 1; j <= 3; j++)
        {
            //todo ��ǰ���۵���������,Ϊ֮ǰ��i-j������Ž��,�����������
            int CurrentCost = dp[i - j] + cost[i - j] * j;
            // ȡ��Сֵ
            if (temp > CurrentCost)
            {
                temp = CurrentCost;
                // ����¼���Ľ�¥��������
                previous[i] = i - j;
            }
        }
        // ���Ž⸳ֵ
        dp[i] = temp;
    }

    //todo �������:
    printf("\n��ǰ¥�ݲ���:");
    for (i = 1; i < N + 1; i++)
    {
        printf("%3d ", i);
    }
    printf(" ��");

    printf("\n�뿪��������:");
    for (i = 0; i < N; i++)
    {
        printf("%3d ", cost[i]);
    }

    printf("\n�ۼ���������:");
    for (i = 0; i < N + 1; i++)
    {
        printf("%3d ", dp[i]);
    }

    printf("\n���Ľ�¥����:");
    for (i = 0; i < N + 1; i++)
    {
        printf("%3d ", previous[i] + 1);
    }

    //todo ��¥�ݹ������
    printf("\n");
    //todo previous[N]Ϊ���Ľ�¥�ݵ���������,���+1.
    printf("  %d->��  ����:%d\n", previous[N] + 1, cost[previous[N]] * (N - previous[N]));
    //todo �Ӷ���ǰ�ʼ,���η���,ֱ��Ϊǰ3��¥��.
    for (i = previous[N]; i >= 3; i = previous[i])
    {
        printf("%3d->%-3d ����:%d\n", previous[i] + 1, i + 1, cost[previous[i]] * (i - previous[i]));
    }
    printf(" ��->%d   ����:%d", i + 1, 0 * (i - START));

    printf("\n\nһ����������:%d\n", dp[N]);

    return 0;
}
