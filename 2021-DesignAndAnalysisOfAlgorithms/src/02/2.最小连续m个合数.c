#include <stdio.h>
#include <math.h>
#include <time.h>
// todo ��������Ϊ��ǧ�İ���
#define N 24000000
#define TYPE long
//!��Ҫ����Ϊȫ�ֱ���,�ֲ�������ʹ��ջ��.
// todo ��������,ӦΪN/lnN,���Ϊ15%
TYPE list2[N / 2 + 1] = {0};
TYPE listCount = 0;
/**
 * @brief  ɸѡ��
 * @note
 * @param  argc:
 * @param  *argv[]:
 * @retval
 */
int main(int argc, char const *argv[])
{
    int m = 0;
    printf("������m:\n");
    scanf("%d", &m);

    TYPE i, j;
    // todo ������ʼ,������2�ı���
    for (i = 3; i <= N; i += 2)
    {
        // todo ������������
        for (j = 0; j < listCount; j++)
        {
            // todo ���������ڱ���������ʱ�˳�
            if (list2[j] > sqrt(i))
            {
                break;
            }
            // todo ������ʱ�˳�
            if (i % list2[j] == 0)
            {
                break;
            }
        }
        // todo ��û�б���������Ϊ����,������������
        if (j >= listCount || list2[j] > sqrt(i))
        {
            list2[listCount] = i;
            // todo ����������������1
            listCount++;

            // todo �ж�֮ǰ����Ĵ�С�Ƿ���ڵ���m.
            if (listCount >= 2 && (list2[listCount - 1] - list2[listCount - 2] - 1) >= m)
            {
                printf("����Ϊ:%ld,%ld\n", list2[listCount - 2] + 1, list2[listCount - 2] +m);
                break;
            }
        }
    }
    return 0;
}
