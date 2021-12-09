#include <stdio.h>
int main(int argc, char const *argv[])
{
    int i, j, c, cw, n, sw, sp, p[50], w[50], m[50][500];
    printf("输入物品数量n:\n");
    scanf("%d", &n);
    printf("输入背包载重量C:\n");
    scanf("%d", &c);

    for (i = 1; i <= n; i++)
    {
        printf("请输入物品%d的重量和价值: ", i);
        scanf("%d%d", &w[i], &p[i]);
    }
    // 边界条件
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

    // 开始顺推
    for (i = 2; i <= n; i++)
    {
        for (j = 0; j <= c; j++)
        {
            // 如果当前物品可以放下,并且不放的收益小于放的收益
            if (j >= w[i] && m[i - 1][j] < m[i - 1][j - w[i]] + p[i])
            {
                m[i][j] = m[i - 1][j - w[i]] + p[i];
            }
            else
            {
                //不放,保持原样.
                m[i][j] = m[i - 1][j];
            }
        }
    }
    cw = c;
    printf("最大重量为:%d\n", c);
    printf("物品编号   重量  价值\n");
    //输出背包内物品
    for (sp = 0, sw = 0, i = n; i >=2; i--)
    {
        // 如果本行大于下行,则表示选择了物品
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
    printf("总重量为:%d,总价值为:%d\n", sw, sp);

    printf("推导过程:\n");
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
