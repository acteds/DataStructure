#include<stdio.h>
#define INF 0x3f3f3f3f
int p, s[100][100];
void print(int a, int b);
int main(int argc, char const *argv[])
{
    int d, n, i, j, k, r[100];
    long t, m[100][100];
    printf("������n:\n");
    scanf("%d", &n);
    printf("������Ȩ��:\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &r[i]);
    }

    // �߽�����
    for ( i = 1; i <= n-1; i++)
    {
        m[i][i + 1] = 0;
    }
    // d����
    for ( d = 2; d <= n-1; d++)
    {
        for ( i = 1; i <= n-d; i++)
        {
            // i��j��d���㻮��������
            j = i + d;
            m[i][j] = INF;
            // ��k���л���
            for ( k = i+1; k < j; k++)
            {
                t = m[i][k] + m[k][j] + r[i] * r[k] * r[j];
                if (t<m[i][j])
                {
                    m[i][j] = t;
                    // ��¼�Ա������ʾ����
                    s[i][j] = k;
                }
            }
        }
    }
    p = 0;
    printf("͹%d���ε���СȨ�����ǻ���Ϊ%d��\n ���Ż�������Ϊ:\n",n,n-3);
    print(1,n);
    printf("\n��С����Ȩֵ��Ϊ%ld\n", m[1][n]);
    return 0;
}
void print(int a,int b){
    // �����������ϵĵ�
    if (b>a+1)
    {
        int c = s[a][b];
        if (c > a + 1)
        {
            //����a�ı���
            printf("%-2d---%2d ", a, c);
        }
        if (c < b - 1)
        {
            //����b�ı���
            printf("%2d---%2d ", c, b);
        }
        // �Ա����ֵĲ��ֱַ�����󻮷�
        print(a, c);
        print(c, b);
    }
}