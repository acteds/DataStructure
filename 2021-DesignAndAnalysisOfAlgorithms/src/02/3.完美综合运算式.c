#include <stdio.h>
#include <math.h>
//todo aΪ�������ӵ���,countΪ�ظ����.
int a[10], count[10];
long n;//todo ����
void cycle(int i);
int main(int argc, char const *argv[])
{
    printf("������f:\n");
    scanf("%d", &a[9]);
    count[a[9]] = 1;

    cycle(0);
    printf("������%ld��", n);
    return 0;
}
/**
 * @brief  ��ͨ���ظ��ж��ٽ�������ƥ��.
 * @note   �Ż�����
 * @param  i: ����λ
 * @retval None
 */
void cycle(int i)
{
    n++;//todo ����
    if (i == 9)
    {
        // todo ��������,���ܱ�����������
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
        //todo λ������
        if ((a[i] == 0 || a[i] == 1) && (i == 0 || i == 1 || i == 4 || i == 8))
        {
            continue;
        }
        if (a[i] == 0 && (i == 2 || i == 5))
        {
            continue;
        }
        //todo ��ǰ�õ���a[i]�ظ���ֱ������.
        if (count[a[i]] == 1)
        {
            continue;
        }
        count[a[i]] = 1; //todo ����ռ��
        cycle(i + 1);
        count[a[i]] = 0;//todo ���ֲ������,����������ռ��
    }
}
