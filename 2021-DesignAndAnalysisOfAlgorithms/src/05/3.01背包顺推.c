#include <stdio.h>
int main(int argc, char const *argv[])
{
    int i, j, c, cw, n, sw, sp, p[50], w[50], m[50][500];
    printf("������Ʒ����n:\n");
    scanf("%d", &n);
    printf("���뱳��������C:\n");
    scanf("%d", &c);

    for (i = 1; i <= n; i++)
    {
        printf("��������Ʒ%d�������ͼ�ֵ: ", i);
        scanf("%d%d", &w[i], &p[i]);
    }
    // �߽�����
    for (j = 0; j <= c; j++)
    {
        if (j >= w[1])
        {
            m[1][j] = p[1];
        }
        else
        {
            m[1][j] = 0;
        }
    }

    // ��ʼ˳��
    for (i = 2; i <= n; i++)
    {
        for (j = 0; j <= c; j++)
        {
            // �����ǰ��Ʒ���Է���,���Ҳ��ŵ�����С�ڷŵ�����
            if (j >= w[i] && m[i - 1][j] < m[i - 1][j - w[i]] + p[i])
            {
                m[i][j] = m[i - 1][j - w[i]] + p[i];
            }
            else
            {
                //����,����ԭ��.
                m[i][j] = m[i - 1][j];
            }
        }
    }
    cw = c;
    printf("�������Ϊ:%d\n", c);
    printf("��Ʒ���   ����  ��ֵ\n");
    //�����������Ʒ
    for (sp = 0, sw = 0, i = n; i >=2; i--)
    {
        // ������д�������,���ʾѡ������Ʒ
        if (m[i][cw] > m[i - 1][cw])
        {
            cw -= w[i];
            sw += w[i];
            sp += p[i];
            printf("%8d   %4d  %4d\n", i, w[i], p[i]);
        }
    }
    if (m[n][c] - sp == p[1])
    {
        sw += w[i];
        sp += p[i];
        printf("%8d   %4d  %4d\n", n, w[i], p[i]);
    }
    printf("������Ϊ:%d,�ܼ�ֵΪ:%d\n", sw, sp);

    printf("�Ƶ�����:\n");
    for (i = 1; i <=n; i++)
    {
        for (j = 0; j <= c; j++)
        {
            printf("%2d ", m[i][j]);
        }
        printf("\n");
    }
    return 0;
}
