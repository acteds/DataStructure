#include <stdio.h>

// �ݴ��
int x[10000];
// ��ʱ���Ž�
int bestx[10000];
// ��ʱ����ֵ
int maximumValue = 0;
/**
 * @brief  ��Ʒ��Ϣ��������Խṹ��
 * @note   ��������
 * @retval None
 */
struct thing
{
    // ��Ʒ�ܸ���
    int count;
    // ��Ʒ��ֵ
    int value[10000];
    // ��Ʒ����
    int weight[10000];
    // ������������
    int backpackMaximumWeight;
} T;
void dfs(int i, int countValue, int countWeight);

int main(int argc, char const *argv[])
{
    // todo ��ʼ��
    int i = 1;
    printf("������������:\n");
    scanf("%d", &T.backpackMaximumWeight);

    printf("��Ʒ�ܸ���:\n");
    scanf("%d", &T.count);

    // ȫ����1��ʼ
    printf("����������Ʒ����:");
    for (i = 1; i <= T.count; i++)
    {
        scanf("%d", &T.weight[i]);
    }

    printf("����������Ʒ��ֵ:");
    for (i = 1; i <= T.count; i++)
    {
        scanf("%d", &T.value[i]);
    }

    // todo ִ�л���
    dfs(1, 0, 0);

    printf("����װ����Ʒ����ֵΪ:%d\n", maximumValue);

    printf("��Ʒѡ������Ϊ:\n");
    for (i = 1; i <= T.count; i++)
    {
        printf("%d ", bestx[i]);
    }
    printf("\n");
    return 0;
}

/**
 * @brief  ����
 * @note
 * @param  i: ��Ʒi
 * @param  countValue: ������������Ʒ�ܼ�ֵ
 * @param  countWeight: ������������Ʒ������
 * @retval None
 */
void dfs(int i, int countValue, int countWeight)
{
    if (i > T.count) //������Ʒ������������
    {
        // ���������������Ʒ�ܼ�ֵ������ʱ����ֵ
        // todo ��ֵ��֮�����ʱ����ֵ
        if (countValue > maximumValue)
        {
            int i; //�ֲ������
            for (i = 1; i <= T.count; i++)
            {
                bestx[i] = x[i];
            }
            maximumValue = countValue;
        }
        return;
    }
    // j:1��ʾѡ��,0��ʾ��ѡ��
    int j;
    for (j = 1; j >= 0; j--)
    {
        x[i] = j;
        // todo �����ǰ������������Ʒ����������(j*��ǰ��Ʒ����)С�ڵ��ڱ�����������
        // todo ��ͨ���ж�,���Լ����ݹ�ѡ����Ʒ,��û��ͨ��������ݹ�
        if (countWeight + j * T.weight[i] <= T.backpackMaximumWeight)
        {
            // todo ѡ����һ����Ʒ,��������������ε���Ʒ����,������ֵ���������Ʒ�ļ�ֵ
            // todo �Ƿ����j����
            dfs(i + 1, countValue + j * T.value[i], countWeight + j * T.weight[i]);
        }
    }
}