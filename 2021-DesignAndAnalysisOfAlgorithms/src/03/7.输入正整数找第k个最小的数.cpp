#include <stdio.h>
int a[11] = {0, 23, 1, 12, 78, 68, 10, 34, 900, 23, 12};
int recursion(int begin, int end, int k);
int main(int argc, char const *argv[])
{
    int begin = 1, end = 10, k;
    printf("������k:\n");
    scanf("%d", &k);
    recursion(begin, end, k);
    printf("��%d����С����Ϊ%d", k, a[k]);
    return 0;
}
int recursion(int begin, int end, int k)
{
    int i, j;
    if (begin < end)
    {
        i = begin;
        j = end;
        a[0] = a[i];//�ҵ�i����Ϊ��׼
        while (i != j)//ֻҪ��ʼ����ָ��û����Ⱦ�����
        {
            // ���ұ߿�ʼ��һ���Ȼ�׼С����
            while (a[j] >= a[0] && j > i)
                j--;
            // �ҵ��������С���������׼��ԭ����λ��
            if (i < j)
            {
                a[i] = a[j];
                i++;
            }
            // �������һ���Ȼ�׼�����
            while (a[i] <= a[0] && j > i)
                i++;
            // �ҵ�����������������֮ǰ�ҵ�С��ԭ����λ��
            if (i < j)
            {
                a[j] = a[i];
                j--;
            }
        }
        // ����׼�����С��֮��
        a[i] = a[0];
        if (i == k)
        {
            return a[k];
        }
        //i��k���������������,�������ұ�������
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
