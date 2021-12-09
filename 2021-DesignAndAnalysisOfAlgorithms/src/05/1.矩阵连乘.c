#include <stdio.h>

int p[] = {30, 35, 15, 5, 10, 20, 25};
int m[7][7], s[7][7];
void matrixchain(int *p, int n);
void traceback(int i, int j);
int main(int argc, char const *argv[])
{
    matrixchain(p, 6);
    printf("结果为:%d\n", m[1][6]);
    traceback(1, 6);
    return 0;
}
void matrixchain(int *p, int n)
{
    int i, r, k;
    //todo 初始化
    for (i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }
    for (r = 2; r <= n; r++)
    {
        for (i = 1; i <= n - r + 1; i++)
        {
            int j = i + r - 1;
            m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
            s[i][j] = i;
            //todo 选择最小的作为最优解
            for (k = i + 1; k < j; k++)
            {
                int temp = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (temp < m[i][j])
                {
                    m[i][j] = temp;
                    //todo 记录k,以便打印过程
                    s[i][j] = k;
                }
            }
        }
    }
}
void traceback(int i, int j){
    if (i==j)
    {
        return;
    }
    traceback(i, s[i][j]);
    traceback(s[i][j] + 1, j);
    printf("(%d,%d) (%d,%d)\n", i, s[i][j], s[i][j] + 1, j);
}