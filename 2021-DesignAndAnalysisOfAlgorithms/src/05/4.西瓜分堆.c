#include <stdio.h>
int main(int argc, char const *argv[])
{
    int i, j, n, cl, s, cb, sb, w[50], m[50][500];
    printf("������Ʒ����n:\n");
    scanf("%d", &n);
    s = 0;
    printf("���������ϵ�����:(�ո����) \n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &w[i]);
        s += w[i];
    }
    cl = s / 2;
    // �߽�����
    for (i = 0; i < w[n]; i++)
    {
        m[n][i] = 0;
    }
    for (i = w[n]; i <= cl; i++)
    {
        m[n][i] = w[n];
    }

    // ��ʼ����
    for (i = n - 1; i >= 1; i--)
    {
        for (j = 0; j <= cl; j++)
        {
            // �����ǰ��Ʒ���Է���,���Ҳ��ŵĲ�С�ڷŲ�
            if (j >= w[i] && m[i + 1][j] < m[i + 1][j - w[i]] + w[i])
            {
                m[i][j] = m[i + 1][j - w[i]] + w[i];
            }
            else
            {
                //����,����ԭ��.
                m[i][j] = m[i + 1][j];
            }
        }
    }
    printf("����֮����СֵΪ:%d\n", s - 2 * m[1][cl]);
    printf("��һ��:");
    //�����һ�������
    cb = m[1][cl];
    for (sb = 0, i = 1; i <= n - 1; i++)
    {
        // ������д�������,���ʾ������Ʒ
        if (m[i][cb] > m[i + 1][cb])
        {
            cb -= w[i];
            sb += w[i];
            printf("%4d", w[i]);
            // �ų�����,��Ϊ�ڶ�������
            w[i] = 0;
        }
    }
    printf(" ����Ϊ%d\n�ڶ���:", sb);
    for (sb=0,i = 1; i <=n; i++)
    {
        if (w[i]!=0)
        {
            sb += w[i];
            printf("%4d", w[i]);
        }
    }
    printf(" ����Ϊ%d\n", sb);
    return 0;
}
