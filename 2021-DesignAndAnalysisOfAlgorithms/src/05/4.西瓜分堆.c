#include <stdio.h>
int main(int argc, char const *argv[])
{
    int i, j, n, cl, s, cb, sb, w[50], m[50][500];
    printf("输入物品数量n:\n");
    scanf("%d", &n);
    s = 0;
    printf("请输入西瓜的重量:(空格隔开) \n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &w[i]);
        s += w[i];
    }
    cl = s / 2;
    // 边界条件
    for (i = 0; i < w[n]; i++)
    {
        m[n][i] = 0;
    }
    for (i = w[n]; i <= cl; i++)
    {
        m[n][i] = w[n];
    }

    // 开始逆推
    for (i = n - 1; i >= 1; i--)
    {
        for (j = 0; j <= cl; j++)
        {
            // 如果当前物品可以放下,并且不放的差小于放差
            if (j >= w[i] && m[i + 1][j] < m[i + 1][j - w[i]] + w[i])
            {
                m[i][j] = m[i + 1][j - w[i]] + w[i];
            }
            else
            {
                //不放,保持原样.
                m[i][j] = m[i + 1][j];
            }
        }
    }
    printf("两数之差最小值为:%d\n", s - 2 * m[1][cl]);
    printf("第一组:");
    //输出第一组的重量
    cb = m[1][cl];
    for (sb = 0, i = 1; i <= n - 1; i++)
    {
        // 如果本行大于下行,则表示放了物品
        if (m[i][cb] > m[i + 1][cb])
        {
            cb -= w[i];
            sb += w[i];
            printf("%4d", w[i]);
            // 排除该数,做为第二组的输出
            w[i] = 0;
        }
    }
    printf(" 重量为%d\n第二组:", sb);
    for (sb=0,i = 1; i <=n; i++)
    {
        if (w[i]!=0)
        {
            sb += w[i];
            printf("%4d", w[i]);
        }
    }
    printf(" 重量为%d\n", sb);
    return 0;
}
