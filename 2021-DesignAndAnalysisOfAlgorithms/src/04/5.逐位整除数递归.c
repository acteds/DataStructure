#include <stdio.h>
/**
 * @brief  valueΪ����,lengthΪλ��
 * @note
 * @retval None
 */
struct number
{
    int value[10000];
    int length;
} N;
//���д���
long n = 0;
//�������
int count = 0;
void cycle(int location);
int main(int argc, char const *argv[])
{
    printf("������n(λ��):\n");
    scanf("%d", &N.length);
    cycle(1);
    printf("����ת����:%ld,��ĸ���Ϊ%d", n, count);
    return 0;
}
/**
 * @brief  ��ת
 * @note
 * @param  location: ����λ
 * @retval None
 */
void cycle(int location)
{
    n++;
    // ��������ȫ���������.
    if (location > N.length)
    {
        printf("��ת����%ld:", n);
        int i;
        for (i = 1; i <= N.length; i++)
        {
            printf("%d", N.value[i]);
        }
        printf("\n");
        count++;
        return;
    }
    // Ϊ��λ1ʱ�ض�ͨ�������ж�,ֱ�������ж�
    if (location == 1)
    {
        for (N.value[location] = 1; N.value[location] < 10; N.value[location]++)
        {
            cycle(location + 1);
        }
        return;
    }
    // todo tempΪ����
    int j, temp;
    for (N.value[location] = 0; N.value[location] < 10; N.value[location]++)
    {
        temp = 0;
        // ʹ�ó�����ʽִ�г���,�ж�ǰlocationΪ�Ƿ�����.
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
