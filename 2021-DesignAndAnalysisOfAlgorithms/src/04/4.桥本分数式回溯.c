#include <stdio.h>
//todo aΪ�������ӵ���,countΪ�ظ����.
int a[10], count[10];
long n; //todo ����
void cycle(int i);
int main(int argc, char const *argv[])
{
    cycle(1);
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
    n++; //todo ����
    if (10 == i)
    {
        // todo ȥ���ظ���
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
            printf("��ת����%8ld : %d/%d + %d/%d = %d/%d\n", n,a[1],m1,a[4],m2,a[7],m3);
        }
        return;
    }
    for (a[i] = 1; a[i] < 10; a[i]++)
    {
        //todo ��ǰ�õ���a[i]�ظ���ֱ������.
        if (count[a[i]] == 1)
        {
            continue;
        }
        count[a[i]] = 1; //todo ����ռ��
        cycle(i + 1);
        count[a[i]] = 0; //todo ���ֲ������,����������ռ��
    }
}
