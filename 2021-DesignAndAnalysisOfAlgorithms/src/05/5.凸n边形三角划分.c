#include<stdio.h>
#define INF 0x3f3f3f3f
int p, s[100][100];
void print(int a, int b);
int main(int argc, char const *argv[])
{
    int d, n, i, j, k, r[100];
    long t, m[100][100];
    printf("请输入n:\n");
    scanf("%d", &n);
    printf("请输入权数:\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &r[i]);
    }

    // 边界条件
    for ( i = 1; i <= n-1; i++)
    {
        m[i][i + 1] = 0;
    }
    // d个点
    for ( d = 2; d <= n-1; d++)
    {
        for ( i = 1; i <= n-d; i++)
        {
            // i到j有d个点划分三角形
            j = i + d;
            m[i][j] = INF;
            // 以k进行划分
            for ( k = i+1; k < j; k++)
            {
                t = m[i][k] + m[k][j] + r[i] * r[k] * r[j];
                if (t<m[i][j])
                {
                    m[i][j] = t;
                    // 记录以便后续显示步骤
                    s[i][j] = k;
                }
            }
        }
    }
    p = 0;
    printf("凸%d边形的最小权重三角划分为%d条\n 最优划分线条为:\n",n,n-3);
    print(1,n);
    printf("\n最小划分权值和为%ld\n", m[1][n]);
    return 0;
}
void print(int a,int b){
    // 不是三个以上的点
    if (b>a+1)
    {
        int c = s[a][b];
        if (c > a + 1)
        {
            //不是a的边线
            printf("%-2d---%2d ", a, c);
        }
        if (c < b - 1)
        {
            //不是b的边线
            printf("%2d---%2d ", c, b);
        }
        // 对被划分的部分分别继续求划分
        print(a, c);
        print(c, b);
    }
}